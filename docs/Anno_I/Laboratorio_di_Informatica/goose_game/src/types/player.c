#include "./player.h"

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
