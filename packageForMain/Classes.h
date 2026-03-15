#pragma once
#include <iostream>

class SharedFunctions {
public:
    static short SecureInput();
    static void PauseMenu();
    static void ClearMenu();
    static void SwapAndClearMenu(void (*callback)());
    static void SwapAndClearMenuAndClear(void (*callback)());
    static void SwapAndClearMenuNoPause(void (*callback)());
};

class MainMenuFunctions {
public:
    static void StartProgram();
private:
    static void DescriptionCategories();
};

class InfoFunctions {
public:
    static void StartInfo();
private:
    static void DescriptionInfoCategories();
    static void InfoSystem();
    static void InfoIp();
    static void InfoResources();
    static void InfoLogs();
    static void InfoTaskList();
    static void InfoNet();
};

class FixFunctions {
public:
    static void StartFix();
private:
    static void DescriptionFixCategories();
    static void FixSystem();
    static void FixDisk();
    static void FixOperationalMemory();
    static void FixDism();
    static void FixNetSettingsReset();
};

class CleaningFunctions {
public:
    static void StartCleaning();
private:
    static void DescriptionCleaningCategories();
    static void CleaningAll();
    static void CleaningTemp();
    static void CleaningUserTemp();
    static void CleaningPrefetch();
    static void CleaningSoftwareDistribution();
    static void CleaningLogs();
    static void CleaningPublicDownloads();
    static void CleaningRecycleBinC();
    static void CleaningAllRecycleBins();
};