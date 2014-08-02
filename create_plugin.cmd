@echo off

:SetupEnvironment
	setlocal enableextensions

	set LocalDir=%~d0%~p0
	if %LocalDir:~-1%==\ set LocalDir=%LocalDir:~0,-1%
	set UtilDir=%LocalDir%\.util

	if "%1"=="" goto ExpandProject
	echo Creating plugin "%1"

:ExpandProject
	"%UtilDir%\txpand" -w "%LocalDir%\~tmp" -o "%LocalDir%" -t "%UtilDir%\template" %1
	if not exist "%LocalDir%\~tmp" goto ExitScript
	set /p name=<"%LocalDir%\~tmp"
	if exist "%LocalDir%\~tmp" del /q "%LocalDir%\~tmp"
	"%UtilDir%\svn.exe" add ".\%name%"

:ExitScript