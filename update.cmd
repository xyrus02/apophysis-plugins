@echo off

set tododir=%~d0%~p0.util\.batch_recompiler\src
set donedir=%~d0%~p0.util\.batch_recompiler\out
set logdir=%~d0%~p0.util\.batch_recompiler\log
set tempdir=%~d0%~p0.util\.batch_recompiler\tmp
set mkplugin=%~d0%~p0.util\.batch_recompiler\bin\mkplugin.exe
set msb=C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe

:parse
set in=%1
for %%i in (%in%) do if exist %%~si\nul goto directory
if exist "%in%" goto file
goto usage

:directory
call :empty
for /f "delims=" %%f in ('dir /b /a-d-h-s "%in%"') do call :handlefile "%in%\%%f"
call :empty
rmdir /s /q "%tempDir%" > nul 2>&1
goto :end

:file
call :empty
call :handlefile %in%
call :empty
rmdir /s /q "%tempDir%" > nul 2>&1
goto :end

:empty
if exist "%doneDir%" rmdir /S /Q "%doneDir%" > nul 2>&1
if exist "%logDir%" rmdir /S /Q "%logDir%" > nul 2>&1
if exist "%tempDir%" rmdir /S /Q "%tempDir%" > nul 2>&1
if exist "%todoDir%" rmdir /S /Q "%todoDir%" > nul 2>&1

mkdir "%doneDir%"
mkdir "%logDir%"
mkdir "%tempDir%"
mkdir "%todoDir%"

goto :eof

:handlefile
set fn=%1
set nn=%~n1.c
copy /y "%fn%" "%~d0%~p0.util\.batch_recompiler\src\%nn%" > nul 2>&1
call :compile "%~d0%~p0.util\.batch_recompiler\src\%nn%"
goto :eof

:compile
"%mkplugin%" "%~n1" "%tempDir%\%~n1" > nul 2>&1
attrib -h "%tempDir%\%~n1\plugin.h" > nul 2>&1
ren "%tempDir%\%~n1\plugin.h" "apoplugin.h" > nul 2>&1
copy /y "%1" "%tempDir%\%~n1\%~n1.cpp" > nul 2>&1

"%msb%" /nologo /verbosity:normal /p:Configuration=Release;Platform=Win32 "%tempDir%\%~n1\%~n1.vcxproj" > "%logDir%\%~n1.x86.log"
"%msb%" /nologo /verbosity:normal /p:Configuration=Release;Platform=x64 "%tempDir%\%~n1\%~n1.vcxproj" > "%logDir%\%~n1.x64.log"

if exist "%tempDir%\%~n1\bin\x86\%~n1.dll" (
	copy /y "%tempDir%\%~n1\bin\x86\%~n1.dll" "%doneDir%\%~n1.x86.dll" > nul 2>&1
	del /q "%logDir%\%~n1.x86.log" > nul 2>&1
	
	if exist "%tempDir%\%~n1\bin\x64\%~n1.dll" (
		copy /y "%tempDir%\%~n1\bin\x64\%~n1.dll" "%doneDir%\%~n1.x64.dll" > nul 2>&1
		del /q "%logDir%\%~n1.x64.log" > nul 2>&1
		echo SUCCESS: Build of "%~n1" completed!
	)
	
	if not exist "%tempDir%\%~n1\bin\x64\%~n1.dll" (
		echo ERROR: Build of "%~n1" failed!
		type "%logDir%\%~n1.x64.log"
		echo.
	)
)

if not exist "%tempDir%\%~n1\bin\x86\%~n1.dll" (
	echo ERROR: Build of "%~n1" failed!
	type "%logDir%\%~n1.x86.log"
	echo.
)
	
rmdir /s /q "%tempDir%\%~n1" > nul 2>&1
goto :eof

:usage
echo Usage: update ^<directory or plugin file^>

:end