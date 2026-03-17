#include "../Classes.h"
#include <string>

int SharedFunctions::errorCount = 0;

short SharedFunctions::SecureInput() {
    std::string line;
    std::cout << std::endl << "Вводите: ";
    std::getline(std::cin, line);

    if (line.empty()) {
        return -1;
    }

    try {
        return std::stoi(line);
    }
    catch (...) {
        return -1;
    }
}

void SharedFunctions::CleaningMenu() {
    system("cls");
}

void SharedFunctions::PauseMenu() {
    std::cout << std::endl << std::endl << "Нажмите Enter чтобы продолжить..." << std::endl;
    std::string dummy;
    std::getline(std::cin, dummy);
}

void SharedFunctions::ErrorMessage() {
    errorCount++;
    SharedFunctions::CleaningMenu();
    std::cout << "Произошла ошибка!" << " Количество ошибок - " << errorCount << std::endl;
    std::cout << "Такого действия не существует!" << std::endl << std::endl;
}

void SharedFunctions::CleaningAndPauseMenu(short typeCleaning, void(*callback)()) {
    if (typeCleaning == 0) {
        SharedFunctions::CleaningMenu();
        callback();
    }
    else if (typeCleaning == 1) {
        SharedFunctions::PauseMenu();
        SharedFunctions::CleaningMenu();
        callback();
    }
    else if (typeCleaning == 2) {
        SharedFunctions::CleaningMenu();
        callback();
        SharedFunctions::PauseMenu();
        SharedFunctions::CleaningMenu();
	}
}