@ECHO OFF

git submodule update --remote --merge > nul
exec\gen_snippets.py