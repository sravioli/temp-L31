# Calcolo del percorso

Costanti globali dichiarate nel file [globals.md](./globals.md).

## get_players_number()

**OUTPUT**:

- `var`: num giocatori

**ALGORITMO**:

```txt title="bozza"
chiedi numero:
verifica che:
sia maggiore di 1
sia minore di 5
```

```txt
StampareAVideo("Inserici numero giocatori:")
ESEGUI
  num_players := LeggereDaTastiera()
  StampareAVideo("Numero non valido.")
FINCHÉ (num_players >= MIN_NUM_PLAYERS AND num_players <= MAX_NUM_PLAYERS)
FINE
```

## get_num_squares()

**ALGORTIMO**

```txt
chiedi numero.
verifica che:
maggiore di 49
minore di 91
```

```txt
StampareAVideo("Inserici numero caselle:")
ESEGUI
  num_squares := LeggereDaTastiera()
  StampareAVideo("Numero non valido.")
FINCHÉ (num_squares >= MIN_NUM_SQUARES AND num_squares <= MAX_NUM_SQUARES)
FINE
```

## place_goose_squares(board, num_squares)

**INPUT**:

`board`
:   indica il tabellone dove si svolgerà la partita, array a 1 dimensione di interi.

`num_squares`
:   numero di spazi scelti dal giocatore. Intero, maggiore o uguale a `MIN_NUM_SQUARES`
    e minore o uguale a `MAX_NUM_SQUARES`.

**OUTPUT**:

`new_board`
:   indica il tabellone modificato con le caselle oca dove si svolgerà la partita,
    array a 1 dimensione di interi.

**LAVORO**:

`i`
:   contatore delle caselle del tabellone di board, intero, >=9.

**ALGORITMO**:

```txt title="place_goose_squares()"
i = 9;
MENTRE (i < num_squares)
    board in posizione i = GOOSE_SQUARE;
    i = i + 9;
FINE
new_board = board;
```

## place_special_squares()

sono:

- locanda (-1): 19 nel percorso 90
- pozzo (-2): 31 nel percorso 90
- ponte (-3): 6 nel percorso 90
- prigione (-4): 52 nel percorso 90
- labirinto (-5): 42 nel percorso 90
- scheletro (-6): 58 nel percorso 90

input:
lunghezza del tabellone, tabellone modificato

OUTPUT: tabellone modificato

algoritmo

```txt
proporzione(num_special, len_board) [num_special:90=x:len_board] (x = (num_special*len_board)/90)
se la posizione x del tabellone è GOOSE_VALUE,
allora x++

caso normale 
si modifica il valore della casella con il valore che identifica la casella speciale
```

```txt
inn_position := proportion(BASE_INN_POSITION, num_squares) (x6) 
inn_position := check_special_position(inn_position, board) (x6)
posizione inn_position-esima di board := inn_position (x6)
```

### proportion(num_special, num_squares)

```txt
x := (num_special*num_squares) / MAX_NUM_SQUARES
```

### is_goose_space(space, board)

```txt
SE (casella space-esima di board = GOOSE_VALUE)
  ALLORA: esito := 1
  ALTRIMenti := 0
FINE
```

### `check_special_position(special_space_position, board)`

**INPUT**:

`special_space_position`
:   valore della posizione della casella speciale all'interno del tabellone.
    Intero maggiore di zero.

`board`
:   il tabellone dove si svolgerà la partita, array di interi a una dimensione.
con lunghezza compresa tra `MIN_NUM_SQUARES`
    e `MAX_NUM_SQUARES` elementi.

**OUTPUT**:

`allowed_special_position`
:   valore della posizione della casella speciale che non crea alcun conflitto
    con le caselle oca. Intero maggiore di zero.

**ALGORITMO**:

```txt title="check_special_position()"
allowed_special_position := special_space_position
SE (is_goose_space(special_space_pos, board) = 1) 
  ALLORA 
    allowed_special_position := allowed_special_position + 1
FINE
```
