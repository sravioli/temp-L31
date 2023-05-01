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
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-04-18 09:46
 * @version 2.0
 * @copyright GNU GPLv3
 */

#ifndef BOARD_H
#define BOARD_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/inc/math.h"
#include "../common/inc/string.h"
#include "../common/inc/term.h"
#include "../inc/board_type.h"
#include "../inc/globals.h"

/**
 * @brief Get the number of squares from user input.
 *
 * This function prompts the user to enter the number of squares for the
 * board game, within the allowed range defined by @c MIN_NUM_SQUARES and
 * @c MAX_NUM_SQUARES constants. It validates the user input and keeps
 * asking for input until a valid number of squares is entered.
 *
 * @return The number of squares entered by the user.
 *
 * @note The function uses @c printf() and @c scanf_s() for input/output
 *       operations.
 * @note The function assumes that @c MIN_NUM_SQUARES and @c MAX_NUM_SQUARES
 * are defined as integer constants in the included @c globals.h file.
 */
int get_num_squares();

/**
 * @brief Creates an empty board with the given dimension, fills it with
 *        squares, and inserts goose and special squares.
 *
 * @param[in] dimension The dimension of the board to be created.
 *
 * @return The created board with initialized squares and inserted @e goose and
 *         @e special squares.
 *
 * @note The created board will have dimension @b dimension and all squares
 *       will be initialized with values ranging from 1 to @b dimension.
 * @note The function calls @c insert_goose_squares() and
 *       @c insert_special_squares() to insert @e goose and @e special squares
 *       into the created board.
 * @note The created board is returned as a value, not a pointer. Copying the
 *       board data may be involved depending on the size of the Board
 *       structure.
 */
Board init_board(const int dimension);

/**
 * @brief Builds the game board as a string representation of the provided Board
 *        using the given border characters and other formatting options.
 *
 * @param[in] board      The Board to build the game board from.
 * @param[in] cols       The number of columns to use for the game board.
 * @param[in] square_len The length of each square in the game board.
 * @param[in] borders    An array of border characters for different parts of
 *                       the game board. The order of characters should be as
 *                       follows:
 *                       @li @c nw_corner  (e.g. "┌");
 *                       @li @c ne_corner  (e.g. "┐");
 *                       @li @c sw_corner  (e.g. "└");
 *                       @li @c se_corner  (e.g. "┘");
 *                       @li @c join_down  (e.g. "┬");
 *                       @li @c join_up    (e.g. "┴");
 *                       @li @c dash       (e.g. "─");
 *                       @li @c vert       (e.g. "│").
 *
 * @return A dynamically allocated char array representing the game board. The
 *         caller is responsible for freeing the memory when no longer needed.
 *
 * @note The returned game board string will contain multiple rows and columns
 *       of squares separated by borders, formatted according to the provided
 *       options.
 * @note The @e Board parameter must be properly initialized and contain valid
 *       data.
 * @note The @e cols parameter should be greater than 0 to avoid division by
 *       zero.
 * @note The @e square_len parameter should be greater than 0 to represent the
 *       length of each square.
 * @note The @e borders array should contain valid characters for each border
 *       position.
 * @note The @e game_board string will be allocated using the @c alloc_char()
 *       function, and the caller is responsible for freeing the memory when no
 *       longer needed.
 * @note The function uses the @c build_border() and @c build_squares() helper
 *       functions to generate the game board string.
 */
char *build_board(const Board board, const int cols, const int square_len,
                  const char *borders[8]);
/**
 * @brief Prints a string representation of a board.
 *
 * This function prints a string representation of a board to the console.
 *
 * @param[in] board A pointer to the board string.
 *
 * @return void.
 */
void print_board(char *board);

#endif  // !BOARD_H
