// ESERCIZIO DEL 28/10/21
//
// Letti in input due insiemi di elementi I1, I2, di cardinalità
// rispettivamente n, m, scrivere un algoritmo in grado di:
//  - individuare gli elementi comuni a entrambi gli insiemi;
//  - unire gli insiemi in un terzo insieme I3;
//  - calcolare la differenza tra I1 e I2;
//  - stampare a video i risultati.
// Considerare i controlli su dati di input.
// Realizzare come prima cosa la decomposizione funzionale.

/*
   Operazioni su insiemi
     Leggere insieme I1
       leggere cardinalità n di I1
       verificare i vincoli di n
       leggere i valori di I1
       verificare i vincoli di I1
     Leggere insieme I2
       leggere cardinalità m di I2
       verificare i vincoli di m
       leggere i valori di I2
       verificare i vincoli di I2
     Calcolare intersezione
       ricercare elemento in insieme
     Calcolare unione
       ricercare elemento in insieme
     Calcolare Differenza
       ricercare elemento in insieme
     Stampare i risultati
       stampare l'insieme intersezione
       stampare l'insieme unione
       stampare l'insieme differenza
 */

#include <stdio.h>
#include <stdlib.h>
#define DIM 50

// Dichiarazione delle funzioni
void readArray(int array[], int card);
int readCard(int *card);

int calcIntersection(int arr1[], int arr2[], int intrs[], int card1, int card2);
int calcUnion(int arr1[], int arr2[], int unn[], int card1, int card2);
int calcDifference(int arr1[], int arr2[], int diff[], int card1, int card2);

void printArray(int array[], int card);

int main(void)
{
    int card_I1;    // cardinalità dell'insieme I1
    int card_I2;    // cardinalità dell'insieme I2
    int card_intrs; // cardinalità dell'insieme intersezione
    int card_unn;   // cardinalità dell'insieme unione
    int card_diff;  // cardinalità dell'insieme differenza

    int I1[DIM];    // insieme I1 di elementi interi
    int I2[DIM];    // insieme I2 di elementi interi
    int intrs[DIM]; // insieme intersezione di elementi interi
    int unn[DIM];   // insieme unione di elementi interi
    int diff[DIM];  // insieme differenza di elementi interi

    // leggere gli insiemi I1 e I2
    card_I1 = readCard(&card_I1);
    readArray(I1, card_I1);

    card_I2 = readCard(&card_I2);
    readArray(I2, card_I2);

    // calcolare intersezione, unione e differenza | ottenere cardinalità
    card_intrs = calcIntersection(I1, I2, intrs, card_I1, card_I2);
    card_unn = calcUnion(I1, I2, unn, card_I1, card_I2);
    card_diff = calcDifference(I1, I2, diff, card_I1, card_I2);

    // stampare i risultati

    printf("I1: ");
    printArray(I1, card_I1);

    printf("I2: ");
    printArray(I2, card_I2);

    printf("Intersezione: ");
    printArray(intrs, card_intrs);

    printf("Unione: ");
    printArray(unn, card_unn);

    printf("Differenza: ");
    printArray(diff, card_diff);
}

int readCard(int *card)
{
    // finché non viene inserito un valore corretto per la cardinalità
    // continua a chiedere di inserire un valore
    do
    {
        printf("Inserire la cardinalita' dell'insieme: ");
        scanf("%d", card);
    } while (*card < 0 || *card > DIM);
    return *card;
}

void readArray(int array[], int card)
{
    // leggere i valori di un insieme
    int i = 0;
    while (i < card)
    {
        printf("Inserire l'elemento %d: ", i + 1);
        scanf("%d", &array[i]);
        i = i + 1;
    }
}

int calcIntersection(int arr1[], int arr2[], int intrs[], int card1, int card2)
{
    int i = 0;
    int j = 0;
    int k = 0;

    // per ogni elemento di arr1 verificare se è presente in arr2
    while (i < card1)
    {
        // per ogni elemento di arr2
        while (j < card2)
        {
            // se l'elemento di arr1 è presente in arr2, inserirlo in intrs
            if (arr1[i] == arr2[j])
            {
                intrs[k] = arr1[i];
                k = k + 1;
            }
            j = j + 1;
        }
        i = i + 1;
        j = 0; // ripristinare j per la prossima iterazione
    }
    // restituire la cardinalità dell'insieme intersezione
    return k;
}

int calcUnion(int arr1[], int arr2[], int unn[], int card1, int card2)
{
    // copia tutti gli elementi in unn
    int k = 0;
    while (k < card1)
    {
        unn[k] = arr1[k];
        k = k + 1;
    }

    // copia gli elementi di arr2 e controlla che non siano uguali
    int i = 0;
    int j = 0;
    while (i < card2)
    {
        while (j < k)
        {
            if (unn[j] == arr2[i])
                break;

            j = j + 1;
        }
        if (j == k)
        {
            unn[k] = arr2[i];
            k = k + 1;
        }
        i = i + 1;
    }
    return k;
}

int calcDifference(int arr1[], int arr2[], int diff[], int card1, int card2)
{
    // trova gli elementi di arr1 che non sono presenti in arr2
    int i = 0;
    int j = 0;
    int k = 0;

    // per ogni elemento di arr1
    while (i < card1)
    {
        // controlla se è presente in arr2
        while (j < card2)
        {
            // se è presente, passa al prossimo elemento di arr1
            if (arr1[i] == arr2[j])
                break;

            j = j + 1;
        }
        // se non è presente, lo aggiunge a diff
        if (j == card2)
        {
            diff[k] = arr1[i];
            k = k + 1;
        }
        i = i + 1;
        j = 0;
    }
    // restituisce la cardinalità di diff
    return k;
}

void printArray(int array[], int card)
{
    int i = 0;

    printf("{");
    while (i < card)
    {
        if (i == card - 1)
            printf("%d", array[i]);
        else
            printf("%d, ", array[i]);
        i = i + 1;
    }
    printf("}\n");
}
