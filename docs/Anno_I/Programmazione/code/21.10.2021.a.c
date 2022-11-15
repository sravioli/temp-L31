// ESERCIZIO 1/2 DEL 21/10/21
//
// Leggere in input due numeri interi n, k > 0 e calcolare i primi n multipli
// di k. Realizzare l'algoritmo in pseudo-codice, considerando i controlli
// sull'input.
//
// Esempio:
// n := 3, k := 4
// i primi 3 multipli di 4 sono := {4, 8, 12}

#include <stdio.h>
#include <stdlib.h>

int getNaturalNum(int *num);
void printMult(int n, int k);

/**
 * Richiede due numeri e calcola i primi n multipli di k
 */
int main(void)
{
    int n; // numero di multipli da calcolare
    int k; // numero di cui calcolare i multipli

    // leggo n
    n = getNaturalNum(&n);
    k = getNaturalNum(&k);

    // calcolo i multipli
    printMult(n, k);
}

/**
 * Legge un numero naturale da tastiera e lo memorizza in una variabile
 *
 * @param num puntatore alla variabile in cui memorizzare il numero
 *
 * @return il numero letto
 */
int getNaturalNum(int *num)
{
    do
    {
        printf("Inserisci un numero naturale: ");
        scanf("%d", num);
    } while (*num <= 0);
}

/**
 * Stampa i primi n multipli di k
 *
 * @param n numero di multipli da calcolare
 * @param k numero di cui calcolare i multipli
 */
void printMult(int n, int k)
{
    int i = 1;

    printf("I primi %d multipli di %d sono: {", n, k);
    while (i <= n)
    {
        if (i == n)
            printf("%d", i * k);
        else
            printf("%d, ", i * k);

        i = i + 1;
    }
    printf("}\n");
}
