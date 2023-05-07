#ifndef GAME_MODULE_H
#define GAME_MODULE_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vadefs.h>

#include "../common/inc/math.h"
#include "../common/inc/string.h"
#include "../common/inc/term.h"

#include "../inc/globals.h"
#include "../inc/private/handle_game.h"

#include "../types/board.h"
#include "../types/fn_lookup.h"
#include "../types/menu.h"
#include "../types/player.h"

Board *init_board(const int dim);
int ask_num_in_range(const int min, const int max, const char name[]);
char *ask_username();

void close_game(void *fst_ptr, ...);

#endif  // !GAME_MODULE_H
