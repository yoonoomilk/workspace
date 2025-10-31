@ECHO OFF

if not exist exec\main.exe (
  exec\frun
)

fc main.cpp exec\backup.cpp > nul

if %errorlevel% == 0 (
  exec\clock
) else (
  exec\frun
)
