#ifndef TERMINAL_UTILS_H_
#define TERMINAL_UTILS_H_

/**
 * @brief Retrieve the terminal size (width and height).
 *
 * This function retrieves the terminal size (width and height) using
 * platform-specific functions, and stores the retrieved values in the
 * provided pointers.
 *
 * @param[out] width Pointer to an integer to store the terminal width.
 * @param[out] height Pointer to an integer to store the terminal height.
 *
 * @note This function is platform-specific and may not work in all terminal
 *       environments or configurations.
 *
 * @return void.
 */
void get_term_size(int *width, int *height);

/**
 * @brief Clears the terminal screen.
 *
 * This function clears the terminal screen. The behavior of this function
 * depends on the platform. On @e Windows, it uses the @c cls command to clear
 * the screen. On @e Linux and @e macOS, it uses the escape sequence @c \033c
 * to clear the screen.
 *
 * @note This function may not work as expected on all terminal emulators
 *       or platforms.
 *
 * @return void.
 */
void clear_screen();

void clear_line();

void center_text(const char *text, int term_width, int term_height);

void print_justified(const char *justification, const char *text,
                     int term_width);

void justify_text(char *text, int term_width, const char *justification);

#endif  // !TERMINAL_UTILS_H_
