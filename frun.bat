@ECHO OFF

if exist exec\main.exe ( del exec\main.exe )
@REM g++ stdc++.h -O2 -Wall -Wno-sign-compare -Wno-char-subscripts -Wno-reorder -Wno-parentheses -static -std=gnu++20 -pedantic
g++ main.cpp -o exec\main -O2 -Wall -Wno-sign-compare -Wno-char-subscripts -Wno-reorder -Wno-parentheses -static -std=gnu++20 -pedantic -lm
copy /Y main.cpp backup.cpp > nul
if exist exec\main.exe (
  echo compiled
  exec\clock
)