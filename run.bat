@ECHO OFF

fc main.cpp backup.cpp > nul

if errorlevel 1 (
  frun
) else (
  exec\clock
)