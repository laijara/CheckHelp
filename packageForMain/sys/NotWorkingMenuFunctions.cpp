#include "../Classes.h"

void NotWorkingMenuFunctions::StartNotWorkingMenu() {
    setlocale(LC_ALL, "ru");
    short inp;
    while (true)
    {
        NotWorkingMenuFunctions::DescriptionNotWorkingMenuCategories();
        inp = SharedFunctions::SecureInput();
        switch (inp)
        {
        case 0:
            SharedFunctions::CleaningMenu();
            return;
        default:
            SharedFunctions::ErrorMessage(0);
            break;
        }
    }
}

void NotWorkingMenuFunctions::DescriptionNotWorkingMenuCategories() {
    std::cout << "ÝÒÎÒ ÁËÎÊ ÂÐÅÌÅÍÍÎ ÍÅ ÐÀÁÎÒÀÅÒ" << std::endl;
    std::cout << "===============================" << std::endl << std::endl;
    std::cout << "0. Âûõîä" << std::endl;
}