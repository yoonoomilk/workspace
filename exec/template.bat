@ECHO OFF

set /p str="base: "

if exist "base\%str%.cpp" (
  copy /Y "base\%str%.cpp" main.cpp > nul
  code main.cpp
) else if exist "base\%str%.c" (
  copy /Y "base\%str%.c" main.c > nul
  code main.c
) else (
  echo no base named %str%
)