#include "../Classes.h"

void NotWorkingMenuFunctions::StartNotWorkingMenu() {
    setlocale(LC_ALL, "ru");
    short inp;
    while (true)
    {
        NotWorkingMenuFunctions::DescriptionNotWorkingMenuCategories();
        inp = SharedFunctions::SecureInput();
        if (inp == 0) {
            SharedFunctions::CleaningMenu();
            return;
		}
        else {
            SharedFunctions::ErrorMessage(0);
		}
    }
}

void NotWorkingMenuFunctions::DescriptionNotWorkingMenuCategories() {
    std::cout << "ÝÒÎÒ ÁËÎÊ ÂÐÅÌÅÍÍÎ ÍÅ ÐÀÁÎÒÀÅÒ!" << std::endl;
    std::cout << "================================" << std::endl << std::endl;
    std::cout << "0. Íàçàä" << std::endl;
}