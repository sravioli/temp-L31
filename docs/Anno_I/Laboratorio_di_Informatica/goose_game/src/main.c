// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "./inc/handle_game.h"
#include "./inc/handle_help.h"

#define MAIN_MENU "./menus/main.txt"

void main_menu() {
  new_screen();
  print_menu(MAIN_MENU);
}

int main(void) {
  main_menu();

  int menu_loop = TRUE;
  while (menu_loop) {
    char key = _getch();

    if (key == 'n') {
      new_game();
      main_menu();
    } else if (key == 's') {
      clear_line();
      printf("DEBUG: key %c: [s]ave games", key);
    } else if (key == 'l') {
      // leaderboard();
      clear_line();
      printf("DEBUG: key %c: [l]eaderboard", key);
    } else if (key == 'h') {
      help_menu();
      main_menu();
    } else if (key == 'q' || key == ESC) {
      clear_line();
      printf("DEBUG: (%c) exiting...", key);
      menu_loop = FALSE;
    } else {
      clear_line();
      printf("Pressed key %c, it does nothing.", key);
    }
  }

  return 0;
}
