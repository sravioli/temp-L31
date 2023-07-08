// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./common/inc/error.h"
#include "./common/inc/logger.h"
#include "./common/inc/term.h"

#include "./inc/globals.h"

#include "./inc/handle_game.h"
#include "./inc/handle_help.h"
#include "./inc/handle_saving.h"

void main_menu() {
  logger.enter_fn(__func__);

  new_screen();
  print_menu(MAIN_MENU);

  logger.exit_fn();
}

int main(void) {
  // logger.disable();
  logger.start("goose.log");
  logger.enter_fn(__func__);

  srand(time(NULL));

  wait_keypress("press to launch game");  // to read errors from compiler
  main_menu();

  int menu_loop = TRUE;
  while (menu_loop) {
    char key = _getch();

    if (key == 'n') {
      logger.log("launching new game");
      new_game();
      main_menu();
    } else if (key == 's') {
      clear_line();
      logger.log("invoked saved games");
      saved_games();
      main_menu();
    } else if (key == 'l') {
      logger.log("invoked leaderboard");
      // leaderboard();
      clear_line();
      printf("DEBUG: key %c: [l]eaderboard", key);
    } else if (key == 'h') {
      logger.log("calling help menu");
      help_menu();
      main_menu();
    } else if (key == 'q' || key == ESC) {
      clear_line();
      printf("DEBUG: (%c) exiting...", key);
      _fcloseall();
      logger.log("exiting game");
      menu_loop = FALSE;
    } else {
      logger.log("invalid key pressed, continuing loop");
      clear_line();
      print_err(INVALID_KEY_ERROR);
    }
  }

  logger.stop();
  return EXIT_SUCCESS;
}
