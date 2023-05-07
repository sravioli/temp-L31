#include <stdio.h>
#include <stdlib.h>

#include "../types/fn_lookup.h"
#include "../types/menu.h"

void display_new_game() { printf("Starting new game\n"); }
void display_saved_games() { printf("Showing saved games\n"); }
void display_help() { printf("Showing help\n"); }
void display_leaderboard() { printf("Showing leaderboard\n"); }
void quit() { printf("Quitting\n"); }

void display_rules() { printf("Showing rules\n"); }
void display_manual() { printf("Showing manual\n"); }

void launch_new_game() { printf("Launching new game\n"); }

Menu main_menu = {"MAIN",
                  {
                      {'n', "[n]ew game", &display_new_game},
                      {'s', "[s]aved games", &display_saved_games},
                      {'l', "[l]eaderboard", &display_leaderboard},
                      {'h', "[h]elp", &display_help},
                      {'w', "[q]uit", &quit},
                  },
                  5};

Menu help_menu = {"HELP",
                  {{'m', "[m]anual", &display_manual},
                   {'r', "[r]ules", &display_rules},
                   {'q', "[q]uit", &quit}},
                  2};

Menu new_game_menu = {
    "NEW GAME",
    {{'g', "launch new [g]ame", &launch_new_game}, {'q', "[q]uit", &quit}},
    2};

Menu saved_games_menu = {"SAVED GAMES", {}, 3};

Menu in_game_menu = {"IN GAME",
                     {{'v', "sa[v]e game", NULL},
                      {'t', "[t]hrow die", NULL},
                      {'e', "l[e]ave game", NULL}},
                     3};
