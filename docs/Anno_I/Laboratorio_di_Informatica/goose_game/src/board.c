// Copyright (c) 2023 {Simone Fidanza, ...} – GNU GPLv3

#include "./types/Board.h"
#include "./globals.h"
#include <stdio.h>
#include <stdlib.h>

int get_num_squares();
void insert_goose_squares(Board *board);
void insert_special_squares(Board *board);
int proportion(const Board *board, int special_square);
int my_floor(float float_num);
int is_goose_square(const Board *board, int position);
int check_special_square(const Board *board, int special_position);
void print_board(const Board *board);
void pprint_square(const int square, const char *color, int align, int space);
void print_square(const char *text, int twidth, int lspace, int rspace);
void pprint_text(const char *text, const char *color, int align, int space);

int main() {
  // Variable declaration
  int num_squares;
  Board board;

  for (int i; i < MAX_NUM_SQUARES; i++) {
    set_square(&board, i, i + 1);
  }

  // Get number of squares from user
  num_squares = get_num_squares();

  // Set board dimension
  set_dim(&board, num_squares);

  // Insert goose squares
  insert_goose_squares(&board);

  // Insert special squares
  insert_special_squares(&board);

  // Print board
  print_board(&board);

  return 0;
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
  if (is_goose_square(board, special_position)) {
    allowed_special_pos = allowed_special_pos + 1;
  }
  return allowed_special_pos;
}

void print_board(const Board *board) {
  int i = 0;
  int counter = 0;
  printf("|");
  while (i < get_dim(board)) {
    int square_j = get_square(board, i);
    if (square_j == 1) {
      pprint_square(square_j, "", 2, 3);
    } else if (square_j == GOOSE_VALUE) {
      pprint_text("x2", "30;44", 2, 3);
    } else if (square_j == BRIDGE_VALUE) {
      pprint_text("BR", "30;48;2;183;65;14", 2, 3);
    } else if (square_j == INN_VALUE) {
      pprint_text("IN", "30;48;2;242;142;28", 2, 3);
    } else if (square_j == WELL_VALUE) {
      pprint_text("WE", "30;48;2;120;115;102", 2, 3);
    } else if (square_j == LABYRINTH_VALUE) {
      pprint_text("LA", "30;48;2;34;139;34", 2, 3);
    } else if (square_j == PRISON_VALUE) {
      pprint_text("PR", "37;48;2;10;10;10", 2, 3);
    } else if (square_j == SKELETON_VALUE) {
      pprint_text("SK", "38;2;26;26;26;48;2;227;218;201", 2, 3);
    } else {
      if (square_j != get_dim(board)) {
        pprint_square(square_j, "", 2, 3);
      } else {
        pprint_square(square_j, "30;42", 2, 3);
      }
    }
    counter = counter + 1;
    if (counter == 10 && square_j < get_dim(board)) {
      printf("%c|", LINE_END);
      counter = 0;
    }
    i = i + 1;
  }
}

void pprint_square(const int square, const char *color, int align, int space) {
  printf("\x1b[%sm", color);
  printf("%*s", space, "");
  printf("%*d", align, square);
  printf("%*s", space, "");
  printf("%s", "\x1b[0m|");
}

void pprint_text(const char *text, const char *color, int align, int space) {
  printf("\x1b[%sm", color);
  printf("%*s", space, "");
  printf("%*s", align, text);
  printf("%*s", space, "");
  printf("%s", "\x1b[0m|");
}
