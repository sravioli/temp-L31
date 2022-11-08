# Informatica – L31

L'obiettivo di questa repository è quello di racchiudere tutti gli appunti dei
vari corsi di Informatica, corso A-L.

## Struttura

La struttura della repository è la seguente:

- `📂 .github\workflows`: contiene una GitHub Action che genera automaticamente
  un changelog ogni volta che viene effettuato un push su `main`;
- `📂 .husky`: contiene un pre-push hook che controlla se la cartella `.vscode` è
  stata modificata, dopodiché o effettua il commit o interrompe il push (viene
  chiesto all'utente in input);
- `📂 .vscode`: contiene opzioni e qualche snippet che facilitano la scrittura
  degli appunti;
- `📂 docs`: la cartella principale, che contiene sia i files di appunti, che
  slides, che esercizi, etc.;
  - `📂 docs\javascripts`: cartella contenente i file JavaScript;
  - `📂 docs\Anno_<NUM>`: contiene i files relativi al corso di Informatica
    dell'anno numero `<NUM>` (es. `Anno_I` per il primo anno, etc.), è suddivisa
    in corsi (es. `Programmazione`, `Matematica Discreta`, etc.).

## Come consultare gli appunti

~~Per sfogliare gli appunti, è possibile utilizzare il sito web~~
~~[https://l31.github.io/informatica/](https://l31.github.io/informatica/)[^1].~~

Per consultare gli appunti bisogna clonare la repository

```bash
$ git clone https://github.com/sRavioli/L31.git informatica
Cloning into 'informatica'...
# ...
```

oppure scaricare il file zip della repository e estrarlo.

Successivamente bisogna scaricare mkdocs

```bash
$ pip install mkdocs-material
Collecting mkdocs-material
# ...
```

e infine avviare il server

```bash
$ mkdocs serve
INFO     -  Building documentation...
INFO     -  Cleaning site directory
INFO     -  Documentation built in 14.52 seconds
INFO     -  [22:29:23] Watching paths for changes: 'docs', 'mkdocs.yml'
INFO     -  [22:29:23] Serving on # http://...
```

Mkdocs avvierà un server locale sulla porta 8000, quindi è ora possibile navigare
sul sito [localhost:8000](http://localhost:8000).

## Come contribuire

Per contribuire, è necessario creare una fork della repository, effettuare le
modifiche e poi aprire una pull request. Gli step sono gli stessi effettuati
per sfogliare il sito, le uniche differenze sono che è molto più comodo
utilizzare `mkdocs serve --dirtyreload` per avviare il server, in modo da
evitare di dover aggiornare ogni singola pagina, ma solo quella modificata.
Inoltre sarebbe opportuno creare una nuova branch per ogni modifica, es.
`git checkout -b feat/ex-prog` per aggiungere un esercizio di programmazione.

## Licenza

Il progetto è sotto licenza [Creative Commons Attribution 4.0 International](LICENCE.md).

[^1]: Non è ancora stato effettuato il deploy del sito web.
