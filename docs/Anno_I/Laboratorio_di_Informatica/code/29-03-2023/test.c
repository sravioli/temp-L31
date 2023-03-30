#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_alnum(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z');
}

void test_is_alnum() {
  printf("Testing is_alnum...\n");
  printf("is_alnum('a') == %d\n", is_alnum('a')); // 1
  printf("is_alnum('A') == %d\n", is_alnum('A')); // 1
  printf("is_alnum('5') == %d\n", is_alnum('5')); // 1
  printf("is_alnum('$') == %d\n", is_alnum('$')); // 0
}

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

  char *stringa = (char *)malloc(sizeof(char) * (size + 1));
  if (stringa == NULL) {
    printf("Errore nell'allocazione della memoria\n");
    fclose(file);
    return NULL;
  }

  // lettura della stringa dal file
  rewind(file);
  int i = 0;
  while ((c = fgetc(file)) != EOF && c != '\n') {
    stringa[i] = c;
    i = i + 1;
  }
  stringa[i] = '\0';

  fclose(file);
  return stringa;
}

void test_read_str_from_file() {
  printf("Testing read_str_from_file...\n");
  char *stringa = read_str_from_file("test.txt");
  if (stringa == NULL) {
    printf("Errore: read_str_from_file restituisce NULL\n");
    return;
  }
  printf("read_str_from_file(\"test.txt\") == \"%s\"\n", stringa); // "ciao"
  free(stringa);
}

int str_len(char *str) {
  int len = 0; // lunghezza della stringa, utilizzato come contatore
  while (str[len] != '\0') {
    len = len + 1;
  }
  return len;
}

void test_str_len() {
  char stringhe_test[][100] = {
      "",
      "a",
      "ciao",
      "1234",
      "una stringa di lunghezza 32",
      "0123456789ABCDEF0123456789ABCDEF",
      "Questa è una stringa un po' più lunga che occupa 60 caratteri"};
  int risultati_attesi[] = {0, 1, 4, 4, 32, 32, 60};
  int num_test = sizeof(stringhe_test) / sizeof(stringhe_test[0]);

  int i = 0;
  while (i < num_test) {
    int risultato = str_len(stringhe_test[i]);
    if (risultato == risultati_attesi[i]) {
      printf("Test %d PASS\n", i + 1);
    } else {
      printf("Test %d FAIL: risultato atteso %d, risultato ottenuto %d\n",
             i + 1, risultati_attesi[i], risultato);
    }
    i = i + 1;
  }
}

void str_invert(char *str) {
  // calcola la lunghezza della stringa
  int len = str_len(str);

  // Variabili per scambiare i caratteri
  char temp;       // variabile temporanea utilizzata nello scambio
  int i = 0;       // contatore intero
  int j = len - 1; // contatore intero che parte dalla lunghezza della stringa

  // inverti la stringa scambiando i caratteri
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i = i + 1;
    j = j - 1;
  }
}

void test_str_invert() {
  char stringhe_test[][100] = {"ciao", "12345", "a",
                               "",     "pippo", "hello world"};
  char risultati_attesi[][100] = {"oaic", "54321", "a",
                                  "",     "oppip", "dlrow olleh"};
  int num_test = sizeof(stringhe_test) / sizeof(stringhe_test[0]);

  int i = 0;
  while (i < num_test) {
    char str[100];
    strcpy(str, stringhe_test[i]);
    str_invert(str);
    if (strcmp(str, risultati_attesi[i]) == 0) {
      printf("Test %d PASS\n", i + 1);
    } else {
      printf("Test %d FAIL: risultato atteso %s, risultato ottenuto %s\n",
             i + 1, risultati_attesi[i], str);
    }
    i = i + 1;
  }
}

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

void test_str_copy() {
  char src[][100] = {"ciao",
                     "prova",
                     "questa è una stringa",
                     "1234",
                     "",
                     "La vecchia scuola",
                     "questa STRINGA ha MAIusCOLE",
                     "LoVeLy",
                     "OriiGinALE",
                     "Questa è l'ultima stringa di test"};

  int num_test = sizeof(src) / sizeof(src[0]);

  int i = 0;
  while (i < num_test) {
    char dest[100];
    str_copy(dest, src[i]);

    if (strcmp(dest, src[i]) == 0) {
      printf("Test %d PASS\n", i + 1);
    } else {
      printf("Test %d FAIL: risultato atteso '%s', risultato ottenuto '%s'\n",
             i + 1, src[i], dest);
    }
    i = i + 1;
  }
}

void to_lowercase(char *str) {
  // converti tutti i caratteri della stringa in minuscolo
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
    i = i + 1;
  }
}

void test_to_lowercase() {
  char stringhe_test[][100] = {"Ciao",  "CaRPe",   "zucchero",       "",
                               "12345", "L'AMORE", "teST Delle caSE"};
  char risultati_attesi[][100] = {"ciao",  "carpe",   "zucchero",       "",
                                  "12345", "l'amore", "test delle case"};
  int num_test = sizeof(stringhe_test) / sizeof(stringhe_test[0]);

  int i = 0;
  while (i < num_test) {
    to_lowercase(stringhe_test[i]);
    if (strcmp(stringhe_test[i], risultati_attesi[i]) == 0) {
      printf("Test %d PASS\n", i + 1);
    } else {
      printf("Test %d FAIL: risultato atteso %s, risultato ottenuto %s\n",
             i + 1, risultati_attesi[i], stringhe_test[i]);
    }
    i = i + 1;
  }
}

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

void test_str_compare() {
  char str1[][100] = {"ciao", "Questa e' una STRINGA", "12345", "", "abcde"};
  char str2[][100] = {"ciao", "Questa e' una stringa", "12345", "", "abcde"};
  int risultati_attesi[] = {1, 1, 1, 1, 1};
  int num_test = sizeof(str1) / sizeof(str1[0]);

  int i = 0;
  while (i < num_test) {
    int risultato = str_compare(str1[i], str2[i]);
    if (risultato == risultati_attesi[i]) {
      printf("Test %d PASS\n", i + 1);
    } else {
      printf("Test %d FAIL: risultato atteso %d, risultato ottenuto %d\n",
             i + 1, risultati_attesi[i], risultato);
    }
    i = i + 1;
  }
}

int is_palindroma(char *str) {
  // copia della stringa originale
  char copia[str_len(str) + 1];
  str_copy(copia, str);

  // invertiamo la copia della stringa
  str_invert(copia);

  // confrontiamo la stringa originale con la sua copia invertita
  return str_compare(str, copia);
}

void test_is_palindroma() {
  char stringhe_test[][100] = {"anna",
                               "AnNa",
                               "ciao",
                               "",
                               "a",
                               "bb",
                               "cCc",
                               "casa",
                               "itopinonavevanonipoti",
                               "radar",
                               "Amore, Roma",
                               "Ai lati d'italia",
                               "I topi non avevano nipoti",
                               "Una volpe rapì Topo Ton",
                               "I denti, amici, e le labbra, nemici",
                               "A man, a plan, a canal, Panama"};
  int risultati_attesi[] = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int num_test = sizeof(stringhe_test) / sizeof(stringhe_test[0]);

  int i = 0;
  while (i < num_test) {
    int risultato = is_palindroma(stringhe_test[i]);
    if (risultato == risultati_attesi[i]) {
      printf("Test %d PASS\n", i + 1);
    } else {
      printf("Test %d FAIL: risultato atteso %d, risultato ottenuto %d\n",
             i + 1, risultati_attesi[i], risultato);
    }
    i = i + 1;
  }
}

int main(void) {
  test_is_alnum();
  test_is_palindroma();
  test_str_copy();
  test_str_invert();
  test_str_compare();
  test_str_len();
  test_to_lowercase();
  test_read_str_from_file();
  return 0;
}
