@echo off
chcp 65001

:: Main
cd /d "%~dp0"
set "CHECK_PATH=%~dp0InfoLibs\"

:: Menu
:menu
echo =======================
echo 0. Выход
echo 1. Информация о системе
echo 2. Информация о соединениях
echo:

:: Input
set /p input= Выберите действие:
if "%input%"=="0" goto exits
if "%input%"=="1" call :absoluteStart "Просмотр информации о системе" "infoSystem.bat"
if "%input%"=="2" call :absoluteStart "Просмотр информации о соединениях" "InfoIp.bat"
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
chcp 866
exit