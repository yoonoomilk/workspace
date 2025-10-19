@ECHO OFF

git submodule update --remote --merge
exec\gen_snippets.py