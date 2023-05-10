// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include <stdio.h>
#include <stdlib.h>

#include "./inc/handle_game.h"

const char *BORDERS[8] = DEFAULT_BORDERS;

int main(void) {
  int num_squares =
      ask_num_in_range(MIN_NUM_SQUARES, MAX_NUM_SQUARES, "squares");
  int num_players =
      ask_num_in_range(MIN_NUM_PLAYERS, MAX_NUM_PLAYERS, "players");
  Players *players = init_players(num_players);

  Board *board = init_board(num_squares);
  char *game_board =
      build_board(*board, DEFAULT_COLS, DEFAULT_SQUARE_LEN, BORDERS);
  print_board(game_board);

  print_positions(players);

  // time_t current_time = time(NULL);
  // srand((unsigned int)current_time);
  // int random_number = rand();
  //
  // printf("%lld-%d\n", current_time, random_number);

  close_game(board, game_board, players);
  return 0;
}
