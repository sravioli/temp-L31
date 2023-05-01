/**
 * @file globals.h
 *
 * @brief Global constants and definitions for the board game module.
 *
 * This file contains global constants and definitions used in all of the board
 * game modules. These constants define the minimum and maximum number of
 * squares and players allowed, values and positions of special squares on the
 * board, and other global settings for the game.
 *
 * @warning This file should be included in any source file that needs to
 *          access these global constants and definitions.
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-04-17 13:13
 * @version 1.0
 * @copyright GNU GPLv3
 */

#ifndef GLOBALS_H
#define GLOBALS_H

// GLOBAL CONSTANTS LIST

// Minimum and maximum number of squares allowed
#define MIN_NUM_SQUARES 50
#define MAX_NUM_SQUARES 90

// Minimum and maximum number of players allowed
#define MIN_NUM_PLAYERS 2
#define MAX_NUM_PLAYERS 4

// Goose square spacing and value
#define GOOSE_SPACING 9
#define GOOSE_VALUE 0

// Board squares positions
#define BRIDGE_SQUARE 6
#define INN_SQUARE 19
#define WELL_SQUARE 31
#define LABYRINTH_SQUARE 42
#define PRISON_SQUARE 52
#define SKELETON_SQUARE 58

// Board squares values
#define BRIDGE_VALUE -1
#define INN_VALUE -2
#define WELL_VALUE -3
#define LABYRINTH_VALUE -4
#define PRISON_VALUE -5
#define SKELETON_VALUE -6

// Default board properties
#define DEFAULT_COLS 15
#define DEFAULT_SQUARE_LEN 7
#define DEFAULT_BORDERS                                                        \
  { "╭", "╮", "╰", "╯", "┬", "┴", "─", "│" }

// Player default properties
#define INITIAL_POSITION 0
#define INITIAL_SCORE 0
#define MAX_NAME_LENGTH 20
#define MAX_USERNAME_LENGTH 3

// Dice properties
#define MIN_DICE_THROW 1
#define MAX_DICE_THROW 6

// Other constants
#define LINE_END "\n"
#define STR_END '\0'
#define STR_EMPTY ""
#define SPACE_CHAR ' '

#define FALSE 0
#define TRUE (!FALSE)

#endif  // GLOBALS_H
