@echo off
setlocal enableextensions
if "%1"=="" goto err
if not exist "%~d0%~p0%1" goto err
set prof=vcpp2012
set dd=%~d0%~p0
if not exist "%~d0%~p0%1\.profile" goto noprof
for /f "tokens=*" %%a in (%~d0%~p0%1\.profile) do set prof=%%a
:noprof
set script=%~d0%~p0build_%prof%.cmd
rem if not exist "%script%" do (
rem   echo No such profile: %prof% - script %script% is missing!
rem   goto eof
rem )
"%script%" %*
goto eof
:err
echo Usage: build ^<name^>
echo.
:eof