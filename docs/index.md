# Home

Raccolta di appunti, file, slides, etc. relativi al corso di Informatica L31,
A.A. 2021-22, dell'Università di Bari "Aldo Moro".

!!! warning "Attenzione"
    Gli appunti sono in fase di stesura e cambiano virtualmente ogni giorno.

## Come contribuire

Se si vuole contribuire al progetto bisogna innanzitutto clonare la repository

=== ":material-git: Git"

    ```sh linenums="0" title=""
    git clone https://github.com/sRavioli/L31.git
    ```

=== ":material-github: GitHub CLI"

    ```sh linenums="0" title=""
    gh repo clone sRavioli/L31
    ```

Una volta clonata la repository, recarsi nella cartella (`#!bash cd L31`) e
installare [Material for MkDocs](https://squidfunk.github.io/mkdocs-material/)
idealmente in un [ambiente virtuale](https://realpython.com/what-is-pip/#using-pip-in-a-python-virtual-environment):

```sh linenums="0" title=""
# .\venv\scripts\activate
pip install mkdocs-material
```

Dopodiché sarà necessario installare le dipendenze del progetto:

```sh linenums="0" title=""
pip install pillow cairosvg
pip install mkdocs-glightbox
```

Avviare il server:

```sh linenums="0" title=""
mkdocs serve --dirtyreload
```

Verrà lanciato un server su <http://localhost:8000/L31> dove saranno presenti
gli appunti. La flag `#!bash --dirtyreload` permette di avere un deploy molto
più veloce poiché carica solo la pagina corrente e questo è ottimale se si
sta modificando la pagina.
Per interrompere il server basta premere ++ctrl+c++.

Per contribuire è necessario creare un nuovo ramo:

```sh linenums="0" title=""
git checkout -b feat/nuova-feature
```

effettuare gli eventuali commit sullo stesso

```sh linenums="0" title=""
git commit -m "feat: add new feature"
```

effettuare il push del nuovo ramo:

```sh linenums="0" title=""
git push -u origin feat/nuova-feature
```

e infine recarsi su :material-github: GitHub e aprire una pull request.
