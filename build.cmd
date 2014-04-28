@echo off

:SetupEnvironment
	if "%1"=="" goto PrintErrorAndExit

:ExecuteMsBuild
	set MsBuildLocation=%WinDir%\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe
	set MsBuildParams=/NOLOGO /property:Configuration=Release /VERBOSITY:normal

	if not exist "%~d0%~p0%1\%1.vcxproj" goto ExecuteMinGw
	if not exist "%MsBuildLocation%" goto NoMsBuild
	
	"%MsBuildLocation%" %MsBuildParams% /property:Platform=Win32 "%~d0%~p0%1\%1.vcxproj"
	"%MsBuildLocation%" %MsBuildParams% /property:Platform=x64 "%~d0%~p0%1\%1.vcxproj"
	
	if not exist "%~d0%~p0%1\.output" goto ErrorRunningMsBuild
	if not exist "%~d0%~p0.output" mkdir "%~d0%~p0.output"
	
	copy /y "%~d0%~p0%1\.output\*.dll" "%~d0%~p0.output" 
	rmdir /s /q "%~d0%~p0%1\.output"
	
	goto ExecuteMinGw
	
:NoMsBuild
	echo Warning: MSBuild was not found at "%MsBuildLocation%" - skipping compilation for 7x15c or higher
	goto ExecuteMinGw
	
:ErrorRunningMsBuild
	echo Warning: error while building "%~d0%~p0%1\%1.vcxproj" with MSBuild!
	goto ExecuteMinGw
	
:ExecuteMinGw
	if not exist "%~d0%~p0%1\apoplugin.c" goto ExitGracefully

	if not exist "%~d0%~p0%1\bin" mkdir "%~d0%~p0%1\bin"
	if not exist "%~d0%~p0%1\obj" mkdir "%~d0%~p0%1\obj"
	
	"%~d0%~p0.util\.mingw\bin\mingw32-gcc.exe" -O2 -Wall -DBUILD_DLL -c "%~d0%~p0%1\apoplugin.c" -o "%~d0%~p0%1\obj\apoplugin.o"
	if not exist "%~d0%~p0%1\obj\apoplugin.o" goto ErrorRunningMinGw
	
	"%~d0%~p0.util\.mingw\bin\mingw32-g++.exe" -shared -Wl,--output-def="%~d0%~p0%1\obj\apoplugin.def" -Wl,--out-implib="%~d0%~p0%1\obj\apoplugin.a" -Wl,--dll "%~d0%~p0%1\obj\apoplugin.o" -o "%~d0%~p0%1\bin\%1.dll" -s -luser32
	if not exist "%~d0%~p0%1\bin\%1.dll" goto ErrorRunningMinGw
	
	if not exist "%~d0%~p0.output" mkdir "%~d0%~p0.output"
	copy /y "%~d0%~p0%1\bin\%1.dll" "%~d0%~p0.output\%1.legacy.dll" 
	
	goto ExitGracefully

:ErrorRunningMinGw
	echo Warning: error while building "%~d0%~p0%1\%1.c" with MinGW!
	goto ExitGracefully

:ExitGracefully
	goto ExitScript

:PrintErrorAndExit
	echo Usage: build ^<name^>
	echo.
	
:ExitScript