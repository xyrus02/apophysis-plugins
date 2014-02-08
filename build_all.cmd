@echo off
FOR /f "tokens=*" %%d IN ('dir /b *.') DO ("%~d0%~p0build" %%d)