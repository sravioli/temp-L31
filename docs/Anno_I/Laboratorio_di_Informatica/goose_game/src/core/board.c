// Copyright (c) 2023 @authors. GNU GPLv3
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/inc/string.h"
#include "../common/inc/term.h"
#include "../inc/board.h"
#include "../inc/globals.h"

int proportion(const Board *board, int special_square) {
  return ((special_square * get_dim(board)) / MAX_NUM_SQUARES);
}

int is_goose_square(const Board *board, int position) {
  int val;
  if (get_square(board, position) == GOOSE_VALUE) {
    val = 1;
  } else {
    val = 0;
  }
  return val;
}

int check_special_square(const Board *board, int special_position) {
  int allowed_special_pos = special_position;
  if (get_square(board, special_position) == GOOSE_VALUE) {
    allowed_special_pos = allowed_special_pos + 1;
  }
  return allowed_special_pos;
}

void insert_goose_squares(Board *board) {
  int i = GOOSE_SPACING - 1;
  while (i < get_dim(board) - 1) {
    set_square(board, i, GOOSE_VALUE);
    i = i + GOOSE_SPACING;
  }
}

void insert_special_squares(Board *board) {
  int special_positions[] = {BRIDGE_SQUARE,    INN_SQUARE,    WELL_SQUARE,
                             LABYRINTH_SQUARE, PRISON_SQUARE, SKELETON_SQUARE};
  int special_values[] = {BRIDGE_VALUE,    INN_VALUE,    WELL_VALUE,
                          LABYRINTH_VALUE, PRISON_VALUE, SKELETON_VALUE};
  int num_special_squares =
      sizeof(special_positions) / sizeof(special_positions[0]);

  int i = 0;
  while (i < num_special_squares) {
    // subtract one to match with the actual board value since it starts
    // counting from 0
    int special_position = proportion(board, special_positions[i]) - 1;
    special_position = check_special_square(board, special_position);
    set_square(board, special_position, special_values[i]);
    i = i + 1;
  }
}

char *build_border(const char *borders[4], const int square_len, const int cols,
                   const int rows, const int row, const Board board) {
  /* segments contains the four segments needed to create a border:
   * - west  0;
   * - east  1;
   * - join  2;
   * - dash  3.
   */
  char *buffer = alloc_char(borders[0], cols * square_len);
  char *ndash = alloc_char(borders[3], square_len - 1);
  nconcat(ndash, borders[3], square_len - 1);

  const int square_size = 1 + square_len * strlen(borders[0]);
  const int board_dim = get_dim(&board);

  int col = 0;
  while (col < cols) {
    if (row % 2 == 0) {
      int pos = row * cols + col;
      int is_last_of_row =
          ((col == cols - 1) && (row != rows - 1)) || (pos == board_dim - 1);

      if (col == 0) {                    // 1st sq of the row
        fconcat(buffer, square_size, "%s%s", borders[0], ndash);
      } else if (is_last_of_row) {       // last sq of the row
        fconcat(buffer, square_size, "%s%s", borders[2], ndash);
        concat(buffer, borders[1]);
      } else if (pos < board_dim - 1) {  // between 1st & last
        fconcat(buffer, square_size, "%s%s", borders[2], ndash);
      } else {                           // when traveling RtL
        fconcat(buffer, square_size, "%*s", square_len, "");
      }
    } else {
      int pos = (row + 1) * cols - col - 1;
      int is_fist = (col == 0) && (row != rows - 1);

      if (is_fist || pos == board_dim - 1) {  // 1st sq of the row and last sq
        fconcat(buffer, square_size, "%s%s", borders[0], ndash);
      } else if (col == cols - 1) {           // last sq of the row
        fconcat(buffer, square_size, "%s%s", borders[2], ndash);
        concat(buffer, borders[1]);
      } else if (pos < board_dim - 1) {       // between 1st & last
        fconcat(buffer, square_size, "%s%s", borders[2], ndash);
      } else {                                // when traveling LtR
        fconcat(buffer, square_size, "%*s", square_len, "");
      }
    }
    col = col + 1;
  }
  // add line end char since nothing should be present on the same line
  concat(buffer, LINE_END);

  return buffer;
}

char *square_to_str(const int square) {
  char *buffer = alloc_char("cc", sizeof(square));
  if (square == GOOSE_VALUE) {
    snprintf(buffer, sizeof(buffer), "%2s", "X2");
  } else if (square == BRIDGE_VALUE) {
    snprintf(buffer, sizeof(buffer), "%2s", "BR");
  } else if (square == INN_VALUE) {
    snprintf(buffer, sizeof(buffer), "%2s", "IN");
  } else if (square == WELL_VALUE) {
    snprintf(buffer, sizeof(buffer), "%2s", "WE");
  } else if (square == LABYRINTH_VALUE) {
    snprintf(buffer, sizeof(buffer), "%2s", "LA");
  } else if (square == PRISON_VALUE) {
    snprintf(buffer, sizeof(buffer), "%2s", "PR");
  } else if (square == SKELETON_VALUE) {
    snprintf(buffer, sizeof(buffer), "%2s", "SK");
  } else {
    snprintf(buffer, sizeof(buffer), "%2d", square);
  }

  return buffer;
}

char *build_squares(const char *vert, const int square_len, const int cols,
                    const int rows, const int row, const Board board) {
  char *buffer = alloc_char(vert, cols * square_len);

  const int square_size = 1 + square_len * strlen(vert);
  const int board_dim = get_dim(&board);
  const int lspacing = (square_len - 3) / 2;
  int rspacing;
  if (square_len % 2 != 0) {
    rspacing = lspacing;
  } else {
    rspacing = lspacing + 1;
  }

  int col = 0;
  while (col < cols) {
    if (row % 2 == 0) {
      int pos = row * cols + col;
      int square = get_square(&board, pos);
      char *sq = square_to_str(square);

      int is_fist = (col == cols - 1) && (row != rows - 1);
      int is_last = (pos == board_dim - 1) && (row == rows - 1);
      if (is_fist || is_last) {
        fconcat(buffer, square_size, "%s%*s%2s%*s%s", vert, lspacing, "", sq,
                rspacing, "", vert);
      } else if (pos < board_dim) {
        fconcat(buffer, square_size, "%s%*s%2s%*s", vert, lspacing, "", sq,
                rspacing, "");
      } else {
        fconcat(buffer, square_size, "%*s", square_len, "");
      }
    } else {
      int pos = (row + 1) * cols - col - 1;
      int square = get_square(&board, pos);
      char *sq = square_to_str(square);

      if (col == cols - 1) {
        fconcat(buffer, square_size, "%s%*s%2s%*s%s", vert, lspacing, "", sq,
                rspacing, "", vert);
      } else if (pos < board_dim) {
        fconcat(buffer, square_size, "%s%*s%2s%*s", vert, lspacing, "", sq,
                rspacing, "");
      } else {
        fconcat(buffer, square_size, "%*s", square_len, "");
      }
    }
    col = col + 1;
  }
  // add line end char since nothing should be present on the same line
  concat(buffer, LINE_END);

  return buffer;
}

char *build_board(const Board board, const int cols, const int square_len,
                  const char *borders[8]) {
  /* border chars will be in the following order:
   * - nw_corner  0  (ex. "┌");
   * - ne_corner  1  (ex. "┐");
   * - sw_corner  2  (ex. "└");
   * - se_corner  3  (ex. "┘");
   * - join_down  4  (ex. "┬");
   * - join_up    5  (ex. "┴");
   * - dash       6  (ex. "─");
   * - vert       7  (ex. "│").
   */
  int rows = (get_dim(&board) + cols - 1) / cols;  // calculate rows needed

  char *game_board = alloc_char(borders[0], 3 * rows * cols * square_len);
  const char *top_borders[4] = {borders[0], borders[1], borders[4], borders[6]};
  const char *bot_borders[4] = {borders[2], borders[3], borders[5], borders[6]};
  const char *vert = borders[7];

  int row = 0;
  while (row < rows) {
    char *top = build_border(top_borders, square_len, cols, rows, row, board);
    char *squares = build_squares(vert, square_len, cols, rows, row, board);
    char *bot = build_border(bot_borders, square_len, cols, rows, row, board);

    const int source_size = 1 + strlen(top) + strlen(squares) + strlen(bot);
    fconcat(game_board, source_size, "%s%s%s", top, squares, bot);

    free(top);
    free(squares);
    free(bot);

    row = row + 1;
  }

  return game_board;
}

int get_num_squares() {
  // get number of squares from user
  int num_squares;
  printf("Insert the number of squares [%d, %d]: ", MIN_NUM_SQUARES,
         MAX_NUM_SQUARES);
  scanf_s("%d", &num_squares, sizeof(num_squares));

  // validate input
  while (num_squares < MIN_NUM_SQUARES || num_squares > MAX_NUM_SQUARES) {
    printf("The number entered is not valid. Insert the number of squares [%d, "
           "%d]: ",
           MIN_NUM_SQUARES, MAX_NUM_SQUARES);
    scanf_s("%d", &num_squares, sizeof(num_squares));
  }
  return num_squares;
}

Board create_board(const int dimension) {
  Board board;
  set_dim(&board, dimension);

  int i = 0;
  while (i < dimension) {
    set_square(&board, i, i + 1);
    i = i + 1;
  }

  insert_goose_squares(&board);
  insert_special_squares(&board);

  return board;
}

void print_board(const Board board, const int cols, const int square_len,
                 const char *borders[8]) {
  char *game_board = build_board(board, cols, square_len, borders);
  printf("%s", game_board);
  free(game_board);
}
