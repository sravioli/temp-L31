// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "../common/inc/types/gamestate.h"
#include "../common/inc/types/gamestates.h"

#include "../common/inc/error.h"
#include "../common/inc/logger.h"
#include "../inc/globals.h"

#include <stdio.h>
#include <stdlib.h>

void read_game_states(GameStates *gss) {
  FILE *fp;
  if (fopen_s(&fp, SAVED_GAMES_FILE, "wb")) {
    throw_err(FILE_NOT_READABLE_ERROR);
  }

  fread(gss, sizeof(*gss), 1, fp);

  fclose(fp);
}

void write_game_states(GameStates *gss) {
  logger.enter_fn(__func__);

  logger.log("opening file");
  FILE *fp;
  if (fopen_s(&fp, SAVED_GAMES_FILE, "wb")) {
    throw_err(FILE_NOT_READABLE_ERROR);
  }

  logger.log("writing to file");
  fwrite(gss, 1, sizeof(*gss), fp);

  logger.log("closing file");
  fclose(fp);
  logger.exit_fn();
}

// void save_game(Players *pls, Board board) {
//
//   // leggere le scorse parite da file (fn a parte)
//   // gss = read_games()
//   GameStates *gss = (GameStates *)malloc(sizeof(GameStates));  // NOLINT
//   read_game_states(gss);
//
//   int index = get_num_games(gss) + 1;
//
//   // if (get_num_games(gss) == MAX_SAVED_GAMES) {
//   //   index = choose_saved_game(gss);
//   //   delete_game(gss, index);
//   // }
//
//   set_num_games(gss, get_num_games(gss) + 1);
//
//   GameState curr_game;
//   set_players(&curr_game, *pls);
//   set_board(&curr_game, board);
//
//   // chiedere nome partita
//   set_game_name(&curr_game, "temp");
//
//   set_gamestate(gss, &curr_game, index);
//
//   write_game_states(gss);
// }

void save_game(Players *pls, Board board) {
  logger.enter_fn(__func__);
  logger.log("creating gamestates");

  GameStates *gss = (GameStates *)malloc(sizeof(GameStates));  // NOLINT
  int index = 0;

  // if (get_num_games(gss) == MAX_SAVED_GAMES) {
  //   index = choose_saved_game(gss);
  //   delete_game(gss, index);
  // }

  set_num_games(gss, get_num_games(gss) + 1);

  GameState curr_game;
  set_players(&curr_game, *pls);
  set_board(&curr_game, board);

  // chiedere nome partita
  set_game_name(&curr_game, "temp");

  set_gamestate(gss, &curr_game, index);

  write_game_states(gss);
  logger.exit_fn();
}
