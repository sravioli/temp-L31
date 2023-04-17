/**
 * @file board_private.h
 *
 * @brief Private header file for board module.
 *
 * This is a private header file that contains declarations for internal
 * functions used within the board module. These functions are not intended for
 * external use and should not be called directly by external code.
 *
 * @attention This file should not be included or used directly by external
 *            code. It is for internal use within the board module only.
 *
 * @authors
 *    Amorese Emanuele <e.amorese3@studenti.uniba.it>
 *    Blanco Lorenzo <l.blanco1@studenti.uniba.it>
 *    Cannito Antonio <a.cannito21@studenti.uniba.it>
 *    Fidanza Simone <s.fidanza1@studenti.uniba.it>
 *    Lecini Fabio <f.lecini@studenti.uniba.it>
 * @date 2023-04-17 13:09
 * @version 1.0
 * @license GNU GPLv3
 *
 * @see board.h for the public interface of the board module.
 */

#ifndef BOARD_PRIVATE_H
#define BOARD_PRIVATE_H

#include "../src/types/board.h"

/**
 * @brief Concatenates a source string to a buffer.
 *
 * This function concatenates a null-terminated source string to the end of a
 * buffer.
 *
 * @param[in,out] buffer Pointer to a buffer where the source string will be
 *                       concatenated. The buffer should have enough space to
 *                       accommodate the concatenated string, including the
 *                       null-terminator.
 * @param[in] source Pointer to a null-terminated source string that will be
 *                   concatenated to the buffer.
 *
 * @return void.
 *
 * @note The buffer should have enough space to accommodate the concatenated
 *       string, including the null-terminator. Otherwise, buffer overflow may
 *       occur.
 * @pre The buffer and source pointers should be valid pointers and should not
 *      be `NULL`.
 * @post The source string will be concatenated to the end of the buffer.
 * @attention This function does not perform any size checking or memory
 *            allocation. It is the responsibility of the caller to ensure that
 *            the buffer has enough space for the concatenated string.
 *
 * @see `snprintf()` for string formatting.
 */
static void concat(char *buffer, const char *source);

/**
 * @brief Concatenates a source string to a buffer 'n' times.
 *
 * This function concatenates a null-terminated source string to the end of a
 * buffer 'n' times.
 *
 * @param[in,out] buffer Pointer to a buffer where the source string will be
 *                       concatenated. The buffer should have enough space to
 *                       accommodate the concatenated strings, including the
 *                       null-terminators.
 * @param[in] source Pointer to a null-terminated source string that will be
 *                   concatenated to the buffer.
 * @param[in] n_times Number of times the source string will be concatenated to
 *                    the buffer.
 *
 * @return void.
 *
 * @note The buffer should have enough space to accommodate the concatenated
 *       strings, including the null-terminators. Otherwise, buffer overflow
 *       may occur.
 * @pre The buffer and source pointers should be valid pointers and should not
 *      be NULL.
 * @post The source string will be concatenated to the end of the buffer 'n'
 *       times.
 * @attention This function does not perform any size checking or memory
 *            allocation. It is the responsibility of the caller to ensure that
 *            the buffer has enough space for the concatenated strings.
 *
 * @see snprintf() for string formatting.
 */
static void nconcat(char *buffer, const char *source, const int n_times);

/**
 * @brief Formats and concatenates a variable argument list to a buffer.
 *
 * This function formats and concatenates a variable argument list to the end of
 * a buffer using a format string and a list of arguments.
 *
 * @param[in,out] buffer Pointer to a buffer where the formatted string will be
 *                       concatenated. The buffer should have enough space to
 *                       accommodate the formatted string, including the
 *                       null-terminator.
 * @param[in] source_size Size of the buffer, in bytes, excluding the null-
 *                        terminator.
 * @param[in] format Format string used to specify the desired format for the
 *                   output. This is similar to the format string used in
 *                   functions like `printf()` and `sprintf()`.
 * @param[in] ... Variable argument list containing the values to be formatted
 *                and concatenated to the buffer, based on the format string.
 *
 * @return void.
 *
 * @note The buffer should have enough space to accommodate the formatted
 *       string, including the null-terminator. Otherwise, buffer overflow may
 *       occur.
 * @pre The buffer and format pointers should be valid pointers and should not
 *      be `NULL`.
 * @post The formatted string will be concatenated to the end of the buffer.
 * @attention This function does not perform any size checking or memory
 *            allocation. It is the responsibility of the caller to ensure that
 *            the buffer has enough space for the formatted string.
 *
 * @see vsnprintf() for string formatting with a variable argument list.
 */
static void fconcat(char *buffer, const int source_size, const char *format,
                    ...);

/**
 * @brief Allocates memory for a character buffer with null-termination.
 *
 * This function dynamically allocates memory for a character buffer with
 * null-termination. The size of the buffer is determined by the given size
 * parameter and the length of the input character c. The resulting buffer will
 * be null-terminated.
 *
 * @param[in] s Pointer to a null-terminated string containing the character to
 *              be allocated.
 * @param[in] size The size of the buffer to be allocated, excluding the null-
 *                 terminator.
 *
 * @return Pointer to the dynamically allocated character buffer. The buffer is
 *         null-terminated and should be freed by the caller using `free()`
 *         function when no longer needed.
 *
 * @note The caller is responsible for freeing the memory allocated by this
 *       function using `free()` when it is no longer needed to avoid memory
 *       leaks.
 * @warning The resulting buffer will be null-terminated. However, it is the
 *          responsibility of the caller to ensure that the input character c
 *          is a null-terminated string, and the size parameter is valid to
 *          prevent buffer overflow.
 * @pre The input character c should be a valid null-terminated string, and the
 *      size parameter should be greater than or equal to zero.
 * @post Memory will be allocated for the character buffer with
 *       null-termination.
 * @attention The size of the allocated buffer is determined by the size
 *            parameter multiplied by the length of the input character c. It
 *            is important to ensure that the resulting buffer is not too
 *            large to prevent memory overflow.
 *
 * @see `malloc()` for memory allocation.
 * @see `free()` for deallocating memory.
 */
static char *alloc_char(const char *s, const int size);

/**
 * @brief Allocates memory for a character buffer with null-termination.
 *
 * This function dynamically allocates memory for a character buffer with
 * null-termination. The size of the buffer is determined by the given size
 * parameter and the length of the input character s. The resulting buffer will
 * be null-terminated.
 *
 * @param[in] s Pointer to a null-terminated string containing the character to
 *              be allocated.
 * @param[in] size The size of the buffer to be allocated, excluding the null-
 *                 terminator.
 *
 * @return Pointer to the dynamically allocated character buffer. The buffer is
 *         null-terminated and should be freed by the caller using `free()`
 *         function when no longer needed.
 *
 * @note The caller is responsible for freeing the memory allocated by this
 *       function using `free()` when it is no longer needed to avoid memory
 *       leaks.
 * @warning The resulting buffer will be null-terminated. However, it is the
 *          responsibility of the caller to ensure that the input character s
 *          is a null-terminated string, and the size parameter is valid to
 *          prevent buffer overflow.
 * @pre The input character s should be a valid null-terminated string, and the
 *      size parameter should be greater than or equal to zero.
 * @post Memory will be allocated for the character buffer with
 *       null-termination.
 * @attention The size of the allocated buffer is determined by the size
 *             parameter multiplied by the length of the input string `s`. It
 *             is important to ensure that the resulting buffer is not too
 *             large to prevent memory overflow.
 *
 * @see `malloc()` for memory allocation.
 * @see `free()` for deallocating memory.
 */
static char *alloc_char(const char *s, const int size);

/**
 * @brief Build a border for a board game.
 *
 * This function builds a border for a board game by concatenating the
 * appropriate border segments together based on the provided parameters.
 *
 * @param borders[in] An array of strings containing the segments needed to
 *                    create the border.
 *                     - `borders[0]`: sg. for the left side of the border.
 *                     - `borders[1]`: sg. for the right side of the border.
 *                     - `borders[2]`: sg. for the join between squares.
 *                     - `borders[3]`: sg. for the dash segment of the border.
 *                    where sg stands for Segment.
 * @param square_len[in] The length of each square in the board.
 * @param cols[in] The number of columns in the board.
 * @param rows[in] The number of rows in the board.
 * @param row[in] The current row for which the border is being built.
 * @param board[in] The board for which the border is being built.
 *
 * @return A dynamically allocated character buffer containing the built border.
 *         The caller is responsible for freeing the allocated memory.
 *
 * @note The caller should ensure that the `borders` array contains valid string
 *       segments and that the length of the `borders` array is 4.
 * @note The caller should also ensure that the `square_len`, `cols`, and `rows`
 *       parameters are valid values that represent the dimensions of the board.
 * @note The returned character buffer contains the built border and is
 *       null-terminated.
 * @note The function uses the `alloc_char()` function for memory allocation,
 *       which allocates memory for a character buffer. The caller is
 *       responsible for freeing the memory allocated by `alloc_char`.
 */
static char *build_border(const char *borders[4], const int square_len,
                          const int cols, const int rows, const int row,
                          const Board board);

/**
 * @brief Convert a square value to a string representation.
 *
 * This function takes an integer square value and converts it into a string
 * representation using a specific format for certain special square values.
 *
 * @param square The integer value of the square to be converted.
 *
 * @return A dynamically allocated character buffer containing the string
 *         representation of the square value. The caller is responsible for
 *         freeing the allocated memory.
 *
 * @note The caller should ensure that the `square` parameter is a valid integer
 *       value.
 * @note The returned character buffer contains the string representation of the
 *       square value and is null-terminated.
 * @note The function uses the `alloc_char()` function for memory allocation,
 *       which allocates memory for a character buffer. The caller is
 *       responsible for freeing the memory allocated by `alloc_char()`.
 * @note The function uses the `snprintf()` function to safely format the string
 *       representation of the square value and store it in the character
 *       buffer. The caller should ensure that the `buffer` parameter passed to
 *       `snprintf()` has enough space to hold the formatted string.
 * @note The function uses specific string representations for certain special
 *       square values, such as:
 *       - "X2" for `GOOSE_VALUE`;
 *       - "BR" for `BRIDGE_VALUE`;
 *       - "IN" for `INN_VALUE`;
 *       - "WE" for `WELL_VALUE`;
 *       - "LA" for `LABYRINTH_VALUE`;
 *       - "PR" for `PRISON_VALUE`;
 *       - "SK" for `SKELETON_VALUE`.
 */
static char *square_to_str(const int square);

/**
 * @brief Builds a row of squares for a game board.
 *
 * This function builds a row of squares for a game board, including the
 * separators, spacing, and square values, and stores the result in a buffer.
 * The resulting string can be used to print a row of the game board.
 *
 * @param[in] vert The string representing the vertical separator between
 *                 squares.
 * @param[in] square_len The length of each square.
 * @param[in] cols The number of columns on the game board.
 * @param[in] rows The number of rows on the game board.
 * @param[in] row The current row being built.
 * @param[in] board The game board.
 *
 * @return A dynamically allocated string containing the built row of squares.
 *         The caller is responsible for freeing the memory when it is no longer
 *         needed.
 *
 * @note The returned string must be freed using the appropriate memory
 *       deallocation function (e.g., 'free()`) when it is no longer needed to
 *       avoid memory leaks.
 */
static char *build_squares(const char *vert, const int square_len,
                           const int cols, const int rows, const int row,
                           const Board board);

/**
 * @brief Builds a game board with borders using provided characters.
 *
 * This function builds a game board with borders using the provided characters
 * for each border type. It calculates the number of rows needed for the game
 * board based on the number of columns and the size of the squares. It then
 * allocates memory for the resulting game board string and populates it with
 * the appropriate characters for each border type and the squares of the game
 * board.
 *
 * @param board The game board to be built.
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
 *
 * @return A dynamically allocated string containing the built game board with
 *         borders. The caller is responsible for freeing the memory when it is
 *         no longer needed.
 *
 * @note The returned string must be freed using the appropriate memory
 *       deallocation function (e.g., `free()`) when it is no longer needed to
 *       avoid memory leaks.
 */
static char *build_board(const Board board, const int cols,
                         const int square_len, const char *borders[8]);

#endif  // !BOARD_PRIVATE_H
