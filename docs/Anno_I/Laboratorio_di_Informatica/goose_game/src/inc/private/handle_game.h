// Copyright (c) 2023 @authors. GNU GPLv3.

/**
 * @file private/handle_game.h
 * @brief ...
 *
 * ...
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date ...
 * @version 1.0
 * @copyright GNU GPLv3
 */

#ifndef GAME_MODULE_PRIVATE_H
#define GAME_MODULE_PRIVATE_H

#include "../handle_game.h"

void conform_username(char *username);
int is_username_valid(const char username[]);
char *ask_username(Players *pls, const int current_player);

void selection_sort_players(Players *players, int *dice_values);

void interactive_roll(Players *pls, int *dice_values);
void interactive_reroll(Players *pls, int *dice_values);
void print_players_list(Players *pls);

int check_square(const Board *board, int position);
void insert_goose_squares(Board *board);
void insert_special_squares(Board *board);

char *sq_to_str(const int square);

char *build_border(const char *borders[4], const int square_len, const int cols,
                   const int rows, const int row, const Board board);

char *build_squares(const char *vert, const int square_len, const int cols,
                    const int rows, const int row, const Board board);

int ask_num_in_range(const int min, const int max, const char name[]);
Players *create_players(const int num_players);

void sort_players_by_dice(Players *pls);

Board *create_board(const int dim);

/**
 * @brief Build the game board as a string.
 *
 * This function takes a @c Board structure, along with other parameters, and
 * creates a string representation of the game board. The resulting string
 * includes the border characters specified in the @c borders array.
 *
 * @param[in] board      The @c Board structure to represent as a string
 * @param[in] cols       The number of columns in the game board
 * @param[in] square_len The length of one side of a square on the game board
 * @param[in] borders    An array of eight characters to use as the border
 *                       characters for the game board. The characters will be
 *                       used in the following order:
 *                       - nw_corner (ex. "┌")
 *                       - ne_corner (ex. "┐")
 *                       - sw_corner (ex. "└")
 *                       - se_corner (ex. "┘")
 *                       - join_down (ex. "┬")
 *                       - join_up (ex. "┴")
 *                       - dash (ex. "─")
 *                       - vert (ex. "│")
 * @return A string representation of the game board
 */
char *build_board(const Board board, const int cols, const int square_len,
                  const char *borders[8]);

/**
 * @brief Prints the game board to stdout.
 *
 * This function prints the provided game board to stdout using the @c printf()
 * function.
 *
 * @param board The game board to print.
 *
 * @return void.
 */
void print_board(const char game_board[]);

void print_positions(Board *board, Players *pls);

void game_loop(Players *pls, Board *board, const char game_board[]);

#endif  // !GAME_MODULE_PRIVATE_H
