// Copyright (c) 2023 @authors. GNU GPLv3.

/**
 * @file handle_game.h
 * @brief This file contains functions related to the game module.
 *
 * The file defines functions for running the main game loop and starting a new
 * game. It includes necessary header files for board and player types from the
 * common module.
 *
 * The `game_loop()` function runs the main game loop, where players take turns
 * rolling the dice and moving on the game board. It displays the game board and
 * player positions, and prompts the current player to roll the dice or pause
 * the game. After each player's turn, it checks for a winner. If a winner is
 * found, the game loop ends, and the winner is displayed. If the game is
 * paused, the function returns to the main menu.
 *
 * The `new_game()` function starts a new game by setting up the game board,
 * creating players, and sorting the players based on their dice rolls. It then
 * enters the game loop by calling `game_loop()` with the necessary arguments.
 *
 * @note The functions in this file depend on the types defined in the
 *       "board.h" and "players.h" header files from the common/inc/types
 *        module. Make sure to include those headers before using the functions.
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-07-08 01:19
 * @version 2.0
 * @copyright GNU GPLv3
 */

#ifndef GAME_MODULE_H
#define GAME_MODULE_H

#include "../common/inc/types/board.h"
#include "../common/inc/types/players.h"

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief Runs the main game loop.
 *
 * This function runs the main game loop where players take turns rolling the
 * dice and moving on the game board. The function displays the game board and
 * player positions, and prompts the current player to roll the dice or pause
 * the game. After each player's turn, the function checks for a winner. If a
 * winner is found, the game loop ends and the winner is displayed. If the game
 * is paused, the function returns to the main menu.
 *
 * @param[in] pls        The players in the game.
 * @param[in] board      The game board.
 * @param[in] game_board The string representation of the game board.
 *
 * @return void.
 */
void game_loop(Players *pls, Board *board, const char game_board[]);

/**
 * @brief Starts a new game.
 *
 * This function starts a new game by setting up the game board, creating
 * players, and sorting the players based on their dice rolls. The function then
 * enters the game loop by calling `game_loop()` with the necessary arguments.
 *
 * @return void.
 */
void new_game();

#endif  // !GAME_MODULE_H
