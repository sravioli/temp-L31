# Algebra Booleana

L'algebra do Bool opera su delle variabili, per l'appunto booleane, e su dei
valori costanti. I valori costanti sono due: vero e falso. Quest'ultimi possono
essere rappresentati con 1 e 0, V e F, true e false ma anche T e F.

Questi valori costanti sono detti valori booleani e sono molto utili per
le condizioni dei costrutti `SE` e `MENTRE`.

## Operatori

Per poter concatenare tra loro più condizioni si possono utilizzare gli
operatori booleani. Questi operatori sono essenzialmente dei costrutti che
operano su valori booleani e restituiscono un valore booleano. Questi operatori
sono:

- `NOT`: **negazione**, inverte il valore booleano e si scrive con il simbolo `¬`;
- `AND`: **congiunzione**, restituisce vero se entrambi i valori sono veri,
  altrimenti restituisce falso e si scrive con il simbolo `∧`;
- `OR`: **disgiunzione**, restituisce vero se almeno uno dei due valori è vero,
  altrimenti restituisce falso e si scrive con il simbolo `∨`;

|  A  |  B  | A ∧ B | A ∨ B |
| :-: | :-: | :---: | :---: |
|  V  |  V  |   V   |   V   |
|  V  |  F  |   F   |   V   |
|  F  |  V  |   F   |   V   |
|  F  |  F  |   F   |   F   |

Come è possibile constatare, l'operazione `AND` è molto più restrittiva delle
altre, infatti restituisce vero solo se entrambi i valori sono veri. L'operazione
`OR` invece è molto più permissiva, infatti restituisce vero se almeno uno dei
due valori è vero.

### Esempi

Con le variabili booleane è possibile costruire delle semplici espressioni che
restituiscono dei valori booleani, ad esempio:

```txt linenums="0"
¬B
¬(A ∨ B)
```

L'operatore `NOT` è sì utile per negare una condizione, ma è molto più comodo
e leggibile utilizzare le condizioni al "positivo", ovvero senza negare la
condizione. Ad esempio:

```txt linenums="0"
¬(a > b) = (a <= b)
```

Bisogna fare attenzione alle condizioni booleane, poiché è possibile che queste
non diventino mai false, ad esempio:

```txt linenums="0"
(a > 5 ) ∧ (a <= 10)
```

In questo caso si ha che $a \in\,]5, 10[$ e nel caso in cui fosse presente un `OR`
al posto dell'`AND` la condizione non diventerebbe mai falsa.

## Asserzioni

Le asserzioni in un linguaggio di programmazione sono delle espressioni booleane
che possono essere utilizzate per:

- documentare un programma, descrivendone la semantica;
- verificare un programma, provandone la correttezza formale.

Le asserzioni possono essere pre-condizioni e post-condizioni

La pre-condizione o premessa, è un'espressione booleana che deve essere
verificata prima di un'istruzione o di un blocco di istruzioni. La post-condizione
o conseguenza, è un'espressione booleana che deve essere verificata dopo
un'istruzione o un blocco di istruzioni.

### Esercizi

Scrivere le espressioni equivalenti alle seguenti senza utilizzare la negazione:

1. `(a > b) = (a <= b)`;
2. `((a <= b) ∧ (c <= d)) = ((a >= b) ∨ (c >= d))`;
3. `((a < 1) ∨ (b < 2) ∧ (c < 3)) = ((a > 1) ∧ (b > 2) ∨ (c > 3))`.
