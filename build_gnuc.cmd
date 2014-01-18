@echo off
if "%1"=="" goto err
if not exist "%~d0%~p0%1\%1.c" goto err
if not exist "%~d0%~p0%1\bin" mkdir "%~d0%~p0%1\bin"
if not exist "%~d0%~p0%1\obj" mkdir "%~d0%~p0%1\obj"
"%~d0%~p0.util\.mingw\bin\mingw32-gcc.exe" -O2 -Wall -DBUILD_DLL -c "%~d0%~p0%1\%1.c" -o "%~d0%~p0%1\obj\%1.o"
if not exist "%~d0%~p0%1\obj\%1.o" goto eof
"%~d0%~p0.util\.mingw\bin\mingw32-g++.exe" -shared -Wl,--output-def="%~d0%~p0%1\obj\%1.def" -Wl,--out-implib="%~d0%~p0%1\obj\%1.a" -Wl,--dll "%~d0%~p0%1\obj\%1.o" -o "%~d0%~p0%1\bin\%1.dll" -s -luser32
if not exist "%~d0%~p0%1\bin\%1.dll" goto eof
if not exist "%~d0%~p0.output" mkdir "%~d0%~p0.output"
copy /y "%~d0%~p0%1\bin\%1.dll" "%~d0%~p0.output\%1.legacy.dll" 
goto eof
:err
echo Usage: build_gnuc ^<name^>
echo.
:eof