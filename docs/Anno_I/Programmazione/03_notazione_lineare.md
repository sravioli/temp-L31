# Notazione Lineare

Chiamiamo algoritmo un metodo risolutivo per un problema, descritto da un
insieme di operazioni elementari o istruzioni. In altre parole un algoritmo è
una sequenza finita di passi elementari che definiscono un procedimento mediante
il quale è possibile risolvere un problema. Un passo elementare è chiamato anche
operazione elementare oppure azione elementare oppure istruzione.

Una operazione si dice elementare se:

- è interpretata in modo univoco dall'esecutore;
- è direttamente eseguita dall'esecutore (uomo o macchina).

Cioè l'esecutore comprende in modo univoco che cosa deve fare e sa come farlo.

## Proprietà di un algoritmo

Un algoritmo gode necessariamente delle seguenti proprietà:

**Non ambiguità**
: ogni operazione descritta nell'algoritmo deve essere interpretata in modo
univoco dall'esecutore.

**Eseguibilità**
: l'esecutore deve essere in grado di eseguire ogni operazione descritta
nell'algoritmo in un tempo finito.

**Finitezza**
: Il numero di operazioni descritte nell'algoritmo deve essere finito e
l'esecuzione di quest'ultimo deve terminare in un tempo finito.

**Generalità**
: Deve produrre un risultato per ogni valore attribuito ai dati iniziali, cioè
un algoritmo deve risolvere tutti i problemi di una stessa classe

## Specifica di un algoritmo

In un algoritmo il risolutore descrive le operazioni necessarie per risolvere un
problema ed anche l'ordine con cui le istruzioni devono essere eseguite

In un algoritmo occorre specificare:

- L'elenco degli oggetti da manipolare (dati iniziali) e l'elenco delle
  informazioni finali (risultati)
- L'insieme delle azioni da eseguire
- L'ordine esatto con cui le azioni devono essere eseguite e le condizioni che
  devono essere verificate perché ad una azione ne segua una piuttosto che un
  altro.

Un algoritmo può essere specificato mediante:

- linguaggio naturale (pseudo-codice);
- diagrammi di flusso (descrizione grafica);
- linguaggio di programmazione (codifica).

Per specificare un algoritmo è necessario evidenziare:

- i dati di ingresso e di uscita;
- le operazioni elementari;
- l'ordine in cui le operazioni elementari devono essere eseguite.

### Linguaggio naturale

Un algoritmo viene descritto con frasi di un linguaggio naturale (italiano,
inglese). Le operazioni elementari sono descritte tramite l'utilizzo di nomi,
verbi ed espressioni. Le operazioni sono scelte in relazione al problema da
risolvere. I nomi, invece, denotano i dati.

Le strutture di controllo o schemi di composizione delle istruzioni sono
definite mediante l'utilizzo di parole chiave ben definite che vedremo in
seguito.

## Strutture di controllo

Esse hanno lo scopo di comporre le istruzioni in modo da ottenere un algoritmo,
definiscono cioè l'ordine in cui le istruzioni devono essere eseguite.

Le strutture fondamentali di controllo sono le seguenti:

- sequenza;
- selezione;
- iterazione.

### Sequenza

La sequenza permette di comporre ede eseguire le istruzioni **una di seguito**
all'altra. Le istruzioni vengono sempre eseguite nell'ordine in cui sono state
poste.

Un esempio di sequenza è il seguente:

```txt
sollevare il ricevitore
attendere il segnale di linea
comporre il numero
attendere la risposta
condurre la conversazione
deporre il ricevitore
```

Il precedente è un algoritmo per effettuare una telefonata.

Questo termina in un tempo finito? Nonostante il numero di operazioni sia finito,
l'esecuzione dell'algoritmo non termina in un tempo finito. Infatti, l'algoritmo
non specifica il caso in cui la linea sia occupata e non si possa effettuare la
chiamata o ancora, il caso in cui il numero chiamato non risponda. In questi casi
l'algoritmo non termina mai.

### Selezione binaria

La selezione binaria permette di comporre ed eseguire le istruzioni in base ad
una condizione. Se la condizione è vera, allora viene eseguita una sequenza di
istruzioni, altrimenti viene eseguita un'altra sequenza di istruzioni.

La scelta viene effettuata sulla base di un'istruzione booleana o di una
condizione[^1].

Il costrutto della selezione binaria è il seguente:

```txt linenums="0"
SE (condizione)
    ALLORA <istruzioni>
    ALTRIMENTI <istruzioni>
FINE
```

Le istruzioni che seguono la parola chiave `SE` vengono eseguite se la condizione
è vera, altrimenti vengono eseguite le istruzioni che seguono la parola chiave
`ALTRIMENTI`.

Un esempio di selezione binaria è il seguente:

```txt
SE (a < b)
    ALLORA massimo := b
    ALTRIMENTI massimo := a
FINE
```

Il precedente algoritmo determina il massimo tra due numeri interi.

### Iterazione a condizione iniziale

L'iterazione a condizione iniziale permette di comporre ed eseguire le istruzioni
ripetutamente fino a quando una condizione diventa falsa. La condizione viene
verificata prima dell'esecuzione della sequenza di istruzioni. Se la condizione
è falsa, allora le istruzioni non vengono eseguite.

Il costrutto dell'iterazione a condizione iniziale è il seguente:

```txt linenums="0"
MENTRE (<condizione>)
    <istruzioni>
FINE
```

Un esempio di iterazione a condizione iniziale è il seguente:

```txt
p := 1
massimo := p-esimo elemento di E
MENTRE (p <= n)
    p = p + 1
    SE (massimo < p-esimo elemento di E)
        ALLORA massimo := p-esimo elemento di E
    FINE
FINE
```

Il precedente algoritmo determina il massimo tra i numeri interi contenuti in un
insieme, con l'ipotesi che l'insieme non sia vuoto. Nell'algoritmo, `p` è un
contatore che indica l'elemento corrente dell'insieme, `n` è il numero di
elementi dell'insieme, `E` è l'insieme di numeri interi.

### Iterazione a condizione finale

L'iterazione a condizione finale permette di comporre ed eseguire le istruzioni
ripetutamente fino a quando una condizione diventa falsa. La condizione viene,
però, controllata dopo l'esecuzione della sequenza di istruzioni.

Il costrutto dell'iterazione a condizione finale è il seguente:

```txt linenums="0"
ESEGUI
    <istruzioni>
FINCHÉ (<condizione>)
FINE
```

## Equivalenza

Due algoritmi si dicono equivalenti se:

- hanno lo stesso dominio di definizione;
- hanno lo stesso dominio immagine;
- in corrispondenza degli stessi valori nel dominio di definizione producono gli
  stessi valori nel dominio immagine.

Dunque, due algoritmi equivalenti, nonostante possano essere diversi e avere
diversa efficienza, forniranno lo stesso risultato.

[^1]: Una condizione è un'espressione che può assumere il valore vero o falso.
