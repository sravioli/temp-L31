// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "../inc/handle_game.h"
#include "../common/inc/term.h"
#include "../inc/private/handle_game.h"
#include <stdio.h>

int ask_num_squares(void) {
  // get number of squares from user
  int num_squares;
  printf("Insert the number of squares [%d, %d]: ", MIN_NUM_SQUARES,
         MAX_NUM_SQUARES);
  scanf_s("%d", &num_squares, sizeof(num_squares));

  // validate input
  while ((num_squares < MIN_NUM_SQUARES) || (num_squares > MAX_NUM_SQUARES)) {
    printf("The number entered is not valid. Insert the number of squares [%d, "
           "%d]: ",
           MIN_NUM_SQUARES, MAX_NUM_SQUARES);
    scanf_s("%d", &num_squares, sizeof(num_squares));
  }
  return num_squares;
}

int ask_num_players(void) {
  int num_players;
  printf("Insert the number of players [%d, %d]\n", MIN_NUM_PLAYERS,
         MAX_NUM_PLAYERS);
  scanf_s("%d", &num_players, sizeof(num_players));

  while ((num_players < MIN_NUM_PLAYERS) || (num_players > MAX_NUM_PLAYERS)) {
    printf("The number entered is not valid. Insert the number of players [%d, "
           "%d]: ",
           MIN_NUM_PLAYERS, MAX_NUM_PLAYERS);
    scanf_s("%d", &num_players, sizeof(num_players));
  }
  return num_players;
}

void ask_username(char username[]) {
  // clear_line();
  int valid = 0;
  while (!valid) {
    printf("Enter your username: ");
    scanf_s("%20s", username, MAX_NAME_LENGTH);

    if (is_username_valid(username)) {
      valid = 1;
      str_truncate(username, MAX_USERNAME_LENGTH);
      str_to_uppercase(username);
    } else {
      printf("Invalid username. Please try again.\n");
    }
  }
}

int ask_player_action(void) {
  int choice;
  printf("What to do?\n[l]eave game(0)\n[t]hrow die(1)\n[s]ave game(2)\n");
  scanf_s("%i", &choice);
  while ((choice < 0) || (choice > 2)) {
    printf("What to do?\n[l]eave game(0)\n[t]hrow die(1)\n[s]ave game(2)\n");
    scanf_s("%i", &choice);
  }
  return choice;
}

int is_username_valid(const char username[]) {
  int i = 0;
  while (username[i]) {
    // no need to check for spaces since scanf_s stops at the first whitespace
    // character
    if (ispunct(username[i]) || isdigit(username[i])) {
      return 0;
    }
    i = i + 1;
  }
  return 1;
}
