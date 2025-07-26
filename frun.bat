@ECHO OFF

if exist exec\main.exe ( del exec\main.exe )
g++ main.cpp -o exec\main -O2 -Wall -Wno-sign-compare -Wno-char-subscripts -Wno-reorder -Wno-parentheses -lm -static -std=gnu++20
if exist exec\main.exe (
  copy /Y main.cpp backup.cpp > nul
  echo compiled
  exec\clock
)