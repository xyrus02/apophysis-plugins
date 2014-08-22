@echo off

:SetupEnvironment
	if "%1"=="" goto PrintErrorAndExit
	set root=..\plugins\
	set project=%~n1

:ExecuteMsBuild
	set MsBuildLocation=%WinDir%\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe
	set MsBuildParams=/NOLOGO /property:Configuration=Release /VERBOSITY:normal

	if not exist "%~d0%~p0%root%%project%\%project%.vcxproj" goto ExecuteMinGw
	if not exist "%MsBuildLocation%" goto NoMsBuild
	
	"%MsBuildLocation%" %MsBuildParams% /property:Platform=Win32 "%~d0%~p0%root%%project%\%project%.vcxproj"
	"%MsBuildLocation%" %MsBuildParams% /property:Platform=x64 "%~d0%~p0%root%%project%\%project%.vcxproj"
	
	if not exist "%~d0%~p0%root%%project%\.output" goto ErrorRunningMsBuild
	if not exist "%~d0%~p0%root%..\output" mkdir "%~d0%~p0%root%..\output"
	
	copy /y "%~d0%~p0%root%%project%\.output\*.dll" "%~d0%~p0%root%..\output" 1>NUL
	rmdir /s /q "%~d0%~p0%root%%project%\.output"
	
	goto ExecuteMinGw
	
:NoMsBuild
	echo Warning: MSBuild was not found at "%MsBuildLocation%" - skipping compilation for 7x15c or higher
	goto ExecuteMinGw
	
:ErrorRunningMsBuild
	echo Warning: error while building "%project%" with MSBuild!
	goto ExecuteMinGw
	
:ExecuteMinGw
	set t=%root%%project%

	if not exist "%~d0%~p0%t%\apoplugin.c" goto ExitGracefully

	if not exist "%~d0%~p0%t%\bin" mkdir "%~d0%~p0%t%\bin"
	if not exist "%~d0%~p0%t%\obj" mkdir "%~d0%~p0%t%\obj"
	
	"%~d0%~p0.util\.mingw\bin\mingw32-gcc.exe" -O2 -Wall -DBUILD_DLL -c "%~d0%~p0%t%\apoplugin.c" -o "%~d0%~p0%t%\obj\apoplugin.o"
	if not exist "%~d0%~p0%t%\obj\apoplugin.o" goto ErrorRunningMinGw
	
	"%~d0%~p0.util\.mingw\bin\mingw32-g++.exe" -shared -Wl,--output-def="%~d0%~p0%t%\obj\apoplugin.def" -Wl,--out-implib="%~d0%~p0%t%\obj\apoplugin.a" -Wl,--dll "%~d0%~p0%t%\obj\apoplugin.o" -o "%~d0%~p0%t%\bin\%project%.dll" -s -luser32
	if not exist "%~d0%~p0%t%\bin\%project%.dll" goto ErrorRunningMinGpp
	
	if not exist "%~d0%~p0..\output" mkdir "%~d0%~p0..\output"
	copy /y "%~d0%~p0%t%\bin\%project%.dll" "%~d0%~p0..\output\%project%.legacy.dll"  1>NUL
	
	goto ExitGracefully

:ErrorRunningMinGw
	echo Warning: error while building "%project%" with MinGW!
	goto ExitGracefully
	
:ErrorRunningMinGpp
	echo Warning: error while linking "%project%" with MinGW!
	goto ExitGracefully

:ExitGracefully
	goto ExitScript

:PrintErrorAndExit
	echo Usage: build ^<name^>
	echo.
	
:ExitScript