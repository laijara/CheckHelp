#include "../Classes.h"

void MainMenuFunctions::StartProgram() {
    setlocale(LC_ALL, "ru");
    short inp;
    while (true)
    {
        MainMenuFunctions::DescriptionCategories();
        inp = SharedFunctions::SecureInput();
        switch (inp)
        {
        case 0:
            SharedFunctions::PauseMenu();
            return;
        case 1:
            SharedFunctions::CleaningAndPauseMenu(0, InfoFunctions::StartInfo);
            break;
        case 2:
            SharedFunctions::CleaningAndPauseMenu(0, FixFunctions::StartFix);
            break;
        case 3:
            SharedFunctions::CleaningAndPauseMenu(0, CleaningFunctions::StartCleaning);
            break;
        default:
			SharedFunctions::ErrorMessage(0);
            break;
        }
    }
}

void MainMenuFunctions::DescriptionCategories() {
    std::cout << "Добро пожаловать в \"Почини компьютер\"!" << std::endl;
    std::cout << "=======================================" << std::endl << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "1. Информационные параметры" << std::endl;
    std::cout << "2. Параметры исправлений" << std::endl;
    std::cout << "3. Очистка компьютера" << std::endl;
}