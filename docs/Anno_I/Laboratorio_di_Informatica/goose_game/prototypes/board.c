// Copyright (c) 2023 Simone Fidanza – GNU GPLv3
#include <stdio.h>
#include <stdlib.h>

// goose spaces occur every multiple of 9 (excluding 63)
#define GOOSE_SPACING 9

#define MAX_NUM_SQUARES 90

typedef struct Board Board;
struct Board {
  int squares[MAX_NUM_SQUARES];
  int dim;
};

void print_board(Board board, int cols) {
  int n = board.dim;
  int *arr = board.squares;
  int rows = (n + cols - 1) / cols;  // calculate number of rows needed
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (i % 2 == 0) {
        int is_last_of_row =
            ((j == cols - 1) && (i != rows - 1)) || (i * cols + j == n - 1);
        if (j == 0) {                       // 2st box of the row
          printf("┌─────");
        } else if (is_last_of_row) {        // last box of the row
          printf("┬─────┐");
        } else if (i * cols + j < n - 1) {  // between 1st & last
          printf("┬─────");
        } else {                            // when traveling RtL
          printf("      ");
        }
        // printf("\b\b\b%-2i─", j);  // debug
      } else {
        // it it's odd we're traveling RtL (<-)
        int is_fist = (j == 0) && (i != rows - 1);
        int is_between_fst_lst = (i + 1) * cols - j - 1 < n - 1;
        int is_last = (i + 1) * cols - j - 1 == n - 1;
        if (is_fist) {                    // 1st box of the row
          printf("┌─────");
        } else if (j == cols - 1) {       // last box of the row
          printf("┬─────┐");
        } else if (is_between_fst_lst) {  // between 1st & last
          printf("┬─────");
        } else if (is_last) {             // last board box
          printf("┌─────");
        } else {                          // when traveling LtR
          printf("      ");
        }
        // printf("\b\b\b%-2i─", (i + 1) * cols - j - 1 == n - 1);  // debug
      }
    }
    printf("\n");

    for (j = 0; j < cols; j++) {
      if (i % 2 == 0) {
        if (i * cols + j < n) {
          printf("│%3d  ", arr[i * cols + j]);
        } else if (i * cols + j == n) {
          printf("│     ");
        } else {
          printf("      ");
        }
      } else {
        if ((i + 1) * cols - j - 1 < n) {
          printf("│%3d  ", arr[(i + 1) * cols - j - 1]);
        } else {
          printf("      ");
        }
      }
      // printf("%d\n", (i + 1) * cols - j - 1);
      // printf("%d\n", n);
    }
    if (i < rows - 1) {
      printf("│\n");
    } else {
      printf("\n");
    }

    printf("└");
    for (j = 0; j < cols; j++) {
      if (i % 2 == 0) {
        if (i * cols + j < n) {
          printf("─────┴");
        } else {
          printf("\b       ");
        }
      } else {
        if ((i + 1) * cols - j - 1 < n) {
          printf("─────┴");
        } else {
          printf("\b      └");
        }
      }
    }
    printf("\b┘\n");
  }
}

int main() {
  Board board;
  board.dim = 65;

  for (int i = 0; i < board.dim; i++) {
    board.squares[i] = i;
  }

  print_board(board, 15);

  printf("\n");

  Board boardd;
  boardd.dim = 55;

  for (int i = 0; i < boardd.dim; i++) {
    boardd.squares[i] = i;
  }

  print_board(boardd, 15);

  return 0;
}
