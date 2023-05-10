// Copyright (c) 2023 @authors. GNU GPLv3.

/**
 * @file player.h
 * @brief Defines a struct for a player in a game.
 *
 * This is a header file named that defines a struct named @c Player which
 * represents a player in the. The struct contains fields for the player's
 * username, position, score, and the number of turns they are blocked for. The
 * file also defines several constants, including the minimum and maximum number
 * of players allowed in the game, the initial position and score of a player,
 * and the maximum length of a player's name and username. Additionally, the
 * file provides functions for setting and getting the @c username, @c position,
 * @c score, and @c turns_blocked fields of a @c Player struct.
 *
 * @authors
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-05-06 13:26
 * @version 1.0
 * @copyright GNU GPLv3
 */

#ifndef PLAYER_TYPE_H
#define PLAYER_TYPE_H

#include <stdio.h>

/**
 * @def MIN_NUM_PLAYERS
 * @brief The minimum number of players allowed in the game.
 */
#define MIN_NUM_PLAYERS 2

/**
 * @def MAX_NUM_PLAYERS
 * @brief The maximum number of players allowed in the game.
 */
#define MAX_NUM_PLAYERS 4

/**
 * @def INITIAL_POSITION
 * @brief The initial position of a player.
 */
#define INITIAL_POSITION 0

/**
 * @def INITIAL_SCORE
 * @brief The initial score of a player.
 */
#define INITIAL_SCORE 0

/**
 * @def INITIAL_TURN
 * @brief The initial turn of a game.
 */
#define INITIAL_TURN 0

/**
 * @def MAX_NAME_LENGTH
 * @brief The maximum length of a player's name.
 */
#define MAX_NAME_LENGTH 20

/**
 * @def MAX_USERNAME_LENGTH
 * @brief The maximum length of a player's username.
 */
#define MAX_USERNAME_LENGTH 3

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief Defines a struct for a player in the game.
 *
 * This struct contains the information needed to define a player in the game,
 * such as their username, current position, current score, and the number of
 * turns they are blocked for.
 *
 * @var Player::username
 * The username of the player, which must be no more than @c MAX_USERNAME_LENGTH
 * characters long.
 *
 * @var Player::position
 * The current position of the player on the game board.
 *
 * @var Player::score
 * The current score of the player.
 *
 * @var Player::turns_blocked
 * The number of turns the player is blocked for.
 */
typedef struct Player {
  char username[MAX_USERNAME_LENGTH + 1];  ///< The username of the player.
  int position;       ///< The current position of the player.
  int score;          ///< The current score of the player.
  int turns_blocked;  ///< The number of turns the player is blocked for.
} Player;

/**
 * @brief Sets the username of a player.
 *
 * This function sets the username of the specified player to the given value.
 * The username is stored as a string, and it will be truncated to a maximum of
 * MAX_USERNAME_LENGTH characters plus a ".3" suffix if it is longer than that.
 *
 * @param[in,out] p        A pointer to the player whose username will be set.
 * @param[in]     username A pointer to the string containing the new username.
 *
 * @return void.
 */
void set_username(Player *p, const char *username);

/**
 * @brief Gets the username of a player.
 *
 * This function returns the current username of the specified player as a
 * constant string.
 *
 * @param[in] p A pointer to the player whose username will be retrieved.
 *
 * @return A pointer to the string containing the player's username.
 */
const char *get_username(const Player *p);

/**
 * @brief Sets the position of a player.
 *
 * This function sets the position of the specified player to the given value.
 * The position represents the current square that the player is on.
 *
 * @param[in,out] p        A pointer to the player whose position will be set.
 * @param[in]     position The new position for the player.
 *
 * @return void.
 */
void set_position(Player *p, int position);

/**
 * @brief Gets the position of a player.
 *
 * This function returns the current position of the specified player.
 * The position represents the current square that the player is on.
 *
 * @param[in] p A pointer to the player whose position will be retrieved.
 *
 * @return The current position of the player.
 */
int get_position(const Player *p);

/**
 * @brief Sets the score of a player.
 *
 * This function sets the score of the specified player to the given value.
 * The score represents the number of points that the player has accumulated.
 *
 * @param[in,out] p     A pointer to the player whose score will be set.
 * @param[in]     score The new score for the player.
 *
 * @return void.
 */
void set_score(Player *p, int score);

/**
 * @brief Gets the score of a player.
 *
 * This function returns the current score of the specified player.
 * The score represents the number of points that the player has accumulated.
 *
 * @param[in] p A pointer to the player whose score will be retrieved.
 *
 * @return The current score of the player.
 */
int get_score(const Player *p);

/**
 * @brief Sets the number of turns that a player is blocked for.
 *
 * This function sets the number of turns that the specified player is blocked
 * for to the given value. If the player is not blocked, this value should be 0.
 *
 * @param[in, out] p             A pointer to the player whose turns_blocked
 *                               value will be set.
 * @param[in]      turns_blocked The new number of turns that the player is
 *                               blocked for.
 *
 * @return void.
 */
void set_turns_blocked(Player *p, int turns_blocked);

/**
 * @brief Gets the number of turns that a player is blocked for.
 *
 * This function returns the number of turns that the specified player is
 * blocked for. If the player is not blocked, this value will be 0.
 *
 * @param[in] p A pointer to the player whose turns_blocked value will be
 *              retrieved.
 *
 * @return The number of turns that the player is blocked for.
 */
int get_turns_blocked(const Player *p);

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief Defines a struct for managing a list of players in the game.
 *
 * This struct contains an array of @c Player structs representing the players
 * in the game, as well as additional information such as the number of players
 * and the turn order.
 *
 * @var Players::players
 * An array of @c Player structs representing the players in the game.
 *
 * @var Players::players_num
 * The number of players in the game.
 *
 * @var Players::turn
 * The index of the current player in the turn order.
 *
 * @var Players::turn_order
 * An array of integers representing the turn order of the players. The value
 * at each index corresponds to the index of the player in the @c players array.
 */
typedef struct Players {
  Player players[MAX_NUM_PLAYERS];  ///< An array of @c Player structs
                                    ///< representing the players in the game.
  int players_num;                  ///< The number of players in the game.
  int turn;  ///< The index of the current player in the turn order.
  int turn_order[MAX_NUM_PLAYERS];  ///< An array of integers representing the
                                    ///< turn order of the players.
} Players;

/**
 * @brief Returns the player at the specified position in the players array.
 *
 * This function returns a copy of the player struct stored at the specified
 * position in the players array of the Players struct.
 *
 * @param[in] ps       A pointer to the Players struct containing the players
 *                     array.
 * @param[in] position The index of the player to be returned.
 *
 * @return A pointer to the player struct stored at the specified position in
 *         the players array.
 */
const Player *get_player(const Players *ps, const int position);

/**
 * @brief Sets the player at the specified position in the players array.
 *
 * This function sets the player struct stored at the specified position in
 * the players array of the Players struct to the provided player struct.
 *
 * @param[in,out] ps       A pointer to the Players struct containing the
 *                         players array.
 * @param[in]     p        A pointer to the player struct to be set.
 * @param[in]     position The index of the player to be set.
 *
 * @return void.
 */
void set_player(Players *ps, const Player *p, const int position);

/**
 * @brief Returns the number of players in the players array of the Players
 * struct.
 *
 * This function returns the value of the players_num field of the Players
 * struct, which contains the number of players in the players array.
 *
 * @param[in] ps A pointer to the Players struct.
 *
 * @return The number of players in the players array of the Players struct.
 */
int get_players_num(const Players *ps);

/**
 * @brief Sets the number of players in the players array of the Players struct.
 *
 * This function sets the value of the players_num field of the Players struct
 * to the provided value, which represents the number of players in the
 * players array.
 *
 * @param[in,out] ps          A pointer to the Players struct.
 * @param[in]     players_num The new number of players in the players array.
 *
 * @return void.
 */
void set_players_num(Players *ps, const int players_num);

/**
 * @brief Returns the current turn number of the game.
 *
 * This function returns the value of the turn field of the Players struct,
 * which contains the current turn number of the game.
 *
 * @param[in] ps A pointer to the Players struct.
 *
 * @return The current turn number of the game.
 */
int get_turn(const Players *ps);

/**
 * @brief Sets the current turn number of the game.
 *
 * This function sets the value of the turn field of the Players struct to
 * the provided value, which represents the current turn number of the game.
 *
 * @param[in,out] ps   A pointer to the Players struct.
 * @param[in]     turn The new turn number of the game.
 *
 * @return void.
 */
void set_turn(Players *ps, const int turn);

#endif  // !PLAYER_TYPE_H
