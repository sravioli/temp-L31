#ifndef SAVING_MODULE_H
#define SAVING_MODULE_H

#include "../common/inc/types/board.h"
#include "../common/inc/types/players.h"

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

#define NO_SAVED_GAMES 0

void save_game(Players *pls, Board board);
void saved_games();

#endif  // !SAVING_MODULE_H
