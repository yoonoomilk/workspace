@ECHO OFF

if exist exec\main.exe (
  del exec\main.exe
)

copy /Y main.cpp exec\backup.cpp > nul

@REM g++ stdc++.h -O2 -Wall -Wno-sign-compare -Wno-char-subscripts -Wno-reorder -Wno-parentheses -std=gnu++23
g++ main.cpp -o exec\main -O2 -Wall -Wno-sign-compare -Wno-char-subscripts -Wno-reorder -Wno-parentheses -std=gnu++23 -lm -ID:/coding/c++/workspace/include

if %errorlevel% == 0 (
  echo compiled
  exec\clock
)