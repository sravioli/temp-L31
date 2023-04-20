#ifndef STRING_UTILS_PRIVATE_H
#define STRING_UTILS_PRIVATE_H

#include <wchar.h>

/**
 * @brief Concatenate a narrow character string to the given buffer.
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
 *       narrow character string. It should have enough space to accommodate the
 *       narrow character source string and its null-terminator.
 * @note The @e source is expected to be a valid pointer to a null-terminated
 *       narrow character string. The @e source string is appended to the end of
 *       the @e buffer, starting from the null-terminator of the @e buffer.
 *
 * @see @c snprintf() for string formatting.
 */
void concat_narrow(char *buffer, const char *source);

/**
 * @brief Concatenate a wide character string to the given buffer.
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
 *       wide character string. It should have enough space to accommodate the
 *       wide character source string and its null-terminator.
 * @note The @e source is expected to be a valid pointer to a null-terminated
 *       wide character string. The @e source string is appended to the end of
 *       the @e buffer, starting from the null-terminator of the @e buffer.
 *
 * @see @c snprintf() for string formatting.
 */
void concat_wide(wchar_t *buffer, const wchar_t *source);

#endif  // !STRING_UTILS_PRIVATE_H
