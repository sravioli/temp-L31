# Algoritmo di Euclide

L'algoritmo di Euclide è un algoritmo per calcolare il massimo comun divisore
di due numeri interi positivi. Dunque, dati due numeri interi \(a, b\) calcolare
$\lcm(a, b)$.

**Input**
: \(a, b\) – coppia di numeri interi maggiori di zero

**Output**
: \(\mcd{}\) – massimo comun divisore di \(a\) e \(b\), numero intero maggiore di zero

L'algoritmo di Euclide si basa sulle seguenti proprietà:

1. Se \(a = b\) allora \(\mcd(a, b) = a = b\);
2. Se \(a > b\) allora \(\mcd(a, b) = \mcd(a - b, b)\);
3. Se \(a < b\) allora \(\mcd(a, b) = \mcd(a, b - a)\).

## Considerazioni

La prima proprietà afferma che il massimo comun divisore di due numeri uguali è
uno qualunque dei due numeri. La seconda e terza proprietà affermano che il
massimo comun divisore di due numeri diversi si può ricondurre al calcolo del
massimo comun divisore del più piccolo dei due numeri e della differenza tra il
più grande e il più piccolo.

Queste proprietà **non** sono l'algoritmo di risoluzione del problema, ma sono
un'idea di come risolvere il problema. Queste proprietà non dicono quando fermarsi
o quando ripetere un'operazione.

## Pseudo codifica

Poiché valgono le proprietà precedenti, nel caso generale si possono calcolare
tante differenze in modo da riportarsi al caso \(a = b\), per il quale il problema
è risolto. Il calcolo delle differenze deve essere ripetuto se risulta vero che
$a$ sia diverso da \(b\). Si può utilizzare una iterazione a condizione iniziale.

Dunque:

```txt title="Algoritmo di Euclide"
MENTRE (𝑎 ≠ 𝑏)
    SE (𝑎 > 𝑏)
        ALLORA assegna ad 𝑎 il valore di 𝑎 - 𝑏
        ALTRIMENTI assegna ad 𝑏 il valore di 𝑏 - 𝑎
    FINE
FINE
```

Il blocco `MENTRE` indica una ripetizione di un blocco di istruzioni. Viene
ripetuto tutto ciò che è contenuto fra `MENTRE` e `FINE` fino a quando la
condizione non risulti falsa. Nel caso in cui il mentre provochi un ciclo
infinito, l'algoritmo è **errato**. È comunque presente un salto ma non è
paragonabile a quello del `GOTO` poiché è nascosto, non arbitrario e controllato
da una condizione. Nel blocco `MENTRE` si verifica la condizione iniziale, se è
vera allora si procede col ciclo, altrimenti si esce dal ciclo; una volta
terminata la prima iterazione si verifica nuovamente la condizione iniziale, se è
vera si ripete il ciclo, altrimenti si esce dal ciclo e così via.

Ad esempio, se i due numeri fossero minori di zero, il ciclo non terminerebbe
mai. In questo caso, l'algoritmo è errato. È necessario che, durante la stesura
dell'algoritmo, si verifichi che non ci siano cicli infiniti. Questo è possibile
verificando che la condizione di uscita dal ciclo si avveri.

Il blocco `SE` presenta una condizione che può essere vera o falsa. Se la
condizione è vera, allora viene eseguito il blocco `ALLORA` e il blocco
`ALTRIMENTI` viene ignorato. Se la condizione è falsa, allora viene eseguito il
blocco `ALTRIMENTI` e il blocco `ALLORA` viene ignorato. Il blocco `SE` può
essere utilizzato anche senza il blocco `ALTRIMENTI`.
