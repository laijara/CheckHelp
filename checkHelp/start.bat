@echo off
chcp 65001
echo "Почини компутер"

:: Main
cd /d "%~dp0"
set "CHECK_PATH=%~dp0checks\"

:: Menu
:menu
echo =======================
echo 1. Проверка оперативной памяти
echo 2. Проверка диска
echo 3. Выход
echo:

:: Input
set /p input= Выберите действие:
if "%input%"=="1" goto checkMemory
if "%input%"=="2" goto checkDisk
if "%input%"=="3" goto exits
goto menu

:: CheckMemory
:checkMemory
echo: 
echo Запуск проверки оперативной памяти
set "target_bat=%CHECK_PATH%checkMemory.bat"
if exist "%target_bat%" (
    powershell -Command "Start-Process -Verb RunAs -FilePath '%target_bat%' -Wait"
) else (
    echo Файл не найден: %target_bat%
)
pause
goto menu

:: CheckDisk
:checkDisk
echo: 
echo Запуск проверки диска
set "target_bat=%CHECK_PATH%checkDisk.bat"
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
exit /b