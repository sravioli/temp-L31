// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include <conio.h>
#include <stdio.h>

#include "../common/inc/string.h"
#include "../common/inc/term.h"
#include "../inc/globals.h"

#include "../inc/handle_help.h"

void print_help_menu() {
  new_screen();
  print_menu(HELP_MENU);
}

void display_file(const char filename[]) {
  new_screen();
  print_file(filename);
  printf("%sExit this view by pressing b/ESC/ENTER/SPACEBAR%s%s", BOLD, RESET,
         LINE_END);

  int display = TRUE;
  while (display) {
    char key = _getch();
    if (is_back_key(key)) {
      display = FALSE;
    }
  }

  print_help_menu();
}

void help_menu() {
  print_help_menu();

  int menu_loop = TRUE;
  while (menu_loop) {
    char key = _getch();

    if (key == 'r') {
      display_file(RULES_FILE);
    } else if (key == 'm') {
      display_file(MANUAL_FILE);
    } else if (key == 'b') {
      menu_loop = FALSE;
    }
  }
}
