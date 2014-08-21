@echo off

:SetupEnvironment
	set Architecture=%2

	if "%1"=="" goto PrintErrorAndExit
	if "%2"=="" set Architecture=x86
	
	set root=..\plugins\
	set project=%~n1

:SetupApophysis
	if not exist "%temp%\Apophysis" (
		mkdir "%temp%\Apophysis"
		copy /y "%~d0%~p0.util\.apo\*.*" "%temp%\Apophysis" > NUL
	)
	
	if not exist "%temp%\Apophysis\Plugins" mkdir "%temp%\Apophysis\Plugins"
	del /q "%temp%\Apophysis\Plugins\*.*" > NUL
	
	if not exist "%~d0%~p0..\output\%project%.%Architecture%.dll" goto PluginNotBuildForArchitecture
	copy /y "%~d0%~p0..\output\%project%.%Architecture%.dll" "%temp%\Apophysis\Plugins" > NUL
	
	if exist "%~d0%~p0%root%%project%\test.flame" start "" "%temp%\Apophysis\%Architecture%.exe" "%~d0%~p0%root%%project%\test.flame"
	if not exist "%~d0%~p0%root%%project%\test.flame" start "" "%temp%\Apophysis\%Architecture%.exe"
	
	goto ExitGracefully

:PluginNotBuildForArchitecture
	echo Warning: could not find "%~d0%~p0..\output\%project%.%Architecture%.dll"!
	echo Please build the plugin first.
	goto ExitScript

:ExitGracefully
	goto ExitScript

:PrintErrorAndExit
	echo Usage: test ^<name^>
	echo.
	
:ExitScript