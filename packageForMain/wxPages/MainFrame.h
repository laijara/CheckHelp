#pragma once
#include "MyProjectBase.h" // Подключаем твой сгенерированный файл

// Наследуемся от твоего класса ComputerHelper
class MainFrame : public ComputerHelper {
public:
    // Конструктор
    MainFrame(wxWindow* parent = nullptr);

protected:
    // Берем из MyProjectBase.h виртуальную функцию и ПЕРЕОПРЕДЕЛЯЕМ её (override).
    // Пока для примера возьмем только одну кнопку. Потом добавишь остальные так же.
    void InfoSystemButtonEvent(wxCommandEvent& event) override;
    void InfoIpButtonEvent(wxCommandEvent& event) override;
    void InfoResourcesButtonEvent(wxCommandEvent& event) override;
    void InfoLogsButtonEvent(wxCommandEvent& event) override;
    void InfoTaskListButtonEvent(wxCommandEvent& event) override;
    void InfoNetButtonEvent(wxCommandEvent& event) override;

    // --- ВКЛАДКА ПОЧИНКА ---
    void FixSystemButtonEvent(wxCommandEvent& event) override;
    void FixDiskButtonEvent(wxCommandEvent& event) override;
    void FixOperationalMemoryButtonEvent(wxCommandEvent& event) override;
    void FixDismButtonEvent(wxCommandEvent& event) override;
    void FixNetSettingsResetButtonEvent(wxCommandEvent& event) override;

    // --- ВКЛАДКА ОЧИСТКА ---
    void CleaningAllButtonEvent(wxCommandEvent& event) override;
    void CleaningTempButtonEvent(wxCommandEvent& event) override;
    void CleaningUserTempButtonEvent(wxCommandEvent& event) override;
    void CleaningPrefetchButtonEvent(wxCommandEvent& event) override;
    void CleaningSoftwareDistributionButtonEvent(wxCommandEvent& event) override;
    void CleaningLogsButtonEvent(wxCommandEvent& event) override;
    void CleaningPublicDownloadsButtonEvent(wxCommandEvent& event) override;
    void CleaningRecycleBinCButtonEvent(wxCommandEvent& event) override;
    void CleaningAllRecycleBinsButtonEvent(wxCommandEvent& event) override;
};