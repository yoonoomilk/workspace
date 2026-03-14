@ECHO OFF

g++ exec\clock.cpp -o exec\clock -O2 -Wall -Wno-sign-compare -Wno-char-subscripts -Wno-reorder -Wno-parentheses -std=gnu++23
python exec\gen_snippets.py