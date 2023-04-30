#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../inc/globals.h"
// #include "../inc/private/string.h"

void concat_narrow(char *buffer, const char *source) {
  snprintf(buffer + strlen(buffer), strlen(source) + 1, "%s", source);
}

void concat_wide(wchar_t *buffer, const wchar_t *source) {
  swprintf(buffer + wcslen(buffer), wcslen(source) + 1, L"%ls", source);
}

void concat(void *buffer, const void *source) {
  // Determine the type of strings based on the buffer pointer
  if (sizeof(*((char *)buffer)) == sizeof(char)) {               // NOLINT
    concat_narrow((char *)buffer, (const char *)source);         // NOLINT
  } else if (sizeof(*((wchar_t *)buffer)) == sizeof(wchar_t)) {  // NOLINT
    concat_wide((wchar_t *)buffer, (const wchar_t *)source);     // NOLINT
  } else {
    printf("error: concat function got unsupported values! Use one of 'char', "
           "'wchar_t'");
    exit(EXIT_FAILURE);
  }
}

void nconcat(char *buffer, const char *source, const int n_times) {
  int buffer_length = strlen(buffer);
  int source_len = strlen(source);
  int i = 0;
  while (i < n_times) {
    snprintf(buffer + buffer_length, source_len + 1, "%s", source);
    buffer_length = buffer_length + source_len;
    i = i + 1;
  }
}

void nconcatw(wchar_t *buffer, const wchar_t *source, const int n_times) {
  int buffer_length = wcslen(buffer);
  int source_length = wcslen(source);

  int i = 0;
  while (i < n_times) {
    int remaining_space =
        wcslen(buffer) - buffer_length;  // Calculate remaining space in buffer
    if (remaining_space <= 0) {
      break;
    }
    // Use swprintf with the remaining space as buffer size
    swprintf(buffer + buffer_length, remaining_space, L"%ls", source);
    buffer_length += source_length;  // Update buffer length
    i = i + 1;
  }
}

void fconcat(char *buffer, const int source_size, const char *format, ...) {
  va_list args;
  va_start(args, format);
  vsnprintf(buffer + strlen(buffer), source_size, format, args);
  va_end(args);
}

char *alloc_char(const char *s, const int size) {
  char *buffer = (char *)malloc(1 + size * strlen(s) * sizeof(s));  // NOLINT
  if (!buffer) {
    printf("error: failed to allocate memory for string of size %i\n", size);
    exit(EXIT_FAILURE);
  }
  // ensure null termination of the string
  memset(buffer, STR_END, strlen(buffer));

  return buffer;
}
