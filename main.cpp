#include <wx/wx.h>
// Указываем путь к твоему классу MainFrame
#include "packageForMain/wxPages/MainFrame.h" 

class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        // Создаем твое окно и показываем его
        MainFrame* frame = new MainFrame(nullptr);
        frame->Show(true);
        return true;
    }
};

// Этот макрос заменяет стандартную функцию int main()
wxIMPLEMENT_APP(MyApp);