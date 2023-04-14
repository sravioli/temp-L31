// Copyright (c) 2023 Simone Fidanza. GNU-GPLv3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/globals.h"
#include "../src/types/board.h"

void concat(char *destination, const char *source);
void nconcat(char *destination, const char *source, const int n_times);

char *nalloc_char(const char *c, const int n_times);
char *nbuild_char(const char *c, const int n_times);

char *alloc_segment(const char *c, const char *ndash, const int square_len);
char *build_segment(const char *c, const char *ndash, const int square_len);

char *alloc_border(const char *segment, const int square_len, const int cols);
char *build_border(const char *segments[4], const int square_len,
                   const int cols, const int rows, const int curr_row,
                   const int board_dim);

void print_board(const Board board, const int cols, const int square_len,
                 const char *border[8]);

void fill_board(Board *board, const int dim);

int main() {
  const char *ascii_borders[8] = {"+", "+", "+", "+", "+", "+", "-", "|"};
  const char *squar_borders[8] = {"┌", "┐", "└", "┘", "┬", "┴", "─", "│"};
  const char *round_borders[8] = {"╭", "╮", "╰", "╯", "┬", "┴", "─", "│"};
  const char *doubl_borders[8] = {"╔", "╗", "╚", "╝", "╦", "╩", "═", "║"};
  const char *lettr_borders[8] = {"p", "q", "b", "d", "v", "^", "-", "|"};

  const int cols = 15;
  const int square_len = 7;

  Board board;
  fill_board(&board, 50);
  print_board(board, cols, square_len, ascii_borders);
  printf("\n");

  Board board1;
  fill_board(&board1, 55);
  print_board(board1, cols, square_len, squar_borders);
  printf("\n");

  Board board2;
  fill_board(&board2, 65);
  print_board(board2, cols, square_len, round_borders);
  printf("\n");

  Board board3;
  fill_board(&board3, 75);
  print_board(board3, cols, square_len, doubl_borders);
  printf("\n");

  Board board4;
  fill_board(&board4, 90);
  print_board(board4, cols, square_len, lettr_borders);
  printf("\n");

  return 0;
}

void concat(char *destination, const char *source) {
  int destination_length = strlen(destination);
  int source_length = strlen(source);
  snprintf(destination + destination_length, source_length + 1, "%s", source);
}

void nconcat(char *destination, const char *source, const int n_times) {
  int destination_length = strlen(destination);
  int source_length = strlen(source);

  int i = 0;
  while (i < n_times) {
    snprintf(destination + destination_length, source_length + 1, "%s", source);
    destination_length += source_length;
    i = i + 1;
  }
}

char *nalloc_char(const char *c, const int n_times) {
  // compute the needed size for the resulting stirng
  int nc_size = n_times * strlen(c) + 1;

  // allocate and check for NULL
  char *nc = (char *)malloc(nc_size * sizeof(char));
  if (nc == NULL) {
    printf("failed to allocate memory for string repetition\n");
    exit(EXIT_FAILURE);
  }
  memset(nc, STR_END, strlen(nc));  // ensure null termination

  return nc;
}

char *nbuild_char(const char *c, const int n_times) {
  char *nc = nalloc_char(c, n_times);
  nconcat(nc, c, n_times);
  return nc;
}

char *alloc_segment(const char *c, const char *ndash, const int square_len) {
  // compute the needed size for the resulting string
  int segment_size = square_len * (strlen(c) + 1);

  // allocate and check for NULL
  char *section = (char *)malloc(segment_size * sizeof(char));
  if (section == NULL) {
    printf("failed to allocate memory for string for border segment\n");
    exit(EXIT_FAILURE);
  }
  memset(section, STR_END, strlen(section));

  return section;
}

char *build_segment(const char *c, const char *ndash, const int square_len) {
  char *segment = alloc_segment(c, ndash, square_len);
  concat(segment, c);
  concat(segment, ndash);

  return segment;
}

char *alloc_border(const char *segment, const int square_len, const int cols) {
  int segment_size = 1 + strlen(segment) / square_len;
  int border_size = 1 + segment_size * square_len * cols;
  char *border = (char *)malloc(border_size * sizeof(char));
  if (border == NULL) {
    printf("failed to allocate memory for border\n");
    exit(EXIT_FAILURE);
  }
  memset(border, STR_END, strlen(border));

  return border;
}

char *build_border(const char *segments[4], const int square_len,
                   const int cols, const int rows, const int row,
                   const int board_dim) {
  // segments contains the four segments needed to create a border:
  // west_segment, east_segment, join_segment, empty_segment

  char *border = alloc_border(segments[0], square_len - 1, cols);

  int col = 0;
  while (col < cols) {
    if (row % 2 == 0) {
      int pos = row * cols + col;
      int is_last_of_row =
          ((col == cols - 1) && (row != rows - 1)) || (pos == board_dim - 1);

      if (col == 0) {                    // 1st box of the row
        concat(border, segments[0]);
      } else if (is_last_of_row) {       // last box of the row
        concat(border, segments[1]);
      } else if (pos < board_dim - 1) {  // between 1st & last
        concat(border, segments[2]);
      } else {                           // when traveling RtL
        concat(border, segments[3]);
      }
    } else {
      // it it's odd we're traveling RtL (<-)
      int pos = (row + 1) * cols - col - 1;
      int is_fist = (col == 0) && (row != rows - 1);

      if (is_fist) {                      // 1st box of the row
        concat(border, segments[0]);
      } else if (col == cols - 1) {       // last box of the row
        concat(border, segments[1]);
      } else if (pos < board_dim - 1) {   // between 1st & last
        concat(border, segments[2]);
      } else if (pos == board_dim - 1) {  // last board box
        concat(border, segments[0]);
      } else {                            // when traveling LtR
        concat(border, segments[3]);
      }
    }
    col = col + 1;
  }
  return border;
}

void print_board(const Board board, const int cols, const int square_len,
                 const char *borders[8]) {
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

  int board_dim = get_dim(&board);
  int rows = (board_dim + cols - 1) / cols;  // calculate rows needed

  // concatenate together the chars that always repeat at the same rate to
  // avoid useless computation when concatenating the border
  char *ndash = nbuild_char(borders[6], square_len - 1);
  char *nempty = nbuild_char(" ", square_len);

  // create the other possibile segments for the border creation
  char *nw_segment = build_segment(borders[0], ndash, square_len);
  char *jd_segment = build_segment(borders[4], ndash, square_len);
  char *ne_segment = build_segment(borders[4], ndash, square_len);
  concat(ne_segment, borders[1]);
  const char *top_segments[4] = {nw_segment, ne_segment, jd_segment, nempty};

  char *sw_segment = build_segment(borders[2], ndash, square_len);
  char *ju_segment = build_segment(borders[5], ndash, square_len);
  char *se_segment = build_segment(borders[5], ndash, square_len);
  concat(se_segment, borders[3]);
  const char *bot_segments[4] = {sw_segment, se_segment, ju_segment, nempty};

  // TODO(sRavioli): next step is to build the board, then print it.

  int row = 0;
  while (row < rows) {
    char *top_border =
        build_border(top_segments, square_len, cols, rows, row, board_dim);
    printf("%s\n", top_border);

    int col = 0;
    while (col < cols) {
      int pos = row * cols + col;
      int square = get_square(&board, pos);
      if (row % 2 == 0) {
        if ((col == cols - 1) && (row != rows - 1)) {
          printf("%s  %2d  %s", borders[7], square, borders[7]);
        } else if (pos < board_dim) {
          printf("%s  %2d  ", borders[7], square);
        } else if (pos == board_dim) {
          printf("%s      ", borders[7]);
        } else {
          printf("       ");
        }
      } else {
        int pos = (row + 1) * cols - col - 1;
        int square = get_square(&board, pos);
        if (col == cols - 1) {
          printf("%s  %2d  %s", borders[7], square, borders[7]);
        } else if (pos < board_dim) {
          printf("%s  %2d  ", borders[7], square);
        } else {
          printf("       ");
        }
      }
      col = col + 1;
    }
    printf("\n");

    char *bot_border =
        build_border(bot_segments, square_len, cols, rows, row, board_dim);
    printf("%s\n", bot_border);

    row = row + 1;
  }
}

void fill_board(Board *board, const int dim) {
  set_dim(board, dim);

  for (int i = 0; i < dim; i++) {
    set_square(board, i, i + 1);
  }
}
