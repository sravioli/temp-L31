// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "../inc/handle_game.h"

#define FILLER_CHAR "*"

int ask_num_in_range(const int min, const int max, const char name[]) {
  int result;
  do {
    printf("Insert the number of %s [%d, %d]: ", name, min, max);
    scanf_s("%d", &result, sizeof(result));
    if ((result < min) || (result > max)) {
      printf("error: given number of %s is out of bounds. Try again.\n", name);
    }
  } while ((result < min) || (result > max));

  return result;
}

void conform_username(char *username) {
  str_truncate(username, MAX_USERNAME_LENGTH);
  str_to_uppercase(username);
  // nconcat(username, FILLER_CHAR, MAX_USERNAME_LENGTH - strlen(username));
  nconcat(username, &username[0], MAX_USERNAME_LENGTH - strlen(username));
}

int is_username_valid(const char username[]) {
  int i = 0;
  while (username[i]) {
    // scanf_s stops at first whitespace so no spaces in username
    if (ispunct(username[i]) || isdigit(username[i])) {
      return FALSE;
    }
    i = i + 1;
  }
  return TRUE;
}

char *ask_username() {
  // clear_line();
  char *username = malloc(sizeof(char));
  memset(username, STR_END, strlen(username));
  int valid = FALSE;
  while (!valid) {
    printf("Enter your username: ");
    scanf_s("%20s", username, MAX_NAME_LENGTH);

    if (is_username_valid(username)) {
      valid = TRUE;
    } else {
      printf("error: invalid username. Try again.\n");
    }
  }

  conform_username(username);
  return username;
}

int ask_player_action(void) {
  int choice;
  do {
    printf("What to do?\n[l]eave game(0)\n[t]hrow die(1)\n[s]ave game(2)\n");
    scanf_s("%i", &choice);
  } while ((choice < 0) || (choice > 2));
  return choice;
}

int check_square(const Board *board, int position) {
  if (get_square(board, position) == GOOSE_VALUE) {
    return position + 1;
  }
  return position;
}

void insert_goose_squares(Board *board) {
  int i = GOOSE_SPACING - 1;
  while (i < get_dim(board) - 1) {
    set_square(board, i, GOOSE_VALUE);
    i = i + GOOSE_SPACING;
  }
}

void insert_special_squares(Board *board) {
  int special_poss[] = {BRIDGE_SQUARE,    INN_SQUARE,    WELL_SQUARE,
                        LABYRINTH_SQUARE, PRISON_SQUARE, SKELETON_SQUARE};
  int special_vals[] = {BRIDGE_VALUE,    INN_VALUE,    WELL_VALUE,
                        LABYRINTH_VALUE, PRISON_VALUE, SKELETON_VALUE};
  int num_special_squares = sizeof(special_poss) / sizeof(special_poss[0]);

  int i = 0;
  while (i < num_special_squares) {
    int special_pos =
        proportion(get_dim(board), special_poss[i], MAX_NUM_SQUARES);
    special_pos = check_square(board, special_pos);
    set_square(board, special_pos, special_vals[i]);
    i = i + 1;
  }
}

Board *init_board(const int dim) {
  Board *board = (Board *)malloc(sizeof(Board));  // NOLINT
  set_dim(board, dim);

  int i = 0;
  while (i < dim) {
    set_square(board, i, i + 1);
    i = i + 1;
  }
  insert_goose_squares(board);
  insert_special_squares(board);
  return board;
}

void close_game(void *fst_ptr, ...) {
  void *ptr = fst_ptr;

  va_list args;
  va_start(args, fst_ptr);
  while (ptr) {
    free(ptr);
    ptr = va_arg(args, void *);
  }
  va_end(args);
}
