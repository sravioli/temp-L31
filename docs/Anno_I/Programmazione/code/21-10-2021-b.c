// ESERCIZIO 2/2 DEL 21/10/21
//
// Leggere in input due interi n,k > 0 e verificare se n sia divisibile per k.
// Realizzare l'algoritmo in pseudo-codice, considerando i controlli sull'input.
//
// Esempio:
// n := 4, k := 2
// 4 è divisibile per 2
//
// n := 5, k := 2
// 5 non è divisibile per 2

#include <stdio.h>
#include <stdlib.h>

int getNaturalNum(int *num);
void isDivisible(int n, int k);

int main(void)
{
    int n; // numero da verificare
    int k; // numero per cui verificare la divisibilità

    // leggo n
    n = getNaturalNum(&n);
    k = getNaturalNum(&k);

    // verifico se n è divisibile per k
    isDivisible(n, k);
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
 * Verifica se n è divisibile per k
 *
 * @param n numero da verificare
 * @param k numero per cui verificare la divisibilità
 */
void isDivisible(int n, int k)
{
    int i = n;

    while (i >= k)
        i = i - k;

    if (i == 0)
        printf("%d divisibile per %d", n, k);
    else
        printf("%d non divisibile per %d", n, k);
}
