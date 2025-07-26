@ECHO OFF

set /p str="template: "

if exist "template\%str%.cpp" (
  copy /Y "template\%str%.cpp" main.cpp > nul
  @REM code main.cpp
) else if exist "template\%str%.c" (
  copy /Y "template\%str%.c" main.c > nul
  @REM code main.c
) else (
  echo no template named %str%
)