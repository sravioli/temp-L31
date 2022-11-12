# Informatica – L31

L'obiettivo di questa repository è quello di racchiudere tutti gli appunti dei
vari corsi di Informatica, corso A-L.

## Struttura

La struttura della repository è la seguente:

- `📂 .husky`: contiene uno script che viene eseguito prima di ogni push[^1].
- `📂 .vscode`: contiene le impostazioni di VSCode e qualche snippet;
- `📂 docs`: la cartella principale, che contiene sia i files di appunti, che
  slides, che esercizi, etc.;
  - `📂 docs\javascripts`: cartella contenente i file JavaScript;
  - `📂 docs\Anno_<NUM>`: contiene i files relativi al corso di Informatica
    dell'anno numero `<NUM>` (es. `Anno_I` per il primo anno, etc.), è suddivisa
    in corsi (es. `Programmazione`, `Matematica Discreta`, etc.).

## Come consultare gli appunti

~~Per sfogliare gli appunti, è possibile utilizzare il sito web~~
~~[https://l31.github.io/informatica/](https://l31.github.io/informatica/)[^2].~~

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
Inoltre sarebbe opportuno creare un branch per ogni modifica, es.
`git checkout -b feat/ex-prog` per aggiungere un esercizio di programmazione.

## Licenza

Il progetto è sotto licenza [Creative Commons Attribution 4.0 International](LICENSE.md).

[^1]:
    Lo script controlla se ci sono cambiamenti nella cartella `.vscode` e effettua
    automaticamente il commit di questi, in modo da non doverlo fare manualmente.
    Inoltre genera automaticamente un changelog tramite [git-cliff](https://www.github.com/orhun/git-cliff)
    e anche di questo effettua il commit automaticamente.
    Per poter utilizzare Husky è necessario installare [Node.js](https://nodejs.org/it/)
    e ovviamente [Husky](https://typicode.github.io/husky/#/?id=install). Per
    ovviare, basta effettuare il commit con la flag `--no-verify`.

[^2]: Non è ancora stato effettuato il deploy del sito web.
