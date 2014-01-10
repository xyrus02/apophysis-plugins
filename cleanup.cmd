@ECHO OFF

:Start
	ECHO Cleaning...
	FOR /d /r . %%d IN (bin,obj) DO @IF EXIST "%%d" RD /s/q "%%d"
	@IF EXIST ".output" RD /s/q ".output"
	
:Exit
	ECHO.