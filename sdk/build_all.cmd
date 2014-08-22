@echo off
set root=..\plugins\
FOR /f "tokens=*" %%d IN ('dir /b %root%\*.') DO ("%~d0%~p0build" %%d %*)