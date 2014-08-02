@echo off

:SetupEnvironment
	setlocal enableextensions

	set LocalDir=%~d0%~p0
	if %LocalDir:~-1%==\ set LocalDir=%LocalDir:~0,-1%
	set UtilDir=%LocalDir%\.util

	if "%1"=="" goto Error
	if not exist "%1" goto Error
	
	set name=%~n1
	echo Creating plugin "%name%"

:ExpandProject
	"%UtilDir%\txpand" -w "%LocalDir%\~tmp" -o "%LocalDir%" -t "%UtilDir%\template_update" %name%
	if not exist "%LocalDir%\~tmp" goto ExitScript
	if exist "%LocalDir%\~tmp" del /q "%LocalDir%\~tmp"
	copy /y "%1" ".\%name%\%name%.h" 1>NUL
	"%UtilDir%\svn.exe" add ".\%name%"
	goto ExitScript
	
:Error
	echo Usage: %~n0 ^<source file^>
	echo ^<source file^> must exist.
	
:ExitScript