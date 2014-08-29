@echo off

:SetupEnvironment
	setlocal enableextensions

	set LocalDir=%~d0%~p0
	if %LocalDir:~-1%==\ set LocalDir=%LocalDir:~0,-1%
	set UtilDir=%LocalDir%\.util

	if "%1"=="" goto Error
	if not exist "%1" goto Error
	
	set root=..\plugins\
	set name=%~n1
	echo Creating plugin "%name%"

:ExpandProject
	set WorkDirRelative=%LocalDir%\%root%
	pushd %WorkDirRelative%
	set WorkDir=%CD%
	popd

	"%UtilDir%\txpand" -w "%WorkDir%\~tmp" -o "%WorkDir%" -t "%UtilDir%\template_update" %name%
	if not exist "%WorkDir%\~tmp" goto ExitScript
	if exist "%WorkDir%\~tmp" del /q "%WorkDir%\~tmp"
	copy /y "%1" "%WorkDir%\%name%\%name%.h" 1>NUL
	"%UtilDir%\svn.exe" add "%WorkDir%\%name%"
	goto ExitScript
	
:Error
	echo Usage: %~n0 ^<source file^>
	echo ^<source file^> must exist.
	
:ExitScript