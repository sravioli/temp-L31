#ifndef MENU_OPTION_TYPE_H
#define MENU_OPTION_TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 64
#define MAX_NUM_OPTIONS 10

/**
 * @brief Defines a struct for a menu option.
 *
 * This struct contains the information needed to define a menu option, such as
 * its key, text, and action.
 *
 * @var MenuOption::key
 * The character key associated with the menu option.
 *
 * @var MenuOption::text
 * The text associated with the menu option.
 *
 * @var MenuOption.action
 * A function pointer to the action that is executed when the menu option is
 * selected.
 */
typedef struct MenuOption {
  char key;  ///< The character key associated with the menu option.
  char text[MAX_LINE_LEN + 1];  ///< The text associated with the menu option.
  void (*action)();  ///< A function pointer to the action that is executed when
                     ///< the menu option is selected.
} MenuOption;

/**
 * @brief Allocates memory for a @c MenuOption struct and returns a pointer to
 *        it.
 *
 * @return A pointer to the allocated @c MenuOption struct.
 */
MenuOption *init_option();

/**
 * @brief Returns the key associated with a @c MenuOption struct.
 *
 * @param[in] option The @c MenuOption struct to retrieve the key from.
 *
 * @return The key associated with the @c MenuOption struct.
 */
char get_key(MenuOption option);

/**
 * @brief Sets the key associated with a @c MenuOption struct.
 *
 * @param[in,out] option The @c @c MenuOption struct to set the key for.
 * @param[in]     key    The key to associate with the @c MenuOption struct.
 */
void set_key(MenuOption *option, char key);

/**
 * @brief Returns the text associated with a @c MenuOption struct.
 *
 * @param[in] option The @c MenuOption struct to retrieve the text from.
 *
 * @return A pointer to a string containing the text associated with the
 *         @c MenuOption struct.
 */
char *get_text(MenuOption option);

/**
 * @brief Sets the text associated with a @c MenuOption struct.
 *
 * @param[in,out] option The @c MenuOption struct to set the text for.
 * @param[in]     text   The text to associate with the @c MenuOption struct.
 */
void set_text(MenuOption *option, char text[]);

/**
 * @brief Returns the function pointer associated with a @c MenuOption struct.
 *
 * @param[in] option The @c MenuOption struct to retrieve the function pointer
 *                   from.
 *
 * @return A pointer to the function associated with the @c MenuOption struct.
 */
void (*get_action(MenuOption option))();

/**
 * @brief Sets the function pointer associated with a @c MenuOption struct.
 *
 * @param[in,out] option The @c MenuOption struct to set the function pointer
 *                       for.
 * @param[in]     action A pointer to the function to associate with the
 *                       @c MenuOption struct.
 */
void set_action(MenuOption *option, void (*action)());

#endif  // !MENU_OPTION_TYPE_H
