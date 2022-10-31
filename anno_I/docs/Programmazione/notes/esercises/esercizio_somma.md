# Esercizi

## Esercizio: somma di due numeri

Dati due numeri interi $a, b$, calcolarne la somma.

Non è possibile restituire come risultato l'espressione $a + b$.

Prendiamo ad esempio due numeri $5, 7$. Siamo in grado di sommare questi due numeri utilizzando, ad esempio, le dita della mano. Il risultato è $12$. Come è stato ottenuto questo risultato? Abbiamo incrementato di uno tante volte il primo numero quante volte è il secondo numero, ovvero $5 + 1 + \cdots + 1$. In questo caso abbiamo incrementato $5$ di uno per $7$ volte, ottenendo quindi $12$.

Abbiamo appena risolto il problema, è ora necessario descriverlo in modo tale che chiunque possa comprendere le operazioni effettuate.

```txt title="Somma di due numeri, v1"
Prendere il valore di a
Prendere il valore di b
Incrementare a di 1
Decrementare b di 1
SE b > 0 ANDARE a 3
Risultato := a
```

Questo è un metodo di risoluzione, ma il termine `ANDARE` è bandito, questo
algoritmo va riscritto diversamente.

Cosa accade nel caso in cui $a \geq 0$ e $b \geq 0$? Il valore di $a$ è ininfluente ma cambiando il valore di $b$ la soluzione sarebbe errata e restituirebbe un risultato diverso da quello atteso.

```txt title="Somma di due numeri, v2"
Prendere il valore di a
Prendere il valore di b
SE b = 0 ANDARE a 7
Incrementare a di 1
Decrementare b di 1
SE b > 0 ANDARE a 4
Risultato := a
```

Questa soluzione è corretta e funziona ma è scritta male poiché utilizza nuovamente il termine `ANDARE`. Cosa succederebbe se $b < 0$? Non otterremo un risultato.

È necessario scrivere una soluzione senza salti, tenendo conto del fatto che le
operazioni sono eseguite dall'alto verso il basso. Nel caso in cui sia necessario effettuare dei salti, questi devono essere controllati con delle condizioni.

Ogni vincolo nei dati va sempre controllato e non va mai dato per scontato.

## Esercizio: conversione da binario a decimale

Dato un numero $a_2$ in base binaria, convertirlo in $a_{10}$ in base decimale.

```txt title="Conversione da binario a decimale, v1"
Prendere la prima cifra di a₂
Moltiplicare questa per 2 elevato alla posizione della cifra
 
```

In questo caso non è possibile scrivere `TORNARE a 1` e neanche di prendere la
penultima cifra poiché non conosciamo la lunghezza del numero.

```txt title="Conversione da binario a decimale, v2"
Prendere la cifra di a₂ in posizione 0
Moltiplicare questa per 2 elevato alla posizione della cifra
TORNARE a 1
```

Questa soluzione è comunque incompleta e non risolve il problema. È necessario utilizzare un contatore che incrementi di uno ad ogni iterazione. Poiché non conosciamo la lunghezza del numero, è necessario esplicitare quest'ultima.

```txt title="Conversione da binario a decimale, v3"
p := 0
Prendere la cifra di a₂ in posizione p
Moltiplicare questa per 2ᵖ
Incrementare il valore di p di 1
TORNARE a 2
```

Nonostante l'utilizzo del contatore, questa soluzione non funziona. Quanto bisogna fermarsi? Quando terminano le cifre, ma come è possibile determinare ciò? È necessario inserire un controllo

```txt title="Conversione da binario a decimale, v4"
p := 0
Prendere la cifra di a₂ in posizione p
Moltiplicare questa per 2ᵖ
Incrementare il valore di p di 1
SE p < C ANDARE a 2
```

Dove con $C$ indichiamo la lunghezza di $a_2$.

Questa soluzione è rende l'idea di come risolvere questo problema, ma non è ancora corretta poiché è necessario sommare le cifre per ottenere il risultato finale.

```txt title="Conversione da binario a decimale, v5"
p := 0
Prendere la cifra di a₂ in posizione p
Moltiplicare questa per 2ᵖ
Sommare questo valore al risultato
Incrementare il valore di p di 1
SE p < C ANDARE a 2
```

Spesso sono necessarie delle informazioni che il problema non ci fornisce e che dobbiamo trovare noi. Se, ad esempio, sono presenti delle sequenze di simboli è necessario conoscere la lunghezza della stessa nonostante la traccia non lo espliciti.
