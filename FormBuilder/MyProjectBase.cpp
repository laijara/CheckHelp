///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyProjectBase.h"

///////////////////////////////////////////////////////////////////////////

ComputerHelper::ComputerHelper( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* mainSettingsSizer;
	mainSettingsSizer = new wxBoxSizer( wxVERTICAL );

	mainNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	Info = new wxPanel( mainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* InfoSizer;
	InfoSizer = new wxBoxSizer( wxVERTICAL );

	InfoTitle = new wxStaticText( Info, wxID_ANY, _("Информационные параметры"), wxDefaultPosition, wxDefaultSize, 0 );
	InfoTitle->Wrap( -1 );
	InfoSizer->Add( InfoTitle, 0, wxALL, 5 );

	wxBoxSizer* InfoButtonsSizer;
	InfoButtonsSizer = new wxBoxSizer( wxVERTICAL );

	InfoSystemButton = new wxButton( Info, wxID_ANY, _("Информация о системе"), wxDefaultPosition, wxDefaultSize, 0 );
	InfoButtonsSizer->Add( InfoSystemButton, 0, wxALL, 5 );

	InfoIpButton = new wxButton( Info, wxID_ANY, _("Информация о IP"), wxDefaultPosition, wxDefaultSize, 0 );
	InfoButtonsSizer->Add( InfoIpButton, 0, wxALL, 5 );

	InfoResourcesButton = new wxButton( Info, wxID_ANY, _("Потребление ресурсов"), wxDefaultPosition, wxDefaultSize, 0 );
	InfoButtonsSizer->Add( InfoResourcesButton, 0, wxALL, 5 );

	InfoLogsButton = new wxButton( Info, wxID_ANY, _("Системные логи"), wxDefaultPosition, wxDefaultSize, 0 );
	InfoButtonsSizer->Add( InfoLogsButton, 0, wxALL, 5 );

	InfoTaskListButton = new wxButton( Info, wxID_ANY, _("Запущенные службы"), wxDefaultPosition, wxDefaultSize, 0 );
	InfoButtonsSizer->Add( InfoTaskListButton, 0, wxALL, 5 );

	InfoNetButton = new wxButton( Info, wxID_ANY, _("Проверка работоспособности интернета"), wxDefaultPosition, wxDefaultSize, 0 );
	InfoButtonsSizer->Add( InfoNetButton, 0, wxALL, 5 );


	InfoSizer->Add( InfoButtonsSizer, 1, wxEXPAND, 5 );


	Info->SetSizer( InfoSizer );
	Info->Layout();
	InfoSizer->Fit( Info );
	mainNotebook->AddPage( Info, _("Информация"), true );
	Fix = new wxPanel( mainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* FixSizer;
	FixSizer = new wxBoxSizer( wxVERTICAL );

	FixTitle = new wxStaticText( Fix, wxID_ANY, _("Параметры исправлений"), wxDefaultPosition, wxDefaultSize, 0 );
	FixTitle->Wrap( -1 );
	FixSizer->Add( FixTitle, 0, wxALL, 5 );

	wxBoxSizer* FixButtonsSizer;
	FixButtonsSizer = new wxBoxSizer( wxVERTICAL );

	FixSystemButton = new wxButton( Fix, wxID_ANY, _("Проверка системных файлов"), wxDefaultPosition, wxDefaultSize, 0 );
	FixButtonsSizer->Add( FixSystemButton, 0, wxALL, 5 );

	FixDiskButton = new wxButton( Fix, wxID_ANY, _("Проверка диска"), wxDefaultPosition, wxDefaultSize, 0 );
	FixButtonsSizer->Add( FixDiskButton, 0, wxALL, 5 );

	FixOperationalMemoryButton = new wxButton( Fix, wxID_ANY, _("Проверка оперативной памяти"), wxDefaultPosition, wxDefaultSize, 0 );
	FixButtonsSizer->Add( FixOperationalMemoryButton, 0, wxALL, 5 );

	FixDismButton = new wxButton( Fix, wxID_ANY, _("Проверка компонентов образов"), wxDefaultPosition, wxDefaultSize, 0 );
	FixButtonsSizer->Add( FixDismButton, 0, wxALL, 5 );

	FixNetSettingsResetButton = new wxButton( Fix, wxID_ANY, _("Сброс сетевых настроек"), wxDefaultPosition, wxDefaultSize, 0 );
	FixButtonsSizer->Add( FixNetSettingsResetButton, 0, wxALL, 5 );


	FixSizer->Add( FixButtonsSizer, 1, wxEXPAND, 5 );


	Fix->SetSizer( FixSizer );
	Fix->Layout();
	FixSizer->Fit( Fix );
	mainNotebook->AddPage( Fix, _("Починка"), false );
	Cleaning = new wxPanel( mainNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* CleaningSizer;
	CleaningSizer = new wxBoxSizer( wxVERTICAL );

	CleaningTitle = new wxStaticText( Cleaning, wxID_ANY, _("Параметры очистки"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningTitle->Wrap( -1 );
	CleaningSizer->Add( CleaningTitle, 0, wxALL, 5 );

	wxBoxSizer* CleaningButtonsSizer;
	CleaningButtonsSizer = new wxBoxSizer( wxVERTICAL );

	CleaningAllButton = new wxButton( Cleaning, wxID_ANY, _("ИСПОЛЬЗОВАТЬ ВСЕ ВАРИАНТЫ!"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningAllButton, 0, wxALL, 5 );

	CleaningTempButton = new wxButton( Cleaning, wxID_ANY, _("Очистка папки TEMP"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningTempButton, 0, wxALL, 5 );

	CleaningUserTempButton = new wxButton( Cleaning, wxID_ANY, _("Очистка временной папки пользователя"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningUserTempButton, 0, wxALL, 5 );

	CleaningPrefetchButton = new wxButton( Cleaning, wxID_ANY, _("Очистка Prefetch"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningPrefetchButton, 0, wxALL, 5 );

	CleaningSoftwareDistributionButton = new wxButton( Cleaning, wxID_ANY, _("Очистка кэша обновлений"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningSoftwareDistributionButton, 0, wxALL, 5 );

	CleaningLogsButton = new wxButton( Cleaning, wxID_ANY, _("Очистка логов Windows"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningLogsButton, 0, wxALL, 5 );

	CleaningPublicDownloadsButton = new wxButton( Cleaning, wxID_ANY, _("Очистка общедоступной папки Downloads"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningPublicDownloadsButton, 0, wxALL, 5 );

	CleaningRecycleBinCButton = new wxButton( Cleaning, wxID_ANY, _("Очистка корзины (диск C:)"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningRecycleBinCButton, 0, wxALL, 5 );

	CleaningAllRecycleBinsButton = new wxButton( Cleaning, wxID_ANY, _("Очистка корзины на всех дисках"), wxDefaultPosition, wxDefaultSize, 0 );
	CleaningButtonsSizer->Add( CleaningAllRecycleBinsButton, 0, wxALL, 5 );


	CleaningSizer->Add( CleaningButtonsSizer, 1, wxEXPAND, 5 );


	Cleaning->SetSizer( CleaningSizer );
	Cleaning->Layout();
	CleaningSizer->Fit( Cleaning );
	mainNotebook->AddPage( Cleaning, _("Очистка"), false );

	mainSettingsSizer->Add( mainNotebook, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( mainSettingsSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	InfoSystemButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::InfoSystemButtonEvent ), NULL, this );
	InfoIpButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::InfoIpButtonEvent ), NULL, this );
	InfoResourcesButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::InfoResourcesButtonEvent ), NULL, this );
	InfoLogsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::InfoLogsButtonEvent ), NULL, this );
	InfoTaskListButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::InfoTaskListButtonEvent ), NULL, this );
	InfoNetButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::InfoNetButtonEvent ), NULL, this );
	FixSystemButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::FixSystemButtonEvent ), NULL, this );
	FixDiskButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::FixDiskButtonEvent ), NULL, this );
	FixOperationalMemoryButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::FixOperationalMemoryButtonEvent ), NULL, this );
	FixDismButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::FixDismButtonEvent ), NULL, this );
	FixNetSettingsResetButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::FixNetSettingsResetButtonEvent ), NULL, this );
	CleaningAllButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningAllButtonEvent ), NULL, this );
	CleaningTempButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningTempButtonEvent ), NULL, this );
	CleaningUserTempButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningUserTempButtonEvent ), NULL, this );
	CleaningPrefetchButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningPrefetchButtonEvent ), NULL, this );
	CleaningSoftwareDistributionButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningSoftwareDistributionButtonEvent ), NULL, this );
	CleaningLogsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningLogsButtonEvent ), NULL, this );
	CleaningPublicDownloadsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningPublicDownloadsButtonEvent ), NULL, this );
	CleaningRecycleBinCButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningRecycleBinCButtonEvent ), NULL, this );
	CleaningAllRecycleBinsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ComputerHelper::CleaningAllRecycleBinsButtonEvent ), NULL, this );
}

ComputerHelper::~ComputerHelper()
{
}
