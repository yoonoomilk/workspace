@ECHO OFF

if exist exec\main.exe ( del exec\main.exe )
g++ main.cpp -o exec\main -O2 -Wall -Wno-sign-compare -Wno-char-subscripts -Wno-reorder -Wno-parentheses -lm -static -std=gnu++20
copy /Y main.cpp backup.cpp > nul
if exist exec\main.exe (
  echo compiled
  exec\clock
)