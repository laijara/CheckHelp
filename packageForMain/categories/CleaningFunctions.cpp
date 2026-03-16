#include "../Classes.h"

void CleaningFunctions::StartCleaning() {

    short inp;
    while (true)
    {
        CleaningFunctions::DescriptionCleaningCategories();
        inp = SharedFunctions::SecureInput();
        switch (inp)
        {
        case 0:
            SharedFunctions::CleaningMenu();
            return;
        case 1:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningAll);
            break;
        case 2:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningTemp);
            break;
        case 3:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningUserTemp);
            break;
        case 4:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningPrefetch);
            break;
        case 5:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningSoftwareDistribution);
            break;
        case 6:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningLogs);
            break;
        case 7:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningPublicDownloads);
            break;
        case 8:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningRecycleBinC);
            break;
        case 9:
            SharedFunctions::CleaningAndPauseMenu(2, CleaningFunctions::CleaningAllRecycleBins);
            break;
        default:
			SharedFunctions::ErrorMessage(0);
            break;
        }
    }
}

void CleaningFunctions::DescriptionCleaningCategories() {
    std::cout << "Параметры очистки" << std::endl;
    std::cout << "==================" << std::endl << std::endl;
    std::cout << "0. Назад" << std::endl;
    std::cout << "1. ИСПОЛЬЗОВАТЬ ВСЕ ВАРИАНТЫ!" << std::endl;
    std::cout << "2. Очистка папки TEMP (системная)" << std::endl;
    std::cout << "3. Очистка временной папки пользователя (%TEMP%)" << std::endl;
    std::cout << "4. Очистка Prefetch" << std::endl;
    std::cout << "5. Очистка кэша обновлений (SoftwareDistribution)" << std::endl;
    std::cout << "6. Очистка логов Windows" << std::endl;
    std::cout << "7. Очистка общедоступной папки Downloads" << std::endl;
    std::cout << "8. Очистка корзины (диск C:)" << std::endl;
    std::cout << "9. Очистка корзины на всех дисках" << std::endl;
}

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
    system("echo off && del /q /f /s \"C:\\Windows\\Temp\\*.*\" && for /d %%p in (\"C:\\Windows\\Temp\\*.*\") do rd /s /q \"%%p\"");
}

void CleaningFunctions::CleaningUserTemp() {
    system("echo off && del /q /f /s \"%TEMP%\\*.*\" && for /d %%p in (\"%TEMP%\\*.*\") do rd /s /q \"%%p\"");
}

void CleaningFunctions::CleaningPrefetch() {
    system("echo off && del /q /f /s \"C:\\Windows\\Prefetch\\*.*\" && for /d %%p in (\"C:\\Windows\\Prefetch\\*.*\") do rd /s /q \"%%p\"");
}

void CleaningFunctions::CleaningSoftwareDistribution() {
    system("echo off && del /q /f /s \"C:\\Windows\\SoftwareDistribution\\Download\\*.*\" && for /d %%p in (\"C:\\Windows\\SoftwareDistribution\\Download\\*.*\") do rd /s /q \"%%p\"");
}

void CleaningFunctions::CleaningLogs() {
    system("echo off && del /q /f /s \"C:\\Windows\\Logs\\*.*\" && for /d %%p in (\"C:\\Windows\\Logs\\*.*\") do rd /s /q \"%%p\"");
}

void CleaningFunctions::CleaningPublicDownloads() {
    system("echo off && del /q /f /s \"C:\\Users\\Public\\Downloads\\*.*\" && for /d %%p in (\"C:\\Users\\Public\\Downloads\\*.*\") do rd /s /q \"%%p\"");
}

void CleaningFunctions::CleaningRecycleBinC() {
    system("echo off && rd /s /q C:\\$Recycle.bin");
}

void CleaningFunctions::CleaningAllRecycleBins() {
    system("echo off && for %%d in (C D E F) do if exist %%d:\\$Recycle.bin rd /s /q %%d:\\$Recycle.bin");
}