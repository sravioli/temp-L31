// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "../common/inc/math.h"
#include "../common/inc/string.h"
#include "../common/inc/term.h"

#include "../inc/handle_game.h"
#include "../inc/private/handle_game.h"

const char *BORDERS[8] = DEFAULT_BORDERS;

int ask_num_in_range(const int min, const int max, const char name[]) {
  // this function asks the user to input a number within a given range. It
  // keeps prompting the user until a valid number within the range is provided.
  int result;
  do {
    printf("Insert the desired number of %s [%d, %d]: ", name, min, max);
    scanf_s("%d", &result, sizeof(result));

    if ((result < min) || (result > max)) {
      printf("given number of %s is out of bounds, please try again.\n", name);
    }
  } while ((result < min) || (result > max));

  return result;
}

void conform_username(char *username) {
  // this function modifies the provided username by truncating it to a maximum
  // length, converting it to uppercase, and adding a filler character if the
  // length is less than the maximum allowed length.

  str_truncate(username, MAX_USERNAME_LENGTH);
  str_to_uppercase(username);
  nconcat(username, FILLER_CHAR, MAX_USERNAME_LENGTH - strlen(username));
}

int is_username_valid(const char username[]) {
  // this function checks if a given username is valid. It scans through each
  // character of the username and returns FALSE if any punctuation or digit is
  // found. Otherwise, it returns TRUE.

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

int find_duplicate_username(Players *pls, const char username[]) {
  // this function searches for any duplicate username. It scans all the
  // previous usernames and returns the index of the duplicate if found,
  // otherwise it will return -1.

  int i = 0;
  while (i < get_players_num(pls)) {
    if (strcmp(get_username(get_player(pls, i)), username) == 0) {
      return i;
    }
    i = i + 1;
  }
  return -1;
}

char *ask_username(Players *pls, const int player_idx) {
  // this function asks the player to enter their username. It allocates memory
  // for the username, reads input from the user, checks if the username is
  // valid, and ensures the username conforms to the required format.

  char *username = (char *)malloc(sizeof(char));  // NOLINT
  memset(username, STR_END, strlen(username));

  int valid = FALSE;
  while (!valid) {
    printf("Player %i, enter your username: ", player_idx);
    scanf_s("%s", username, MAX_BUFFER_LEN);

    conform_username(username);

    if (is_username_valid(username)) {
      int duplicate = find_duplicate_username(pls, username);
      if (duplicate != -1) {
        printf("can't have the same username as %s! Try again.\n",
               get_username(get_player(pls, duplicate)));
      } else {
        printf("your username will be: %s\n", username);
        valid = TRUE;
      }
    } else {
      printf("this (%s) username is invalid, please try again.\n", username);
    }
  }
  printf("\n");

  return username;
}

Players *create_players(const int num_players) {
  // this function creates a Players struct. It allocates memory for it, calls
  // ask_username() to get the username for each user, sets all the default
  // values necessary to start a new game.

  printf("\nUSERNAMES SELECTION\n");

  // create the struct
  Players *pls = (Players *)malloc(sizeof(Players));  // NOLINT

  set_players_num(pls, num_players);
  set_turn(pls, INITIAL_TURN);

  int i = 0;
  while (i < num_players) {
    Player *pl = (Player *)malloc(sizeof(Player));  // NOLINT

    char *username = ask_username(pls, i + 1);
    set_username(pl, username);
    free(username);

    set_id(pl);

    set_position(pl, INITIAL_POSITION);
    set_score(pl, INITIAL_SCORE);

    set_player(pls, pl, i);
    free(pl);

    i = i + 1;
  }

  return pls;
}

void selection_sort_players(Players *players, int *dice_rolls) {
  // this function uses selection sort to sort the players according to their
  // dice rolls.

  int i = 0;
  while (i < get_players_num(players) - 1) {
    int max_idx = i;
    int j = i + 1;
    while (j < get_players_num(players)) {
      if (dice_rolls[j] > dice_rolls[max_idx]) {
        max_idx = j;
      }
      j = j + 1;
    }
    if (max_idx != i) {
      swap_int(&dice_rolls[i], &dice_rolls[max_idx]);
      swap_players(players, i, max_idx);
    }
    i = i + 1;
  }
}

void interactive_roll(Players *pls, int *dice_rolls) {
  // this function makes each player roll dice interactively by asking to press
  // any key. It will then fill the given dice_rolls array.

  int i = 0;
  while (i < get_players_num(pls)) {
    const char *username = get_username(get_player(pls, i));
    wait_keypress("%s press any key to roll dice", username);

    dice_rolls[i] = roll_dice();
    clear_line();
    printf("%s rolled a %d\n", username, dice_rolls[i]);

    i = i + 1;
  }
  printf("\n");
}

void interactive_reroll(Players *pls, int *dice_rolls) {
  // this function makes players who have rolled the same number, re-roll dice
  // interactively by asking to press any key. It will then sort the players
  // accordingly.

  int i = 0;
  while (i < get_players_num(pls) - 1) {
    int reroll_start = i;
    while (i < get_players_num(pls) - 1 && dice_rolls[i] == dice_rolls[i + 1]) {
      i = i + 1;
    }
    if (reroll_start != i) {
      printf("Tie detected! Rerolling for tied players:\n");

      // reroll
      int j = reroll_start;
      while (j <= i) {
        const char *username = get_username(get_player(pls, j));
        wait_keypress("%s press any key to re-roll", username);

        dice_rolls[j] = roll_dice();
        clear_line();
        printf("%s rerolled and got a %d\n", username, dice_rolls[j]);

        j = j + 1;
      }
      selection_sort_players(pls, dice_rolls);
    }
    i = i + 1;
  }
  printf("\n");
}

void print_players_list(Players *pls) {
  // this function print the players in the order that has been decided by dice
  // rolls.

  printf("Based on the dice rolls, the turn order is:\n");
  int i = 0;
  while (i < get_players_num(pls)) {
    printf("%s", get_username(get_player(pls, i)));
    if (i < get_players_num(pls) - 1) {
      printf(", ");
    }
    i = i + 1;
  }
  printf("\n\n");
}

void sort_players_by_dice(Players *pls) {
  // this function sorts the players in the Players struct based on their dice
  // rolls. It rolls the dice for each player, assigns the dice values to their
  // dice_rolls array, sorts the players array using selection sort based on the
  // dice rolls, rerolls the dice for tied players, and prints the sorted list
  // of players and their final die values.

  int *dice_rolls =
      (int *)malloc(get_players_num(pls) * sizeof(int));  // NOLINT

  printf("TURN ORDER\n\n");

  // roll dice for each player and assign to their dice_rolls array
  interactive_roll(pls, dice_rolls);

  // sort players array based on dice roll using selection sort
  selection_sort_players(pls, dice_rolls);

  // reroll dice for tied players until there are no more ties
  interactive_reroll(pls, dice_rolls);
  free(dice_rolls);

  // print the sorted list of players and their final die values
  print_players_list(pls);
  wait_keypress("Press any key to continue");
}

int check_square(const Board *board, int position) {
  // this function checks the value of a square on the board and returns the
  // position to move to based on the square type.

  if (get_square(board, position) == GOOSE_VALUE) {
    return position + 1;
  }
  return position;
}

void insert_goose_squares(Board *board) {
  // this function inserts goose squares on the board at regular intervals.

  int i = GOOSE_SPACING - 1;
  while (i < get_dim(board) - 1) {
    set_square(board, i, GOOSE_VALUE);
    i = i + GOOSE_SPACING;
  }
}

void insert_special_squares(Board *board) {
  // this function inserts special squares (e.g., bridge, inn, well) on the
  // board at specific positions.

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

Board *create_board(const int board_dim) {
  // creates a new game board with the specified dimensions. Initializes the
  // board with sequential values, inserts goose squares, and inserts special
  // squares.

  Board *board = (Board *)malloc(sizeof(Board));  // NOLINT
  set_dim(board, board_dim);

  int i = 0;
  while (i < board_dim) {
    set_square(board, i, i + 1);
    i = i + 1;
  }

  insert_goose_squares(board);
  insert_special_squares(board);

  return board;
}

char *sq_to_str(const int square) {
  char *buffer = str_allocate((int)sizeof(square));  // NOLINT
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
      char *sq = sq_to_str(square);

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
      char *sq = sq_to_str(square);

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

void print_board(const char game_board[]) { printf("%s", game_board); }

int find_other_player_in_square(Players *pls, Player *curr_pl,
                                const int target_sq) {
  int i = 0;
  while (i < get_players_num(pls)) {
    // check whether a player different than the given one is in the square
    Player *other_pl = get_player(pls, i);
    if (other_pl->id != curr_pl->id && get_position(other_pl) == target_sq) {
      return i;
    }

    free(other_pl);
    i = i + 1;
  }
  return -1;
}

void update_score(Player *pl, const int roll) {
  set_score(pl, get_score(pl) + (roll * 10));
}

int check_player_pos(Players *pls, Player *pl, Board *board, const int roll) {
  int current_sq = get_square(board, get_position(pl));
  int target_pos = roll + get_position(pl);
  int target_sq = get_square(board, target_pos);

  int turns_blocked = get_turns_blocked(pl);

  // score has to be updated for each roll
  update_score(pl, roll);

  // player is blocked
  if (turns_blocked > NO_TURNS_BLOCKED) {
    // decrement counter
    set_turns_blocked(pl, turns_blocked - 1);

    // player stays where he is
    if (current_sq == INN_VALUE) {
      return get_position(pl);
    }

    // player has escaped prison/well, get his new position
    if ((current_sq == PRISON_VALUE || current_sq == WELL_VALUE) &&
        (roll == ESCAPE_ROLL1 || roll == ESCAPE_ROLL2)) {
      set_turns_blocked(pl, NO_TURNS_BLOCKED);
      return check_player_pos(pls, pl, board, roll + get_position(pl));
    }
  }

  // player is free to move, check for special squares
  if (turns_blocked == NO_TURNS_BLOCKED) {
    // check if player goes beyond the number of squares
    if (target_sq > get_dim(board)) {
      return get_dim(board) + (get_dim(board) - (current_sq + roll));
    }
    // check if the return position should be different than target_pos
    if (target_sq == GOOSE_VALUE || target_sq == BRIDGE_VALUE) {
      return (roll * 2) + get_position(pl);
    } else if (target_sq == SKELETON_VALUE) {
      return INITIAL_POSITION;
    }

    if (target_sq == PRISON_VALUE || target_sq == WELL_VALUE) {
      int other_pl_pos = find_other_player_in_square(pls, pl, target_sq);
      if (other_pl_pos != -1) {
        Player other_pl = *get_player(pls, other_pl_pos);
        set_turns_blocked(&other_pl, NO_TURNS_BLOCKED);
        set_turns_blocked(pl, INDEF_BLOCK);
      }
    }
  }

  // player isn't on special square, return the roll + it's current position
  return target_pos;
}

void move_player(Players *pls, Player *pl, const int roll, Board *board) {
  set_position(pl, check_player_pos(pls, pl, board, roll));
}

int is_player_winner(Players *pls, Board *board) {
  int i = 0;
  while (i < get_players_num(pls)) {
    int pos = get_position(get_player(pls, i)) + 1;
    if (pos == get_dim(board)) {
      return TRUE;
    }
    i = i + 1;
  }
  return FALSE;
}

void print_positions(Players *pls) {
  printf("NAME\tPOS\n");
  int i = 0;
  while (i < get_players_num(pls)) {
    printf("%s\t", get_username(get_player(pls, i)));
    printf("%d\t", get_id(get_player(pls, i)));
    printf("%d\n", 1 + get_position(get_player(pls, i)));
    i = i + 1;
  }
}

void pause_menu(int *quit, Players *pls, Board *board,
                const char game_board[]) {
  new_screen();
  print_menu("./menus/pause.txt");

  int display = TRUE;
  while (display) {
    char key = _getch();

    if (key == 's') {
      wait_keypress("saving game...");
      new_screen();
      game_loop(pls, board, game_board);
    } else if (key == 'l') {
      leave_game(board, pls, game_board);
      *quit = TRUE;
    } else if (is_back_key(key)) {
      new_screen();
      game_loop(pls, board, game_board);
    }
    display = FALSE;
  }
}

void game_loop(Players *pls, Board *board, const char game_board[]) {
  int quit = FALSE;
  while (is_player_winner(pls, board) || !quit) {
    int i = 0;
    while (i < get_players_num(pls)) {
      print_board(game_board);
      print_positions(pls);
      printf("%s press 'r' to roll dice, 'p' to pause the game\n",
             get_username(get_player(pls, i)));

      char keypress = _getch();
      if (keypress == 'p') {
        pause_menu(&quit, pls, board, game_board);
      } else if (keypress == 'r') {
        int roll = roll_dice();
        move_player(pls, get_player(pls, i), roll, board);
        printf("%s rolled a %d...", pls->players[0].username, roll);
        new_screen();
      } else {
        clear_line();
        printf("key '%c' does nothing", keypress);
      }
      i = i + 1;
    }
  }
}

void dev_game_loop(Players *pls, Board *board, const char game_board[]) {
  int quit_game = FALSE;
  while (!quit_game) {
    if (is_player_winner(pls, board)) {
      quit_game = TRUE;
      new_screen();
      printf("There is a winner!\n");
      wait_keypress("exiting...");
    } else {
      int i = 0;
      while (i < get_players_num(pls)) {
        new_screen();
        print_board(game_board);
        print_positions(pls);
        printf("press 'r' to roll, 'p' to pause game\n");

        int get_keypress = TRUE;
        while (get_keypress) {
          char keypress = _getch();
          get_keypress = FALSE;

          if (keypress == 'p') {
            pause_menu(&quit_game, pls, board, game_board);
          } else if (keypress == 'r') {
            const int roll = roll_dice();
            move_player(pls, get_player(pls, i), roll, board);
          } else {
            clear_line();
            printf("key '%c' does nothing", keypress);
            get_keypress = TRUE;
          }
        }
        i = i + 1;
      }
    }
  }
}

void new_game() {
  new_screen();

  // prepare for a new game
  int num_squares =
      ask_num_in_range(MIN_NUM_SQUARES, MAX_NUM_SQUARES, "squares");
  int num_players =
      ask_num_in_range(MIN_NUM_PLAYERS, MAX_NUM_PLAYERS, "players");

  Board *board = create_board(num_squares);
  Players *pls = create_players(num_players);

  const char *game_board =
      build_board(*board, DEFAULT_COLS, DEFAULT_SQUARE_LEN, BORDERS);

  new_screen();
  sort_players_by_dice(pls);

  new_screen();
  // game_loop(pls, board, game_board);
  dev_game_loop(pls, board, game_board);
}

void leave_game(void *ptr, ...) {
  void *pl = ptr;

  va_list args;
  va_start(args, ptr);
  while (pl) {
    free(pl);
    pl = va_arg(args, void *);
  }
  va_end(args);
}

// int main() {
//   // Seed the random number generator
//   srand(time(NULL));
//
//   new_game();
//
//   return 0;
// }
