@echo off

:SetupEnvironment
	if "%1"=="" goto PrintErrorAndExit
	set root=..\plugins\
	set project=%~n1
	
	setlocal enableextensions

	set LocalDir=%~d0%~p0
	if %LocalDir:~-1%==\ set LocalDir=%LocalDir:~0,-1%
	set UtilDir=%LocalDir%\.util
	
	set WorkDirRelative=%LocalDir%\%root%
	pushd %WorkDirRelative%
	set WorkDir=%CD%
	popd
	
	echo Patching plugin "%project%"

:SelectPatchFile
	echo %WorkDir%

	if exist "%WorkDir%\%project%\variable_info.h" goto AlreadyPatched
	if exist "%WorkDir%\%project%\variables.h" goto PluginSDK
	
	if not exist "%WorkDir%\%project%\%project%.vcxproj" goto Error
	if not exist "%WorkDir%\%project%\%project%.def" goto Error
	if not exist "%WorkDir%\%project%\%project%.cbp" goto Error
	if not exist "%WorkDir%\%project%\apoplugin.c" goto Error
	if not exist "%WorkDir%\%project%\apoplugin_msvc.cpp" goto Error
	
	goto Legacy
	
:PluginSDK
	set PatchFile=varinfo_pluginsdk
	goto Patch
	
:Legacy
	set PatchFile=varinfo_legacy
	goto Patch
	
:Patch
	"%UtilDir%\txpand" -o "%WorkDir%" -t "%UtilDir%\template_qvipatch" %project%
	pushd %WorkDir%\%project%
	"%UtilDir%\diff.exe" -p0 < "%WorkDir%\%project%\%PatchFile%.patch"
	del "%WorkDir%\%project%\varinfo_legacy.patch"
	del "%WorkDir%\%project%\varinfo_pluginsdk.patch"
	del "%WorkDir%\%project%\%project%.vcxproj.orig"
	"%UtilDir%\svn.exe" add "%WorkDir%\%project%\variable_info.h"
	popd
	goto Success
	
:Error
	echo Unable to determine working copy structure - failed!
	goto ExitScript

:AlreadyPatched
	echo Working copy already patched - skipping!
	goto ExitScript
	
:Success
	echo Successfully patched working copy using "%PatchFile%" - exiting!
	goto ExitScript

:ExitScript