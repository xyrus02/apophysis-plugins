@echo off
set dd=%~d0%~p0
if %dd:~-1%==\ set dd=%dd:~0,-1%
set dir=%dd%\.util
"%dir%\txpand" -o "%dd%" -t "%dir%\template" %*
