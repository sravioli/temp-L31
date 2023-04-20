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

// minimum number of squares allowed
#define MIN_NUM_SQUARES 50

// maximum number of squares allowed
#define MAX_NUM_SQUARES 90

// minimum number of players allowed
#define MIN_NUM_PLAYERS 2

// maximum number of players allowed
#define MAX_NUM_PLAYERS 4

// value of a "goose" square
#define GOOSE_VALUE 0

// spacing between "goose" squares
#define GOOSE_SPACING 9

// base position of the "bridge" square on the board
#define BRIDGE_SQUARE 6

// base position of the "inn" square on the board
#define INN_SQUARE 19

// base position of the "well" square on the board
#define WELL_SQUARE 31

// base position of the "labyrinth" square on the board
#define LABYRINTH_SQUARE 42

// base position of the "prison" square on the board
#define PRISON_SQUARE 52

// base position of the "skeleton" square on the board
#define SKELETON_SQUARE 58

// value of the "bridge" square
#define BRIDGE_VALUE -1

// value of the "inn" square
#define INN_VALUE -2

// value of the "well" square
#define WELL_VALUE -3

// value of the "labyrinth" square
#define LABYRINTH_VALUE -4

// value of the "prison" square
#define PRISON_VALUE -5

// value of the "skeleton" square
#define SKELETON_VALUE -6

// end of string indicator
#define STR_END '\0'

// end of line indicator
#define LINE_END "\n"

#endif  // GLOBALS_H
