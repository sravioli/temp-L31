// Copyright (c) 2023 Simone Fidanza. All Rights Reserved.
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN

int is_alphanumeric(char c);
char *read_str_from_file(char *filename);
int is_palindrome(char *string);
int str_length(char *string);
void str_invert(char *string);
void str_copy(char *copy, char *str_to_copy);
int str_compare(char *first_str, char *second_str);
void to_lowercase(char *string);

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
 * @brief Determines if the given char is alphanumeric or not.
 *
 * @param c  char to check if is alphanumeric
 * @return   either 0 or 1.
 */
int is_alphanumeric(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z');
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

  char *string = (char *)malloc(sizeof(char) * (size + 1));
  if (string == NULL) {
    printf("Errore nell'allocazione della memoria\n");
    fclose(file);
    return NULL;
  }

  // lettura della stringa dal file
  rewind(file);
  int i = 0;
  while ((c = fgetc(file)) != EOF && c != '\n') {
    string[i] = c;
    i = i + 1;
  }
  string[i] = '\0';

  fclose(file);
  return string;
}

/**
 * @brief Finds the lenght of a given string.
 *
 * @param string the string of which to find the lenght.
 * @return       the length of the string.
 */
int str_length(char *string) {
  int len = 0; // lunghezza della stringa, utilizzato come contatore
  while (string[len] != '\0') {
    len = len + 1;
  }
  return len;
}

/**
 * @brief Inverts the given string (hello --> olleh)
 *
 * @param string The string that will be inverted.
 */
void str_invert(char *string) {
  // calcola la lunghezza della stringa
  int len = str_length(string);

  // Variabili per scambiare i caratteri
  char temp;       // variabile temporanea utilizzata nello scambio
  int i = 0;       // contatore intero
  int j = len - 1; // contatore intero che parte dalla lunghezza della stringa

  // inverti la stringa scambiando i caratteri
  while (i < j) {
    temp = string[i];
    string[i] = string[j];
    string[j] = temp;
    i = i + 1;
    j = j - 1;
  }
}

/**
 * @brief Copies a string into another.
 *
 * @param dest The string that will recieve the copy.
 * @param src The string to copy.
 */
void str_copy(char *dest, char *src) {
  // Copiamo il valore della stringa src nella stringa dest
  int i = 0; // contatore
  while (src[i] != '\0') {
    dest[i] = src[i];
    i = i + 1;
  }
  // Aggiungiamo il terminatore di stringa
  dest[i] = '\0';
}

/**
 * @brief Converts all string chars into lowercase.
 *
 * @param string the string that will be converted.
 */
void to_lowercase(char *string) {
  // converti tutti i caratteri della stringa in minuscolo
  int i = 0; // contatore
  while (string[i] != '\0') {
    if (string[i] >= 'A' && string[i] <= 'Z') {
      string[i] = string[i] + 32;
    }
    i = i + 1;
  }
}

/**
 * @brief Compares two given strings, that is checks if they are equal.
 *
 * @param str1 First string to compare.
 * @param str2 second string to compare.
 * @return either 0 or 1.
 */
int str_compare(char *str1, char *str2) {
  // Convertiamo tutte le lettere in minuscolo
  to_lowercase(str1);
  to_lowercase(str2);

  // Verifichiamo se le stringhe sono uguali carattere per carattere
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return 0;
    }
    i = i + 1;
  }
  if (str1[i] != '\0' || str2[i] != '\0') {
    return 0;
  }
  return 1;
}

/**
 * @brief Checks if a given string is palindrome or not.
 *
 * @param string String that will be checked.
 * @return either 0 or 1.
 */
int is_palindrome(char *string) {
  // copia della stringa originale
  char copy[str_length(string) + 1];
  str_copy(copy, string);

  // invertiamo la copia della stringa
  str_invert(copy);

  // confrontiamo la stringa originale con la sua copia invertita
  return str_compare(string, copy);
}
