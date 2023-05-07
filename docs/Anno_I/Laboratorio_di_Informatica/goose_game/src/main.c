// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include <stdio.h>
#include <stdlib.h>

#include "./inc/globals.h"
#include "./inc/handle_game.h"

const char *BORDERS[8] = DEFAULT_BORDERS;

int main(void) {
  int num_squares =
      ask_num_in_range(MIN_NUM_SQUARES, MAX_NUM_SQUARES, "squares");
  int num_players =
      ask_num_in_range(MIN_NUM_PLAYERS, MAX_NUM_PLAYERS, "players");
  char *username = ask_username();
  printf("username: %s\n", username);

  Board *board = init_board(num_squares);
  char *game_board =
      build_board(*board, DEFAULT_COLS, DEFAULT_SQUARE_LEN, BORDERS);
  print_board(game_board);

  close_game(board, game_board, username);
  return 0;
}
