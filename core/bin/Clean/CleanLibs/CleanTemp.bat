@echo off
del /q /f /s "C:\Windows\Temp\*.*"
for /d %%p in ("C:\Windows\Temp\*.*") do rd /s /q "%%p"
pause