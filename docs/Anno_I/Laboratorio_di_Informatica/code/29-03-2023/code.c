// Copyright (c) 2023 Simone Fidanza. All Rights Reserved.
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN

int is_alnum(char c);
int is_space(char c);
int is_punct(char c);

void to_lower(char *str);

int str_len(char *str);
void str_copy(char *copy, char *str);
void str_invert(char *str);
int str_compare(char *str1, char *str2);

int is_palindrome(char *str);

char *read_str_from_file(char *filename);

int main(void) {
  char *string = read_str_from_file("input.txt");

  if (is_palindrome(string)) {
    printf("La stringa %s e' palindroma\n", string);
  } else {
    printf("La stringa %s non e' palindroma\n", string);
  }

  return 0;
}

/**
 * @brief Determines whether a given character is alphanumeric.
 *
 * A character is considered alphanumeric if it is a digit ('0'-'9') or a letter
 * ('a'-'z' or 'A'-'Z').
 *
 * @param c The character to be tested.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int is_alnum(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z');
}

/**
 * @brief Determines whether a given character is a whitespace character.
 *
 * A character is considered a whitespace character if it is a space (' '), tab
 * ('\t'), or newline ('\n').
 *
 * @param c The character to be tested.
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int is_space(char c) {
  if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r') || (c == '\f') ||
      (c == '\v')) {
    return 1;
  } else {
    return 0;
  }
}

/**
 * @brief Determines whether a given character is a punctuation character.
 *
 * A character is considered a punctuation character if it is any of the
 * following characters: , . - ; : _ ? ^ ' " !
 *
 * @param c The character to be tested.
 * @return 1 if the character is a punctuation character, 0 otherwise.
 */
int is_punct(char c) {
  if (c == ',' || c == '.' || c == '-' || c == ';' || c == ':' || c == '_' ||
      c == '?' || c == '^' || c == '\'' || c == '\"' || c == '!') {
    return 1;
  } else {
    return 0;
  }
}

/**
 * @brief Converts all uppercase letters in a string to lowercase.
 *
 * This function iterates over all characters in the input string and, if a
 * character is an uppercase letter, it is converted to lowercase by adding 32
 * to its ASCII value. The input string is modified in-place, so its contents
 * are changed by this function.
 *
 * @param str the input string to convert to lowercase.
 */
void to_lower(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
    i = i + 1;
  }
}

/**
 * @brief Calculates the length of a given null-terminated string.
 *
 * This function iterates through each character of the provided string
 * until it encounters the null character '\0', which signals the end of
 * the string. The number of characters that were read before the null
 * character is then returned as the length of the string.
 *
 * @param str A pointer to the first character of the string to measure.
 *               The string must be null-terminated.
 * @return The length of the string, excluding the null character.
 */
int str_len(char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len = len + 1;
  }
  return len;
}

/**
 * @brief Copies a string into a new character array
 *
 * @param copy The destination character array to copy the string to
 * @param str The source string to copy
 */
void str_copy(char *copy, char *str) {
  int i = 0;

  while (str[i] != '\0') {
    copy[i] = str[i];
    i = i + 1;
  }
  // add string terminator
  copy[i] = '\0';
}

/**
 * @brief Inverts a string in place.
 *
 * This function takes a string as input and reverses it in place, i.e. without
 * creating a new string. It uses a temporary variable to exchange characters
 * from the beginning and the end of the string, until the middle of the string
 * is reached. If the string length is an odd number, the middle character is
 * left in place as it does not need to be exchanged.
 *
 * @param str the string to be inverted.
 */
void str_invert(char *str) {
  int len = str_len(str);

  char temp;
  int i = 0;
  int j = len - 1;

  // exchange chars
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i = i + 1;
    j = j - 1;
  }
}

/**
 * @brief Compare two strings, ignoring spaces and punctuation marks.
 *
 * This function compares two strings, ignoring spaces and punctuation marks.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return     1 if the strings are equal, 0 otherwise.
 */
int str_compare(char *str1, char *str2) {
  // convert to lowercase
  to_lower(str1);
  to_lower(str2);

  int i = 0, j = 0;

  // compare characters in both strings until one of them ends
  while (str1[i] != '\0' && str2[j] != '\0') {
    // ignore spaces and punctuation marks in both strings
    if (!is_space(str1[i]) && !is_punct(str1[i])) {
      if (!is_space(str2[j]) && !is_punct(str2[j])) {
        // compare lowercase versions of characters to ignore case
        return 0;
        i = i + 1;
        j = j + 1;
      } else {
        // ignore spaces and punctuation marks in second string
        j = j + 1;
      }
    } else {
      // ignore spaces and punctuation marks in first string
      i = i + 1;
    }
  }
  // ignore any remaining spaces and punctuation marks at the end of each string
  while (is_space(str1[i]) || is_punct(str1[i])) {
    i = i + 1;
  }
  while (is_space(str2[j]) || is_punct(str2[j])) {
    j = j + 1;
  }
  // return 1 if both strings have ended (i.e. they are equal), 0 otherwise
  return (str1[i] == '\0' && str2[j] == '\0');
}

/**
 * @brief Checks if a given string is palindrome or not.
 *
 * @param string String that will be checked.
 * @return either 0 or 1.
 */
int is_palindrome(char *str) {
  // copy original str
  char copy[str_len(str) + 1];
  str_copy(copy, str);

  // invert the copy
  str_invert(copy);

  // confront them
  return str_compare(str, copy);
}

/**
 * @brief Reads a string from a text file and saves it into a char *
 *
 * @param filename the name of the file from which to read the string.
 * @return         the string that has been read.
 */
char *read_str_from_file(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Errore nell'apertura del file %s\n", filename);
    return NULL;
  }

  // allocazione della memoria per la stringa
  int size = 0;
  char c;
  while ((c = fgetc(file)) != EOF && c != '\n') {
    size = size + 1;
  }

  char *str = (char *)malloc(sizeof(char) * (size + 1));
  if (str == NULL) {
    printf("Errore nell'allocazione della memoria\n");
    fclose(file);
    return NULL;
  }

  // lettura della stringa dal file
  rewind(file);
  int i = 0;
  while ((c = fgetc(file)) != EOF && c != '\n') {
    str[i] = c;
    i = i + 1;
  }
  str[i] = '\0';

  fclose(file);
  return str;
}
