@echo off
setlocal enableextensions
set dd=%~d0%~p0
if %dd:~-1%==\ set dd=%dd:~0,-1%
set dir=%dd%\.util
"%dir%\txpand" -w "%dd%\~tmp" -o "%dd%" -t "%dir%\template" %*
if not exist "%dd%\~tmp" goto exit
for /f "tokens=*" %%a in (%dd%\~tmp) do set pname=%%a
del /q "%dd%\~tmp"
type "%dd%\%pname%\%pname%.vcxproj" | "%dir%\sxtract" "\u003CProjectGuid\u003E\u007B([a-z\d\x2D]+)\u007D\u003C\u002FProjectGuid\u003E" > "%dd%\~tmp"
if not exist "%dd%\~tmp" goto exit
for /f "tokens=*" %%a in (%dd%\~tmp) do set pguid=%%a
del /q "%dd%\~tmp"
"%dir%\slnadd" "%dd%\all_plugins.sln" "%pname%\%pname%.vcxproj" "%pguid%"
:exit