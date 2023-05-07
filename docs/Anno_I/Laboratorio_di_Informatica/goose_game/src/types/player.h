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

#ifndef Player_TYPE_H
#define Player_TYPE_H

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
 * @def MAX_NAME_LENGTH
 * @brief The maximum length of a player's name.
 */
#define MAX_NAME_LENGTH 20

/**
 * @def MAX_USERNAME_LENGTH
 * @brief The maximum length of a player's username.
 */
#define MAX_USERNAME_LENGTH 3

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

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

#endif  // !Player_TYPE_H
