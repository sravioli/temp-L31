# Grammatiche e Linguaggi

## Linguaggi formali e Monoidi liberi

Il concetto di *linguaggio formale* è strettamente correlato a quello di
*monoide libero* (generato da un insieme).

## Definizioni

### Alfabeto

Un insieme \(X\) finito e non vuoto di simboli è un *alfabeto*.

!!! example "Esempi"

    - L'alfabeto latino, con l'aggiunta dei simboli di interpunzione e dello
      spazio bianco: \(a\) \(b\; \ldots\; z\) \(;\) \(,\) \(.\) \(:\);
    - L'insieme delle dieci cifre arabe \(0\) \(1\; \dots\; 9\).

Con i simbolil primitivi dell'alfabeto si formano le parole (es. \(abc\),
\(127\), \(casa\), etc.).

### Parole o stringhe

Una sequenza finita di simboli \(x_1\, x_2 \dots x_n\), dove ogni \(x_i\) è preso
da uno stesso alfabeto \(X\) è una **parola** su \(X\).

!!! example "Esempi"

    - \(X = \set{0,\ 1}\);
    - \(001110\) è una parola su \(X\);

Una parola è ottenuta giustapponendo o concatenando simboli (caratteri)
dell'alfabeto. Se una stringa ha \(m\) simboli non necessariamente distinti,
allora diciamo che ha lunghezza \(m\).

### Lunghezza di una parola o stringa

La lunghezza di una stringa \(w\) è denotata con \(\abs{w}\). Le parole di
lunghezza \(1\) sono i simboli di \(X\). Quindi \(001110\) è una parola di
lunghezza \(6\):

\[ \abs{001110} = 6 \]

La parola vuota (o stringa vuota), denotata con \(\lambda\), è una stringa priva
di simboli e ha lunghezza \(0\):

\[ \abs{\lambda} = 0 \]

### Uguaglianza tra stringhe

Due stringhe sono uguali se i loro caratteri, letti ordinatamente da sinistra a
destra, coincidono.

### \(X^\ast\)

L'insieme di tutte le stringhe di lunghezza finita sull'alfabeto \(X\) si denota
con \(X^\ast\).

!!! example "Esempio"

    Se \(X = \set{0,\ 1}\), allora
    \(X^\ast = \set{\lambda,\ 0,\ 1,\ 00,\ 01,\ 10,\ 11, \dots}\).

L'insieme \(X^\ast\) ha un numero di elementi che è un infinito numerabile. Dalla
definizione, segue che \(\lambda \in X^\ast\) per ogni insieme \(X\).

### Concatenazione o prodotto

Siano \(\alpha,\, \beta \in X^\ast\) due stringhe di lunghezza rispettivamente
\(m,\, n\). La concatenazione di \(\alpha\) e \(\beta\), denotata con
\(\alpha\beta\) o \(\alpha \cdot \beta\), è definita come la stringa di lunghezza
\(m + n\), i cui primi \(m\) simboli sono gli stessi di quelli di \(\alpha\) e
gli ultimi \(n\) simboli sono gli stessi di \(\beta\).

Quindi se \(\alpha = x_1\,x_2 \dots x_m\) e \(\beta = y_1\,y_2 \dots y_n\), si ha:

\[ \alpha\beta = x_1\,x_2 \dots x_m\,y_1\,y_2 \dots y_n \]

### Operazione di concatenazione

La concatenazione di stringhe su \(X\) è una operazione binaria su \(X^\ast\):

\[ \cdot : X^\ast \times X^\ast \to X^\ast \]

- è associativa, infatti:
  \((\alpha\beta)\gamma = \alpha(\beta\gamma) = \alpha\beta\gamma\),
  \(\;\forall \alpha,\beta,\gamma \in X^\ast\);
- non è commutativa, infatti:
  \(\exists \alpha,\beta \in X^\ast \tc \alpha\beta \neq \beta\alpha\);
- ha elemento neutro \(\lambda\): \(\lambda\alpha = \alpha\lambda = \alpha\),
  \(\;\forall \alpha \in X^\ast\).

Dunque \((X^\ast,\ \cdot)\) è un monoide non commutativo.

### Prefisso, suffisso

Se \(\lambda \in X^\ast\) è della forma \(\gamma = \alpha\beta\), dove
\(\alpha,\,\beta \in X^\ast\), allora \(\alpha\) è un prefisso di \(\gamma\) e
\(\beta\) è un suffisso di \(\gamma\).

### Sottostringa

Se \(\delta,\,\beta \in X^\ast\), con \(\delta\) della forma
\(\delta = \alpha\beta\gamma\), dove \(\alpha,\beta,\gamma \in X^\ast\) allora
\(\beta\) è una sottostringa di \(\delta\).

!!! example "Esempio"

    Sia \(\gamma = 001100\), allora:

    - \(\set{\lambda,\ 0,\ 00,\ 001,\ 0011,\ \gamma}\) è l'insieme dei prefissi
      di \(\gamma\);
    - \(\set{\lambda,\ 0,\ 10,\ 110,\ 0110,\ \gamma}\) è l'insieme dei suffissi
      di \(\gamma\);
    - \(\set{
        \lambda,\ 0,\ 1,\ 00,\ 01,\ 10,\ 11,\ 001,\ 011,\ 110,\ 0011,\ 0110,\
        \gamma}
      \) è l'insieme delle sottostringhe di \(\gamma\).

### Potenza di una stringa

Data una stringa \(\alpha\) su \(X\), la potenza \(h\)-esima di \(\alpha\) è
definita induttivamente come segue:

\[
\alpha^h =  \begin{cases}
                \lambda             &\text{se } h = 0 \\
                \alpha\alpha^{h-1}  &\text{altrimenti}
            \end{cases} \quad
\forall h \in \N
\]

La potenza \(h\)-esima di una stringa è un caso speciale di concatenamento (in
quanto la si ottiene concatenando una stringa \(h\) volte con se stessa).

### Potenza di un alfabeto

Sia \(X\) un alfabeto, poniamo:

1. \(X^1 = X\);
2. \(X^2 = \set{x_1\,x_2 \mid x_1,x_2 \in X, \quad x_1\,x_2 \equiv x_1 \cdot x_2}\);
3. \(X^3 = \set{
        x_1\,x_2\,x_3 \mid x_1,x_2 \in X,\; x_3 \in X, \quad
        x_1 x_2 x_3 \equiv x_1 x_2 \cdot x_3}
   \);

si ha dunque:

\[
X^i = \set{
    x_1\,x_2 \dots x_{i-1}\, x_i \mid x_1\,x_2 \dots x_{i-1} \in X^{i-1},\,
    x_i \in X, \quad
    x_1\,x_2 \dots x_i \equiv x_1\,x_2 \dots x_{i-1} \cdot x_i}
\]

Se \(i \geq 2\) si ha:

\[ X^+ = X \cup X^2 \cup \dots \cup X^i \cup \dots = \bigcup^{+\infty}_{i=1}x^i \]

Se \(\lambda\) è la parola vuota e si prende un \(w \in X^+\) tale che
\(w \cdot \lambda = \lambda \cdot w = w\) si ha:

\[ x^\ast = \set{\lambda} \cup X^+ \]

Inoltre si ha:

\[
X^h = \begin{cases}
            \set{\lambda}   &\text{se } h = 0 \\
            X \cdot X^{h-1} &\text{altrimenti}
      \end{cases}
\]

### Linguaggio formale

Un *lingauggio formale* \(L\) su un alfabeto \(X\) è un sottoinsieme di \(X^\ast\),
ovvero \(L \subseteq X^\ast\).

!!! example "Esempio"

    Il linguaggio delle parentesi ben formate è un linguaggio formale in quanto,
    denotato con \(M\) tale linguaggio, si ha:

    \[ M \subset \set{(,\ )}^\ast \]

I linguaggi formali possono essere di natura molto diversa l'uno dall'altro.

## Esempi di linguaggi formali

Un linguaggio di programmazione può essere costruito a partire dall'alfabeto
\(X\) dei simboli sulla tastiera.

L'insieme, finito o infinito, dei programmi ben costruiti sintatticamente (ossia,
che rispettano la sintassi) costituisce un linguaggio.

Consideriamo l'insieme dei teoremi di una teoria matematica. I teoremi sono
particolari stringhe di simboli del nostro alfabeto. L'insieme dei teoremi "ben
formati" rappresenta un linguaggio. Ad esempio, la stringa "\(ab = ba\)" non è
un teorema della teoria dei gruppi, ma della teoria dei gruppi abeliani.

## Generazione e riconoscimento di linguaggi formali

Siamo interessati ai linguaggi formali da almeno due punti di vista: descrittivo
e/o generativo, riconoscitivo.

### Generazione di linguaggi formali

Come è possibile generare gli elementi di un dato linguaggio \(L\)? Un linguaggio
finito può essere descritto/generato per elencazione degli elementi (se il
numero non è troppo grande). Un linguaggio infinito non è elencabile.

Questi sono i più interessanti perché devono essere specificati necessariamente
attraverso una proprietà che ne caratterizza gli elementi, che ne definisce
l'intensione. Tale proprietà può essere vista come una regola da seguire per
generare gli elementi del linguaggio. Il vero problema è trovare le o la regola
generativa, o di produzione di un linguaggio.

È quello che accade quando si impara una lingua dato che non è possibile
memorizzare tutte le frasi della lingua.

!!! example "Esempio"

    - Non è possibile "elencare" tutti i teoremi della teoria dei gruppi, dato
      dato che sono infiniti i teoremi realizzabili combinando quelli noti;
    - Un libro di teoria dei gruppi non è l'elencazione dei teoremi, ma fornisce
      una serie di assiomi e regole con le quali, a partire dagli assiomi, è
      possibile costruire tutti i teoremi della teoria dei gruppi;

Per descrivere la regola di produzione di un linguaggio, verrà utilizzata una
notazione insiemistica.

!!! example "Esempio"

    Sia \(L\) il linguaggio su \(X = \set{0}\) costituito da tutte e sole le
    stringhe che hanno un numero pari di \(0\), ovvero:

    \[ L = \set{\lambda,\ 00,\ 0000\, \dots} \]

    La regola di produzione di \(L\) viene espressa come segue:

    \[ L = \set{\lambda} \cup \set{w^n \mid w = 00,\ n = 1,2,\dots} \]

### Riconoscimento di linguaggi formali

Com'è possibile *riconoscere* gli elementi di un dato linguaggio $L$? Questo
secondo punto di vista ha come obiettivo la costruzione di "macchine" in grado
di decidere o stabilire se una stringa è un elemento di $L$ oppure no. Si intende
costruire una "macchinetta" cui dare in ingresso una particolare parola e che
produca una tra due possibili risposte:

- \(sì \equiv parola \in L'\)
- \(no \equiv parola \notin L'\)

!!! example "Esempio"

    L'esecuzione di un programma errato sintatticamente viene inibita. Questo è
    indice dell'esistenza di una "macchinetta" che stabilisce se il programma
    appartiene o no all'insieme dei programmi sintatticamente ben costruiti.

Analizziamo il problema della generazione di \(L\).

Sia dato l'alfabeto: \(X = \set{0,\ 1,\ 2, \dots,\ 9,\ +,\ -}\). Si vuole generare
il linguaggio \(L\) dei numeri interi relativi. Ovviamente \(L \subseteq X^\ast\),
più precisamente \(L \subset X^\ast\) poichè ad esempio \(1++-5 \notin L\).

Non è possibile elencare gli elementi di \(L\). È dunque necessario trovare una
serie di regole mediante le quali è possibile produrre tutti e soli gli elementi
di \(L\).

Sia assunto, per semplicità, che un numero relativo sia costituito da una serie
di cifre precedute da \(+\) o \(-\).

Adottata la BNF per descrivere le produzioni, si ha:

\[
\begin{align}
    \bnf{S} &\Coloneqq +\bnf{I} \mid -\bnf{I} \\
    \bnf{I} &\Coloneqq \bnf{D} \mid \bnf{I} \bnf{D} \\
    \bnf{D} &\Coloneqq 0 \mid 1 \mid 2 \mid 3 \mid 4 \mid 5
                         \mid 6 \mid 7 \mid 8 \mid 9
\end{align}
\]

Queste regole generano tutti gl iinteri relativi, purché si parta dal simbolo
non-terminale \(S\). Il simbolo non-terminale \(I\) è anche detto *categoria
sintattica* e sta ad indicare la classe dei numeri interi. Questo è definito
ricorsivamente o come una cifra o come un intero seguito da una cifra.
Dunque ogni intero relativo è generato da queste regole e niente che non sia un
intero relativo può essere generato da queste regole.

!!! example "Esempio"

    Si vuole generare ad albero l'intero relativo \(-375\). Tale albero prende
    il nome di *albero di derivazione*.


    ```mermaid
    flowchart LR
        S ------> -;
        S --> I --> I1[I] --> I2[I] --> D --> 3;
        I1 --> D1[D] ---> 7;
        I --> D2[D] ----> 5;
    ```

    \[ S \astimplies -375 \iff -375 \in L \]

    Nella notazione vista per il linguaggio delle parentesi ben formate, tipica
    dei linguaggi formali, la grammatica diventa:

    \[
    \begin{align}
        S &\to +I \mid -I   \\
        I &\to D \mid I\;D  \\
        D &\to 0 \mid 1 \mid 2 \mid 3 \mid 4 \mid 5 \mid 6 \mid 7 \mid 8 \mid 9
    \end{align}
    \]

## Grammatiche generative

Dagli esempi di linguaggi visti, è possibile trarre le seguenti conclusioni. Per
generare un linguaggio sono necessari:

- un insieme \(X\) di simboli primitivi con cui si formano le parole del
  linguaggio, detto alfabeto dei simboli terminali o alfabeto terminale;
- un insieme \(V\) di simboli ausiliari o variabili con cui si identificano
  le categorie sintattiche del linguaggio, detto alfabeto dei simboli
  non-terminali (ausiliari) o alfabeto non-terminale o alfabeto delle variabili;
- un simbolo speciale \(S\), scelto tra i non-terminali, da cui far partire la
  generazione delle parole del linguaggio. Tale simbolo è detto assioma o scopo
  o simbolo distintivo o simbolo di partenza o simbolo iniziale;
- un insieme \(P\) di produzioni, espresse in un formalismo quali: regole di
  riscrittura, BNF \((a \Coloneqq b)\), carte sintattiche,...

### Definizione

Una grammatica generativa o a astruttura di frase di \(G\) è una quadrupla

\[ G = (X,\ V,\ S,\ P) \]

dove:

- \(X\) è l'**alfabeto terminale** per la grammatica;
- \(v\) è l'**alfabeto non-terminale** o delle variabili per la grammatica;
- \(S\) è il **simbolo di partenza** per la grammatica;
- \(P\) è l'insime delle **produzioni** della grammatica.
_
Valgono inoltre le seguenti condizioni:

- \(\XiV = \emptyset\);
- \(S \in V\).

## Definizione di produzione

Una **produzione** è una coppia \((v,\ w)\), dove \(v \in {(\XuV)}^+\) e \(V\)
contiene un simbolo non-terminale se e solo se \(v \in {(\XuV)}^\ast V {(\XuV)}^\ast\)
e \(w \in {(\XuV)}^\ast\), quindi \(w\) può essere anche \(\lambda\).

Un elemento \((v,\ w)\) di \(P\) è comunemente scritto nella forma:

\[ v \to w \]

Una produzione deve, in qualche modo, riscrivere un simbolo non-terminale.

Per convenzione, gli elementi di \(X\) sono rappresentati di solito con lettere
minuscole (con o senza pedici e di solito sono le prime lettere dell’alfabeto)
o cifre ed operatori (connettivi), mentre gli elementi di \(V\) sono
rappresentati con lettere maiuscole (con o senza pedici) o con stringhe
delimitate dalle parentesi angolari "\(\langle\)" e "\(\rangle\)".

La notazione \(a \to b_1 \mid b_2 \mid \dots \mid b_k\) è impiegata come
abbreviazione della seguente:

\[
\begin{align}
    a &\to b_1 \\
    a &\to b_2 \\
      &\hspace{0.7em}\vdots \\
    a &\to b_k
\end{align}
\]
