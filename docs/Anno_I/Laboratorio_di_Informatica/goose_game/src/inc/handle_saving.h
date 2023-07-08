#ifndef SAVING_MODULE_H
#define SAVING_MODULE_H

#include "../common/inc/types/board.h"
#include "../common/inc/types/gamestate.h"
#include "../common/inc/types/gamestates.h"
#include "../common/inc/types/players.h"

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

void save_game(Players *pls, Board board);
void saved_games();

#endif  // !SAVING_MODULE_H
