# Changelog

All notable changes to this project will be documented in this file.

Loosely based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).
Commit messages should follow the [Conventional Commits Specification](https://www.conventionalcommits.org/en/v1.0.0/#summary).

## \[unreleased\]

### Bug Fixes

- Rewrite board printing prototype, still WiP
- Switch pos of `STR_END` and `LINE_END` in `globals.h`
- Rename to `src/types`
- Conform `GOOSE_SQUARE` to `GOOSE_VALUE`
- Conform `recotds.txt` to syntax
- Fix variable name in main `board.txt` algorithm
- Change `new_board` for `board`
- Properly format `globals.txt`
- Complete `board.txt` module
- Use `square` instead of `space` to improve clarity
- Add file doxygen, remove main(), adjust Entry declaration
- Fix typo
- Add base path for snippets
- Remove `notes` folder
- Fix various typos and conform to new folder name (`svgs`)
- Fix mkdocs.yml spacing
- Addo short phrase to improve readability
- Improve structure, complete unfinished work
- Improve readability, better file structure
- Complete the rewrite of SO2
- Remove trailing spaces
- Comment out the TODOs, useless to have them in plain text
- General syntax fix, add various mermaid charts
- Rewrite of the page
- Rewrite page
- Fix typos, mispelling and phrasing
- Rename to add page index to filename
- Replace empty file with one with content
- Remove linter warnings, fix typos, adjust syntax
- :fire: change LaTeX math delimiter, fix syntax, complete pages
- :fire: change all `$...$` for `\(...\)` and `$$...$$` to `\[...\]`
- Syntax cleanup, complete page
- Fix spacing, refine old commands, improve new ones
- Fix old commands, add new commands
- :pencil2: fix (&shorten) page name
- :bug: correct syntax, remove wrong symbols
- Fix typos, format, add sections
- Fix command names, add new section
- Change command name, add negative hspace
- :pencil2: fix typos and syntax
- :art: change `i++` to `i = i + 1`
- Reformat code using clang_format, fix linter warnings
- Rewrite project tree structure comments, remove unused footnote
- :pencil2: fix typo
- 🐛 move javascript explanation to file tree
- 🐛 rewrite file structure, update footnotes
- :bug: correct `.editorconfig` syntax
- :memo: rewrite README.md
- :see_no_evil: remove `binaries/` from gitignore
- :ok_hand: change condition of while loop to `>=`
- :pencil2: correct comments
- :pencil2: fix name error for `LICENSE.md`
- :art: add blank line
- :pencil: change `HW` for `Hardware` and `SW` for `Software`
- :art: use `&&` to combine operations
- :pencil2: fix typo
- :recycle: refactor to change variables names
- :fire: remove gh action
- :art: update file structure, remove linter warnings
- :fire: remove extra comment
- :fire: remove `index.md`, useless
- :art: improve format and spelling
- :fire: remove latex `\newcommand`
- :fire: remove comment
- :fire: remove files, moved to other folder
- :bug: change file extension
- :page_facing_up: add licence
- :fire: complete overhaul of folder structure

### Features

- Translate from `board.txt` to C code
- Start converting pseudo into C code, !prototype!
- Prototype C fn to print out the game board
- Add handouts from class
- Add `@brief`s for functions
- Almost complete pseudocode for board.txt, create file for structs
- Create txt file for global variables
- Add src folder, will populate with time
- Add more prototypes, need adjusting, maybe removing
- Create leaderboard.h module
- Create folder for project prototyping
- Record barebone demo of main menu
- Add new note file for InfLab
- Add testing module !needs rewrite
- Complete the leaderboard module, create txt file
- Start prototyping for game of goose
- Rewrite and adjust notes for InfLab
- Add code relative to exercise of 29/03
- Add new lab notes
- Add new file for `AESO`
- Add new note file for lab
- Add new custom admonition
- Add code for ex of `22-03-23`
- Add new terms to the glossary and sort them
- Add new page for `AESO`, already completed
- Add new page for AESO
- Add macro for inline p-matrices
- Remove unwanted backslashes
- Add exercises and notes, fix formatting
- Remove notes folder in favour of no folder
- Remove all TODOs from file, add missing images, improve structure, fix typos
- Add entries, sort alphabetically
- Add new entries to the glossary
- Change default favicon
- Add emoji support, improve homepage
- Remove old workflow, modify the current to be more verbose and install plugins
- [**BREAKING**] Add more settings, custom CSS; change color scheme
- Add hyperlinks to remaining badges
- Add hyperlinks to badges
- Add landing page
- Add units of measurement
- Add macros
- Semi-finish page, add some images (SVGs)
- Add QoL macros
- Rewrite page, adjust formatting, remove some linter warnings
- Add macros for bit/byte units, fix wrong plugin loading
- Add commit/month activity badge
- Rename old pdfs, add new ones
- Small rewrite of (almost) all LaTeX macros (WiP)
- Add section, correct paragraph titles
- Add LaTeX commands, fix older commands
- Add more LaTeX macros, add text plugin
- Add LaTeX command for Sx, Dx and ^
- Add new page
- Add LaTeX macros
- Add new LaTeX macros
- Create course folder
- Remove linter warnings
- Add new LaTeX macros
- :see_no_evil: update `.gitignore` to include python
- :wrench: add `.editorconfig`
- :heavy_plus_sign: add husky and commitizen dependencies
- [**BREAKING**] :truck: use `-` as digit separator (`.` is confusing)
- :see_no_evil: updated gitignore for `.c` files
- :pencil: update readme to include more infos on hook and project structure
- :recycle: actually use half the loC for the hook
- :bento: ignore automatic commits from husky hook
- :pencil: create notes about top-down
- ✨ update `README.md`
- :construction_worker: add pull before push
- :sparkles: complete document
- :speech_balloon: update settings, create snippet file
- :speech_balloon: update .vscode settings
- :art: improve format, remove linter warnings & blank lines
- :sparkles: create some math macros
- :ok_hand: completing first two pages
- :lipstick: enable collapsible sections in side nav bar
- :package: update mkdocs config
- :package: update vscode settings

### Miscellaneous Tasks

- :fire: remove github action in favour of a pre-push hook

### Refactor

- [**BREAKING**] :recycle: hook is faster s/ half the lines
- [**BREAKING**] :recycle: rewrite hook to re-use functions and have better checks
- :recycle: change file structure, generate changelog automatically
- :recycle: change header, add parsers, customize settings

### Testing

- Test deploy with gh actions

### Fix

- [**BREAKING**] :truck: rename folder to long name

Automatically generated by [git-cliff](https://www.github.com/orhun/git-cliff).
