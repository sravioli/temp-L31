/**
 * @file board.h
 * @brief Header file for board related functions.
 *
 * This file contains declarations for functions related to game board
 * operations such as getting the number of squares from user input,
 * creating a board with given dimension, inserting various types of squares
 * on the board, and printing the game board with borders.
 *
 * @authors
 *    Amorese Emanuele <e.amorese3@studenti.uniba.it>
 *    Blanco Lorenzo <l.blanco1@studenti.uniba.it>
 *    Cannito Antonio <a.cannito21@studenti.uniba.it>
 *    Fidanza Simone <s.fidanza1@studenti.uniba.it>
 *    Lecini Fabio <f.lecini@studenti.uniba.it>
 * @date 2023-04-18 09:46
 * @version 2.0
 * @license GNU GPLv3
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "../types/board.h"

/**
 * @brief Get the number of squares from user input.
 *
 * This function prompts the user to enter the number of squares for the board
 * game, within the allowed range defined by `MIN_NUM_SQUARES` and
 * `MAX_NUM_SQUARES` constants. It validates the user input and keeps asking for
 * input until a valid number of squares is entered.
 *
 * @return The number of squares entered by the user.
 *
 * @note The function uses `printf()` and `scanf_s()` for input/output
 *       operations.
 * @note The function assumes that `MIN_NUM_SQUARES` and `MAX_NUM_SQUARES` are
 *       defined as integer constants in the included "globals.h" file.
 */
int get_num_squares();

/**
 * @brief Creates an empty board with the given dimension, fills it with
 *        squares, and inserts goose and special squares.
 *
 * @param[in] dimension The dimension of the board to be created.
 *
 * @return The created board with initialized squares and inserted goose and
 *         special squares.
 *
 * @note The created board will have dimension x dimension size and all squares
 *       will be initialized with values ranging from 1 to dimension.
 * @note The function calls `insert_goose_squares()` and
 *       `insert_special_squares()` to insert goose and special squares into the
 *       created board.
 * @note The created board is returned as a value, not a pointer. Copying the
 *       board data may be involved depending on the size of the Board
 *       structure.
 */
Board create_board(const int dimension);

/**
 * @brief Prints the game board with borders using provided characters.
 *
 * This function prints the game board with borders using the provided
 * characters for each border type. It calls the `build_board()` function to
 * build the game board as a dynamically allocated string, then prints the
 * resulting string using `printf()` function. After printing, it frees the
 * memory allocated by `build_board()` function.
 *
 * @param board The game board to be printed.
 * @param cols The number of columns on the game board.
 * @param square_len The length of each square.
 * @param borders An array of strings representing the characters for each
 *        border type. The array should contain 8 strings in the following
 *        order:
 *        - nw_corner (ex. "┌");
 *        - ne_corner (ex. "┐");
 *        - sw_corner (ex. "└");
 *        - se_corner (ex. "┘");
 *        - join_down (ex. "┬");
 *        - join_up (ex. "┴");
 *        - dash (ex. "─");
 *        - vert (ex. "│").
 */
void print_board(const Board board, const int cols, const int square_len,
                 const char *borders[8]);

#endif  // !BOARD_H_
