# Esercitazione del 28.10.21

Esercitazione del 28 ottobre 2021

Letti in input 2 insiemi di elementi I1 e I2, di cardinalità n ed m rispettivamente, scrivere un
algoritmo in grado di:

- individuare gli elementi comuni ai 2 insiemi
- unire i due insiemi in un unico insieme
- calcolare la differenza tra i due insiemi
- stampare a video tutti i risultati

Considerare i controlli sui dati di input

Realizzare come prima cosa la decomposizione funzionale

```txt title="albero di lavoro"
Operazioni su insiemi
    Leggere insieme I1
        Leggere cardinalità n di I1
        Verificare i vincoli di n
        Leggere i valori di I1
        Verificare i vincoli di I1
    Leggere insieme l2
        Leggere cardinalità m di I2
        Verificare i vincoli di m
        Leggere i valori di I2
        Verificare i vincoli di I2
    Calcolare intersezione
        Ricercare elemento in insieme
    Calcolare Unione
        Ricercare elemento in insieme
    Calcolare Differenza
        Ricercare elemento in insieme
    Stampare i risultati
        Stampare insieme intersezione
        Stampare insieme unione
        Stampare insieme differenza
```

## Operazioni su insiemi

```txt title="Operazioni su insiemi"
printf("Inserisci la cardinalità di I1: ");
```
