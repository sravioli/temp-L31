// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "../inc/handle_game.h"
#include <stdlib.h>

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

char *ask_username(int player_num) {
  char *username = (char *)malloc(sizeof(char));  // NOLINT
  memset(username, STR_END, strlen(username));
  int valid = FALSE;
  while (!valid) {
    printf("Player %i, enter your username: ", player_num);
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

Player *init_player(int player_num) {
  Player *p = (Player *)malloc(sizeof(Player));  // NOLINT
  char *username = ask_username(player_num);
  set_username(p, username);
  set_position(p, INITIAL_POSITION);
  set_score(p, INITIAL_SCORE);
  return p;
}

Players *init_players(const int num_players) {
  Players *ps = (Players *)malloc(sizeof(Players));  // NOLINT
  set_players_num(ps, num_players);
  set_turn(ps, INITIAL_TURN);

  int i = 0;
  while (i < num_players) {
    Player *p = init_player(i);
    set_player(ps, p, i);
    i = i + 1;
  }
  return ps;
}

void print_players(const Players *ps) {
  printf("USERNAMES:\n");
  for (int i = 0; i < get_players_num(ps); i++) {
    printf("ps->players[%i].username = %s\n", i + 1, ps->players[i].username);
  }
  printf("\n");

  printf("SCORES:\n");
  for (int i = 0; i < get_players_num(ps); i++) {
    printf("ps->players[%i].score = %d\n", i + 1, ps->players[i].score);
  }
  printf("\n");

  printf("POSITIONS:\n");
  for (int i = 0; i < get_players_num(ps); i++) {
    printf("ps->players[%i].position = %d\n", i + 1, ps->players[i].position);
  }
  printf("\n");
}

void print_positions(const Players *ps) {
  printf("%s %s\n", "NAME", "POS");
  int i = 0;
  while (i < get_players_num(ps)) {
    printf("%s %3d\n", get_username(get_player(ps, i)),
           get_position(get_player(ps, i)) + 1);
    i = i + 1;
  }
}

void sort_players_by_dice(Players *players) {
  int i, j, max_idx;
  int *dice_values = (int *)malloc(players->players_num);

  // Roll dice for each player and assign to their dice_values array
  for (i = 0; i < players->players_num; i++) {
    dice_values[i] = roll_die();
  }

  // Sort players array based on dice roll using selection sort
  for (i = 0; i < players->players_num - 1; i++) {
    max_idx = i;
    for (j = i + 1; j < players->players_num; j++) {
      if (dice_values[j] > dice_values[max_idx]) {
        max_idx = j;
      }
    }
    if (max_idx != i) {
      // Swap dice values
      int temp_dice = dice_values[i];
      dice_values[i] = dice_values[max_idx];
      dice_values[max_idx] = temp_dice;

      // Swap player structs
      Player temp_player = players->players[i];
      players->players[i] = players->players[max_idx];
      players->players[max_idx] = temp_player;
    }
  }
  free(dice_values);
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

void close_game(void *ptr, ...) {
  void *p = ptr;

  va_list args;
  va_start(args, ptr);
  while (p) {
    free(p);
    p = va_arg(args, void *);
  }
  va_end(args);
}
