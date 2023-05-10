#ifndef GAME_MODULE_H
#define GAME_MODULE_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../common/inc/math.h"
#include "../common/inc/string.h"
#include "../common/inc/term.h"

#include "../inc/globals.h"
#include "../inc/private/handle_game.h"

#include "../types/board.h"
#include "../types/menu.h"
#include "../types/players.h"

Board *init_board(const int dim);

int ask_num_in_range(const int min, const int max, const char name[]);

Players *init_players(const int num_players);
void print_players(const Players *ps);
void print_positions(const Players *ps);

void close_game(void *ptr, ...);

#endif  // !GAME_MODULE_H
