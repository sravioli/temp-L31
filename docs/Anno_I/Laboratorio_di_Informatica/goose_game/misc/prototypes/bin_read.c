#include <corecrt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat(char *buffer, const char *source) {
  snprintf(buffer + strlen(buffer), strlen(source) + 1, "%s", source);
}

char *alloc_char(const char *s, const int size) {
  char *buffer = (char *)malloc(1 + size * strlen(s) * sizeof(s));  // NOLINT
  if (buffer == NULL) {
    printf("error: failed to allocate memory for string of size %i\n", size);
    exit(EXIT_FAILURE);
  }
  // ensure null termination of the string
  memset(buffer, '\0', strlen(buffer));

  return buffer;
}

typedef struct MenuOption {
  char key;
  char text[256];
} MenuOption;

typedef struct Menu {
  char *title;
  MenuOption options[10];
} Menu;

void parse_option(const char *str, MenuOption option) {
  const char *key_start = strchr(str, '[');
  if (!key_start) {
    printf("error: no opening bracket found in '%s'\n", str);
    exit(EXIT_FAILURE);
  }

  const char *key_end = strchr(str, '[');
  if (!key_end) {
    printf("error: no closing bracket found in '%s'\n", str);
    exit(EXIT_FAILURE);
  }

  if (key_end - key_start != 2) {
    printf("error: key is not one character long\n");
    exit(EXIT_FAILURE);
  }
}

Menu read_menu(const char *filename) {
  FILE *fp;
  if (fopen_s(&fp, filename, "rb") != 0) {
    printf("error: failed to open file '%s'\n", filename);
    exit(EXIT_FAILURE);
  }

  Menu menu;
  fgets(menu.title, sizeof(menu.title), fp);

  int num_options = 0;
  char line[15];
  while (fgets(line, sizeof(line), fp)) {
    MenuOption option;
    parse_option(line, option);
    menu.options[num_options] = option;
    num_options = num_options + 1;
    // concat(option, line);
  }

  return menu;
}

int main(void) {
  // char *main_menu = read_menu("main_menu.bin");
  // printf("%s\n", main_menu);
  Menu main_menu = read_menu("main_menu.bin");

  printf("main_menu.title = %s\n", main_menu.title);

  // free(main_menu);

  return EXIT_SUCCESS;
}
