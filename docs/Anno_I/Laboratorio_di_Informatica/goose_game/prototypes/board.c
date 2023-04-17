// Copyright (c) 2023 Simone Fidanza. GNU-GPLv3
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/globals.h"
#include "../src/types/board.h"
#include "./board.h"
#include "./board.private.h"

#define DEFAULT_COLS 15
#define DEFAULT_SQUARE_LENGTH 7

static void concat(char *buffer, const char *source);
static void nconcat(char *buffer, const char *source, const int n_times);
static void fconcat(char *buffer, const int source_size, const char *format,
                    ...);

static char *alloc_char(const char *s, const int size);

static char *build_border(const char *borders[4], const int square_len,
                          const int cols, const int rows, const int row,
                          const Board board);

static char *square_to_str(const int square);
static char *build_squares(const char *vert, const int square_len,
                           const int cols, const int rows, const int row,
                           const Board board);

static char *build_board(const Board board, const int cols,
                         const int square_len, const char *borders[8]);

void print_board(const Board board, const int cols, const int square_len,
                 const char *borders[8]);

void fill_board(Board *board, const int dim);

int main() {
  const char *squar_borders[8] = {"┌", "┐", "└", "┘", "┬", "┴", "─", "│"};
  const char *round_borders[8] = {"╭", "╮", "╰", "╯", "┬", "┴", "─", "│"};

  Board board;
  fill_board(&board, 65);
  print_board(board, 15, DEFAULT_SQUARE_LENGTH, round_borders);

  return 0;
}

static void concat(char *buffer, const char *source) {
  snprintf(buffer + strlen(buffer), strlen(source) + 1, "%s", source);
}

static void nconcat(char *buffer, const char *source, const int n_times) {
  int buffer_length = strlen(buffer);
  int i = 0;
  while (i < n_times) {
    snprintf(buffer + buffer_length, strlen(source) + 1, "%s", source);
    buffer_length = buffer_length + strlen(source);
    i = i + 1;
  }
}

static void fconcat(char *buffer, const int source_size, const char *format,
                    ...) {
  va_list args;
  va_start(args, format);
  vsnprintf(buffer + strlen(buffer), source_size, format, args);
  va_end(args);
}

static char *alloc_char(const char *s, const int size) {
  char *buffer = (char *)malloc(1 + size * strlen(s) * sizeof(s));  // NOLINT
  if (buffer == NULL) {
    printf("error: failed to allocate memory for string of size %i\n", size);
    exit(EXIT_FAILURE);
  }
  // ensure null termination of the string
  memset(buffer, STR_END, strlen(buffer));

  return buffer;
}

static char *build_border(const char *borders[4], const int square_len,
                          const int cols, const int rows, const int row,
                          const Board board) {
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
  concat(buffer, LINE_END);

  return buffer;
}

static char *square_to_str(const int square) {
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

static char *build_squares(const char *vert, const int square_len,
                           const int cols, const int rows, const int row,
                           const Board board) {
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
  concat(buffer, LINE_END);

  return buffer;
}

static char *build_board(const Board board, const int cols,
                         const int square_len, const char *borders[8]) {
  /* border chars will be in the following order:
   * - nw_corner  0  (ex. "┌");
   * - ne_corner  1  (ex. "┐");
   * - sw_corner  2  (ex. "└");
   * - se_corner  3  (ex. "┘");
   * - join_down  4  (ex. "┬");
   * - join_up    5  (ex. "┴");
   * - dash       6  (ex. "─");
   * - vert       7  (ex. "│");
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

void print_board(const Board board, const int cols, const int square_len,
                 const char *borders[8]) {
  char *game_board = build_board(board, cols, square_len, borders);
  printf("%s", game_board);
  free(game_board);
}

void fill_board(Board *board, const int dim) {
  set_dim(board, dim);

  int i = 0;
  while (i < dim) {
    set_square(board, i, i + 1);
    i = i + 1;
  }

  i = 0;
  while (i < dim) {
    int square = get_square(board, i);
    if (square == BRIDGE_SQUARE) {
      set_square(board, i, BRIDGE_VALUE);
    } else if (square == INN_SQUARE) {
      set_square(board, i, INN_VALUE);
    } else if (square == WELL_SQUARE) {
      set_square(board, i, WELL_VALUE);
    } else if (square == LABYRINTH_SQUARE) {
      set_square(board, i, LABYRINTH_VALUE);
    } else if (square == PRISON_SQUARE) {
      set_square(board, i, PRISON_VALUE);
    } else if (square == SKELETON_SQUARE) {
      set_square(board, i, SKELETON_VALUE);
    }
    i = i + 1;
  }

  i = GOOSE_SPACING - 1;
  while (i < get_dim(board) - 1) {
    set_square(board, i, GOOSE_VALUE);
    i = i + GOOSE_SPACING;
  }
}
