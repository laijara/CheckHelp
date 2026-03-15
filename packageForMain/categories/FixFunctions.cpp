#include "../Classes.h"

void FixFunctions::StartFix() {

    short inp;
    while (true)
    {
        FixFunctions::DescriptionFixCategories();
        inp = SharedFunctions::SecureInput();
        switch (inp)
        {
        case 0:
            SharedFunctions::ClearMenu();
            return;
        case 1:
            SharedFunctions::SwapAndClearMenuAndClear(FixFunctions::FixSystem);
            break;
        case 2:
            SharedFunctions::SwapAndClearMenuAndClear(FixFunctions::FixDisk);
            break;
        case 3:
            SharedFunctions::SwapAndClearMenuAndClear(FixFunctions::FixOperationalMemory);
            break;
        case 4:
            SharedFunctions::SwapAndClearMenuAndClear(FixFunctions::FixDism);
            break;
        case 5:
            SharedFunctions::SwapAndClearMenuAndClear(FixFunctions::FixNetSettingsReset);
            break;
        default:
            SharedFunctions::ClearMenu();
            std::cout << "Такого действия не существует!" << std::endl << std::endl;
            break;
        }
    }
}

void FixFunctions::DescriptionFixCategories() {
    std::cout << "Параметры исправлений" << std::endl;
    std::cout << "======================" << std::endl << std::endl;
    std::cout << "0. Назад" << std::endl;
    std::cout << "1. Проверка системных файлов (sfcscan)" << std::endl;
    std::cout << "2. Проверка диска (chkdsk)" << std::endl;
    std::cout << "3. Проверка оперативной памяти (mdsched.exe)" << std::endl;
    std::cout << "4. Проверка компонентов образов (dism)" << std::endl;
    std::cout << "5. Сброс сетевых настроек (TCP/IP)" << std::endl;
}

void FixFunctions::FixSystem() {
    system("echo off && sfc /scannow");
}

void FixFunctions::FixDisk() {
    system("echo off && chkdsk C: /F /R");
}

void FixFunctions::FixOperationalMemory() {
    system("echo off && C:\\Windows\\System32\\mdsched.exe");
}

void FixFunctions::FixDism() {
    system("echo off && DISM /Online /Cleanup-Image /RestoreHealth");
}

void FixFunctions::FixNetSettingsReset() {
    system("echo off && netsh winsock reset && netsh int ip reset && ipconfig /flushdns");
}