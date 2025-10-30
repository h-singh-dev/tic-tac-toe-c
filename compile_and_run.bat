@echo off
echo Compiling Tic Tac Toe Game...
echo =============================

REM Try to compile with gcc (MinGW, TDM-GCC, etc.)
gcc tic_tac_toe.c -o tic_tac_toe.exe
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful!
    echo Running the game...
    echo ===================
    tic_tac_toe.exe
    goto end
)

REM If gcc is not found, try Visual Studio compiler
cl tic_tac_toe.c /Fe:tic_tac_toe.exe >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful!
    echo Running the game...
    echo ===================
    tic_tac_toe.exe
    goto end
)

echo.
echo Error: No C compiler found.
echo Please install one of the following:
echo  - MinGW (includes gcc)
echo  - TDM-GCC
echo  - Visual Studio (includes cl compiler)
echo  - Code::Blocks (includes MinGW)
echo  - Dev-C++ (includes MinGW)
echo.
echo After installation, make sure the compiler is in your PATH.
echo Alternatively, open this project in Code::Blocks or Dev-C++.

:end
pause