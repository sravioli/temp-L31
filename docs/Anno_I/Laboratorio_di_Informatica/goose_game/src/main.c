// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele <e.amorese3@studenti.uniba.it>
//    Blanco Lorenzo <l.blanco1@studenti.uniba.it>
//    Cannito Antonio <a.cannito21@studenti.uniba.it>
//    Fidanza Simone <s.fidanza1@studenti.uniba.it>
//    Lecini Fabio <f.lecini@studenti.uniba.it>

#include <stdio.h>
#include <stdlib.h>

#include "./globals.h"
#include "./modules/board.h"

int main(void) {
  const char *round_borders[8] = {"╭", "╮", "╰", "╯", "┬", "┴", "─", "│"};

  int num_squares = get_num_squares();
  Board board = create_board(num_squares);
  print_board(board, 15, 7, round_borders);

  return 0;
}
