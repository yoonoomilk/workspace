@ECHO OFF

if not exist exec\main.exe (
  frun
)

fc main.cpp backup.cpp > nul

if errorlevel 1 (
  frun
) else (
  exec\clock
)