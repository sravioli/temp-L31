/**
 * @file menu.h
 * @brief Defines a struct for representing a menu with options.
 *
 * This header file defines a struct called @c Menu that represents a menu with
 * a title and a list of options. It also provides functions for getting and
 * setting the title, getting and setting the options, getting the key and text
 * of an option, and calling the action associated with an option.
 *
 * @author
 *    Amorese Emanuele
 *    Blanco Lorenzo
 *    Cannito Antonio
 *    Fidanza Simone
 *    Lecini Fabio
 *
 * @date 2023-05-03 20:48
 * @version 1.0
 * @copyright GNU GPLv3
 *
 * @note This file requires the standard library headers @c stdio.h,
 *       @c stdlib.h, and @c string.h.
 */

#ifndef MENU_TYPE_H
#define MENU_TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @def MAX_LINE_LEN
 * @brief The maximum line length allowed.
 */
#define MAX_LINE_LEN 64

/**
 * @def MAX_LINE_LEN
 * @brief The maximum number of option that a menu can have.
 */
#define MAX_NUM_OPTIONS 10

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

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
void (*get_action(MenuOption option))();  // NOLINT

/**
 * @brief Sets the function pointer associated with a @c MenuOption struct.
 *
 * @param[in,out] option The @c MenuOption struct to set the function pointer
 *                       for.
 * @param[in]     action A pointer to the function to associate with the
 *                       @c MenuOption struct.
 */
void set_action(MenuOption *option, void (*action)());

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/**
 * @brief Struct for storing a menu with a title and a list of options.
 *
 * The @c Menu struct contains a @c title, which is a character array that can
 * store a string up to @c MAX_LINE_LEN characters long. It also contains an
 * array of @c options, which is a list of @c MenuOption structs representing
 * the choices available in the menu. Finally, it has an @c int field
 * @c num_options that stores the number of options in the menu.
 *
 * @var Menu::title
 * Title of the menu.
 *
 * @var Menu::MenuOption
 * List of options in the menu.
 *
 * @var Menu::num_options
 * Number of options in the menu.
 */
typedef struct Menu {
  char title[MAX_LINE_LEN + 1];         ///< Title of the menu.
  MenuOption options[MAX_NUM_OPTIONS];  ///< List of options in the menu.
  int num_options;                      ///< Number of options in the menu.
} Menu;

/**
 * @brief Returns the title of a given menu.
 *
 * @param menu The @c Menu struct whose title to retrieve.
 * @return A pointer to a static character array containing the title of the
 *         menu.
 */
char *get_title(Menu menu);

/**
 * @brief Set the title of the menu.
 *
 * @param[in, out] menu  A pointer to the menu.
 * @param[in]      title The new title for the menu.
 */
void set_title(Menu *menu, char title[]);

/**
 * @brief Returns the @c MenuOption struct located at the specified index in a
 *        given @c Menu.
 *
 * @param[in] menu  The @c Menu instance to search for the option.
 * @param[in] index The index of the desired option in the @c Menu.
 *
 * @return The @c MenuOption struct located at the specified index.
 */
MenuOption get_option(Menu menu, int index);

/**
 * @brief Sets the @c MenuOption struct located at the specified index in a
 *        given @c Menu.
 *
 * @param[in,out] menu        The @c Menu instance in which to set the option.
 * @param[in]     num_options The index of the desired option in the @c Menu.
 * @param[in]     option      The new @c MenuOption to set in the specified
 *                            index of the @c Menu.
 */
void set_option(Menu *menu, int num_options, struct MenuOption option);

/**
 * @brief Returns the key of the @c MenuOption struct located at the specified
 *        index in a given @c Menu.
 *
 * @param[in] menu  The @c Menu instance in which to search for the option key.
 * @param[in] index The index of the desired option in the @c Menu.
 *
 * @return The key of the @c MenuOption struct located at the specified index.
 */
char get_menu_key(Menu menu, const int index);

/**
 * @brief Returns the text of the @c MenuOption struct located at the specified
 *        index in a given @c Menu.
 *
 * @param[in] menu  The @c Menu instance in which to search for the option text.
 * @param[in] index The index of the desired option in the @c Menu.
 *
 * @return A pointer to the text of the @c MenuOption struct located at the
 *         specified index.
 */
char *get_menu_text(Menu menu, const int index);

/**
 * @brief Calls the function associated with the @c MenuOption struct located at
 * the specified index in a given @c Menu.
 *
 * @param[in] menu  The @c Menu instance in which to search for the option
 *                  function.
 * @param[in] index The index of the desired option in the @c Menu.
 */
void call_action(Menu menu, const int index);

/**
 * @brief Returns the number of options in a given @c Menu.
 *
 * @param[in] menu The @c Menu instance in which to count the options.
 *
 * @return The number of options in the specified @c Menu.
 */
int get_num_options(Menu menu);

/**
 * @brief Sets the number of options in a given @c Menu.
 *
 * @param[in,out] menu    The @c Menu instance in which to set the number of
 *                        options.
 * @param[in] num_options The new number of options to set in the specified
 *                        @c Menu.
 */
void set_num_options(Menu *menu, int num_options);

#endif  // !MENU_TYPE_H
