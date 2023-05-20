#include "../inc/logger.h"
#include <stdio.h>

#define THROW_FORMAT "%s[%s()] %serror: %s.%s\n"
#define MAX_BUFFER_LEN 256

static char log_filename[20];
bool is_active = true;

static bool is_initialized = false;

void throw(const char caller[], const char format[], ...) {
  char buffer[MAX_BUFFER_LEN];  // will recieve the error message

  // format the errror message into the buffer
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, sizeof(buffer), format, args);
  va_end(args);

  // print to stderr the exception
  fprintf(stderr, THROW_FORMAT, YELLOW, caller, RED, buffer, END_COLOR);
  exit(EXIT_FAILURE);
}

bool is_filename_valid(const char filename[]) {
  // check for empty
  if (!filename || !strlen(filename)) {
    return false;
  }

  // check that each char is a valid one
  int i = 0;
  while (i < strlen(filename)) {
    char ch = filename[i];
    if (!isalnum(ch) && ch != '_' && ch != '-' && ch != '.') {
      return false;
    }
    i = i + 1;
  }

  // check if the filename ends with a dot or a space (which is not allowed)
  char last_char = filename[strlen(filename) - 1];
  if (last_char == '.' || last_char == ' ') {
    return false;
  }

  // filename is valid
  return true;
}

void start_logger(const char *filename) {
  // check if logging has been disabled
  if (!is_active) {
    return;
  }

  if (!is_filename_valid(filename)) {
    throw(__func__, "given filename '%s' is invalid", filename);
  }
  // copy given filename to static variable
  snprintf(log_filename, sizeof(log_filename), "%s", filename);

  FILE *log_fp;
  if (fopen_s(&log_fp, log_filename, "w")) {
    throw(__func__, "failed to open file '%s' for writing", log_filename);
  }
  fprintf(log_fp, "====== START LOG ======\n");

  // log file has been created and can be written to
  is_initialized = true;

  fclose(log_fp);
  return;
}

void stop_logger() {
  if (!is_active || !is_initialized) {  // avoid undesired logging
    return;
  }
  // indicate log termination
  FILE *log_fp;
  if (fopen_s(&log_fp, log_filename, "a")) {
    throw(__func__, "failed to open file '%s' for writing", log_filename);
  }
  fprintf(log_fp, "======  END LOG  ======\n");

  // close file
  fclose(log_fp);
  return;
}

void log_event(const char *caller, const char *format, ...) {
  if (!is_active || !is_initialized) {  // avoid undesired logging
    return;
  }
  // get the current time
  static struct tm timeinfo;
  static char timestamp[20];

  time_t now = time(NULL);
  localtime_s(&timeinfo, &now);
  strftime(timestamp, sizeof(timestamp), "%d/%m/%y %H:%M:%S", &timeinfo);

  // print the timestamp and function name to the log file
  FILE *log_fp;
  if (fopen_s(&log_fp, log_filename, "a")) {
    throw(__func__, "failed to open file '%s' for writing", log_filename);
  }
  fprintf(log_fp, "[%s] %s() - ", timestamp, caller);

  // print the formatted message using the variable arguments
  va_list args;
  va_start(args, format);
  vfprintf(log_fp, format, args);
  va_end(args);

  // add a new line and close the log file
  fprintf(log_fp, "\n");
  fclose(log_fp);
  return;
}

void disable_logger() { is_active = false; }
void enable_logger() { is_active = true; }

struct Logger logger = {
    .start = start_logger,
    .log = log_event,
    .stop = stop_logger,
    .disable = disable_logger,
    .enable = enable_logger,
};