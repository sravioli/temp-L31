/**
 * @file board_type.h
 *
 * @brief Header file for the Board struct and associated functions.
 *
 * This header file defines the Board struct, which represents a game board,
 * along with functions to manipulate the board, such as getting and setting
 * the value of a square, as well as getting and setting the dimension of the
 * board.
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-04-22 15:49
 * @version 1.0
 * @copyright GNU GPLv3
 */

#ifndef BOARD_TYPE_H
#define BOARD_TYPE_H

#include "./globals.h"

/**
 * @struct Board
 * @brief Struct representing a board.
 * @var Board::squares
 * Array to store the values of squares on the board.
 * @var Board::dim
 * Dimension of the board.
 */
typedef struct Board {
  int squares[MAX_NUM_SQUARES];  ///< Array to store the values of squares on
                                 ///< the board.
  int dim;                       ///< Dimension of the board.
} Board;

/**
 * @brief Get the value of a square on the board.
 *
 * This function retrieves the value of a square on the board, given its
 * position.
 *
 * @param[in] board    Pointer to the Board struct.
 * @param[in] position Position of the square on the board.
 *
 * @return Value of the square at the given position.
 */
int get_square(const Board *board, int position);

/**
 * @brief Set the value of a square on the board.
 *
 * This function sets the value of a square on the board, given its position and
 * value.
 *
 * @param[in,out] board    Pointer to the Board struct.
 * @param[in]     position Position of the square on the board.
 * @param[in]     value    Value to set for the square.
 *
 * @return void.
 */
void set_square(Board *board, int position, int value);

/**
 * @brief Get the dimension of the board.
 *
 * This function retrieves the dimension of the board.
 *
 * @param[in] board Pointer to the Board struct.
 *
 * @return Dimension of the board.
 */
int get_dim(const Board *board);

/**
 * @brief Set the dimension of the board.
 *
 * This function sets the dimension of the board.
 *
 * @param[in,out] board     Pointer to the Board struct.
 * @param[in]     dimension Dimension to set for the board.
 *
 * @return void.
 */
void set_dim(Board *board, int dimension);

#endif  // !BOARD_TYPE_H
