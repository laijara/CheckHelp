@echo off

:: Main
cd /d "%~dp0"
set "CHECK_PATH=%~dp0CleanLibs\"

:: Menu
:menu
echo =======================
echo 0. Выход
echo 1. Очистка папки TEMP
echo:

:: Input
set /p input= Выберите действие:
if "%input%"=="0" goto exits
if "%input%"=="1" call :absoluteStart "Просмотр информации о системе (systeminfo)" "CleanTemp.bat"
goto menu

:: absoluteStart
:absoluteStart
echo: 
echo %~1
set "target_bat=%CHECK_PATH%%~2"
if exist "%target_bat%" (
    powershell -Command "Start-Process -Verb RunAs -FilePath '%target_bat%' -Wait"
) else (
    echo Файл не найден: %target_bat%
)
pause
goto menu

:: Exit
:exits
cd ..\..\
set "default_bat=start.bat"
if exist "%default_bat%" (
    %default_bat%
) else (
    echo Файл не найден: %default_bat_bat%
)
goto menu