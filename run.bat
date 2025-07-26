@ECHO OFF

if exist exec\main.exe (
  exec\clock
) else (
  echo no main.exe
)