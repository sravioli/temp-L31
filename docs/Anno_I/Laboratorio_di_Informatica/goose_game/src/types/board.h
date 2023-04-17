/**
 * @file board.h
 *
 * @brief Declaration of the Board struct and its getter and setter functions.
 *
 * This file contains the declaration of the Board struct and its getter and
 * setter functions. The Board struct represents a game board and stores
 * information such as the values of squares and the dimension of the board.
 *
 * @authors
 *    Amorese Emanuele <e.amorese3@studenti.uniba.it>
 *    Blanco Lorenzo <l.blanco1@studenti.uniba.it>
 *    Cannito Antonio <a.cannito21@studenti.uniba.it>
 *    Fidanza Simone <s.fidanza1@studenti.uniba.it>
 *    Lecini Fabio <f.lecini@studenti.uniba.it>
 * @date 2023-04-11 12:44
 * @version 1.0
 * @license GNU GPLv3
 */

#ifndef BOARD_TYPE_H
#define BOARD_TYPE_H

#include "../globals.h"

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
 * @param[in] board Pointer to the Board struct.
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
 * @param[in,out] board Pointer to the Board struct.
 * @param[in] position Position of the square on the board.
 * @param[in] value Value to set for the square.
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
 * @param[in,out] board Pointer to the Board struct.
 * @param[in] dimension Dimension to set for the board.
 *
 * @return void.
 */
void set_dim(Board *board, int dimension);

#endif  // BOARD_H
