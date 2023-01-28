# L31 – Appunti di Informatica

![GitHub](https://img.shields.io/github/license/sRavioli/L31)
![GitHub issues](https://img.shields.io/github/issues/sRavioli/L31)
![GitHub last commit](https://img.shields.io/github/last-commit/sRavioli/L31)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/sRavioli/L31)

Raccolta di appunti, file, slides, etc. relativi al corso di Informatica L31,
A.A. 2021-22, dell'Università di Bari "Aldo Moro".

## Eseguire Localmente

Clonare il progetto

```bash
git clone https://github.com/sRavioli/L31.git
```

Recarsi nella cartella del progetto

```bash
cd L31
```

e installare [Material for MkDocs](https://squidfunk.github.io/mkdocs-material/),
idealmente in un ambiente virtuale[^1].

```bash
pip install mkdocs-material
```

Avviare il server

```bash
mkdocs serve
```

MkDocs avvierà un server su [localhost:8000](http://localhost:8000/) dove
saranno presenti gli appunti.

<!-- markdownlint-disable MD033 -->
Per interrompere il server basta premere <kbd>Ctrl</kbd>+<kbd>C</kbd>.
<!-- markdownlint-enable MD033 -->

## Struttura

È possibile consultare gli appunti o le slides direttamente, senza dover far
partire il server mkdocs. Segue la struttura degli appunti di Programmazione
come esempio:

```txt
./L31/DOCS/
├───Anno_I
│   └───Programmazione
│       ├───code                      [C]   Codice degli esercizi
│       ├───handouts                  [PDF] File di appunti
│       │   ├───articles              [PDF] Articoli di approfondimento
│       │   ├───examples              [PDF] Esempi fatti a lezione
│       │   └───exercises             [PDF] Esercizi fatti a lezione
│       └───notes                     [MD]  File di appunti
│           └───exercises             [MD]  Esercizi fatti a lezione con soluzione
└───javascripts
```

**Extra**:

- `📂 .husky` – presenta uno script che effettua commit automaticamente se
  `📂 .vscode/*` o `📄 CHANGELOG.md` vengono aggiornati[^2]. Inoltre genera
  automaticamente un changelog con [git-cliff](https://www.github.com/orhun/git-cliff);
- `📂 .vscode` – impostazioni, snippets e estensioni consigliate per
  [VSCode](https://github.com/microsoft/vscode);

## Come contribuire

1. Creare un fork della repository;
2. Creare un nuovo branch che rispecchi il nome del cambiamento (es.
   `feat/ex_programmazione` per indicare un nuovo esercizio di programmazione);
3. Aprire una Pull Request.

## Licenza

Il progetto è sotto licenza [Creative Commons Attribution 4.0 International](LICENSE.txt).

[^1]:
    Si trovano più informazioni nella sezione [installazione](https://squidfunk.github.io/mkdocs-material/getting-started/#installation)
    della documentazione di Material for MkdDocs.
[^2]:
    L'hook utilizza [Husky](https://typicode.github.io/husky/#/?id=install), che
    richiede [Node.js](https://nodejs.org/it/). Per ignorare l'hook (se non si
    vuole installare husky o per altri motivi) bisogna effettuare il push con
    la flag `--no-verify`.
