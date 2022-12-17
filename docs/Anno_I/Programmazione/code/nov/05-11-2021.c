// ESERCIZIO DEL 05/11/2021
//
// Dati due elenchi di numeri interi, E1 ed E2, realizzare un algoritmo in grado
// di:
// - leggere i due elenchi di numeri da tastiera
// - Calcolare la somma di ogni elemento corrispondente di E1 ed E2
// - Calcolare la sottrazione di ogni elemento corrispondente di E1 ed E2
// - Calcolare il massimo di E1 ed E2
// - Stampare i risultati

#include <stdio.h>
#include <stdlib.h>
#define DIM 50

int getCard(int *c, char *name);
void populateArray(int *array, int c, char *name);

int calculateSum(int *arrSum, int *array1, int *array2, int c1, int c2);
int calculateDiff(int *arrDiff, int *array1, int *array2, int c1, int c2);
int calculateMax(int *array, int c);

void printResults(int *arrSum, int cSum, int *arrDiff, int cDiff, int max1,
                  int max2);

int main(void) {
  int card1; // cardinalità del primo array
  int card2; // cardinalità del secondo array

  int cSum;  // cardinalità dell'array contenente la somma di ogni elemento
             // corrispondente di E1 ed E2
  int cDiff; // cardinalità dell'array contenente la sottrazione di ogni
             // elemento

  int array1[DIM]; // primo array di numeri interi
  int array2[DIM]; // secondo array di numeri interi

  int sum[DIM];  // array contenente la somma di ogni elemento corrispondente
                 // di E1 ed E2
  int diff[DIM]; // array contenente la sottrazione di ogni elemento
                 // corrispondente di E1 ed E2
  int max1;      // massimo di E1
  int max2;      // massimo di E2

  // chiede all'utente di inserire la cardinalità dei due array
  card1 = getCard(&card1, "E1");
  card2 = getCard(&card2, "E2");
  // printf("%d %d", card1, card2); // debug

  // popola i due array con i valori inseriti dall'utente
  populateArray(array1, card1, "E1");
  populateArray(array2, card2, "E2");

  // calcola la somma di ogni elemento corrispondente di E1 ed E2
  cSum = calculateSum(sum, array1, array2, card1, card2);
  // calcola la sottrazione di ogni elemento corrispondente di E1 ed E2
  cDiff = calculateDiff(diff, array1, array2, card1, card2);

  // calcola il massimo di E1 ed E2
  max1 = calculateMax(array1, card1);
  max2 = calculateMax(array2, card2);

  // stampa i risultati
  printResults(sum, cSum, diff, cDiff, max1, max2);
}

int getCard(int *c, char *name) {
  do {
    printf_s("Inserisci la cardinalità di %s: ", name);
    scanf_s("%d", c);
  } while (*c < 0 || *c > DIM);

  return *c;
}

void populateArray(int *array, int c, char *name) {
  int i = 0;
  while (i < c) {
    printf_s("Inserisci il valore %d di %s: ", i + 1, name);
    scanf_s("%d", &array[i]);
    i = i + 1;
  }
  return;
}

int calculateSum(int *arrSum, int *array1, int *array2, int c1, int c2) {
  int i = 0;
  while (i < c1 && i < c2) {
    arrSum[i] = array1[i] + array2[i];
    i = i + 1;
  }

  return i;
}

int calculateDiff(int *arrDiff, int *array1, int *array2, int c1, int c2) {
  int i = 0;
  while (i < c1 && i < c2) {
    arrDiff[i] = array1[i] - array2[i];
    i = i + 1;
  }

  return i;
}

int calculateMax(int *array, int c) {
  int i = 0;
  int max = array[0];
  while (i < c) {
    if (array[i] > max) {
      max = array[i];
    }
    i = i + 1;
  }
  return max;
}

void printResults(int *arrSum, int cSum, int *arrDiff, int cDiff, int max1,
                  int max2) {
  int i = 0;
  printf_s("Somma: { ");
  while (i < cSum) {
    printf_s("%d ", arrSum[i]);
    i = i + 1;
  }
  printf_s("}\n");

  i = 0;
  printf_s("Differenza: { ");
  while (i < cDiff) {
    printf_s("%d ", arrDiff[i]);
    i = i + 1;
  }
  printf_s("}\n");
  printf_s("Massimo di E1: %d\n", max1);
  printf_s("Massimo di E2: %d\n", max2);

  return;
}
