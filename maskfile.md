# Tasks

> Useful tasks for the project

## install

> Will create a python virtual env and install the required dependencies.

Creates a virtual environment, activates it, upgrades pip to the latest version
and installs the required dependencies.

```bash
[[ "$verbose" == "true" ]] && echo "Creating python environment"
python -m venv venv

[[ "$verbose" == "true" ]] && echo "Activating python environment"
source venv/bin/activate

[[ "$verbose" == "true" ]] && echo "Upgrading pip"
python -m pip install --upgrade pip

[[ "$verbose" == "true" ]] && echo "Installing required dependencies"
pip install -r ./requirements.txt
```

```pwsh
if ($env:verbose) { Write-Output "Creating python environment" }
python -m venv venv

if ($env:verbose) { Write-Output "Activating python environment" }
./venv/Scripts/activate

if ($env:verbose) { Write-Output "Upgrading pip" }
python -m pip install --upgrade pip

if ($env:verbose) { Write-Output "Installing required dependencies" }
pip install -r ./requirements.txt
```

## serve

> Will activate the python virtual env, then serve the site.

**OPTIONS**

* dirty
  * flags: -d --dirty
  * desc: Serve site in dirty reload mode

```bash
[[ "$verbose" == "true" ]] && echo "Activating python environment"
source venv/bin/activate
if "$dirty" == "true"; then
  [[ "$verbose" == "true" ]] && echo "Running in dirtyreload mode..."
  mkdocs serve --dirtyreload
else
  [[ "$verbose" == "true" ]] && echo "Running..."
  mkdocs serve
fi
```

```pwsh
if ($env:verbose) { Write-Output "Activating python environment" }
./venv/Scripts/activate
if ($env:dirty) {
  if ($env:verbose) { Write-Output "Running in dirtyreload mode..." }
  Invoke-Expression -Command "mkdocs serve --dirtyreload"
} else {
  if ($env:verbose) { Write-Output "Running..." }
  Invoke-Expression -Command "mkdocs serve"
}
```

## sort-glossary

> It will sort alphabetically the contents of `includes/glossary.md`.

```bash
[[ "$verbose" == "true" ]] && echo "Sorting file contents"
sort ./includes/glossary.md > ./includes/sorted.md

[[ "$verbose" == "true" ]] && echo "Writing to file"
mv --force ./includes/sorted.md ./includes/glossary.md
```

```pwsh
if ($env:verbose) { Write-Output "Sorting file contents" }
Get-Content -Path ./includes/glossary.md `
    | Sort-Object `
    | Out-File -FilePath ./includes/sorted.md -Encoding UTF-8

if ($env:verbose) { Write-Output "Writing to file" }
Move-Item -Path ./includes/sorted.md -Destination ./includes/glossary.md -Force
```
