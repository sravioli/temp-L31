# Problem Solving

## Il metodo di sviluppo del Software

Per sviluppare Software è necessario seguire i seguenti passaggi:

1. Specificare i requisiti del problema;
2. Analizzare il problema;
3. Progettare la sequenza di istruzioni per risolvere il problema;
4. Realizzare la sequenza di azioni;
5. Fare il test e la verifica del programma;
6. Fare la manutenzione e l'aggiornamento del programma.

Analizziamo questi passaggi in dettaglio.

### Specificare i requisiti del problema

È necessario specificare il problema in maniera non ambigua eliminando tutti gli
aspetti non importanti e specificando tutti quelli che sono necessari per
risolvere il problema.

### Analizzare il problema

L'analisi del problema è una fase fondamentale per risolvere il problema. In
questa fase si devono identificare i dati da elaborare (-in), i risultati
desiderati (-out), gli eventuali vincoli tra i dati e, infine, il formato di
presentazione dei risultati.

In questo modo si individuano i dati utili e quelli inutili, si individuano i
vincoli tra i dati e si individuano i dati che possono essere calcolati a partire
da altri dati.

### Progettare la sequenza di istruzioni per risolvere il problema

Una volta individuati i dati utili e quelli inutili, i vincoli tra i dati e i
dati che possono essere calcolati a partire da altri dati, si può procedere al
progetto della sequenza di istruzioni per risolvere il problema.

Per fare ciò è necessario individuare la sequenza di azioni da eseguire per
risolvere il problema, ovvero l'algoritmo. È inoltre necessario verificare
manualmente che l'algoritmo sia corretto.

Nello scrivere l'algoritmo è preferibile procedere in maniera Top-Down,
individuando inizialmente i passi principali e poi risolvere ognuno di questi
separatamente.

È importante non utilizzare termini ambigui e non utilizzare termini tecnici che
non siano stati definiti, come ad esempio sintassi di altri linguaggi di
programmazione.

### Realizzare la sequenza di azioni

Una volta individuato l'algoritmo, si può procedere alla realizzazione del
programma. Per fare ciò è necessario tradurre l'algoritmo in un linguaggio di
programmazione.

### Fare il test e la verifica del programma

È sicuramente l'operazione più costosa a livello di tempo e risorse. È necessario
testare il programma in modo da verificare che questo risolva il problema in
maniera corretta.

Ad esempio, un programma che calcola la somma di due numeri deve essere testato
con numeri positivi, negativi, decimali, con numeri molto grandi e con numeri
molto piccoli. È possibile dire che funzionerà con tutti i numeri? È impossibile
dirlo con certezza poiché i numeri sono infiniti; è però possibile essere certi
che il programma funzionerà nel $99.9\%$ dei casi.

Un altro esempio è il programma Microsoft PowerPoint. Quest'ultimo presenta
innumerevoli funzionalità e questo porta ad avere altrettanti problemi.

A volte questa fase può impiegare mesi per programmi molto complessi e imponenti.

### Fare la manutenzione e l'aggiornamento del programma

Una volta che il programma è stato testato, verificato e rilasciato al pubblico,
è necessario fare la manutenzione e l'aggiornamento del programma.

Ad esempio, tempo fa, i programmi di contabilità codificavano al loro interno il
valore dell'IVA. Questo comportava che ogni volta che l'IVA venisse modificata,
tutti i programmi di contabilità dovevano essere modificati.

L'alternativa sarebbe quella di lasciare che l'utenza inserisca il valore
dell'IVA e di utilizzare questo valore per calcolare i prezzi. Se invece si vuole
mantenere il pieno controllo del programma, codificarlo è l'unico modo.

## Metodi di descrizione degli algoritmi

I metodi di descrizione degli algoritmi sono molteplici e sono semplicemente
delle convenzioni. Il metodo che utilizzeremo è lo pseudo-codice. Sono presenti
anche flowchart, etc.

Lo -pseudo che utilizzeremo possiede una sintassi ben precisa e, ad esempio, non
è presente l'istruzione `goto`. È possibile inserire un numero per ogni riga ma
non è obbligatorio.

Come prima cosa bisogna elencare i dati in ingresso e in uscita.

Ogni rigo ospita un dato differente con: nome del dato, descrizione dello stesso,
tipo di dato[^1] e vincoli, in questo preciso ordine.

Il nome del dato è arbitrario, però è necessario che sia rappresentativo del dato
stesso. È possibile utilizzare lettere singole, anche se non è consigliabile[^2].

!!! example

    Ad esempio, nel convertire un numero da binario a decimale, scriveremo:

    ❌ numero binario, numero binario

    ✔️ numero binario, numero binario da convertire a decimale

In generale, la descrizione del dato deve essere più dettagliata possibile e più
lunga del nome del dato. Dopo aver scritto la descrizione è consigliabile
rileggerla circa due volte e cercare di aggiungere informazioni.

Per poter scrivere queste informazioni è necessario un minimo lavoro di analisi
poiché non è scontato che la traccia del problema fornisca tutte le informazioni
necessarie.

### Esempio: convertire da miglia a chilometri

**Problema**:

convertire da miglia a chilometri.

**Analisi**:

È necessario capire cosa fare: dobbiamo convertire dei valori da un sistema di
misura ad un altro, ovvero da miglia a chilometri. Il dato da elaborare è
quindi una distanza in miglia. Il risultato desiderato è la distanza in chilometri.

Per poter risolvere il problema è necessario conoscere la relazione esistente
tra miglia e chilometri: $1\,{\rm mi} = 1.609\,{\rm km}$.

**INPUT**
: miglio, la distanza espressa in miglia

**OUTPUT**
: chilometro, la distanza espressa in chilometri

**VINCOLI**
: $1\,{\rm mi} = 1.609\,{\rm km}$

**Progettazione**:

Un algoritmo iniziale potrebbe essere simile al seguente:

<!-- markdownlint-disable MD046 -->

```txt title="Algoritmo iniziale"
Acquisire la distanza in miglia
Convertire la distanza in chilometri
Visualizzare la distanza in chilometri
```

<!-- markdownlint-enable MD046-->

Il primo e ultimo passo non necessitano di ulteriori raffinamenti, però il
secondo passo può essere migliorato. È possibile scrivere: la distanza in
chilometri è uguale a $1.609$ volte la distanza in miglia.

<!-- markdownlint-disable MD046-->

```txt title="Algoritmo con raffinamenti"
Acquisire la distanza in miglia
Convertire la distanza in chilometri
    La distanza in chilometri è uguale a 1.609 volte la distanza in miglia
Visualizzare la distanza in chilometri
```

<!-- markdownlint-enable MD046-->

(Esercizio analisi e progettazione di come cucinare la pasta al forno)

<!-- Footnotes -->

[^1]:
    Con tipo di dato non si intendono i tipi del C o di altri linguaggi di
    programmazione, ma semplicemente il tipo di dato che si vuole utilizzare
    (numero intero, numero reale, stringa, etc.).

[^2]:
    Questo è generalmente vero, ma nei casi dei contatori è possibile utilizzare
    lettere singole.
