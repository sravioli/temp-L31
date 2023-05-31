# L31 – Appunti di Informatica

[![Project license](https://img.shields.io/github/license/sRavioli/L31)](./LICENSE.txt)
[![GitHub issues](https://img.shields.io/github/issues/sRavioli/L31)](https://github.com/sRavioli/L31/issues)
[![GitHub last commit](https://img.shields.io/github/last-commit/sRavioli/L31)](https://github.com/sRavioli/L31/commit/main)
[![GitHub commit activity](https://img.shields.io/github/commit-activity/m/sRavioli/L31)](https://github.com/sRavioli/L31/commits/main)

Raccolta di appunti, file, slides, etc. relativi al corso di Informatica L31,
A.A. 2021-22, dell'Università di Bari "Aldo Moro".

## Struttura della repository

La repository contiene sia il materiale che i professori rilasciano, che gli
appunti. Per consultare le slides è necessario farlo da GitHub, per gli appunti
bisogna consultare il [sito](https://sravioli.github.io/L31/).

La struttura è semplice, tutti gli appunti sono contenuti all'interno della
cartella `docs/`, suddivisi in base all'anno accademico con la seguente sintassi:

```text
Anno_<numero>
```

dove con `<numero` si intende un numero romano che indichi l'anno del corso di
laurea. Ogni cartella del tipo `Anno_<numero>` contiene a sua volta altre
cartelle, ognuna delle quali rappresenta un corso differente. Ad esempio, gli
appunti di programmazione presentano la seguente struttura:

```text
L31/docs/Anno_I/
└───Programmazione
    ├───code
    │   ├───nov
    │   └───oct
    ├───exercises
    └───handouts
        ├───articles
        ├───examples
        └───exercises
```

La cartella `handouts/` contiene tutte le slides e il materiale che il professore
ha rilasciato, la cartella `code/` contiene dei file C relativi a esercizi, la
cartella `exercises/` contiene file relativi a esercizi effettuati in aula o
assegnati e poi corretti.

<!-- markdownlint-disable MD033 -->
<details>

<summary>per i curiosi</summary>

### `.husky/`

Contiene un piccolo script che controlla se la cartella `.vscode/` oppure il
file auto-generato `CHANGELOG.md` siano stati aggiornati e se sì, esegue
automaticamente il commit di questi cambiamenti.

Il pre-push hook utilizza [Husky](https://typicode.github.io/husky/#/?id=install),
che richiede [Node.js](https://nodejs.org/it/).

Per non far eseguire l'hook bisogna effettuare il push con la flag `--no-verify`:

```sh
git push --no-verify
```

### `.vscode/`

Contiene impostazioni, snippets e estensioni consigliate per l'editor
[VSCode](https://github.com/microsoft/vscode);

</details>

## Eseguire localmente

Innanzitutto è necessario clonare la repository:

```sh
git clone https://github.com/sRavioli/L31.git
cd L31
```

Se si ha [mask](https://github.com/jacobdeichert/mask), dopo aver clonato la
repository basterà scrivere:

```sh
mask prepare   # crea l'ambiente virtuale (va chiamato una sola volta)
mask serve     # attiva l'ambiente virtuale e avvia il server MkDocs
```

In alternativa, è necessario:

1. creare un ambiente virtuale python e attivarlo:

    ```sh
    python -m venv venv
    venv/Scripts/activate
    ```

2. installare [Material for MkDocs](https://squidfunk.github.io/mkdocs-material/)
   e i pacchetti necessari:

    ```sh
    python -m pip install --upgrade pip
    pip install -r requirements.txt
    ```

3. e infine avviare il server:

    ```sh
    mkdocs serve
    ```

MkDocs inizierà la build del sito, dopodiché quest'utltimo sarà accessibile
tramite browser all'indirizzo [localhost:8000](http://localhost:8000/).

Per interrompere il server MkDocs bisogna premere <kbd>Ctrl</kbd>+<kbd>C</kbd>
nel terminale.
<!-- markdownlint-enable MD033 -->

## Come contribuire

1. Creare un fork della repository;
2. Creare un nuovo branch che rispecchi il nome del cambiamento (es.
   `feat/ex_programmazione` per indicare un nuovo esercizio di programmazione);
3. Aprire una Pull Request.

## Licenza

Il progetto è sotto licenza [Creative Commons Attribution 4.0 International](./LICENSE.txt)
