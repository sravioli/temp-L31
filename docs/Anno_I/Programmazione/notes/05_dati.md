# I Dati

I dati rappresentano oggetti e proprietà della realtà rilevanti per il problema
in esame. I dati sono un'astrazione degli oggetti del mondo reale, nel senso che:

!!! quote "N. Wirth, Algoritmi e strutture dati"

    Alcune proprietà e caratteristiche degli oggetti in esame vengono ignorate
    perché sono irrilevanti e marginali per il particolare problema considerato

<!-- Il concetto di dati è estremamente importante in informatica, in quanto l'intero
processo di progettazione di un programma è incentrato sulla gestione dei dati.
In particolare, il processo di decomposizione di un problema in sotto-problemi
consiste nel trovare una corrispondenza tra i dati del problema e i dati dei
sotto-problemi. -->

Il concetto di dati è estremamente importante in informatica e la sua comprensione
è fondamentale per la progettazione di un programma. Durante il processo di
progettazione di un programma è necessario individuare i dati che sono rilevanti
per il problema in esame e descriverli, fornendo una descrizione il quanto più
completa e appropriata possibile.

Le caratteristiche che vanno descritte sono solo alcune, come ad esempio il tipo
di dato, la quantità dello stesso, etc.

Se, ad esempio, si volesse descrivere un algoritmo utile a gestire i dati
anagrafici e la carriera degli studenti universitari, un dato fondamentale sarebbe,
ovviamente, lo studente stesso. Dati non fondamentali sono, ad esempio: altezza,
colore degli occhi o dei capelli, etc.
Dati che invece sono fondamentali sono, ad esempio: nome, cognome, data di
nascita, luogo di nascita, residenza, sesso, reddito, etc.

All'anagrafe, invece, risultano essere utili tutti i dati che riguardano le
caratteristiche fisiche dello studente, in pratica l'opposto dell'algoritmo.

!!! info "Informazioni"

    A seconda della situazione, l'oggetto viene descritto (con dei dati), in modo
    diverso.

## Dati semplici

I dati semplici o elementari rappresentano oggetti, entità, proprietà elementari
o atomiche non decomponibili. Ad esempio:

- la misura di un lato di un poligono;
- il numero di matricola di uno studente;
- il voto di un esame.

## Dati strutturati

I dati strutturati rappresentano oggetti, entità, proprietà più complesse,
decomponibili in dati elementari. Essi sono aggregati di dati semplici.

!!! example "Esempio"

    === "Studente"

        ```txt linenums="0"
        Studente:
            Matricola;
            Nome e cognome;
            Corso di laurea;
            Università.
        ```

    === "Data"

        ```txt linenums="0"
        Data:
            Giorno;
            Mese;
            Anno.
        ```

    === "Persona"

        ```txt linenums="0"
        Persona:
            Informazioni fisiche:
                Altezza;
                Colore degli occhi;
                Colore dei capelli;
                Peso;
            Informazioni anagrafiche:
                Nome;
                Cognome;
                Data di nascita;
                Stato civile;
                Residenza.
        ```

I dati strutturati possono a loro volta essere descritti con altri dati strutturati.

## Tipi di dati

Ogni dato è caratterizzato da un nome (o identificatore) e da un tipo.
Il nome viene utilizzato per identificare univocamente il dato[^1]
Il tipo di dato è legato al contenuto dello stesso, nel caso di dato semplice si
tratta del dato stesso, nei casi di dati strutturati si tratta di una descrizione
dei dati semplici che lo compongono. Il tipo indica anche le operazioni che
possono essere eseguite sul dato.

Sui tipi di dati definiti dall'utente, è ques'ultimo che deve definire le
operazioni che possono essere eseguite.

Inoltre, i dati possono essere:

- Dati di input
- Dati di output
- Dati di lavoro (utilizzati durante l'esecuzione dell'algoritmo)

[^1]: È consigliabile utilizzare nomi che ricordino il contenuto del dato.
