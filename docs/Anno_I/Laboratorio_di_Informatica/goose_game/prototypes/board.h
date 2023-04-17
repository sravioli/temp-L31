#ifndef BOARD_H
#define BOARD_H

#include "../src/types/board.h"

/**
 * @brief Prints the game board with borders using provided characters.
 *
 * This function prints the game board with borders using the provided
 * characters for each border type. It calls the `build_board()` function to
 * build the game board as a dynamically allocated string, then prints the
 * resulting string using `printf()` function. After printing, it frees the
 * memory allocated by `build_board()` function.
 *
 * @param board The game board to be printed.
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
 */
void print_board(const Board board, const int cols, const int square_len,
                 const char *borders[8]);

#endif  // !BOARD_H
