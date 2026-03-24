#include "../Classes.h"

void CleaningFunctions::CleaningAll() {
    CleaningFunctions::CleaningTemp();
    CleaningFunctions::CleaningUserTemp();
    CleaningFunctions::CleaningPrefetch();
    CleaningFunctions::CleaningSoftwareDistribution();
    CleaningFunctions::CleaningLogs();
    CleaningFunctions::CleaningPublicDownloads();
    CleaningFunctions::CleaningRecycleBinC();
    CleaningFunctions::CleaningAllRecycleBins();
}

void CleaningFunctions::CleaningTemp() {
    system("del /q /f /s \"C:\\Windows\\Temp\\*.*\" >nul 2>&1 && for /d %p in (\"C:\\Windows\\Temp\\*.*\") do rd /s /q \"%p\" >nul 2>&1 && pause && exit");
}

void CleaningFunctions::CleaningUserTemp() {
    system("del /q /f /s \"%TEMP%\\*.*\" >nul 2>&1 && for /d %p in (\"%TEMP%\\*.*\") do rd /s /q \"%p\" >nul 2>&1 && pause && exit");
}

void CleaningFunctions::CleaningPrefetch() {
    system("del /q /f /s \"C:\\Windows\\Prefetch\\*.*\" >nul 2>&1 && for /d %p in (\"C:\\Windows\\Prefetch\\*.*\") do rd /s /q \"%p\" >nul 2>&1 && pause && exit");
}

void CleaningFunctions::CleaningSoftwareDistribution() {
    system("del /q /f /s \"C:\\Windows\\SoftwareDistribution\\Download\\*.*\" >nul 2>&1 && for /d %p in (\"C:\\Windows\\SoftwareDistribution\\Download\\*.*\") do rd /s /q \"%p\" >nul 2>&1 && pause && exit");
}

void CleaningFunctions::CleaningLogs() {
    system("del /q /f /s \"C:\\Windows\\Logs\\*.*\" >nul 2>&1 && for /d %p in (\"C:\\Windows\\Logs\\*.*\") do rd /s /q \"%p\" >nul 2>&1 && pause && exit");
}

void CleaningFunctions::CleaningPublicDownloads() {
    system("del /q /f /s \"C:\\Users\\Public\\Downloads\\*.*\" >nul 2>&1 && for /d %p in (\"C:\\Users\\Public\\Downloads\\*.*\") do rd /s /q \"%p\" >nul 2>&1 && pause && exit");
}

void CleaningFunctions::CleaningRecycleBinC() {
    system("rd /s /q C:\\$Recycle.bin >nul 2>&1 && pause && exit");
}

void CleaningFunctions::CleaningAllRecycleBins() {
    system("for %d in (C D E F) do if exist %d:\\$Recycle.bin rd /s /q %d:\\$Recycle.bin >nul 2>&1 && pause && exit");
}