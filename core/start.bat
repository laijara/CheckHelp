@echo off
chcp 65001
echo "Почини компутер"

:: Main
cd /d "%~dp0"
set "CHECK_PATH=%~dp0bin\"

:: Menu
:menu
echo =======================
echo 0. Выход
echo 1. Информационные параметры
echo 2. Параметры для исправлений
echo 3. Чистка компьютера
echo:

:: Input
set /p input= Выберите действие:
if "%input%"=="0" goto exits
if "%input%"=="1" call :absoluteStart "Список информационных параматеров" "Info.bat" "Info"
if "%input%"=="2" call :absoluteStart "Список параметров для исправлений" "Fix.bat" "Fix"
if "%input%"=="3" call :absoluteStart "Список параметров для исправлений" "Clean.bat" "Clean"
goto menu

:: absoluteStart
:absoluteStart
echo: 
echo %~1
set "target_bat=%CHECK_PATH%%~3\%~2"
if exist "%target_bat%" (
    start %target_bat%
) else (
    echo Файл не найден: %target_bat%
)
pause
goto menu

:: Exit
:exits
chcp 866
exit