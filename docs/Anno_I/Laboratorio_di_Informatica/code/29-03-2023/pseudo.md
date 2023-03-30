# Esercizio del 29/03/2023

> Leggere in input, da file di testo, un testo scritto in italiano e memorizzarlo
> nell'ordine in cui è stato letto.
>
> Dopo aver memorizzato l'intero testo, verificare se e' palindromo o no (I
> caratteri di punteggiatura non influiscono sulla verifica. I caratteri
> maiuscoli e minuscoli sono considerati uguali).
>
> Stampare un messaggio in base all'esito della verifica.
>
> Realizzare pseudocodice, casi di test e codice in linguaggio C, e inviare tutto
> via e-mail entro le 17.30. La valutazione dipendera' per il 50% dalla
> correttezza della soluzione e per il restante 50% dallo stile di programmazione
> adottato.

**INPUT**:

- `nomefile`: nome del file di testo

**OUTPUT**:

- `NULL`: non vi è output

**ALGORITMO**:

```txt title="Pseudocodice"
stringa = LeggereDaFile(nomefile)
SE (Palindroma(stringa) == 1) ALLORA
    StampareAVideo("Il testo è palindromo")
  ALTRIMENTI
    StampareAVideo("Il testo non è palindromo")
```

***

## LunghezzaStringa()

**INPUT**:

- `stringa`: stringa di cui calcolare la lunghezza, stringa di caratteri

**OUTPUT**:

- `lunghezza`: lunghezza della stringa di caratteri, numero intero

**ALGORITMO**:

```txt title="Pseudocodice"
lunghezza := 0
MENTRE(elemento lunghezza-esimo di stringa != '\0')
 lunghezza := lunghezza + 1
FINE
```

## Palindroma()

**INPUT**:

- `stringa`: la sequenza caratteri di cui verificare se è palindroma o meno

**OUTPUT**:

- `palindroma`: stabilisce se la parola sia palindroma o meno, intero che assume
  valore 0/1.

**LAVORO**:

- `copia`: copia della stringa originale, stringa di caratteri alfanumerici
- `invertita`: string originale invertita, stringa di caratteri alfanumerici

**ALGORITMO**:

```txt title="Pseudocodice"
copia = CopiaStringa(stringa)
invertita = InvertiStringa(copia)
SE (ComparaStringhe(invertita, stringa) == 0) ALLORA
    palindroma := 1
ALTRIMENTI
   palindroma := 0
```

### InvertiStringa()

**INPUT**:

- `stringa_da_invertire`: stringa che deve essere invertita, stringa di caratteri

**OUTPUT**:

- `stringa_invertita`: stringa che è stata invertita, stringa di caratteri

**LAVORO**:

- `i`: contatore, intero

**ALGORITMO**:

```txt title="Pseudocodice"
i := LunghezzaStringa(stringa_da_invertire)
j := 0
MENTRE (i > 0)
    carattere i-esimo di stringa_da_invertire := carattere j-esimo di stringa_invertita
    i := i - 1
    j := j + 1
FINE
```

### CopiaStringa()

**INPUT**:

- `stringa_da_copiare`: stringa che dev'essere copiata in un'altra stringa,
  stringa di caratteri

**OUTPUT**:

- `copia`: copia della stringa originale, stringa di caratteri

**LAVORO**:

- `i`: contatore, numero intero

**ALGORITMO**:

```txt title="Pseudocodice"
MENTRE (i < LunghezzaStringa(stringa_da_copiare))
    carattere i-esimo di copia := carattere i-esimo stringa_da_copiare
    i := i + 1
FINE
```

### ComparaStringa()

**INPUT**:

- `prima_stringa`: prima stringa che dev'essere comparata
- `seconda_stringa`: seconda stringa da comparare

**OUTPUT**:

- `uguali`: determina se le due stringe sono uguali, numero intero che assume
  valore 0/1.

**LAVORO**:

- `i`: contatore, numero intero

**ALGORITMO**:

```txt title="Pseudocodice"
SE (LunghezzaStringa(prima_stringa) != LunghezzaStringa(seconda_stringa))
  ALLORA
    uguali := 0
  ALTRIMENTI
    i := 0
    MENTRE (i < LunghezzaStringa(prima_stringa))
    >> va messo un altro controllo che verifichi che il carattere non sia uno 
    >> spazio o un simbolo di punteggiatura
    >> praticamente se è uno di questi due bisogna avanzare di una posizione
      SE (
          (ePunteggiatura(carattere i-esimo di prima_stringa) OR 
          (eSpazio(carattere i-esimo di prima_stringa)
         )
        ALLORA
          i := i + 1
      FINE
      SE (
          (ePunteggiatura(carattere j-esimo di prima_stringa) OR 
          (eSpazio(carattere j-esimo di prima_stringa)
         )
        ALLORA
          j := j + 1
      FINE
      SE (carattere i-esimo di prima_stringa != carattere j-esimo di seconda_stringa)
        ALLORA
          uguali := 0
        ALTRIMENTI
          uguali := 1
      FINE
      i := i + 1
    FINE
FINE
```

#### ePunteggiatura()

**INPUT**:

- `carattere`: carattere da analizzare, carattere.

**OUTPUT**:

- `risultato`: indica se il carattere dato è un simbolo di punteggiatura o no,
  intero che assume valore 0/1;

**ALGORITMO**:

```txt title="Pseudocodice
SE (
    (carattere = ',') OR
    (carattere = '.') OR
    (carattere = '-') OR
    (carattere = ';') OR
    (carattere = ':') OR
    (carattere = '_') OR
    (carattere = '?') OR
    (carattere = '^') OR
    (carattere = '\') OR
    (carattere = '\") OR
    (carattere = '!')
  ) 
  ALLORA 
    risultato := 1
  ALTRIMENTI
    risultato := 0
FINE
```

#### eSpazio()

**INPUT**:

- `carattere`: carattere da analizzare, carattere.

**OUTPUT**:

- `risultato`: indica se il carattere dato è un simbolo di punteggiatura o no,
  intero che assume valore 0/1;

**ALGORITMO**:

```txt title="Pseudocodice"
SE (carattere = ' ')
  ALLORA
    risultato := 1
  ALTRIMENTI
    risultato := 0
FINE
```
