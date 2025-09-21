@echo off

:: Main
cd /d "%~dp0"
set "CHECK_PATH=%~dp0InfoLibs\"

:: Menu
:menu
echo =======================
echo 0. Выход
echo 1. Информация о системе (systeminfo)
echo 2. Информация о соединениях (ipconfig)
echo 3. Информация о потреблении ресурсов (resmon)
echo 4. Просмотр логов (eventvwr.msc)
echo 5. Информация о запущенных задачах (tasklist)
echo 6. Проверка работоспособности интернета
echo:

:: Input
set /p input= Выберите действие:
if "%input%"=="0" goto exits
if "%input%"=="1" call :absoluteStart "Просмотр информации о системе (systeminfo)" "InfoSystem.bat"
if "%input%"=="2" call :absoluteStart "Просмотр информации о соединениях (ipconfig)" "InfoIp.bat"
if "%input%"=="3" call :absoluteStart "Просмотр информации о соединениях (resmon)" "InfoResources.bat"
if "%input%"=="4" call :absoluteStart "Просмотр логов (eventvwr.msc)" "InfoResources.bat"
if "%input%"=="5" call :absoluteStart "Просмотр запущенных задач (tasklist)" "InfoTaskList.bat"
if "%input%"=="6" call :absoluteStart "Проверка работоспособности интернета" "InfoNet.bat"
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