#pragma once
#include <iostream>

class InfoFunctions {
public:
    static void InfoSystem();
    static void InfoIp();
    static void InfoResources();
    static void InfoLogs();
    static void InfoTaskList();
    static void InfoNet();
};

class FixFunctions {
public:
    static void FixSystem();
    static void FixDisk();
    static void FixOperationalMemory();
    static void FixDism();
    static void FixNetSettingsReset();
};

class CleaningFunctions {
public:
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