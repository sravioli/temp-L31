# Espressioni logiche booleane e mappe di Karnaugh

## Espressioni logiche

!!! def "Espressione Logica"

    Un'espressione logica (o funzione logica) è una qualsiasi espressione
    composta da variabili logiche, le quali possono assumere solo valori
    booleani (vero/falso) e da connettivi logici (operatori logici).

Un esempio di espressione logica è:

\[ f = \overline{AB} + \bar{A}(\bar{B} + \bar{C}\bar{D}) \]

La quale è una funzione logica in \(4\) variabili ovvero \(A\), \(B\), \(C\) e
\(D\).

L'algebra di Boole ha le seguenti proprietà:

<!-- markdownlint-disable MD013 -->
| Nome                       | Forma AND                             | Forma OR                              |
| :------------------------  | :------------------------------------ | :------------------------------------ |
| Elemento neutro            | \(1A = A\)                            | \(0 + A = A\)                         |
| Annullamento               | \(0A = 0\)                            | \(1 + A = 1\)                         |
| Idempotenza                | \(AA = A\)                            | \(A + A = A\)                         |
| Complementazione           | \(A\bar{A} = 0\)                      | \(A + \bar{A} = A\)                   |
| Proprietà commutativa      | \(AB = BA\)                           | \(A + B = B + A\)                     |
| Proprietà associativa      | \((AB)C = A(BC)\)                     | \((A + B)C = A + (B + C)\)            |
| Proprietà distributiva     | \(A + BC = (A + B)(A + C)\)           | \(A(B + C) = AB + AC\)                |
| Legge di de Morgan         | \(\overline{AB} = \bar{A} + \bar{B}\) | \(\overline{A + B} = \bar{A}\bar{B}\) |
| 1^a^ legge di assorbimento | \(A(A + B) = A\)                      | \(A + AB = A\)                        |
| 2^a^ legge di assorbimento | \(A(\bar{A} + B) = AB\)               | \(A + \bar{A}B = A + B\)              |
<!-- markdownlint-enable MD013 -->

Un'espressione logica può essere rappresentata in modo esaustivo utilizzando una
**tavola di verità**. Ciascuna espressione logica ha un suo equivalente **circuito
logico**. Ad esempio, \(A + B\bar{C}\):

\[
    \begin{array}{ ccccc|c }
        A & B & C & \bar{C} & B\bar{C} & A + B\bar{C}   \\ \hline
        0 & 0 & 0 &    1    &     0    &     0          \\
        0 & 0 & 1 &    0    &     0    &     0          \\
        0 & 1 & 0 &    1    &     1    &     1          \\
        0 & 1 & 1 &    0    &     0    &     0          \\
        1 & 0 & 0 &    1    &     0    &     1          \\
        1 & 0 & 1 &    0    &     0    &     1          \\
        1 & 1 & 0 &    1    &     1    &     1          \\
        1 & 1 & 1 &    0    &     0    &     1          \\
    \end{array}
\]

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Circuito della tabella di verità](./imgs/circuit/light-mode.svg#only-light){ width="450" loading=lazy }
  ![Circuito della tabella di verità](./imgs/circuit/dark-mode.svg#only-dark){ width="450" loading=lazy }
  <figcaption>Circuito logico corrispondente alla funzione riportata sopra</figcaption>
</figure>
<!-- markdownlint-enable MD013 MD033 -->

## Forma normale disgiuntiva e congiuntiva

!!! def "DNF"
    Un'espressione logica è detta in **forma normale disgiuntiva** (DNF o anche
    prima forma canonica) se è una disgiunzione di clausole, dove ciascuna
    clausola è una congiunzione di letterali.

Ad esempio:

\[ AB + B\bar{C} + A\bar{B}C \]

!!! def "CNF"
    Un'espressione logica è detta in **forma normale congiuntiva** (CNF o anche
    seconda forma canonica) se è una congiunzione di clausole, dove ciascuna
    clausola è una disgiunzione di letterali.

Ad esempio:

\[ (A + B)(B + \bar{C})(A + \bar{B} + C) \]

Una qualsiasi espressione logica può essere tradotta in DNF o in CNF.

### Ricostruire un'espressione logica

È immediato, avendo a disposizione una funzione logica arbitraria, ricavarne la
tavola di verità e il circuito logico corrispondente. Partendo da un circuito
logico è immediato ricostruire l'espressione corrispondente a tale circuito.

<!-- markdownlint-disable MD013 -->
!!!question "Come ricavare l'espressione logica corrispondente alla tavola di verità di una funzione logica?"

    Per raggiungere tale scopo si utilizzano diversi strumenti, tra cui:

    - la **riscrittura in somma di mintermini**;
    - la **riscrittura in prodotto di maxtermini**;
    - il **Teorema di Shannon**;
    - le **mappe di Karnaugh**.
<!-- markdownlint-enable MD013 -->

## Mintermini e maxtermini

La procedura di riscrittura in **somma di mintermini** (o somma di prodotti)
consente di ricavare l'espressione logica di una funzione booleana qualsiasi.
L'espressione risultante sarà espressa, appunto, come somma di mintermini, ovvero
sarà in **forma normale disgiuntiva**.

!!! def "Mintermine"
    Un **mintermine** (o *prodotto canonico*) è una funzione booleana che assume
    il valore ^^vero^^ in corrispondenza di un'unica configurazione di variabili
    booleane indipendenti.

In maniera perfettamente speculare,

!!! def "Maxtermine"
    Si definisce **maxtermine** (o *somma canonica*) una funzione booleana che
    assume il valore ^^falso^^ in corrispondenza di un'unica configurazione di
    variabili booleane indipendenti.

Allo stesso modo, quindi, sarà possibile riscrivere una funzione booleana
qualsiasi come **prodotto di maxtermini** (o prodotto di somme), il cui risultato
sarà in CNF. ^^*Le due scritture si equivalgono*^^.

Per ciascuna combinazione di input della tavola di verità è quindi possibile
ricavare un mintermine e un maxtermine

\[
    \begin{array}{ ccc|c|c }
        A & B & C & \text{Mintermine}     & \text{Maxtermine}           \\ \hline
        0 & 0 & 0 & \bar{A}\bar{B}\bar{C} & A + B + C                   \\
        0 & 0 & 1 & \bar{A}\bar{B}C       & A + B + \bar{C}             \\
        0 & 1 & 0 & \bar{A}B\bar{C}       & A + \bar{B} + C             \\
        0 & 1 & 1 & \bar{A}BC             & A + \bar{B} + \bar{C}       \\
        1 & 0 & 0 & A\bar{B}\bar{C}       & \bar{A} + B + C             \\
        1 & 0 & 1 & A\bar{B}C             & \bar{A} + B + \bar{C}       \\
        1 & 1 & 0 & AB\bar{C}             & \bar{A} + \bar{B} + C       \\
        1 & 1 & 1 & ABC                   & \bar{A} + \bar{B} + \bar{C} \\
    \end{array}
\]

Ciascun mintermine si ottiene come prodotto delle singole variabili booleane,
associando:

- la variabile booleana quando il valore è \(1\);
- la variabile booleana negata quando il valore è \(0\).

Ciascun maxtermine si ottiene come somma delle singole variabili booleane,
associando:

- la variabile booleana negata quando il valore è \(1\);
- la variabile booleana quando il valore è \(0\)

Ciascun mintermine è la negazione logica del relativo maxtermine (e viceversa)
a seguito dell'applicazione delle leggi di de Morgan.

È facile verificare che ciascun mintermine e ciascun maxtermine rispetta la
definizione:

- **mintermine**: *assume il valore ^^vero^^ in corrispondenza di un'unica
  configurazione di variabili booleane indipendenti*;
- **maxtermine**: *assume il valore ^^falso^^ in corrispondenza di un'unica
  configurazione di variabili booleane indipendenti*.

Ad esempio, la configurazione \(A = 0\), \(B = 1\), \(C = 0\), \(D = 1\) ha per
mintermine: \(\bar{A}B\bar{C}D\), mentre per maxtermine: \(A + \bar{B} + C + \bar{D}\).

Infatti, in corrispondenza della configurazione \(A = 0\), \(B = 1\), \(C = 0\),
\(D = 1\), si ha come mintermine: \(\bar{A}B\bar{C}D\) ovvero
\(\bar{0}1\bar{0}1 = 1111 = 1\). In tutte le altre configurazioni restituirà \(0\),
mentre come maxtermine: \(A + \bar{B} + C + \bar{D}\) ovvero
\(0 + \bar{1} + 0 + \bar{1}\) e quindi \(0 + 0 + 0 + 0 = 0\). In tutte le altre
configurazioni restituirà \(1\).

### Somma di mintermini

Una qualsiasi funzione booleana può essere scritta in somma di mintermini sommando
tutti i mintermini delle combinazioni dove la funzione assume valore \(1\). Ad
esempio:

\[
    \begin{array}{ ccc|l }
        A & B & C & f                           \\ \hline
        0 & 0 & 0 & 1 \to \bar{A}\bar{B}\bar{C} \\
        0 & 0 & 1 & 0                           \\
        0 & 1 & 0 & 1 \to \bar{A}B\bar{C}       \\
        0 & 1 & 1 & 1 \to \bar{A}BC             \\
        1 & 0 & 0 & 0                           \\
        1 & 0 & 1 & 0                           \\
        1 & 1 & 0 & 1 \to AB\bar{C}             \\
        1 & 1 & 1 & 1 \to ABC                   \\
    \end{array}
\]

Quindi.

\[ f = \bar{A}\bar{B}\bar{C} + \bar{A}B\bar{C} + \bar{A}BC + AB\bar{C} + ABC. \]

### Prodotto di maxtermini

Una qualsiasi funzione booleana può essere scritta in prodotto di maxtermini
moltiplicando tutti i maxtermini delle combinazioni dove la funzione assume
valore \(0\). Ad esempio:

\[
    \begin{array}{ ccc|l }
        A & B & C & f                           \\ \hline
        0 & 0 & 0 & 1                           \\
        0 & 0 & 1 & 0 \to A + B + \bar{C}       \\
        0 & 1 & 0 & 1                           \\
        0 & 1 & 1 & 1                           \\
        1 & 0 & 0 & 0 \to \bar{A} + B + C       \\
        1 & 0 & 1 & 0 \to \bar{A} + B + \bar{C} \\
        1 & 1 & 0 & 1                           \\
        1 & 1 & 1 & 1                           \\
    \end{array}
\]

Quindi,

\[ f = (A + B + \bar{C})(\bar{A} + B + C)(\bar{A} + B + \bar{C}). \]

La stessa funzione può essere quindi scritta, ^^equivalentemente^^, come somma
di mintermini o prodotto di maxtermini. Generalmente, la scrittura in somma di
mintermini è preferita.

L'espressione risultante, però, **non è detto che sia minima**, pertanto si deve
provare a semplificarla attraverso l'uso delle proprietà dell'algebra di Boole
mediante, quindi, dei passaggi algebrici.

Semplificare l'espressione consente dei vantaggi:

- gestione algebrica più semplice: avere meno porte significa avere un circuito
  più semplice;
- in termini di velocità: avere meno porte significa avere un circuito più
  veloce;
- in termini di costi: avere meno porte significa avere meno spese.

Ad esempio, l'espressione di prima:

\[ f = \bar{A}\bar{B}\bar{C} + \bar{A}B\bar{C} + \bar{A}BC + AB\bar{C} + ABC \]

richiede \(5\) porte AND a tre vie, \(1\) porta OR a \(5\) vie e \(7\) porte NOT.
Se fossero disponibili solo porte a due vie, servirebbero \(10\) porte AND, \(4\)
porte OR e \(7\) porte NOT.

#### Semplificazione dell'espressione

Sia dunque l'espressione logica da semplificare la seguente:

\[
    f = \bar{A}\bar{B}\bar{C}
        + \underline{\bar{A}B\bar{C} + \bar{A}BC}
        + \underline{AB\bar{C} + ABC}
\]

È innanzitutto possibile applicare la forma distributiva della forma OR e la
complementazione in forma OR. dunque:

\[
    f = \bar{A}\bar{B}\bar{C}
        + \bar{A}B\underbrace{(\bar{C} + C)}_1
        + AB\underbrace{(\bar{C} + C)}_1
\]

L'elemento neutro per l'AND è l'\(1\):

\[
    f = \bar{A}\bar{B}\bar{C} + \underline{\bar{A}B + AB}
\]

È ora possibile applicare la proprietà distributiva nella forma OR agli elementi
evidenziati e successivamente la complementazione in forma OR:

\[
    f = \bar{A}\bar{B}\bar{C} + B\underbrace{(A + \bar{A})}_1
\]

di nuovo, l'elemento neutro per l'AND è proprio l'\(1\) e dunque si può
applicare la seconda legge di assorbimento nella forma OR:

\[ f = \bar{A}\bar{C} + B \]

## Teorema di Shannon

Il teorema di Shannon[^1] consente di scomporre una funzione booleana
complessa in funzioni più semplici

!!! def "Teorema di Shannon"
    data una funzione booleana \(f\) in \(n\) variabili \(\oneton{v}\) si ha che:

    \[
        f(\oneton{v}) = v_1 \cdot f(1,\, v_2, \,\dots,\, v_n)
                        + \bar{v}_1 \cdot f(0,\, v_2, \,\dots,\, v_n)
    \]

Nel caso sopracitato il teorema è applicato rispetto alla variabile \(v_1\), ma
può essere applicato a una qualsiasi delle variabili \(\oneton{v}\).

La funzione complessa di partenza in \(n\) variabili viene trasformata in una
somma di due prodotti, aventi ciascuno una funzione in \(n − 1\) variabili (in
quanto la variabile su cui è applicato il Teorema di Shannon è già avvalorata).

[^1]: È attribuito a Shannon nonostante sia stato enunciato prima da George Boole.

Un esempio pratico di applicazione del teorema di Shannon è il seguente.

Sia \(f\) una funzione delle variabili \(A\), \(B\), \(C\), avente la seguente
tavola di verità:

\[
    \begin{array}{ ccc|c }
        A & B & C & f \\ \hline
        0 & 0 & 0 & 1 \\
        0 & 0 & 1 & 0 \\
        0 & 1 & 0 & 1 \\
        0 & 1 & 1 & 0 \\
        1 & 0 & 0 & 0 \\
        1 & 0 & 1 & 1 \\
        1 & 1 & 0 & 1 \\
        1 & 1 & 1 & 1
    \end{array}
\]

essa può essere riscritta in due funzioni più semplici, separando sulla base di
una variabile.

Ad esempio, scegliendo di separare sulla base della variabile \(B\):

\[
    \begin{array}{ ccc|c }
        A &         B        & C & f \\ \hline
        0 & {\color{green}0} & 0 & 1 \\
        0 & {\color{green}0} & 1 & 0 \\
        0 & {\color{teal}1}  & 0 & 1 \\
        0 & {\color{teal}1}  & 1 & 0 \\
        1 & {\color{green}0} & 0 & 0 \\
        1 & {\color{green}0} & 1 & 1 \\
        1 & {\color{teal}1}  & 0 & 1 \\
        1 & {\color{teal}1}  & 1 & 1
    \end{array}
        \qquad\qquad
    \begin{array}{c}
        \begin{array}{ ccc|c }
            A &        B         & C & f \\ \hline
            0 & {\color{green}0} & 0 & 1 \\
            0 & {\color{green}0} & 1 & 0 \\
            1 & {\color{green}0} & 0 & 0 \\
            1 & {\color{green}0} & 1 & 1 \\
        \end{array}     \\[1em]
        \begin{array}{ ccc|c }
            A &        B        & C & f \\ \hline
            0 & {\color{teal}1} & 0 & 1 \\
            0 & {\color{teal}1} & 1 & 0 \\
            1 & {\color{teal}1} & 0 & 1 \\
            1 & {\color{teal}1} & 1 & 1
        \end{array}
    \end{array}
\]

Si avrà allora che:

\[ f(A,\, B,\, C) = B \cdot f(A,\, 1,\, C) + \bar{B} \cdot f(A,\, 0,\, C) \]

Il funzionamento del teorema di Shannon è il seguente nel caso in cui \(B = 0\):

\[
    \begin{align}
        f(A,\, B,\, C) &= B \cdot f(A,\, 1,\, C) + \bar{B} \cdot f(A,\, 0,\, C) \\
                       &= 0 \cdot f(A,\, 1,\, C) + \bar{0} \cdot f(A,\, 0,\, C) \\
                       &= 0 + 1 \cdot f(A,\, 0,\, C)                            \\
                       &= 0 + f(A,\, 0,\, C)                                    \\
                       &= f(A,\, 0,\, C)
    \end{align}
\]

È analogo per \(B = 1\).

## Mappe di Karnaugh

La mappa di Karnaugh è uno strumento che consente di ricavare, partendo dalla
tavola di verità di una funzione logica, la sua espressione minima.

Il metodo della mappa di Karnaugh si basa sul metodo della somma di mintermini,
ma le espressioni vengono semplificate direttamente. Se il metodo viene applicato
al massimo delle sue potenzialità, ovvero scegliendo i raggruppamenti migliori,
si ricaverà l'espressione minima, altrimenti si ricaveranno delle espressioni
semplificabili.

Tale metodo è particolarmente efficace nei casi di funzioni fino a quattro
variabili, gestibile nei casi di cinque e sei variabili, difficilmente
applicabile nei casi di funzioni a più di sei variabili. Per quest'ultime si
utilizzano altri metodi che non saranno trattati in questo corso.

La mappa di Karnaugh può essere quindi utilizzata per ottimizzare un'espressione
logica o un circuito logico. La mappa di Karnaugh opera in tre fasi:

1. costruzione della o delle mappe;
2. scelta dei raggruppamenti;
3. generazione degli implicanti e dell'espressione finale.

### Costruzione della mappa

Una singola mappa di Karnaugh può essere realizzata per due, tre o quattro
variabili. La costruzione di tale mappa avviene disponendo le variabili lungo
il lato sinistro e il lato superiore di una tabella (massimo due variabili per
lato). I lati dove sono disposte due variabili verranno divisi in quattro parti,
i lati dove è disposta una sola variabile verranno divisi in due parti. La
scelta di come disporre le variabili e in quale ordine sta all'utilizzatore della
mappa ed è indifferente per il risultato.

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  <figcaption>Mappe di Karnaugh...</figcaption>
  ![Mappe di Karnaugh a 2, 3 e 4 variabili](./imgs/karnaugh/empty/dark-mode.svg#only-dark){ width="600" loading=lazy }
  ![Mappe di Karnaugh a 2, 3 e 4 variabili](./imgs/karnaugh/empty/light-mode.svg#only-light){ width="600" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Lungo i lati della mappa di Karnaugh si riportano le configurazioni:

- \(0\)-\(1\) per i lati a singola variabile;
- \(00\)-\(01\)-\(11\)-\(10\) per i lati a doppia variabile.

I valori riportati rappresentano le possibili configurazioni delle variabili.
Tali disposizioni possono essere anche scritte al contrario (\(1\)-\(0\) e
\(10\)-\(11\)-\(01\)-\(00\)).

!!! warning "Attenzione"
    La configurazione per la doppia variabile **NON** è \(00\)-\(01\)-\(10\)-\(11\),
    ma è \(00\)-\(01\)-\(11\)-\(10\). Tale codifica prende il nome di codifica
    di Gray ed è utilizzata in questo caso in maniera tale che nel passare da
    una casella all'altra cambi sempre il valore di una sola variabile.

Prendendo la tavola di verità, si riportano nella mappa di Karnaugh i valori.
È sufficiente riportare i valori per i quali la funzione assume il valore
\(1\) della funzione per ciascuna configurazione:

\[
    \begin{array}{ cccc|c }
        A & B & C & D & f \\ \hline
        0 & 0 & 0 & 0 & 0 \\
        0 & 0 & 0 & 1 & 1 \\
        0 & 0 & 1 & 0 & 1 \\
        0 & 0 & 1 & 1 & 1 \\
        0 & 1 & 0 & 0 & 0 \\
        0 & 1 & 0 & 1 & 1 \\
        0 & 1 & 1 & 0 & 0 \\
        0 & 1 & 1 & 1 & 1 \\
        1 & 0 & 0 & 0 & 0 \\
        1 & 0 & 0 & 1 & 0 \\
        1 & 0 & 1 & 0 & 1 \\
        1 & 0 & 1 & 1 & 1 \\
        1 & 1 & 0 & 0 & 1 \\
        1 & 1 & 0 & 1 & 0 \\
        1 & 1 & 1 & 0 & 0 \\
        1 & 1 & 1 & 1 & 1 \\
    \end{array}
\]

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Mappa di Karnaugh della tabella di verità precedente](./imgs/karnaugh/table/dark-mode.svg#only-dark){ loading=lazy }
  ![Mappa di Karnaugh della tabella di verità precedente](./imgs/karnaugh/table/light-mode.svg#only-light){ loading=lazy }
  <figcaption>Mappa di Karnaugh della tabella precedente</figcaption>
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Le due rappresentazioni si equivalgono.

### Scelta dei raggruppamenti

dalla mappa di Karnaugh devono essere effettuati dei raggruppamenti delle celle
dove è contenuto il valore \(1\). Tali raggruppamenti devono rispondere a tutte
le seguenti condizioni:

1. si possono raggruppare solo elementi tra celle adiacenti orizzontalmente o
   verticalmente;
2. i raggruppamenti non devono contenere celle con il valore \(0\);
3. si possono raggruppare solo elementi in rettangoli o quadrati;
4. il numero di celle di ciascun raggruppamento deve essere una potenza di \(2\);
5. tutte le celle con il valore \(1\) devono essere contenute almeno in un
   raggruppamento

I raggruppamenti di \(2^k\) elementi prendono anche il nome di \(k\)-cubi.

!!! example "Esempi di singoli raggruppamenti validi"

    <!-- markdownlint-disable MD013 MD033 -->
    <figure markdown>
      ![Quattro mappe di Karnaugh valide](./imgs/karnaugh/valid/1-dark-mode.svg#only-dark){ width="700" loading=lazy }
      ![Quattro mappe di Karnaugh valide](./imgs/karnaugh/valid/1-light-mode.svg#only-light){ width="700" loading=lazy }
    </figure>
    <!-- markdownlint-enable MD013 MD033 -->

    !!! note "Nota Bene"
        La griglia non è da considerarsi come un piano, bensì come un ^^toro^^.
        Pertanto i raggruppamenti possono attraversare i bordi della mappa, sia
        verticalmente che orizzontalmente, passando da un lato a quello opposto.

    Sono quindi dei raggruppamenti validi:

    <!-- markdownlint-disable MD013 MD033 -->
    <figure markdown>
      ![Tre mappe di Karnaugh valide, toro](./imgs/karnaugh/valid/2-dark-mode.svg#only-dark){ width="700" loading=lazy }
      ![Tre mappe di Karnaugh valide, toro](./imgs/karnaugh/valid/2-light-mode.svg#only-light){ width="700" loading=lazy }
    </figure>
    <!-- markdownlint-enable MD013 MD033 -->

    Come da figura è possibile oltrepassare il limite sia orizzontalmente, che
    verticalmente, che in entrambe le direzioni

!!! example "Esempi di singoli raggruppamenti NON validi"

    <!-- markdownlint-disable MD013 MD033 -->
    <figure markdown>
      ![Quattro mappe di Karnaugh non valide](./imgs/karnaugh/invalid/dark-mode.svg#only-dark){ width="700" loading=lazy }
      ![Quattro mappe di Karnaugh non valide](./imgs/karnaugh/invalid/light-mode.svg#only-light){ width="700" loading=lazy }
    </figure>
    <!-- markdownlint-enable MD013 MD033 -->

    In ordine:

    - il numero di elementi non è una potenza di \(2\);
    - sono prese celle non aventi il valore \(1\);
    - il raggruppamento non è né rettangolare né quadrato;
    - sono prese celle non adiacenti.

Nell'ambito della scelta dei raggruppamenti, è sempre preferibile scegliere i
raggruppamenti in maniera tale che siano sempre i più grandi possibile, anche
selezionando lo stesso valore più volte (ridondanza). La ragione verrà spiegata
in seguito.

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Raggruppamenti progressivamente migliori](./imgs/karnaugh/groups/dark-mode.svg#only-dark){ width="700" loading=lazy }
  ![Raggruppamenti progressivamente migliori](./imgs/karnaugh/groups/light-mode.svg#only-light){ width="700" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

La qualità dei raggruppamenti migliora progressivamente dal primo esempio (figura
\(\text{(a)}\)) all'ultimo (figura \(\text{(D)}\)). L'ultimo esempio è infatti
quello che ha i raggruppamenti di dimensione più grande che coprono l'intera
superficie delle celle con valore \(1\).

Non ha invece senso creare un raggruppamento ridondante se tutte le celle
interessate sono già state selezionate.

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Raggruppamento inutile vs. utile](./imgs/karnaugh/groups/useless/dark-mode.svg#only-dark){ width="700" loading=lazy }
  ![Raggruppamento inutile vs. utile](./imgs/karnaugh/groups/useless/light-mode.svg#only-light){ width="700" loading=lazy }
  <figcaption>Raggruppamento inutile (rosso)</figcaption>
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Il raggruppamento in rosso è superfluo, quindi inutile: tutte le celle del
raggruppamento sono già coperte dal quello azzurro e dal quello in verde.

### Generazione degli implicanti

L'espressione finale risultante dalla mappa di Karnaugh sarà una somma di
implicanti:

\[ f = \sumton{I} \]

**Ciascun raggruppamento individuato darà luogo a un singolo implicante.** Il
singolo termine \(I_i\), corrispondente a un \(k\)-cubo, è detto implicante in
quanto implica la funzione \(f\): se \(I_i\) è vero allora \(f\) è vero. Questo,
"se \(I_i\) è vero allora \(f\) è vero", è corretto in virtù delle proprietà
dell'OR (somma logica), cioè che una qualsiasi somma logica è vera se almeno uno
degli elementi che la compone è vero.

Ma come si generano gli implicanti a partire dai raggruppamenti?

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Implicante di un raggruppamento a singola cella](./imgs/karnaugh/implicants/1-dark-mode.svg#only-dark){ width="300" loading=lazy }
  ![Implicante di un raggruppamento a singola cella](./imgs/karnaugh/implicants/1-light-mode.svg#only-light){ width="300" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

L'implicante di un raggruppamento composto da una singola cella è equivalente al
mintermine di tale cella, in questo caso:

\[
    \begin{array}{ cccc }
        A & B & C & D \\ \hline
        0 & 1 & 1 & 1
    \end{array}
\]

Ovvero:

\[ \bar{A}BCD \]

La mappa di Karnaugh, quindi, nel caso in cui vengano scelti tutti i raggruppamenti
con celle singole, corrisponde perfettamente alla somma di mintermini:

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Implicante di tre raggruppamenti a singola cella](./imgs/karnaugh/implicants/2-dark-mode.svg#only-dark){ width="300" loading=lazy }
  ![Implicante di tre raggruppamenti a singola cella](./imgs/karnaugh/implicants/2-light-mode.svg#only-light){ width="300" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Che corrispondono, dall'alto verso il basso, a:

\[
    \begin{array}{ cccc }
        A & B & C & D \\ \hline
        1 & 0 & 0 & 0
    \end{array}
    \qquad
    \begin{array}{ cccc }
        A & B & C & D \\ \hline
        0 & 1 & 1 & 1
    \end{array}
    \qquad
    \begin{array}{ cccc }
        A & B & C & D \\ \hline
        1 & 0 & 1 & 0
    \end{array}
\]

ovvero a:

\[
    A\bar{B}\bar{C}\bar{D}
    \qquad
    \bar{A}BCD
    \qquad
    A\bar{B}C\bar{D}
\]

e dunque:

\[ f = A\bar{B}\bar{C}\bar{D} + \bar{A}BCD + A\bar{B}C\bar{D} \]

L'implicante di un raggruppamento composto da più celle è calcolato in maniera
analoga al mintermine ma utilizzando solo le variabili che mantengono un valore
costante:

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Implicante di un raggruppamento a due celle](./imgs/karnaugh/implicants/3-dark-mode.svg#only-dark){ width="300" loading=lazy }
  ![Implicante di un raggruppamento a due celle](./imgs/karnaugh/implicants/3-light-mode.svg#only-light){ width="300" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

In questo caso si ha

\[
    \begin{array}{ cccc }
        A & B & C & D \\ \hline
        0 & 1 & 1 & 1 \\
        1 & 1 & 1 & 1
    \end{array}
\]

che sarebbe \(BCD\). Questo perché:

- \(A\) varia (\(0\)-\(1\)), viene esclusa;
- \(B\) è costante (\(1\)), viene mantenuta;
- \(C\) è costante (\(1\)), viene mantenuta;
- \(D\) è costante (\(1\)), viene mantenuta.

Altri due esempi:

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Implicante di due raggruppamenti a otto e quattro celle](./imgs/karnaugh/implicants/4-dark-mode.svg#only-dark){ width="300" loading=lazy }
  ![Implicante di due raggruppamenti a otto e quattro celle](./imgs/karnaugh/implicants/4-light-mode.svg#only-light){ width="300" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Nel primo raggruppamento si ha:

\[
    \begin{array}{ cccc }
        A & B & C & D \\ \hline
        0 & 0 & 0 & 0 \\
        0 & 1 & 0 & 0 \\
        1 & 1 & 0 & 0 \\
        1 & 0 & 0 & 0 \\
        0 & 0 & 0 & 1 \\
        0 & 1 & 0 & 1 \\
        1 & 1 & 0 & 1 \\
        1 & 0 & 0 & 1
    \end{array}
\]

poiché

- \(A\) varia (\(0\)-\(1\)), viene esclusa;
- \(B\) varia (\(0\)-\(1\)), viene esclusa;
- \(C\) è costante (\(0\)), viene mantenuta;
- \(D\) varia (\(0\)-\(1\)), viene esclusa.

Nel secondo raggruppamento, invece, si ha:

\[
    \begin{array}{ cccc }
        A & B & C & D \\ \hline
        1 & 1 & 1 & 1 \\
        1 & 0 & 1 & 1 \\
        1 & 1 & 1 & 0 \\
        1 & 0 & 1 & 0
    \end{array}
\]

questo poiché:

- \(A\) è costante (\(1\)), viene mantenuta;
- \(B\) varia (\(0\)-\(1\)), viene esclusa;
- \(C\) è costante (\(1\)), viene mantenuta;
- \(D\) varia (\(0\)-\(1\)), viene esclusa.

!!! def "Implicante primo"
    Un implicante è detto implicante primo di \(f\) se non implica un altro
    implicante di \(f\). **Un implicante primo corrisponde a un \(k\)-cubo di
    dimensione massima**, ovvero un \(k\)-cubo che non è contenuto per intero
    in un \(x\)-cubo di dimensioni maggiori.

Ovvero:

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Implicante primo](./imgs/karnaugh/implicants/5-dark-mode.svg#only-dark){ width="300" loading=lazy }
  ![Implicante primo](./imgs/karnaugh/implicants/5-light-mode.svg#only-light){ width="300" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

<!-- TODO: rivedere i colori degli implicanti nel testo. -->

Gli implicanti prodotti dai raggruppamenti magenta e beige ^^**non**^^ sono
primi, in quanto sono contenuti interamente nel raggruppamento blu. Il
raggruppamento blu è un \(2\)-cubo, mentre il raggruppamento magenta e quello
beige sono \(1\)-cubi. Il raggruppamento blu genera un implicante primo,
in quanto \(k\)-cubo di dimensione maggiore.

È semplice dimostrare che gli implicanti corrispondenti ai raggruppamenti rosso
e giallo implicano quello corrispondente al raggruppamento azzurro (pertanto non
sono primi).

Siano:

\[
    {\color{blue}\bar{A}D}
    \qquad
    {\color{magenta}\bar{A}\bar{B}D}
    \qquad
    {\color{beige}\bar{A}BD}
\]

Sia \({\color{magenta}\bar{A}\bar{B}D} \implies {\color{blue}\bar{A}D}\),
ovvero che se \({\color{magenta}\bar{A}\bar{B}D}\) è vero, allora
\({\color{blue}\bar{A}D}\) è vero. Allora, per proprietà associativa,
\(\bar{A}\bar{B}D = (\bar{A}D)\bar{B}\). dalle proprietà dell'AND deriva che se
\((\bar{A}D)\bar{B}\) è vero, allora lo sono sia \(\bar{A}D\) che \(\bar{B}\).
Quindi \((\bar{A}D)\) è vero.

Sia \({\color{beige}\bar{A}BD} \implies {\color{blue}\bar{A}D}\) ovvero che se
\({\color{beige}\bar{A}BD}\) è vero allora \({\color{blue}\bar{A}D}\) è vero.
Allora, per proprietà associativa, \(\bar{A}BD = (\bar{A}D)B\). dalle proprietà
dell'AND, se \((\bar{A}D)B\) è vero, allora lo sono sia \(\bar{A}D\) che \(B\).
Quindi \(\bar{A}D\) è vero.

Infatti gli implicanti dei raggruppamenti rosso e giallo possono essere
semplificati algebricamente nell'implicante primo del raggruppamento azzurro:

\[
    {\color{magenta}\bar{A}\bar{B}D}
        + {\color{beige}\bar{A}BD} = \bar{A}D(\bar{B} + B)
                                   = \bar{A}D(1)
                                   = {\color{blue}\bar{A}D}
\]

Come già affermato in precedenza, i raggruppamenti di destra nell'esempio di
sotto sono preferibili a quelli di sinistra. Ciò perché gli implicanti dei
raggruppamenti di destra sono più semplici

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Raggruppamenti preferibili per la generazione degli implicanti](./imgs/karnaugh/implicants/6-dark-mode.svg#only-dark){ width="500" loading=lazy }
  ![Raggruppamenti preferibili per la generazione degli implicanti](./imgs/karnaugh/implicants/6-light-mode.svg#only-light){ width="500" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

e sono ricavabili algebricamente dagli implicanti dei raggruppamenti di sinistra,
scomponendo il raggruppamento azzurro nelle sue parti, applicando le proprietà e
ricomponendo il raggruppamento azzurro:

\[
    \begin{align}
        f = {\color{blue}\bar{A}D} + {\color{magenta}ABCD}
            &= {\color{blue}(\bar{A}\bar{B}\bar{C}D + \bar{A}B\bar{C}D
                + \bar{A}\bar{B}CD + \bar{A}BCD)} + \color{magenta}{ABCD}   \\
            &= \bar{A}\bar{B}\bar{C}D + \bar{A}B\bar{C}D
                + \bar{A}\bar{B}CD + \bar{A}BCD + ABCD                      \\
            &= \bar{A}\bar{B}\bar{C}D + \bar{A}\bar{B}CD
                + \bar{A}BCD + ABCD + \bar{A}BCD                            \\
            &= \bar{A}\bar{B}\bar{C}D + \bar{A}B\bar{C}D
                + \bar{A}\bar{B}CD + \bar{A}BCD + ABCD + \bar{A}BCD         \\
            &= \bar{A}\bar{B}\bar{C}D + \bar{A}B\bar{C}D
                + \bar{A}\bar{B}CD + \bar{A}BCD + BCD(A + \bar{A})          \\
            &= \bar{A}\bar{B}\bar{C}D + \bar{A}B\bar{C}D
                + \bar{A}\bar{B}CD + \bar{A}BCD + BCD(1)                    \\
            &= \bar{A}\bar{B}\bar{C}D + \bar{A}B\bar{C}D
                + \bar{A}\bar{B}CD + \bar{A}BCD + BCD                       \\
            &= {\color{blue}(\bar{A}\bar{B}\bar{C}D + \bar{A}B\bar{C}D
                + \bar{A}\bar{B}CD + \bar{A}BCD)} + {\color{green}BCD}      \\
            &= {\color{blue}\bar{A}D} + {\color{green}BCD}                  \\
            &= f'
    \end{align}
\]

\({\color{blue}\bar{A}D}\) e \({\color{green}BCD}\) sono quindi ambedue
implicanti primi (anche se hanno \({\color{red}\bar{A}BCD}\) in comune).
Infatti, l'uno non implica l'altro. Provando a dimostrare che l'uno implichi
l'altro si ha:

1. \({\color{blue}\bar{A}D} \implies {\color{green}BCD}\) ovvero che se
   \({\color{blue}\bar{A}D}\) è vero allora \({\color{green}BCD}\) è vero;
2. \({\color{green}BCD} \implies {\color{blue}\bar{A}D}\) ovvero che se
   \({\color{green}BCD}\) è vero allora \({\color{blue}\bar{A}D}\) è vero.

Allora:

1. Per proprietà associativa \(\bar{A}D = (\bar{A})(D)\). Sapendo che
   \(\bar{A}D\) è vero, allora sia \(\bar{A}\) che \(D\) sono vere. Pertanto
   \(BCD = BC1 = BC\). Si vuole quindi ora dimostrare che \(\bar{A}D \implies BC\),
   ovvero che \(1 \implies BC\), ma non vi sono elementi sulla veridicità di \(B\)
   e \(C\), pertanto l'uno non implica l'altro.
2. Per proprietà associativa \(BCD = (B)(C)(D)\). Sapendo che \(BCD\) è vero,
   allora sia \(B\) che \(C\) che \(D\) sono vere. Pertanto
   \(\bar{A}D = \bar{A}1 = \bar{A}\). Si vuole quindi ora dimostrare che
   \(BCD \implies \bar{A}\), ovvero che \(1 \implies \bar{A}\), ma non vi sono
   elementi sulla veridicità di \(A\), pertanto l'uno non implica l'altro.

### Condizioni di indifferenza

È possibile avere delle funzioni booleane nelle quali l'output della funzione
per una certa configurazione, per diverse ragioni possibili (es. è una
configurazione non ammessa), non è di interesse. Tale condizione prende il nome
di condizione di indifferenza per la specifica configurazione.

Le condizioni di indifferenza sono generalmente indicate con la lettera greca
phi \(\varphi\) (che idealmente rappresenta uno zero e un uno sovrapposti), ma
anche con \(X\), \(\delta\), \(\ast\), etc.

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Raggruppamento con una condizione di indifferenza](./imgs/karnaugh/implicants/7-dark-mode.svg#only-dark){ width="300" loading=lazy }
  ![Raggruppamento con una condizione di indifferenza](./imgs/karnaugh/implicants/7-light-mode.svg#only-light){ width="300" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Le condizioni di indifferenza rappresentano quindi un jolly: verranno considerate
se aiutano (in verde) a costituire un raggruppamento o a costituire un raggruppamento
migliore, non verranno considerate se non forniscono un contributo (in rosso).

Non hanno senso raggruppamenti di sole condizioni di indifferenza

### Dividere in più mappe

Utilizzando il Teorema di Shannon, si può dividere una qualsiasi mappa di Karnaugh
a \(n\) variabili in due mappe di Karnaugh a \(n − 1\) variabili. Ad esempio,
dividendo una mappa a \(4\) variabili \(A\), \(B\), \(C\) e \(D\) sulla base
della variabile \(C\):

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Divisione di una mappa di Karnaugh in due mappe](./imgs/karnaugh/implicants/8-dark-mode.svg#only-dark){ width="700" loading=lazy }
  ![Divisione di una mappa di Karnaugh in due mappe](./imgs/karnaugh/implicants/8-light-mode.svg#only-light){ width="700" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Agli implicanti ottenuti dalle singole mappe sarà quindi necessario moltiplicare
il termine \(C\), sulla base della mappa:

- \(C\) per la mappa con \(C = 1\);
- \(\bar{C}\) per la mappa con \(C = 0\).

Tale approccio viene applicato per utilizzare le mappe di Karnaugh con \(5\)
variabili (due mappe da \(4\) variabili) e con \(6\) variabili (quattro mappe
da \(4) variabili).

Le due mappe separate possono essere viste in maniera sovrapposta, consentendo
dei raggruppamenti cubici: si è parlato, infatti, di \(k\)-cubi (in realtà sono
parallelepipedi):

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Due mappe separate viste in maniera sovrapposta](./imgs/karnaugh/implicants/9-dark-mode.svg#only-dark){ width="700" loading=lazy }
  ![Due mappe separate viste in maniera sovrapposta](./imgs/karnaugh/implicants/9-light-mode.svg#only-light){ width="700" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Queste due mappe è come se fossero sovrapposte, formando dunque:

\[
    \begin{array}{c}
        \begin{array}{ ccccc }
            A & B & C & D & E \\ \hline
            0 & 0 & 0 & 1 & 0 \\
            0 & 1 & 0 & 1 & 0 \\
            0 & 0 & 1 & 1 & 0 \\
            0 & 1 & 1 & 1 & 0 \\ \hline
            0 & 0 & 0 & 1 & 1 \\
            0 & 1 & 0 & 1 & 1 \\
            0 & 0 & 1 & 1 & 1 \\
            0 & 1 & 1 & 1 & 1
        \end{array} \\
        {\color{magenta}\bar{A}D}
    \end{array}
%
    \qquad\qquad
%
    \begin{array}{c}
        \begin{array}{ ccccc }
            A & B & C & D & E \\ \hline
            1 & 0 & 1 & 1 & 0 \\ \hline
            1 & 0 & 1 & 1 & 1
        \end{array} \\
        {\color{yellow}A\bar{B}CD}
    \end{array}
\]

!!! note "Nota Bene"

    Quelli proposti non sono i raggruppamenti migliori, in quanto si sarebbe
    potuto operare un raggruppamento di \(4\) elementi, ovvero il raggruppamento
    giallo con \(\bar{A}\bar{B}CD\bar{E}\) e \(\bar{A}\bar{B}CDE\).

### Maxtermini

È possibile, in maniera speculare, utilizzare le mappe di Karnaugh con gli zeri,
individuando un corrispettivo speculare degli implicanti analogo ai maxtermini:

<!-- markdownlint-disable MD013 MD033 -->
<figure markdown>
  ![Mappe di Karnaugh con maxtermini anziché mintermini](./imgs/karnaugh/implicants/10-dark-mode.svg#only-dark){ width="400" loading=lazy }
  ![Mappe di Karnaugh con maxtermini anziché mintermini](./imgs/karnaugh/implicants/10-light-mode.svg#only-light){ width="400" loading=lazy }
</figure>
<!-- markdownlint-enable MD013 MD033 -->

Così si ha:

\[
    \begin{array}{ c }
        \begin{array}{ cccc }
            A & B & C & D \\ \hline
            0 & 0 & 0 & 0 \\
            0 & 1 & 0 & 0 \\
            0 & 0 & 0 & 1 \\
            0 & 1 & 0 & 1
        \end{array} \\
        {\color{blue}A + C}
    \end{array}
%
    \qquad
%
    \begin{array}{ c }
        \begin{array}{ cccc }
            A & B & C & D \\ \hline
            0 & 1 & 1 & 1 \\
            1 & 1 & 1 & 1
        \end{array} \\
        {\color{magenta}\bar{B} + \bar{C} + \bar{D}}
    \end{array}
%
    \qquad
%
    \begin{array}{ c }
        \begin{array}{ cccc }
            A & B & C & D \\ \hline
            0 & 0 & 0 & 0 \\
            0 & 0 & 0 & 1 \\
            0 & 0 & 1 & 1 \\
            0 & 0 & 1 & 0
        \end{array} \\
        {\color{green}A + B}
    \end{array}
\]

Dunque:

\[
    f = (A + C)(\bar{B} + \bar{C} + \bar{D})(A + B).
\]
