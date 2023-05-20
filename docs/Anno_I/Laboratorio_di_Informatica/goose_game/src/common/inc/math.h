// Copyright (c) 2023 @authors. GNU GPLv3.

/**
 * @file math.h
 * @brief Header file for maths related functions.
 *
 * This file contains declarations for functions related to mathematical
 * operations such as a proportion or rolling two die.
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-05-17 09:31
 * @version 1.5
 * @copyright GNU GPLv3
 */

#ifndef MATHS_UTILS_H
#define MATHS_UTILS_H

#include "./../../inc/globals.h"

#include <stdlib.h>
#include <time.h>

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @}
 * @defgroup DiceConstants Dice Constants
 * @brief Constants related to dice throwing.
 * @{
 */

/**
 * @def MIN_DICE_THROW
 * @brief Minimum value of a dice throw.
 */
#define MIN_DICE_THROW 1

/**
 * @def MAX_DICE_THROW
 * @brief Maximum value of a dice throw.
 */
#define MAX_DICE_THROW 6
/** @} */  // End of DiceConstants group

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

int proportion(const int numerator, const int known_value,
               const int denominator);

int roll_dice();

void swap_int(int *a, int *b);

#endif  // !MATHS_UTILS_H
