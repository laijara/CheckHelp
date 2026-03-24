#include "MainFrame.h"
#include <wx/iconbndl.h>
#include "../Logic/Classes.h"

// Реализация конструктора. Мы передаем parent в базовый класс ComputerHelper
MainFrame::MainFrame(wxWindow* parent) : ComputerHelper(parent) {
    // Здесь твой интерфейс уже полностью загружен и отрисован.
    // Если нужно, тут можно задать иконку окна или изменить стартовый размер.
	wxIconBundle bundle;
	bundle.AddIcon(wxICON(MAINICON));
	SetIcons(bundle);
}

void MainFrame::InfoSystemButtonEvent(wxCommandEvent& event)
{
    InfoFunctions::InfoSystem();
}

void MainFrame::InfoIpButtonEvent(wxCommandEvent& event)
{
    InfoFunctions::InfoIp();
}

void MainFrame::InfoResourcesButtonEvent(wxCommandEvent& event)
{
    InfoFunctions::InfoResources();
}

void MainFrame::InfoLogsButtonEvent(wxCommandEvent& event)
{
	InfoFunctions::InfoLogs();
}

void MainFrame::InfoTaskListButtonEvent(wxCommandEvent& event)
{
	InfoFunctions::InfoTaskList();
}

void MainFrame::InfoNetButtonEvent(wxCommandEvent& event)
{
	InfoFunctions::InfoNet();
}




void MainFrame::FixSystemButtonEvent(wxCommandEvent& event)
{
	FixFunctions::FixSystem();
}

void MainFrame::FixDiskButtonEvent(wxCommandEvent& event)
{
	FixFunctions::FixDisk();
}

void MainFrame::FixOperationalMemoryButtonEvent(wxCommandEvent& event)
{
	FixFunctions::FixOperationalMemory();
}

void MainFrame::FixDismButtonEvent(wxCommandEvent& event)
{
	FixFunctions::FixDism();
}

void MainFrame::FixNetSettingsResetButtonEvent(wxCommandEvent& event)
{
	FixFunctions::FixNetSettingsReset();
}




void MainFrame::CleaningAllButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningAll();
}

void MainFrame::CleaningTempButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningTemp();
}

void MainFrame::CleaningUserTempButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningUserTemp();
}

void MainFrame::CleaningPrefetchButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningPrefetch();
}

void MainFrame::CleaningSoftwareDistributionButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningSoftwareDistribution();
}

void MainFrame::CleaningLogsButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningLogs();
}

void MainFrame::CleaningPublicDownloadsButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningPublicDownloads();
}

void MainFrame::CleaningRecycleBinCButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningRecycleBinC();
}

void MainFrame::CleaningAllRecycleBinsButtonEvent(wxCommandEvent& event)
{
	CleaningFunctions::CleaningAllRecycleBins();
}
