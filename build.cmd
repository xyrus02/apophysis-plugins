@echo off
if "%1"=="" goto err
if not exist "%~d0%~p0%1\%1.vcxproj" goto err
set verb=normal
set tool=C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe
set params=/NOLOGO /property:Configuration=Release /property:Platform=Win32
"%tool%" %params% /VERBOSITY:%verb% "%~d0%~p0%1\%1.vcxproj"
set params=/NOLOGO /property:Configuration=Release /property:Platform=x64
"%tool%" %params% /VERBOSITY:%verb% "%~d0%~p0%1\%1.vcxproj"
if not exist "%~d0%~p0%1\.output" goto eof
if not exist "%~d0%~p0.output" mkdir "%~d0%~p0.output"
copy /y "%~d0%~p0%1\.output\*.dll" "%~d0%~p0.output" 
rmdir /s /q "%~d0%~p0%1\.output"
goto eof
:err
echo Usage: build ^<name^>
echo.
:eof