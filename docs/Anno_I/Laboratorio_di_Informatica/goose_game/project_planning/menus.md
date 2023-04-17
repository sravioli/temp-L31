# Menù di gioco

Il lavoro consiste nella definizione di tutte le funzioni principali che
prevedete di realizzare per il progetto, suddivise per le 4 operazioni previste
(Nuova partita, Carica partita, Classifica e Aiuto).

 Di ogni funzione dovete indicare:

- nome della funzione
- nome e descrizione dei dati di input
- nome e descrizione del dato di output

## Menù principale

### funzione print_menu()

INPUT:

- nullo, non riceve ...

OUTPUT:

- nullo, non riceve ...

stampa a video menù principale:

- nuova
- carica
- aiuto (manuale+regole)
- classifica
- esci

## Menù nuova partita

### funzione print_new_game_menu()

INPUT:

- nullo, non riceve ...

OUTPUT:

- nullo, non riceve ...

stampare a video menù nuova partita:

- inzia (opzioni) (se durante partita chiede se salvare o meno)
- salva
- abbandona
- esci

### funzione print_start_game_menu()

INPUT:
 nullo, non riceve ...
OUTPUT:
 nullo, non riceve ...

stampa le opzioni, fa scegliere all'utente e poi avvia la partita

- numero giocatori
- lunghezza tabellone
- esci

### funzione save_game()

INPUT:

- file

OUTPUT:

- nullo, non riceve ...

chiede all'utente (altra fn?) il nome del file di salvataggio, poi salva.

#### funzione get_save_file_name()

INPUT:

- nullo, non riceve ...
OUTPUT:
- nomefile

chiede all'utente il nome con cui salvare la partita.

### funzione leave_game()

INPUT:
 nullo, non riceve ...
OUTPUT:
 nullo, non riceve ...

abbandona la partita corrente (se si è in partita), tornando al menù principale.
chiede se si vuole salvare (chiama save_game()) oppure no (esce).

## Menù carica partita

### funzione print_load_game_menu()

INPUT:

- nullo, non riceve ...

OUTPUT:

- nullo, non riceve ...

stampare a avideo menù  carica partita
<!-- da qui puoi caricare una partita salvata, selezionala -->

- carica da file (5 file max) è un altro menù
- esci

#### funzione print_load_from_file()

INPUT:

- nullo, non riceve ...

OUTPUT:

- nullo, non riceve ...

stampa a video i file salvati e chiama una fn per caricare il file scelto
dall'utente. (esci)

##### funzione choose_saved_file()

in :

- nullo, non riceve ...

OUTPUT:

- file/nomefile/indice

chiede all'utente che file vuole dei salvati. (esci)

### funzione load_game()

INPUT:

- file (opzioni+partita)

OUTPUT:

- nullo, non riceve ...

carica una partita da un file di testo

## Menù aiuto

### funzione print_help()

INPUT:

- nullo, non riceve ...

OUTPUT:

- nullo, non riceve ...

stampa menù:

- manuale
- regole
- esci

### funzione print_manual()

INPUT:

- nullo, non riceve ...

OUTPUT:

- nullo, non riceve ...

stampa tutto il manuale di gioco salvato su un file di testo.

### funzione print_rules()

INPUT:

- nullo, non riceve ...

OUTPUT:

- nullo, non riceve ...

stampa tutte le regole di gioco salvate su un file di testo.

## Menù classifica

### funzione print_leaderboard()

stampa la classifica salvata su file di testo (class. globale)
