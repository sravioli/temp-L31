// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include <stdio.h>
#include <stdlib.h>

#include "./common/inc/string.h"
#include "./common/inc/term.h"
#include "./inc/board.h"
#include "./inc/globals.h"

int main(void) {
  const char *round_borders[8] = {"╭", "╮", "╰", "╯", "┬", "┴", "─", "│"};

  // int num_squares = get_num_squares();
  int num_squares = 50;
  Board board = create_board(num_squares);
  print_board(board, 15, 7, round_borders);

  return 0;
}
