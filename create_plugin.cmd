@echo off

:SetupEnvironment
	setlocal enableextensions

	set LocalDir=%~d0%~p0
	if %LocalDir:~-1%==\ set LocalDir=%LocalDir:~0,-1%
	set UtilDir=%LocalDir%\.util

:SetupProfile
	set BuildProfile=vcpp2012
	if "%1"=="" goto ConsumeProfile
	if not exist "%LocalDir%\.util\%1" goto ConsumeProfile
	set BuildProfile=%1
	shift

:ConsumeProfile
	echo Using profile "%BuildProfile%"
	if "%1"=="" goto ExpandTemplate
	echo Creating plugin "%1"

:ExpandTemplate
	echo.
	"%UtilDir%\txpand" -w "%LocalDir%\~tmp" -o "%LocalDir%" -t "%UtilDir%\%BuildProfile%" %1
	
	if not exist "%LocalDir%\~tmp" goto ExitScript
	rem echo %BuildProfile%>"%LocalDir%\%1\.profile"
	
:AddProjectToSolution
	for /f "tokens=*" %%a in (%LocalDir%\~tmp) do set ProjectName=%%a
	del /q "%LocalDir%\~tmp"
	
	if not exist "%LocalDir%\%ProjectName%\%ProjectName%.vcxproj" goto ExitScript
	type "%LocalDir%\%ProjectName%\%ProjectName%.vcxproj" | "%UtilDir%\sxtract" "\u003CProjectGuid\u003E\u007B([a-z\d\x2D]+)\u007D\u003C\u002FProjectGuid\u003E" > "%LocalDir%\~tmp"

	if not exist "%LocalDir%\~tmp" goto ExitScript
	for /f "tokens=*" %%a in (%LocalDir%\~tmp) do set ProjectGuid=%%a
	
	del /q "%LocalDir%\~tmp"
	"%UtilDir%\slnadd" "%LocalDir%\all_plugins.sln" "%ProjectName%\%ProjectName%.vcxproj" "%ProjectGuid%"
	
:ExitScript