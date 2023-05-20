#ifndef LOGGER_H
#define LOGGER_H

#include "../inc/term.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vadefs.h>

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @brief Checks if a filename is valid.
 *
 * This function checks whether a given filename is valid according to the
 * following criteria:
 * - The filename is not empty.
 * - Each character in the filename is alphanumeric, underscore (_), dash (-),
 *   or dot (.), and no other characters are allowed.
 * - The filename does not end with a dot or a space.
 *
 * @param[in] filename The filename to be checked.
 *
 * @return @c TRUE if the filename is valid, @c FALSE otherwise.
 */
int is_filename_valid(const char filename[]);

/**
 * @brief Starts the logger with the specified filename.
 *
 * This function starts the logger by opening the log file with the given
 * filename. It performs the following steps:
 * - Checks if logging is active. If logging is disabled, the function returns
 *   without performing any further actions.
 * - Checks the validity of the given filename using the @c is_filename_valid
 *   function. If the filename is invalid, an error is thrown using the
 *   @c throw_err function.
 * - Copies the given filename to the static variable @c log_filename using
 *   @c snprintf.
 * - Opens the log file in write mode and writes the start log message.
 * - Sets the @c is_initialized flag to @c TRUE to indicate that the log file
 *   has been created and can be written to.
 * - Closes the log file.
 *
 * @param[in] filename The filename for the log file.
 *
 * @note The function assumes that @c is_active and @c log_filename are global
 *       variables accessible within the scope of the function.
 *
 * @see @c is_filename_valid()
 * @see @c throw_err()
 */
void start_logger(const char *filename);

/**
 * @brief Stops the logger.
 *
 * This function stops the logger by writing the end log message and closing
 * the log file. It performs the following steps:
 * - Checks if logging is active and if the logger has been initialized. If
 *   either condition is false, the function returns without performing any
 *   further actions.
 * - Opens the log file in append mode and writes the end log message.
 * - Closes the log file.
 *
 * @note The function assumes that @c is_active, @c is_initialized, and
 *       @c log_filename are global variables accessible within the scope of the
 *       function.
 */
void stop_logger();

/**
 * @brief Logs an event to the log file.
 *
 * This function logs an event to the log file by appending the timestamp,
 * caller information, and the formatted message. It performs the following
 * steps:
 * - Checks if logging is active and if the logger has been initialized. If
 *   either condition is false, the function returns without performing any
 *   further actions.
 * - Retrieves the current time and formats it as a timestamp.
 * - Opens the log file in append mode and writes the timestamp, caller name,
 *   and the formatted message using variable arguments.
 * - Appends a new line to the log file and closes it.
 *
 * @param[in] caller The name of the function or caller logging the event.
 * @param[in] format The format string for the event message.
 * @param[in] ...    Additional arguments to be formatted into the event
 *                   message.
 *
 * @return void.
 */
void log_event(const char *caller, const char *format, ...);

/**
 * @brief Disables the logger.
 *
 * This function disables the logger by setting the @c is_active flag to @c
 * FALSE. When logging is disabled, the logger functions (start_logger,
 * stop_logger, log_event) will return without performing any actions.
 *
 * @return void.
 */
void disable_logger();

/**
 * @brief Enables the logger.
 *
 * This function enables the logger by setting the @c is_active flag to @c TRUE.
 * When logging is enabled, the logger functions (start_logger, stop_logger,
 * log_event) will perform their respective actions.
 *
 * @return void.
 */
void enable_logger();

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

/**
 * @struct Logger
 * @brief Represents a logger object with various logging functions.
 *
 * The Logger struct defines a set of function pointers that can be used to
 * perform logging operations. The struct includes functions for starting the
 * logger, logging events, stopping the logger, disabling the logger, and
 * enabling the logger.
 *
 * Example Usage:
 *
 * @code{.c}
 * struct Logger logger;
 *
 * // Start the logger
 * logger.start("logfile.txt");
 *
 * // Log an event
 * logger.log(__func__, "This is an event message: %s", "some data");
 *
 * // Stop the logger
 * logger.stop();
 * @endcode
 */
struct Logger {
  /**
   * @brief Starts the logger with the specified filename.
   *
   * This function starts the logger by opening the log file with the given
   * filename.
   *
   * @param[in] filename The filename for the log file.
   */
  void (*start)(const char filename[]);

  /**
   * @brief Logs an event with the specified caller and message.
   *
   * This function logs an event to the log file with the given caller name and
   * formatted message.
   *
   * @param[in] caller  The name of the function or caller logging the event.
   * @param[in] format  The format string for the event message.
   * @param[in] ...     Additional arguments to be formatted into the event
   *                    message.
   */
  void (*log)(const char caller[], const char format[], ...);

  /**
   * @brief Stops the logger and closes the log file.
   *
   * This function stops the logger by closing the log file.
   */
  void (*stop)();

  /**
   * @brief Disables the logger.
   *
   * This function disables the logger, preventing any further logging
   * operations.
   */
  void (*disable)();

  /**
   * @brief Enables the logger.
   *
   * This function enables the logger, allowing logging operations to be
   * performed.
   */
  void (*enable)();
};

/**
 * @brief The global logger instance.
 *
 * This is the global instance of the Logger struct that can be used to access
 * the logger functions.
 * The @c logger variable represents a global instance of the Logger struct,
 * which can be used to access the logging functions.
 *
 * @see @c Logger
 */
extern struct Logger logger;

#endif  // !LOGGER_H
