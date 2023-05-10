// Copyright (c) 2023 @authors. GNU GPLv3.
// @authors
//    Amorese Emanuele
//    Blanco Lorenzo
//    Cannito Antonio
//    Fidanza Simone
//    Lecini Fabio

#include "./players.h"

void set_username(Player *p, const char *username) {
  snprintf(p->username, MAX_USERNAME_LENGTH + 1, "%s.3", username);
}
const char *get_username(const Player *p) { return p->username; }

void set_position(Player *p, int position) { p->position = position; }
int get_position(const Player *p) { return p->position; }

void set_score(Player *p, int score) { p->score = score; }
int get_score(const Player *p) { return p->score; }

void set_turns_blocked(Player *p, int turns_blocked) {
  p->turns_blocked = turns_blocked;
}
int get_turns_blocked(const Player *p) { return p->turns_blocked; }

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

const Player *get_player(const Players *ps, const int position) {
  return &ps->players[position];
}
void set_player(Players *ps, const Player *p, const int position) {
  ps->players[position] = *p;
}

int get_players_num(const Players *ps) { return ps->players_num; }
void set_players_num(Players *ps, const int players_num) {
  ps->players_num = players_num;
}

int get_turn(const Players *ps) { return ps->turn; }
void set_turn(Players *ps, const int turn) { ps->turn = turn; }
// void next_turn(Players *ps) { ps->turn = ps->turn + 1; }

int get_turn_order(const Players *ps, const int position) {
  return ps->turn_order[position];
}
void set_turn_order(Players *ps, const int turn_order, const int position) {
  ps->turn_order[position] = turn_order;
}
