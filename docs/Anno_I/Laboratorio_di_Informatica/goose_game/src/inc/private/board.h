/**
 * @file board.private.h
 *
 * @brief Private header file for board module.
 *
 * This is a private header file that contains declarations for internal
 * functions used within the board module. These functions are not intended for
 * external use and should not be called directly by external code.
 *
 * @warning This file should not be included or used directly by external
 *          code. It is for internal use within the board module only.
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 * @date 2023-04-18 09:46
 * @version 2.0
 * @copyright GNU GPLv3
 *
 * @see "board.h" for the public interface of the board module.
 */

#ifndef BOARD_PRIVATE_H
#define BOARD_PRIVATE_H

#include "../board_type.h"

/**
 * @brief Calculate the proportional position of a special square on the board.
 *
 * This function calculates the proportional position of a special square on the
 * board based on the given special square index and the dimension of the board.
 * The calculation is done using the formula:
 *     proportion = (special_square * board_dimension) / MAX_NUM_SQUARES
 *
 * @param[in] board Pointer to the Board structure.
 * @param[in] special_square Index of the special square.
 *
 * @return The proportional position of the special square on the board.
 *
 * @note The special_square parameter is expected to be in the range
 *       [0, MAX_NUM_SQUARES-1].
 */
int proportion(const Board *board, int special_square);

/**
 * @brief Check if a position on the board is a goose square.
 *
 * This function checks if the value of the square at the given position on the
 * board is equal to the predefined value for a goose square.
 *
 * @param[in] board Pointer to the Board structure.
 * @param[in] position Index of the position to check.
 *
 * @return 1 if the square at the given position is a goose square, 0 otherwise.
 *
 * @note The position parameter is expected to be a valid index in the range
 *       [0, MAX_NUM_SQUARES-1].
 */
int is_goose_square(const Board *board, int position);

/**
 * @brief Check if a position on the board is a special square and adjust if
 *        necessary.
 *
 * This function checks if the value of the square at the given position on the
 * board is a goose square, and if so, adjusts the special position by
 * incrementing it by 1.
 *
 * @param[in] board Pointer to the Board structure.
 * @param[in] special_position Index of the special position to check.
 *
 * @return The adjusted special position, taking into account if the square is a
 * goose square.
 *
 * @note The special_position parameter is expected to be a valid index in the
 *       range [0, MAX_NUM_SQUARES-1].
 */
int check_special_square(const Board *board, int special_position);

/**
 * @brief Inserts goose squares into the Board at regular intervals, following
 * the specified GOOSE_SPACING.
 *
 * @param[in,out] board Pointer to the Board where goose squares are to be
 * inserted.
 *
 * @note The Board parameter must be properly initialized and contain valid
 *       data.
 * @note The function iterates over the squares in the Board, starting from the
 *       GOOSE_SPACING-th square and inserts the GOOSE_VALUE at regular
 *       intervals with a spacing of GOOSE_SPACING.
 * @note The function modifies the Board in place by setting the GOOSE_VALUE at
 *       the appropriate squares.
 */
void insert_goose_squares(Board *board);

/**
 * @brief Inserts special squares into the Board at predefined positions with
 *        corresponding special values.
 *
 * @param[in,out] board Pointer to the Board where special squares are to be
 *                      inserted.
 *
 * @note The Board parameter must be properly initialized and contain valid
 *       data.
 * @note The function iterates over the predefined special positions and inserts
 *       the corresponding special values into the Board.
 * @note The function modifies the Board in place by setting the special values
 *       at the appropriate squares.
 * @note The special_positions and special_values arrays must have the same
 *       number of elements and the corresponding elements must be correctly
 *       defined before calling this function.
 */
void insert_special_squares(Board *board);

/**
 * @brief Build a border for a square board based on given border segments.
 *
 * This function dynamically allocates memory for a character string that
 * represents a border for a square board, based on given border segments. The
 * border is constructed for a specific row of the board, taking into account
 * the square length, number of columns, number of rows, and the current row
 * being processed.
 *
 * @param[in] borders Array of pointers to border segments for the top, right,
 *                    bottom, and left borders, respectively.
 * @param[in] square_len Length of each square in the board.
 * @param[in] cols Number of columns in the board.
 * @param[in] rows Number of rows in the board.
 * @param[in] row Current row for which the border is being constructed.
 * @param[in] board The board for which the border is being constructed.
 *
 * @return Pointer to the dynamically allocated memory containing the
 *         constructed border.
 *
 * @note The input border segments in the borders array should be valid
 *       null-terminated strings.
 * @note The returned pointer points to the dynamically allocated memory and
 *       should be freed by the caller when no longer needed to avoid memory
 * leaks.
 */
char *build_border(const char *borders[4], const int square_len, const int cols,
                   const int rows, const int row, const Board board);

/**
 * @brief Convert an integer value representing a square to a string
 *        representation.
 *
 * This function takes an integer value representing a square and converts it to
 * a string representation using predefined string values for specific square
 * values. It allocates memory for the resulting string using `alloc_char`
 * function.
 *
 * @param[in] square Integer value representing the square.
 *
 * @return A pointer to a dynamically allocated string representing the square.
 *         The caller is responsible for freeing the memory using appropriate
 *         means, such as `free()`.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       returned string.
 * @warning The `buffer` pointer returned by this function is dynamically
 *          allocated and should not be accessed after it has been freed.
 */
char *square_to_str(const int square);

/**
 * @brief Build a row of square representations as a string for a given row on
 * the game board.
 *
 * This function takes a row number and constructs a string representation of
 * the squares in that row on the game board, using the provided parameters for
 * formatting. It allocates memory for the resulting string using the
 * `alloc_char` function.
 *
 * @param[in] vert String representation of the vertical separator between
 *                 squares.
 * @param[in] square_len Length of each square representation.
 * @param[in] cols Number of columns on the game board.
 * @param[in] rows Number of rows on the game board.
 * @param[in] row Row number for which the string representation is being built.
 * @param[in] board Game board object.
 *
 * @return A pointer to a dynamically allocated string representing the row of
 *         squares.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       returned string.
 * @warning The `buffer` pointer returned by this function is dynamically
 *          allocated and should not be accessed after it has been freed.
 */
char *build_squares(const char *vert, const int square_len, const int cols,
                    const int rows, const int row, const Board board);

#endif  // !BOARD_PRIVATE_H
