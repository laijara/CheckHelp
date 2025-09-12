@echo off
chcp 65001

:: Main
cd /d "%~dp0"
set "CHECK_PATH=%~dp0FixLibs\"

:: Menu
:menu
echo =======================
echo 0. Выход
echo 1. Проверка системных файлов
echo 2. Проверка диска
echo 3. Проверка оперативной памяти
echo 4. Проверка компонентов образов
echo:

:: Input
set /p input= Выберите действие:
if "%input%"=="0" goto exits
if "%input%"=="1" call :absoluteStart "Запуск проверки системных файлов" "checkSystem.bat"
if "%input%"=="2" call :absoluteStart "Запуск проверки диска" "checkDisk.bat"
if "%input%"=="3" call :absoluteStart "Запуск проверки оперативной памяти" "checkMemory.bat"
if "%input%"=="4" call :absoluteStart "Запуск проверки компонентов образов" "checkDism.bat"
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