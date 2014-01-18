@echo off
FOR /f "tokens=*" %%d IN ('dir /b *.') DO (@IF EXIST "%~d0%~p0%%d\.profile" "%~d0%~p0build" %%d)