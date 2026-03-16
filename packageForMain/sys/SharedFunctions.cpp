#include "../Classes.h"

int SharedFunctions::errorCount = 0;

short SharedFunctions::SecureInput() {
    short inp;
    std::cout << std::endl << "Вводите: ";

    if (std::cin >> inp) {
        return inp;
    }
    else {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return -1;
    }
}

void SharedFunctions::CleaningMenu() {
    system("cls");
}

void SharedFunctions::PauseMenu() {
    std::cout << std::endl << std::endl << "Нажмите любую кнопку для продолжения..." << std::endl;
    std::cin.ignore(9999, '\n');
    std::cin.get();
}

void SharedFunctions::ErrorMessage(short errorLevel) {
    errorCount++;
    if (errorLevel == 0) {
        SharedFunctions::CleaningMenu();
        std::cout << "Произошла ошибка!" << " Количество ошибок - " << errorCount << std::endl;
        std::cout << "Такого действия не существует!" << std::endl << std::endl;
    }
    else if (errorLevel == 1) {
        SharedFunctions::CleaningMenu();
        std::cout << "Произошла ошибка!" << " Количество ошибок - " << errorCount << std::endl;
        std::cout << "Ошибка ввода!" << std::endl << std::endl;
    }
    else {
        SharedFunctions::CleaningMenu();
        std::cout << "Произошла ошибка!" << " Количество ошибок - " << errorCount << std::endl;
        std::cout << "Неизвестная ошибка!" << std::endl << std::endl;
    }
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