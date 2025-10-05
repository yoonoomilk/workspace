@ECHO OFF

if not exist exec\main.exe (
  exec\frun
)

fc main.cpp exec\backup.cpp > nul

if errorlevel 1 (
  exec\frun
) else (
  exec\clock
)
