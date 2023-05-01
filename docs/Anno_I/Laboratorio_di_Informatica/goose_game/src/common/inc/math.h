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
 * @date 2023-05-01 12:35
 * @version 1.0
 * @copyright GNU GPLv3
 */

#ifndef MATHS_UTILS_H
#define MATHS_UTILS_H

#include "./../../inc/globals.h"
#include <stdlib.h>
#include <time.h>

int proportion(const int numerator, const int known_value,
               const int denominator);

int roll_die();

#endif  // !MATHS_UTILS_H
