// Copyright (c) 2022 Simone Fidanza. All Rights Reserved.

// ESERCIZIO DEL 14/10/21
//
// Dati due insiemi di elementi I1, I1, di cardinalità rispettivamente n, m,
// scrivere un algoritmo in grado di individuare gli elementi comuni a entrambi
// gli insiemi.

#include <stdio.h>
#include <stdlib.h>
#define DIM 50

int askCard(int *c, char name);
void populateArray(int v[], int n, char name);
int calcIntersection(int v[], int w[], int intersezione[], int n, int m);
void printArray(int v[], int n, char name);

int main(void) {
  int n; // Cardinalità del primo insieme
  int m; // Cardinalità del secondo insieme
  int k; // Cardinalità dell'insieme intersezione

  int v[DIM];            // Primo insieme
  int w[DIM];            // Secondo insieme
  int intersezione[DIM]; // Insieme intersezione

  // Input
  n = askCard(&n, 'v');
  m = askCard(&m, 'w');

  // Popolamento vettori
  populateArray(v, n, 'v');
  populateArray(w, m, 'w');

  // Stampa vettori iniziali (solo per controllo)
  printArray(v, n, 'v');
  printArray(w, m, 'w');

  // Calcolo intersezione
  k = calcIntersection(v, w, intersezione, n, m);

  // stampa risultato
  printArray(intersezione, k, 'i');
}

/**
 * Richiede all'utente di inserire la cardinalità di un insieme e la restituisce
 *
 * @param c puntatore all'intero che conterrà la cardinalità dell'insieme
 * @param name nome dell'insieme
 *
 * @return il valore del puntatore c
 */
int askCard(int *c, char name) {
  printf("Inserisci la cardinalità dell'insieme %c: ", name);
  scanf("%d", c);
  return *c;
}

/**
 * Richiede all'utente di inserire n interi e li memorizza nell'array v
 *
 * @param v l'array in cui memorizzare i valori
 * @param n la dimensione dell'array v
 * @param name il nome dell'array
 */
void populateArray(int v[], int n, char name) {
  int i = 0;
  printf("Inserisci gli elementi dell'insieme %c: ", name);
  while (i < n) {
    scanf("%d", &v[i]);
    i = i + 1;
  }
}

/**
 * Calcola l'intersezione tra due insiemi e la memorizza in un terzo insieme
 *
 * @param v primo insieme di cui calcolare l'intersezione
 * @param w secondo insieme di cui calcolare l'intersezione
 * @param intersezione insieme in cui memorizzare l'intersezione
 * @param n cardinalità del primo insieme
 * @param m cardinalità del secondo insieme
 *
 * @return la cardinalità dell'insieme intersezione
 */
int calcIntersection(int v[], int w[], int intersezione[], int n, int m) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n) {
    while (j < m) {
      if (v[i] == w[j]) {
        intersezione[k] = v[i];
        k = k + 1;
      }
      j = j + 1;
    }
    i = i + 1;
    j = 0;
  }
  return k;
}

/**
 * Stampa gli elementi di un array di interi
 *
 * @param v l'array da stampare
 * @param n la dimensione dell'array
 * @param name il nome dell'array
 */
void printArray(int v[], int n, char name) {
  int i = 0;
  printf("Insieme %c = {", name);
  while (i < n) {
    if (i == n - 1) {
      printf("%d", v[i]);
    } else {
      printf("%d, ", v[i]);
    }
    i = i + 1;
  }
  printf("}\n");
}
