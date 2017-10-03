@ECHO OFF
REM Batch file to delete Doxygen auto-generated files. (They consume quite a bit of space!)
REM These files can be re-generated if necessary, so should NOT be placed in Version Control.

del /F /Q /S .\html\*.*
del /F /Q /S .\xml\*.*