/**
 * @file fn_lookup.h
 * @brief Defines a struct for associating character keys with function
 *        pointers.
 *
 * This header file defines a struct called @c FnLookup that associates a
 * character key with a function pointer. It also provides several functions for
 * getting and setting keys and function pointers, as well as searching for a
 * function in an array of @c FnLookup structs.
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-05-03 20:46
 * @version 1.0
 * @copyright GNU GPLv3
 *
 * @note This file requires the standard library headers @c stdio.h and
 *       @c stdlib.h.
 */

#ifndef FN_LOOKUP_TYPE_H
#define FN_LOOKUP_TYPE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief A struct that associates a character key with a function pointer.
 *
 * This struct contains a character key and a function pointer. The key is used
 * to identify the function, and the function pointer points to the function's
 * code.
 *
 * @var FnLookup::key
 * The character key associated with the function.
 *
 * @var FnLookup::fn
 * A function pointer that points to the function's code.
 */
typedef struct FnLookup {
  char key;      ///< The character key associated with the function.
  void (*fn)();  ///< A function pointer that points to the function's code.
} FnLookup;

/**
 * @brief Gets the key of the function at the specified index.
 *
 * This function retrieves the key of the function in the @c FnLookup array at
 * the specified index.
 *
 * @param[in] functions An array of @c FnLookup structs.
 * @param[in] index     The index of the function to get.
 *
 * @return The key of the function at the specified index.
 */
char get_fn_key(struct FnLookup functions[], const int index);

/**
 * @brief Sets the key of a function.
 *
 * This function sets the key of a function in a @c FnLookup struct.
 *
 * @param[in,out] functions A pointer to the @c FnLookup struct to modify.
 * @param[in]     key       The new key for the function.
 *
 * @return void.
 */
void set_fn_key(struct FnLookup *functions, const char key);

/**
 * @brief Gets a function pointer from an array of function pointers.
 *
 * This function retrieves a function pointer from an array of function pointers
 * contained in a @c FnLookup struct.
 *
 * @param[in] functions An array of @c FnLookup structs.
 * @param[in] index     The index of the function to get.
 *
 * @return A function pointer.
 */
void (*get_fn(struct FnLookup functions[], const int index))();

/**
 * @brief Sets a function pointer in a @c FnLookup struct.
 *
 * This function sets a function pointer in a @c FnLookup struct at the
 * specified index.
 *
 * @param[in,out] functions A pointer to the @c FnLookup struct to modify.
 * @param[in]     index     The index of the function to set.
 * @param[in]     fn        A function pointer to set.
 *
 * @return void.
 */
void set_fn(struct FnLookup *functions, const int index, void (*fn)());

/**
 * @brief Searches for a function in an array of @c FnLookup structs.
 *
 * This function searches for a function in an array of @c FnLookup structs and
 * returns the index of the function if found. If the function is not found, an
 * error message is printed to the console and the program exits with a failure
 * code.
 *
 * @param[in] functions     An array of @c FnLookup structs to search in.
 * @param[in] num_functions The number of @c FnLookup structs in the array.
 * @param[in] key           The key of the function to search for.
 *
 * @return The index of the function in the array of @c FnLookup structs.
 */
int lookup_fn(struct FnLookup functions[], const int num_functions, char key);

#endif  // !FN_LOOKUP_TYPE_H
