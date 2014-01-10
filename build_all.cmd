@echo off
set verb=normal
set tool=C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe
set params=/NOLOGO /property:Configuration=Release /property:Platform=Win32
"%tool%" %params% /VERBOSITY:%verb% "%~d0%~p0all_plugins.sln"
set params=/NOLOGO /property:Configuration=Release /property:Platform=x64
"%tool%" %params% /VERBOSITY:%verb% "%~d0%~p0all_plugins.sln"