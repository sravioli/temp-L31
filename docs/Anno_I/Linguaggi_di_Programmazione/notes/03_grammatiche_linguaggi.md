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

Con i simboli primitivi dell'alfabeto si formano le parole (es. \(abc\),
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

Com'è possibile *riconoscere* gli elementi di un dato linguaggio \(L\)? Questo
secondo punto di vista ha come obiettivo la costruzione di "macchine" in grado
di decidere o stabilire se una stringa è un elemento di \(L\) oppure no. Si intende
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

\[ \grammar \]

dove:

- \(X\) è l'**alfabeto terminale** per la grammatica;
- \(v\) è l'**alfabeto non-terminale** o delle variabili per la grammatica;
- \(S\) è il **simbolo di partenza** per la grammatica;
- \(P\) è l'insime delle **produzioni** della grammatica.

Valgono inoltre le seguenti condizioni:

- \(\XiV = \emptyset\);
- \(S \in V\).

## Altre definizioni

### Produzione

Una **produzione** è una coppia \((v,\ w)\), dove \(v \in \XuVplus\) e \(V\)
contiene un simbolo non-terminale se e solo se \(v \in \XuVast V \XuVast\)
e \(w \in \XuVast\), quindi \(w\) può essere anche \(\lambda\).

Un elemento \((v,\ w)\) di \(P\) è comunemente scritto nella forma:

\[ v \to w \]

Una produzione deve, in qualche modo, riscrivere un simbolo non-terminale.

Per convenzione, gli elementi di \(X\) sono rappresentati di solito con lettere
minuscole (con o senza pedici e di solito sono le prime lettere dell'alfabeto)
o cifre ed operatori (connettivi), mentre gli elementi di \(V\) sono
rappresentati con lettere maiuscole (con o senza pedici) o con stringhe
delimitate dalle parentesi angolari "\(\langle\)" e "\(\rangle\)".

La notazione \(a \to b_1 \mid b_2 \mid \dots \mid b_k\) è impiegata come
abbreviazione della seguente:

\[
    \begin{align}
        a &\to b_1              \\
        a &\to b_2              \\
          &\hspace{0.7em}\vdots \\
        a &\to b_k
    \end{align}
\]

!!! example "Esempi"

    - La grammatica per il linguaggio della parentesi ben formate è la seguente:

    \[
        G_1 = \left(
            \set{(, )},\ \set{S},\ S,\ \set{S \to (\;),\ S \to (S),\ S \to SS}
        \right)
    \]

    - La grammatica per il linguaggio dei numeri interi relativi è la seguente:

    \[
        G_2 = \left(
            \set{0, 1, \dots, 9, +, -}, \set{S, I, D}, S,
            \set{S \to +I,\ S \to -I,\ I \to D,\ I \to ID,\
                 D \to 0,\ D \to 1, \dots, D \to 9}
        \right)
    \]

### Derivazione o produzione diretta

Sia \(G = \set{X,\ V,\ S,\ P}\) una gramamtica e siano \(y,z\) su \(\XuV\) due
stringhe finite di simboli sia terminali che non-terminali, tali che:

\[ y = \gamma\alpha\delta \quad\text{ e }\quad z = \gamma\beta\delta \]

dove \(y \in \XuVplus\), \(z \in \XuVast\), \(\alpha,\beta,\gamma \in \XuVast\).

Si scrive

\[ y \implies z \]

e si dice che \(y\) *produce direttamente* \(z\) o che \(z\) è *derivata
direttamente* da \(y\) se:

\[ \alpha \to \beta \in P \]

ossia se esiste in \(G\) un produzione \(\alpha \to \beta\).

Si scrive, invece:

\[ y \astimplies z \]

e si dice che \(y\) *produce* \(z\) o che \(z\) è *derivabile* da \(y\) se
\(y = z\) o se esiste una sequenza di stringhe \(w_1,\, w_2, \dots,\, w_n\), con
\(w_1,\, w_2,\, \dots,\, w_{n-1} \in \XuVplus\) e \(w_n \in \XuVast\), avendo
\(w_1 = y\) e \(w_n = z\) tali che \(\forall i,\; i = 1,\, 2,\, \dots,\, n - 1 :
w_i \underset{\substack{G}}{\implies} w_{i+1}\), ovvero \(w_i\) produce
direttamente \(w_{i+1}\), cioè:

\[
    y \astimplies z \iff
    \begin{align}
        &y = z              \\
        &\text{oppure }     \\
        &w_1 = y \implies w_2 \implies \dots \implies w_{n-1} \implies w_n = z
    \end{align}
\]

La notazione di derivazione diretta stabilisce una relazione binaria in \(\XuVast\).

Date due stringhe \(y,z\), il simbolo \(\implies\) può esserci o meno, dipende
dall'esistenza di una produzione. Allora è possibile anche definire una
composizione di relazioni:

\[
     y \Oimplies{2} z \deff \exists x : y \implies w \land w \implies z
\]

dove \(2\) è il numero di trascrizioni necessarie per passare da \(y\) a \(z\),
ossia la *lunghezza della derivazione*.

Da ciò si ha che \(\astimplies\) non è altro che:

\[
    I \cup \implies \cup \Oimplies{2} \cup \Oimplies{3} \cup \cdots
\]

dove \(I\) è la relazione identica e \(\Oimplies{n}\) indica la composizione
della relazione \(implies\) \(n\) volte con se stessa. Dunque:

- \(\astimplies\) è la *chiusura riflessiva e transitiva* della relazione di
  derivazione diretta;
- \(\Oimplies{+}\) è la *chiusura transitiva* della stessa relazione.

### Linguaggio generato da una grammatica

Sia \(\grammar\) una grammatica. Il **linguaggio generato da \(G\)**, denotato
con \(L(G)\), è l'insieme delle stringhe di simboli terminali derivabili dal
simbolo di partenza \(S\):

\[
    L(G) = \set{w \in X^\ast\ \middle|\ \OUimplies{\ast}{G} w}
\]

Sono, dunque, stringhe di \(L(G)\) le stringhe che:

- consistono di soli simboli terminali;
- possono essere derivate da \(S\) in \(G\).

### Forma di frase

Sia \(\grammar\) una grammatica. Una stringa \(w \in \XuVast\) è un **forma di
frase** di \(G\) se

\[ S \OUimplies{\ast}{G} w \]

Alle forme di frasi si applicano le stesse definizioni (es. potenza) e gli stessi
operatori (es. concatenazione) dati per le stringhe.

#### Proposizione

Data una grammatica \(\grammar\), \(L(G)\) è l'insieme delle forme di frase
terminali (o frasi) di \(G\).

### Grammatiche equivalenti

Due grammatiche \(G\) e \(G'\) si dicono **equivalenti** se generano lo stesso
linguaggio, ossia se

\[ L(G) = L(G') \]

#### Esempio

Sia \(\grammar\), con:

\[
    X = \set{a,\ b},\quad V = \set{S},\quad
    P = \set{S \supto{(1)} aSb,\ S \supto{(2)} ab}
\]

Si determini \(L(G)\). Si ha \(ab \in L(G)\), poiché \(S \Uimplies{(2)} ab\).

Se si numerano le produzioni, è possibile indicare la produzione usata
immediatamente al di sotto del simbolo \(\implies\):

- \(\Uimplies{n} \equiv\) è stata applicata la produzione \(n\);
- \(y \Oimplies{k} z \equiv\) \(y\) produce \(z\) in \(k\) paassi, dove \(k\)
  è la lunghezza della derivazione.

Si ha \(a^2b^2 \in L(G)\) dato che \(S \Uimplies{(1)} aSb \Uimplies{(2)} a^2b^2\),
inoltre \(a^3b^3 \in L(G)\) poiché \(S \Oimplies{3} a^3b^3\), e dunque

\[ \set{a^n b^n \mid n > 0} \subseteq L(G) \]

Inoltre, qualsiasi derivazione da \(S\) in \(G\) produce frasi del tipo \(a^nb^n\),
dunque \(L(G) \subseteq \set{a^nb^n \mid n > 0}\), e quindi:

\[ L(G) = \set{a^n b^n \mid n > 0} \]

## Notazione

Per rendere più concisa la descrizione di una grammatica, spesso ci si limiterà
a elencarne le produzioni, quando sia chiaro quale sia il simbolo di partenza e
quali siano i simboli terminali e quelli non-terminali.

Inoltre, le produzioni con la stessa parte sinistra vengono accorpate attraverso
l'uso del simbolo "\(\mid\)" (preso in prestito dalla BNF).

Infine, verrà omessa l'indicazione della grammatica dalla simbologia di
derivazione e derivazione diretta quando sia chiaro dal contesto a quale
grammatica si fa riferimento.

!!! example "Esempio"

    Sia data la seguente grammatica:

    \[
        S \to \sup{A}{(1)} \mid \sup{B}{(2)},\
        A \to \sup{aA}{(3)} \mid \sup{a}{(4)},\
        B \to \sup{bB}{(5)} \mid \sup{b}{(6)}
    \]

    Determinare \(L(G)\).

    Non si sa se applicare \(S \supto{(1)} A\) oppure \(S \supto{(2)} B\)
    inizialmente. I meccanismi di costruzione di un linguaggio sono generalmente
    non deterministici, poiché può non essere univoca la sostituzione da operare
    ad una forma di frase se uno stesso simbolo non-terminale si trova a
    sinistra di due o più produzioni, come illustrato nella figura seguente

    ```mermaid
    flowchart LR
        S ==>|"(2)"| B ==>|"(5)"| bB;
                     B ==>|"(6)"| b["b ∈ L(G)"];

        S ==>|"(1)"| A ==>|"(4)"| a["a ∈ L(G)"];
                     A ==>|"(3)"| aA ==>|"(4)"| aa["aa ∈ L(G)"];
                                  aA ==>|"(3)"| aaA ==>|"(4)"| aaa["aaa ∈ L(G)"];
                                                aaA ==>|"(3)"| aaaA;
    ```

    Ne consegue che

    \[ L(G) = \set{a^n \mid n > 0} \cup \set{b^n \mid n > 0} \]

Dunque, una grammatica è uno **strumento generativo** di un linguaggio perché,
data una qualsiasi parola di quel linguaggio, è possibile risalire mediante le
produzioni al simbolo di partenza della brammatica.

Viceversa, dato iìsimbolo di partenza di una grammatica, seguendo uno qualsiasi
dei cammini dell'albero di derivazione, si produce una parola "valida" del
linguaggio.

in generale, dato un linguaggio \(L\) e una grammatica \(G\), **non** esiste un
algoritmo in grado di dimostrare che la grammatica genera il linguaggio, ossia
che \(L = L(G)\).

Più specificamente, **non** esiste un algoritmo che stabilisce se una data stringa
è generata o no dalla grammatica presa in considerazione.

Tutto ciò si riassume nella seguente proposizione:

!!! quote "Proposizione"

    Il problema di dimostrare la correttezza di una grammatica non è risolubile
    algoritmicamente, in generale.

In molti casi impotanti, però, è possibile dimostrare per induzione che una
particolare grammatica genera proprio un particolare linguaggio.

Queste dimostrazioni consentono di stabilire se, data una grammatica \(G\) e un
linguaggio \(L\), risulta:

1. \(w \in L(G) \implies w \in L\) ovvero \(L(G) \subseteq L\);
2. \(w \in L \implies w \in L(G)\) ovvero \(L \subseteq L(G)\).

Il punto 1. afferma che la grammatica \(G\) genera solo stringhe appartenenti
al linguaggio \(L\), ovvero *coerenza* o *consistenza* di \(G\).
Il secondo punto afferma che il linguaggio \(L\) comprende solo parole generabili
dalla grammatica \(G\), ovvero la *completezza* di \(G\).

## Principio di Induzione (extra)

Sia \(n_0\) un intero e sia \(P = P(n)\) un enunciato che ha senso per ogni
intero maggiore o uguale a \(n_0\). Se

\[
    P(n_0) \text{ è vero } \land
    \forall n > n_0,\; P(n-1) \text{ è vero } \implies P(n) \text{ è vero}
\]

allora \(P(n)\) è vero per tutti gli \(n\) maggiori o uguali a \(n_0\)
