#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/types/fn_lookup.h"
#include "../../src/types/menu.h"

void display_new_game() { printf("Starting new game\n"); }
void display_saved_games() { printf("Showing saved games\n"); }
void display_help() { printf("Showing help\n"); }
void display_leaderboard() { printf("Showing leaderboard\n"); }
void quit() { printf("Quitting\n"); }

struct FnLookup funs[] = {
    {'n', &display_new_game},
    {'s', &display_saved_games},
    {'h', &display_help},
    {'l', &display_leaderboard},
    {'q', &quit},
};

char *trim(char *str) {
  // Find the length of the string
  size_t len = strlen(str);

  // Trim leading whitespace
  while (isspace(str[0])) {
    str = str + 1;
    len = len - 1;
  }

  // Trim trailing whitespace
  while ((len > 0) && (isspace(str[len - 1]))) {
    len = len - 1;
  }
  str[len] = '\0';

  // Return a pointer to the trimmed string
  return str;
}

const int num_functions = sizeof(funs) / sizeof(FnLookup);

struct MenuOption *parse_option(char line[]) {
  // allocate memory for the option
  struct MenuOption *option = init_option();
  set_text(option, trim(line));  // save the line as the text field

  // tokenize the string by searching for `[<key>]`
  char *next_key;
  char key = *strtok_s(line, "[]", &next_key);
  set_key(option, key);

  // lookup the function corresponding to the found key
  const int fn_index = lookup_fn(funs, num_functions, key);
  // set the fn as the option action
  set_action(option, get_fn(funs, fn_index));

  return option;
}

Menu read_menu(const char filename[]) {
  struct Menu menu;
  // fread(menu, sizeof(Menu), 1, fp);
  FILE *fp;

  // Open file and check for errors
  if (fopen_s(&fp, filename, "rb") != 0) {
    printf("error: failed to open file '%s'.\n", filename);
    exit(EXIT_FAILURE);
  }

  // Read the title from the fp
  char title[MAX_LINE_LEN];
  fgets(title, sizeof(title), fp);
  set_title(&menu, title);

  // parse the remaining lines as menu options
  char line[MAX_LINE_LEN];
  int num_options = 0;
  while (fgets(line, sizeof(line), fp)) {
    struct MenuOption *option = parse_option(line);  // parse line into struct
    set_option(&menu, num_options, *option);         // fill the menu
    num_options = num_options + 1;
  }

  fclose(fp);  // Close file

  // Set the number of options in the menu
  set_num_options(&menu, num_options);
  return menu;
}

void print_menu(Menu menu) {
  printf("%s\n", get_title(menu));
  int i = 0;
  while (i < get_num_options(menu)) {
    printf("%s\n", get_menu_text(menu, i));
    i = i + 1;
  }
}

int launch_option(Menu menu) {
  int menu_loop = 1;
  while (menu_loop) {
    char key = _getch();
    int i = 0;
    int is_key_invalid = 1;
    while (i < get_num_options(menu)) {
      if (get_menu_key(menu, i) == key) {
        printf("\r\x1b[2K");  // clear line
        menu_loop = 0;
        is_key_invalid = 0;
        call_action(menu, i);
        return 1;
      }
      i = i + 1;
    }
    if (is_key_invalid) {
      printf("\r\x1b[2K");
      printf("pressed key %c, it does nothing\n", key);
    }
  }
  return 0;
}

int main() {
  Menu test = read_menu("main_menu.bin");
  print_menu(test);
  if (launch_option(test)) {
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
