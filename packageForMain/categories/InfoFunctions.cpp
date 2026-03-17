#include "../Classes.h"

void InfoFunctions::StartInfo() {
    
    short inp;
    while (true)
    {
        InfoFunctions::DescriptionInfoCategories();
        inp = SharedFunctions::SecureInput();
        switch (inp)
        {
        case 0:
            SharedFunctions::CleaningMenu();
            return;
        case 1:
            SharedFunctions::CleaningAndPauseMenu(2, InfoFunctions::InfoSystem);
            break;
        case 2:
            SharedFunctions::CleaningAndPauseMenu(2, InfoFunctions::InfoIp);
            break;
        case 3:
            SharedFunctions::CleaningAndPauseMenu(2, InfoFunctions::InfoResources);
            break;
        case 4:
            SharedFunctions::CleaningAndPauseMenu(2, InfoFunctions::InfoLogs);
            break;
        case 5:
            SharedFunctions::CleaningAndPauseMenu(2, InfoFunctions::InfoTaskList);
            break;
        case 6:
            SharedFunctions::CleaningAndPauseMenu(2, InfoFunctions::InfoNet);
            break;
        default:
            SharedFunctions::ErrorMessage();
            break;
        }
    }
}

void InfoFunctions::DescriptionInfoCategories() {
    std::cout << "Информационные параметры" << std::endl;
    std::cout << "=========================" << std::endl << std::endl;
    std::cout << "0. Назад" << std::endl;
    std::cout << "1. Информация о системе (systeminfo)" << std::endl;
    std::cout << "2. Информация о соединениях (ipconfig)" << std::endl;
    std::cout << "3. Информация о потреблении ресурсов (resmon)" << std::endl;
    std::cout << "4. Просмотр логов (eventvwr.msc)" << std::endl;
    std::cout << "5. Информация о запущенных задачах (tasklist)" << std::endl;
    std::cout << "6. Проверка работоспособности интернета" << std::endl;
}

void InfoFunctions::InfoSystem() {
    system("echo off && systeminfo");
}

void InfoFunctions::InfoIp() {
    system("echo off && ipconfig");
}

void InfoFunctions::InfoResources() {
    system("echo off && resmon");
}

void InfoFunctions::InfoLogs() {
    system("echo off && eventvwr.msc");
}

void InfoFunctions::InfoTaskList() {
    system("echo off && tasklist");
}

void InfoFunctions::InfoNet() {
    system("echo off && ping ya.ru && tracert ya.ru");
}