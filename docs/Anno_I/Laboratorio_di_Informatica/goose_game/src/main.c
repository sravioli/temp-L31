// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include <stdio.h>
#include <stdlib.h>

#include "./inc/board.h"

int main(void) {
  const char *round_borders[8] = {"╭", "╮", "╰", "╯", "┬", "┴", "─", "│"};

  // int num_squares = get_num_squares();
  int num_squares = 50;
  Board board = init_board(num_squares);
  char *game_board = build_board(board, 15, 7, round_borders);

  print_board(game_board);

  free(game_board);
  return 0;
}
