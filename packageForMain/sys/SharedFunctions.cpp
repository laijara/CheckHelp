#include "../Classes.h"

short SharedFunctions::SecureInput() {
    short inp;
    std::cout << std::endl << "Вводите: ";
    std::cin >> inp;
    if (!std::cin.fail()) {
        return inp;
    }
    else {
        std::cin.clear();
        std::cin.ignore();
        return -1;
    }
}

void SharedFunctions::PauseMenu() {
    std::cout << std::endl << std::endl << "Нажмите любую кнопку для продолжения..." << std::endl;
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();
}

void SharedFunctions::SwapAndClearMenu(void(*callback)()) {
    SharedFunctions::PauseMenu();
    SharedFunctions::ClearMenu();
    callback();
}

void SharedFunctions::SwapAndClearMenuAndClear(void(*callback)()) {
    SharedFunctions::PauseMenu();
    SharedFunctions::ClearMenu();
    callback();
    SharedFunctions::PauseMenu();
    SharedFunctions::ClearMenu();
}

void SharedFunctions::SwapAndClearMenuNoPause(void(*callback)()) {
    SharedFunctions::ClearMenu();
    callback();
}

void SharedFunctions::ClearMenu() {
    system("cls");
}