# Tipi di dato e la loro Rappresentazione

## Il bit

Alfabeto del calcolatore costituito da due simboli: 0,1.
BIT (binary digit):
Unità elementare di informazione. La cifra binaria può
assumere solo due valori alternativi: 0 oppure 1. Archiviato
da un dispositivo digitale o un sistema fisico che esiste in
uno di due possibili stati distinti.
Es.:
•
i due stati stabili di un flip-flop
•
due posizioni di un interruttore elettrico
•
due distinte tensione o gli attuali livelli consentiti da un
circuito
•
due distinti livelli di intensità della luce
•
due direzioni di magnetizzazione o di polarizzazione, ecc

Sequenze di bit
Per poter rappresentare un numero maggiore di informazione si usano sequenze di bit
Il processo che fa corrispondere ad un dato reale una sequenze di bit prende il nome di
codifica dell’informazione
Ottimo
0
0
Discreto
0
1
Sufficiente
1
0
Insufficiente
1
1
Es.1: un esame può avere quattro possibili esiti:
ottimo, discreto, sufficiente, insufficiente. Quanti bit
sono necessari per codificare tale informazione?
Rosso
0
0
0
Blu
0
0
1
Verde
0
1
0
Giallo
0
1
1
Viola
1
0
0
Bianco
1
0
1
Nero
1
1
0
Grigio
1
1
1
Es.2: rappresentazione di otto colori

bit, Byte e word
• Con 𝑛 bit si possono rappresentare 2𝑛 stati/valori differenti
• Per rappresentare 𝑛 stati/valori, devo usare almeno log2 𝑛
I sistemi moderni memorizzano e manipolano miliardi di bit: vi è quindi la necessità di
avere dei multipli
8 bit = 1 byte
Con la lettera b minuscola si indicano i bit, mentre con la lettera B si indicano i byte

Multipli del byte
Byte
1 B =
8 bit
100 B
KiloByte
1 KB =
1000 B
103 B
MegaByte
1 MB =
1000 KB
106 B
GigaByte
1 GB =
1000 MB
109 B
TeraByte
1 TB =
1000 GB
1012 B
PetaByte
1 PB =
1000 TB
1015 B
ExaByte
1 EB =
1000 PB
1018 B
ZettaByte
1 ZB =
1000 EB
1021 B
YottaByte
1 YB =
1000 ZB
1024 B
Byte
1 B =
8 bit
20 B
KibiByte
1 KiB =
1024 B
210 B
MebiByte
1 MiB =
1024 KiB
220 B
GibiByte
1 GiB =
1024 MiB
230 B
TebiByte
1 TiB =
1024 GiB
240 B
PebiByte
1 PiB =
1024 TiB
250 B
ExbiByte
1 EiB =
1024 PiB
260 B
ZebiByte
1 ZiB =
1024 EiB
270 B
YobiByte
1 YiB =
1024 ZiB
280 B
Esistono analoghe misure per i multipli dei bit (Kb – KiloBit – 1000 bit), utilizzati
generalmente come misura nelle quantità di dati trasmessi
Fino a qualche anno fa le misure sulla sinistra non esistevano, e i nomi di quelle sulla
sinistra erano corrispondenti a quelle di destra (cioè 1 KiloByte equivaleva a 1024 Byte)

Tipi di dati non numerici
Booleani: i dati booleani sono contenuti all’interno di singoli bit che assumono valore 0/1
– F/V. Comunemente si considera come falso il valore 0 e come vero qualsiasi altro valore.
Ad esempio:
if(a) corrisponde a if(a!=0)
In questa situazione il valore viene memorizzato all’interno di uno (ad esempio per il char)
o più byte (short, int…).
L’unico caso in cui un booleano viene effettivamente memorizzato in un singolo bit si ha
quando si utilizzano le mappe di bit: viene considerato un byte come se fosse un array di
bit, ciascuno dei quali rappresenta un valore booleano.

Tipi di dati non numerici
Caratteri: Mappati come interi equivalenti in ASCII/UNICODE
In particolare si ha
UNICODE:
ASCII invece occupa 7 bit
UTF-8
8 bit (1 byte)
ASCII esteso
UTF-16
16 bit (2 byte)
Espansione a linguaggi
occidentali
UTF-32
32 bit (4 byte)
Set più completo di
caratteri

Tipi di dati non numerici
Puntatori: rappresentano e memorizzano delle locazioni in memoria.
Lo spazio occupato per un puntatore dipende dalla dimensione dello spazio di
indirizzamento.

Tipi di dati numerici
La rappresentazione dei numeri, così come tutte le altre rappresentazioni dei dati, in
informatica, a livello circuitale, avviene per tramite del codice binario.
Le unità in memoria sono valori binari (corrispondenti ai bit)

Basi numeriche

Base numerica
Il nostro sistema numerico è in base 10
Un numero 𝑛 si denota come scritto in una certa base numerica 𝑏 mediante la seguente
notazione:
𝑛𝑏
Ad esempio:
1510 indica il numero 15 in base 10
0100012 indica il numero 010001 in base 2
23𝐶16 indica il numero 23𝐶 in base 16

Base numerica
Un numero scritto in base 𝑏 può essere composto unicamente dalle cifre comprese tra 0 e
𝑏 − 1 incluse
Per le basi superiori a 10 si usano le lettere dell’alfabeto per indicare le cifre successive. Ad
esempio, in base 16 si usano le seguenti cifre:
Le basi più utilizzate in informatica (oltre alla base 10) sono:
•
La base 2, detto sistema binario
Le stringhe binarie sono generalmente indicate con il prefisso 0b (ad esempio 0b01001010)
•
La base 8, detto sistema ottale
•
La base 16, detto sistema esadecimale (HEX)
Le stringhe esadecimali sono generalmente indicate con il prefisso 0x (ad esempio 0xFF2C9A)
0
1
2
3
4
5
6
7
8
9
A
B
C
D
E
F
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15

Conversione da base 𝑏 in base 10
Un numero si converte in base 10 mediante la seguente formula
Sia 𝑘𝑏 = (𝑐𝑁−1 … 𝑐3𝑐2𝑐1𝑐0)𝑏 un numero di 𝑛 cifre in base 𝑏, dove 𝑐𝑖 rappresenta l’𝑖-esima
cifra in base 𝑏 partendo da destra
𝑘10 = ෍
𝑖=0
𝑛−1
𝑐𝑖𝑏𝑖 = 𝑐0 ∙ 𝑏0 + 𝑐1 ∙ 𝑏1 + ⋯ + (𝑐𝑛−1 ∙ 𝑏𝑛−1)

Conversione da base 𝑏 in base 10
Esempio:
3𝐹𝐶216 = ?10
3 ∙ 163 + 𝐹 ∙ 162 + 𝐶 ∙ 161 + 2 ∙ 160
3 ∙ 163 + 15 ∙ 162 + 12 ∙ 161 + 2 ∙ 160
3 ∙ 4096 + 15 ∙ 256 + 12 ∙ 16 + 2 ∙ 1
= 𝟏𝟔𝟑𝟐𝟐𝟏𝟎

Conversione da base 𝑏 in base 10
Esempio:
100101012 = ?10
128 + 16 + 4 + 1 = 𝟏𝟒𝟗𝟏𝟎
𝟐𝟕
𝟐𝟔
𝟐𝟓
𝟐𝟒
𝟐𝟑
𝟐𝟐
𝟐𝟏
𝟐𝟎
1
0
0
1
0
1
0
1
128
-

-

16
-

4
-

1

Conversione da base 10 a base 𝑏
Si prende il numero e lo si divide per la base 𝑏 in forma di quoto e resto, successivamente
si divide il quoto come prima e si continua fin quando non si ottiene il valore 0 come
quoto.
Il numero in base 𝑏 è rappresentato dai singoli resti, presi come cifre, considerando
l’ultimo resto come cifra più significativa e il primo resto come cifra meno significativa.
ALGORITMO:
• 𝑖 = 0
• Finché 𝑛 ≠ 0:
•
𝑐𝑖 = 𝑛 % 𝑏
•
𝑛 =
Τ
𝑛 𝑏
•
𝑖 = 𝑖 + 1
Operazione modulo
(resto nella divisione)

Conversione da base 10 a base 𝑏
Esempio:
342510 = ?16
Valore
Dividendo
Operazione
Quoto
Resto
3425
3425/16
214
1
214
214/16
13
6
13
13/16
0
D
(13)
1.
2.
3.
FINE
ALGORITMO
𝑫𝟔𝟏𝟏𝟔

Conversione da base 10 a base 𝑏
Esempio:
21310 =?2
213
106
53
26
13
6
3
1
0
1
0
1
0
1
0
1
1
𝟏𝟏𝟎𝟏𝟎𝟏𝟎𝟏𝟐
Dividendo per 2 è immediato ricavare il resto:
0 se il numero è pari
1 se il numero è dispari

Conversione rapida da base 2𝑛 a base 2 e viceversa
Essendo da/verso la base 16 = 24 divido in blocchi da 4 cifre a partire da destra e
trasformo il blocco da una base all’altra
16
0
0
1
1
0
1
1
0
1
1
0
1
1
1
1 2
1
B
6
F

Rappresentazione di un numero
Per rappresentare un numero 𝑛 ∈ ℕ in base 𝑏 sono necessarie log𝑏 𝑛 cifre
Quindi, per rappresentare un numero 𝑛 ∈ ℕ in binario sono necessari log2 𝑛 bit

Operazioni di somma e sottrazione
Nel sistema binario le operazioni di somma e sottrazione si effettuano nella stessa
maniera in cui le effettueremmo in base 10, considerando però i riporti alla base 2:
11
10110+
00111=
11101
0100
10110-
00111=
01111
2210
710
2910
2210
710
1510

Rappresentazione dei numeri relativi

Rappresentazione in modulo e segno
Modulo e segno: viene destinato il bit più significativo al segno (0 = +, 1 = -) e i restanti bit al
modulo del numero
Esempio:
Con la rappresentazione modulo e segno in 𝑛 bit si possono rappresentare 2𝑛 − 1 numeri così
divisi:
•
2𝑛−1 numeri positivi (incluso lo zero)
•
2𝑛−1 numeri negativi (incluso lo zero)
L’intervallo rappresentabile è −2𝑛−1 + 1, 2𝑛−1 − 1 10
segno
modulo
1
1
0
1
0
1
0
1
−𝟖𝟓

Rappresentazione in modulo e segno
Se ho a disposizione 𝑛 bit posso normalmente rappresentare 2𝑛 valori, ma con il modulo
e segno ne riesco a rappresentare 2𝑛 − 1
Ciò è dovuto alla doppia rappresentazione del valore zero:
Che corrispondono rispettivamente a +0 e −0
segno
modulo
0
0
0
0
0
0
0
0
1
0
0
0
0
0
0
0

Operazioni di somma e sottrazione
•
Vedremo di seguito come vengono effettuate le operazioni di addizione e sottrazione nella
nostra rappresentazione dei dati
•
Le operazioni di sottrazione possono essere sempre ottenute invertendo il sottraendo:
𝐴 − 𝐵 = 𝐴 + (−𝐵)
•
Vi saranno casi in cui le operazioni produrranno un overflow in termini di bit. Laddove i segni
siano concordi è necessario valutare se la somma dei moduli (sia essa positiva o negativa)
costituisca un valore rappresentabile con il numero di bit scelti per la rappresentazione:
•
Se il modulo è troppo grande per essere rappresentato si ha una situazione di overflow (se gli operandi
sono positivi) o di underflow (se gli operandi sono negativi) – le operazioni produrranno dunque un
risultato errato
•
Se invece il modulo può essere rappresentato, il bit in eccesso dovrà essere gestito correttamente per
garantire la validità del risultato
•
Il bit in eccesso si può presentare anche nei casi in cui i segni sono discordi, in tal caso dovrà
essere gestito correttamente per garantire la validità del risultato

Rappresentazione in modulo e segno
Somma e sottrazione in modulo e segno:
Per effettuare le operazioni di somma e sottrazione tra numeri in modulo e segno è
necessario rimuovere il bit di segno e procedere come segue sulla base del segno:
Ipotizzando di voler effettuare la somma 𝐴 + 𝐵
Svantaggio: eccessivamente complicato
𝐴 > 0
𝐴 < 0
𝐵 > 0
|𝐴| + |𝐵|
Se 𝐵 < |𝐴| allora – (|𝐴| − |𝐵|)
Se 𝐵 > |𝐴| allora 𝐵 − |𝐴|
𝐵 < 0
Se 𝐴 < |𝐵| allora – (|𝐵| − |𝐴|)
Se 𝐴 > |𝐵| allora 𝐴 − |𝐵|
− 𝐴 + 𝐵

Rappresentazione in complemento a uno
Complemento a uno: i numeri negativi vengono rappresentati tramite il complemento
della loro rappresentazione positiva
Esempio:
Posso rappresentare anche qui 2𝑛 − 1 valori, in quanto vi è la doppia rappresentazione
dello 0: 00000000 e 11111111
L’intervallo rappresentabile è anche qui −2𝑛−1 + 1, 2𝑛−1 − 1 10
Il primo bit non viene comunque utilizzato per rappresentare il modulo (in quanto se fosse
1 supererebbe il valore massimo rappresentabile), quindi può essere utilizzato per
identificare il segno
decimale
binario
+89
0
1
0
1
1
0
0
1
-89
1
0
1
0
0
1
1
0

Rappresentazione in complemento a uno
Somma e sottrazione in complemento a uno:
Si procede sommando normalmente i valori, e, laddove l’operazione produca un riporto
successivo al bit del segno, quest’ultimo viene aggiunto al risultato:
Svantaggio: il riporto in eccesso va sommato, quindi potrei avere una somma in più da effettuare
Vantaggio: evidentemente più comodo del modulo e segno
decimale
binario
riporti
1
1
1
+10
0
1
0
1
0
+
-4
1
1
0
1
1
=

1
0
0
1
0
1
0
0
1
0
1
+
1
=

+6
0
0
1
1
0
Riporto in
eccesso
(overflow di bit)

Rappresentazione in complemento a due
Complemento a due: i numeri negativi vengono rappresentati con il complemento a uno
incrementato di 1
Esempio:
Il primo bit non viene comunque utilizzato per rappresentare il modulo (in quanto se fosse
1 supererebbe il valore massimo rappresentabile), quindi può essere utilizzato per
identificare il segno
decimale
binario
+90
0
1
0
1
1
0
1
0
-90
(Ca1)
1
0
1
0
0
1
0
1
-90
(Ca2)
1
0
1
0
0
1
1
0

Confronto tra rappresentazioni su 4 bit
Decimale
Senza segno
Modulo e segno
Complemento a uno Complemento a due
8
1000
n/d
n/d
n/d
7
111
0111
0111
0111
6
110
0110
0110
0110
5
101
0101
0101
0101
4
100
0100
0100
0100
3
11
0011
0011
0011
2
10
0010
0010
0010
1
1
0001
0001
0001
(+)0
0
0000
0000
0000
(−)0
n/d
1000
1111
−1
n/d
1001
1110
1111
−2
n/d
1010
1101
1110
−3
n/d
1011
1100
1101
−4
n/d
1100
1011
1100
−5
n/d
1101
1010
1011
−6
n/d
1110
1001
1010
−7
n/d
1111
1000
1001
−8
n/d
n/d
n/d
1000

Vantaggi del complemento a due
Vantaggio n° 1a: unica rappresentazione dello zero
Si può notare che la rappresentazione di +0 e −0 si equivalgono, in quanto la somma
finale genera un overflow che non viene considerato in quanto sfora il numero di bit in
considerazione
decimale
binario
0
0
0
0
0
0
0
0
0
-0
(Ca1)
1
1
1
1
1
1
1
1
-0
(Ca2)
1
0
0
0
0
0
0
0
0

Vantaggi del complemento a due
Vantaggio n° 1b: uso al massimo delle rappresentazioni possibili
Questo vantaggio deriva dal fatto che, contestualmente al fatto che lo zero viene
rappresentato una sola volta, la rappresentazione «aggiuntiva» occupata dallo zero nel
Ca1 diventa la rappresentazione di un altro valore
In particolare:
•
lo zero resta corrispondente solo alla notazione composta da tutti 0
•
la notazione composta da tutti 1 corrisponde invece al valore −1
•
Viene rappresentato un valore negativo in più: −2𝑛−1
In complemento a due su 𝑛 bit sono quindi rappresentati 2𝑛 valori
L’intervallo rappresentabile è quindi −2𝑛−1, 2𝑛−1 − 1 10

Rappresentazione in complemento a due su 4 bit
decimale
binario
-8
1
0
0
0
-7
1
0
0
1
-6
1
0
1
0
-5
1
0
1
1
-4
1
1
0
0
-3
1
1
0
1
-2
1
1
1
0
-1
1
1
1
1
0
0
0
0
0
+1
0
0
0
1
+2
0
0
1
0
+3
0
0
1
1
+4
0
1
0
0
+5
0
1
0
1
+6
0
1
1
0
+7
0
1
1
1
decimale
binario
+0
0
0
0
0
+1
0
0
0
1
+2
0
0
1
0
+3
0
0
1
1
+4
0
1
0
0
+5
0
1
0
1
+6
0
1
1
0
+7
0
1
1
1
-8
1
0
0
0
-7
1
0
0
1
-6
1
0
1
0
-5
1
0
1
1
-4
1
1
0
0
-3
1
1
0
1
-2
1
1
1
0
-1
1
1
1
1
in ordine di valore
in ordine di rappresentazione binaria

Rappresentazione in complemento a due su 4 bit

Rappresentazione in complemento a due
Il valore decimale di un numero negativo in complemento a due può essere ricavato velocemente
tramite il seguente trucco
Considero solo i valori 1 senza considerare il bit di segno.
Sommo al valore di potenza di 2 negato corrispondente al bit più significativo (cioè −2𝑛−1 su Ca2
a 𝑛 bit) i valori di potenza di due corrispondenti ai bit avvalorati a 1:
−128 + 32 + 8 + 4 + 1 = −𝟖𝟑
Il valore di un numero binario su 𝑛 bit composto dai bit 𝑐𝑁−1𝑐𝑁−2 … 𝑐1𝑐0 in complemento a due è
equivalente infatti a:
−2𝑛−1𝑐𝑛−1 + ෍
𝑖=0
𝑛−2
𝑐𝑖2𝑖
𝟐𝟕
𝟐𝟔
𝟐𝟓
𝟐𝟒
𝟐𝟑
𝟐𝟐
𝟐𝟏
𝟐𝟎
1
0
1
0
1
1
0
1
-128
+32
+8
+4
+1

Rappresentazione in complemento a due
Somma e sottrazione in complemento a due: si procede normalmente ignorando
l’eventuale bit di overflow
Vantaggio n° 2 del complemento a due: somme e sottrazioni possono essere ottenute
senza particolari problemi
decimale
binario
riporti
1
1
1
+10
0
1
0
1
0
+
-6
1
1
0
1
0
=

1
0
0
1
0
0
+4
0
0
1
0
0

Bug dell’anno 2038
Nel complemento a due, come abbiamo potuto notare
precedentemente,
sommando
1
al
numero
più
grande
rappresentabile si ottiene il numero più piccolo rappresentabile
Questo effetto indesiderato può procurare bug nei sistemi che
gestiscono il tempo come numero intero:
•
Ad esempio, nei sistemi UNIX, il tempo è considerato come il
numero
di
secondi
a
partire
dal
capodanno
del
1970
(rappresentazione POSIX)
Poiché tale valore di tempo veniva memorizzato in variabili da
32 bit, giunti al massimo valore rappresentabile, il secondo
immediatamente successivo viene interpretato come il minimo
valore rappresentabile su 32 bit:
<https://it.wikipedia.org/wiki/Bug_dell%27anno_2038>

Rappresentazione dei numeri razionali

Rappresentazione dei numeri razionali
Per rappresentare un numero razionale* (al netto degli errori di approssimazione) vi sono
due strade principali:
Notazione in virgola fissa: dedico un numero di cifre alla parte intera e un numero di
cifre alla parte decimale:
±𝒊𝒊𝒊𝒊, 𝒅𝒅𝒅
Notazione in virgola mobile (floating point – IEEE 754): faccio scorrere la virgola
secondo le esigenze di rappresentazione – rappresenta molti più valori utilizzando gli
stessi bit rispetto alla virgola fissa

- I numeri reali sono composti dai numeri razionali + i numeri irrazionali: i numeri irrazionali
non sono rappresentabili

Rappresentazione in mantissa, base ed esponente
Qualsiasi numero può essere scritto nella seguente forma:
±𝑀 × 𝑏±𝑒
Dove 𝑀 prende il nome di mantissa, 𝑏 è la base ed 𝑒 è l’esponente
Quando tale sistema viene applicato alla base 10 prende il nome di notazione scientifica
(ad esempio 0,83234 × 102)
Naturalmente, tale rappresentazione dovrà essere approssimata destinando un certo
numero di bit alla mantissa e un certo numero di bit all’esponente

Rappresentazione floating point
Precisione nel floating point:
Non è necessario memorizzare la base in quanto è implicita (2)
Non tutte le configurazioni di esponenti sono disponibili, alcune sono riservate
Gli esponenti sono rappresentati in forma polarizzata, ovvero si memorizza in binario
l’esponente sommato a una costante che è detta bias – ciò consente di effettuare più facilmente
controlli di maggioranza o minoranza tra interi polarizzati (l’esponente più basso assume valore
00000000 e il più alto 11111111)
Precisione singola
Precisione doppia
Bit per il segno
1
1
Bit per l’esponente
8
11
Bit per la mantissa
23
52
Bit totali
32
64
Intervallo esponente
[-126, 127]
[-1022, 1023]
Bias esponente
127
1023

Rappresentazione in floating point
Vi sono diverse tipologie di numeri nel floating point:
segno
esponente
mantissa
±
≠0 e ≠111…111
Qualsiasi
±
0
Qualsiasi (tranne 0)
±
0
0
±
111…111
0
±
111…111
Qualsiasi (tranne 0)
Numero normalizzato
Numero denormalizzato
±0
±∞
NaN (Not a Number)

Floating point: numeri normalizzati
Un numero normalizzato espresso in floating point su un calcolatore è definito come
segue:
±1, 𝑥𝑥𝑥𝑥𝑥𝑥𝑥2 × 2𝑦𝑦𝑦𝑦
𝑥𝑥𝑥𝑥𝑥𝑥𝑥 sono i bit destinati alla mantissa e 𝑦𝑦𝑦𝑦 i bit destinati all’esponente.
Il valore di mantissa in un numero normalizzato è sempre compreso tra 1 (compreso) e 2
(escluso)
Si usano tutti i bit 𝑥 per identificare la parte frazionaria (l’1 intero è implicito)

Floating point: numeri normalizzati
Il valore di un numero a 32 bit in floating point è dato dalla seguente formula:
−1 𝑏31 × 2 𝑏30, 𝑏29, … , 𝑏23 −127 × 1, 𝑏22𝑏21 … 𝑏0 2

Convertire un numero reale in binario
Per la parte intera si procede come già visto
Per la parte frazionaria si moltiplica il valore per 2 e si prende la cifra intera ricavata, la si sottrae e si procede fin
quando non si esaurisce la precisione (numero di cifre binarie che è possibile memorizzare) o il risultato è 1
Esempio:
19,312510 =?2
Step 1: Parte intera
1910 = 100112
Step 2: Parte decimale
0,3125 × 2 = 0,625
0,625 × 2 = 1,250
0,250 × 2 = 0,500
0,500 × 2 = 1,0
Quindi 19,312510 = 10011,01012
Ho ottenuto
precisamente 1
FINE ALGORITMO

Convertire un numero reale in binario
Proviamo a vedere se è vero…
16 + 2 + 1 + 0,25 + 0,0625 = 19,3125
Dopo aver effettuato la conversione si imposta l’esponente in maniera tale da far scorrere
la virgola del numero di posizioni necessarie per rappresentare il numero correttamente
𝟐𝟒
𝟐𝟑
𝟐𝟐
𝟐𝟏
𝟐𝟎
𝟐−𝟏
𝟐−𝟐
𝟐−𝟑
𝟐−𝟒
1
0
0
1
1
,
0
1
0
1
16
2
1
0,25
0,0625

Floating point: numeri denormalizzati
Un numero denormalizzato espresso in floating point su un calcolatore è definito come
segue:
±0, 𝑥𝑥𝑥𝑥𝑥𝑥𝑥2 × 21−𝑏
𝑏 è il bias
Qui la mantissa è sempre compresa tra 0 e 1 e i bit dell’esponente sono impostati a 0
Servono a riempire l’intervallo tra lo zero e il più piccolo numero normalizzato
rappresentabile

Floating point su 32 bit (precisione singola)

Rappresentazione in floating point
In generale l’aritmetica a virgola mobile è affetta da alcune problematiche:
•
Non sono valide in generale la proprietà associativa e la proprietà distributiva
•
Assorbimento: ad esempio 1015 + 1 = 1015
•
Cancellazione: si ottiene quando sottraendo due numeri molto vicini si ottiene 0
•
Arrotondamento
Gli errori di calcolo sono invece ottenuti da:
•
Le operazioni in overflow danno risultato +∞, −∞
•
Situazioni di underflow, ovvero valori molto piccoli trasformati in 0
•
Le operazioni impossibili (ad esempio la radice quadrata di un numero negativo) restituisce NaN

Rappresentazione in floating point
I problemi di arrotondamento sono dati da una duplice natura:

1. Operazioni aritmetiche: Τ
2 3 = 0,666667
2. Numeri non rappresentabili
Ad esempio 0,1 non è un numero rappresentabile:
0,1 × 2 = 0,2
0,2 × 2 = 0,4
0,4 × 2 = 0,8
0,8 × 2 = 1,6
0,6 × 2 = 1,2
0,2 × 2 = 0,4
0,4 × 2 = 0,8
…
Si ha un evidente ciclo infinito sulla cifra finale 2-4-8-6

Operazioni in floating point
Confronto di uguaglianza: Poiché i dati possono provenire da operazioni di natura
diversa ha senso definire l’uguaglianza come segue:
A = B ⟺
𝐴 − 𝐵 < 𝜀
ovvero se i due numeri sono «sufficientemente» vicini tra loro
Confronto maggiore/minore: non è un caso che vengano memorizzati nell’ordine segno,
esponente e mantissa. Per confrontarli è sufficiente scorrere i bit dei due numeri fin
quando non si trova un bit diverso:
•
Se si trova nel segno, è più grande il numero con il segno positivo (0)
•
Se si trova nell’esponente o nella mantissa è più grande il numero con il bit a 1

Operazioni in floating point
Somma/sottrazione:
•
Si allineano i due numeri per raggiungere lo stesso esponente
•
Si sommano le mantisse
•
Si normalizza il risultato
•
Si controlla se è overflow o underflow
•
Si arrotonda il numero
•
Se non è normalizzato, lo si normalizza
Prodotto/divisione:
•
Si sommano gli esponenti – bias
•
Si moltiplicano le mantisse
•
Si normalizza il risultato
•
Si controlla se è overflow o underflow
•
Si arrotonda il numero
•
Se non è normalizzato, lo si normalizza
