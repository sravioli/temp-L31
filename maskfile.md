# Tasks

> Useful tasks for the project

## prepare

> Will create a python virtual env and install the required dependencies.

Creates a virtual environment, activates it, upgrades pip to the latest version
and then will install the required dependencies.

~~~bash
python -m venv venv
source venv/bin/activate
python -m pip install --upgrade pip
pip install -r ./requirements.txt
~~~

~~~powershell
python -m venv venv
./venv/Scripts/activate
python -m pip install --upgrade pip
pip install -r ./requirements.txt
~~~

## serve

> Will activate the python virtual env, then serve the site.

~~~bash
source venv/bin/activate
mkdocs serve
~~~

~~~powershell
./venv/Scripts/activate
mkdocs serve
~~~

### serve dev

> Will serve in dirty reload mode, useful to develop the site.

~~~bash
source venv/bin/activate
mkdocs serve --dirtyreload
~~~

~~~powershell
./venv/Scripts/activate
mkdocs serve --dirtyreload
~~~
