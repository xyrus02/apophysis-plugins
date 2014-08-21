@echo off

:SetupEnvironment
	setlocal enableextensions

	set LocalDir=%~d0%~p0
	if %LocalDir:~-1%==\ set LocalDir=%LocalDir:~0,-1%
	set UtilDir=%LocalDir%\.util

	set root=..\plugins\
	set project=%~n1
	if "%1"=="" (
		set project=
		goto ExpandProject
	)
	
	echo Creating plugin "%project%"

:ExpandProject
	set WorkDirRelative=%LocalDir%\%root%
	pushd %WorkDirRelative%
	set WorkDir=%CD%
	popd

	"%UtilDir%\txpand" -w "%WorkDir%\~tmp" -o "%WorkDir%" -t "%UtilDir%\template" %project%
	if not exist "%WorkDir%\~tmp" goto ExitScript
	set /p name=<"%WorkDir%\~tmp"
	if exist "%WorkDir%\~tmp" del /q "%WorkDir%\~tmp"
	"%UtilDir%\svn.exe" add "%WorkDir%\%name%"

:ExitScript