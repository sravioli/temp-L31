#ifndef STRING_UTILS_H_
#define STRING_UTILS_H_

/**
 * @brief Concatenate a source string to the given buffer.
 *
 * This function appends the contents of the given @e source string to the end
 * of the given @e buffer, effectively concatenating them. The @e buffer is
 * updated in-place.
 *
 * @param[in,out] buffer Pointer to the buffer to concatenate to.
 * @param[in]     source Pointer to the source string to append.
 *
 * @return void.
 *
 * @warning This function does not perform any size checking or memory
 *          allocation! It is responsibility of the caller to ensure that the
 *          @e buffer has enough space for the concatenated string.
 *
 * @note The @e buffer is espected to be a valid pointer to a null-terminated
 *       string. It should have enough space to accommodate the source string
 *       and its null-terminator.
 * @note The @e source parameter is expected to be a valid pointer to a
 *       null-terminated string. The @e source string is appended to the end of
 *       the @e buffer, starting from the null-terminator of the @e buffer.
 *
 * @see @c snprintf() for string formatting.
 */
// void concat(char *buffer, const char *source);
void concat(void *buffer, const void *source);

/**
 * @brief Concatenate a source string to the given buffer "n" times.
 *
 * This function appends the contents of the @e source string to the end of the
 * given @e buffer multiple times, as specified by the @c n_times parameter. The
 * @e buffer is updated in-place.
 *
 * @param[in,out] buffer  Pointer to the buffer to concatenate to.
 * @param[in]     source  Pointer to the source string to append.
 * @param[in]     n_times Number of times to concatenate the source string to
 *                        the buffer.
 *
 * @return void.
 *
 * @warning This function does not perform any size checking or memory
 *          allocation! It is responsibility of the caller to ensure that the
 *          @e buffer has enough space for the concatenated string.
 *
 * @note The @e buffer parameter is expected to be a valid pointer to a
 *       null-terminated string. It should have enough space to accommodate the
 *       concatenated strings and their null-terminators.
 * @note The @e source parameter is expected to be a valid pointer to a
 *       null-terminated string.
 *
 * @see @c snprintf() for string formatting.
 */
void nconcat(char *buffer, const char *source, const int n_times);

/**
 * @brief Concatenate a formatted string to the given buffer.
 *
 * This function append the given formatted string to the end of the @e buffer,
 * using the provide format specifier and a <em>variable argument list</em>. The
 * @e buffer is updated in-place.
 *
 * @param[in,out] buffer      Pointer to the buffer to concatenate to.
 * @param[in]     source_size Maximum size of the source string to be formatted
 *                            and concatenated.
 * @param[in]     format      Format specifier string.
 * @param[in]     va_list     Variable argument list to be formatted.
 *
 * @return void.
 *
 * @warning This function does not perform any size checking or memory
 *          allocation! It is the responsibility of the caller to ensure that
 *          the @e buffer has enough space for the formatted string.
 * @note The @e buffer parameter is expected to be a valid pointer to a
 *       null-terminated string and to have enough space to accommodate the
 *       formatted string and its null-terminator.
 * @note The @e source_size parameter specifies the maximum size of the source
 *       string that can be formatted and concatenated to the @e buffer.
 * @note The @e format parameter is expected to be a valid format specifier
 *       string according to the rules of the C @c printf() function.
 * @note The <em>variable argument list</em> should correspond to the format
 *       specifier string and provide the values to be formatted.
 *
 * @see @c snprintf() for string formatting.
 * @see @c vsnprintf() for string formatting with a variable argument list.
 */
void fconcat(char *buffer, const int source_size, const char *format, ...);

/**
 * @brief Allocates memory for a character buffer with null-termination.
 *
 * This function dynamically allocates memory for a character buffer with
 * null-termination. The size of the buffer is determined by the given size
 * parameter and the length of the input character s. The resulting buffer will
 * be null-terminated.
 *
 * @param[in] s Pointer to the input string to be copied.
 * @param[in] size Size of the allocated memory for the copied string.
 *
 * @return Pointer to the dynamically allocated memory containing the copied
 *         string.
 *
 * @attention The size of the allocated buffer is determined by the size
 *            parameter multiplied by the length of the input character s. It
 *            is important to ensure that the resulting buffer is not too
 *            large to prevent memory overflow.
 * @note The input string s should be a valid null-terminated string.
 * @note The size parameter specifies the size of the allocated memory for the
 *       copied string, including space for the null terminator.
 * @note The returned pointer points to the dynamically allocated memory and
 *       should be freed by the caller when no longer needed to avoid memory
 *       leaks.
 * @note If the memory allocation fails, an error message is printed and the
 *       program exits with a failure status code.
 *
 * @see `malloc()` for memory allocation.
 * @see `free()` for deallocating memory.
 */
char *alloc_char(const char *c, const int size);

#endif  // !STRING_UTILS_H_
