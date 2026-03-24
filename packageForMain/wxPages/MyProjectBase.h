///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class ComputerHelper
///////////////////////////////////////////////////////////////////////////////
class ComputerHelper : public wxFrame
{
private:

protected:
	wxNotebook* mainNotebook;
	wxPanel* Info;
	wxStaticText* InfoTitle;
	wxButton* InfoSystemButton;
	wxButton* InfoIpButton;
	wxButton* InfoResourcesButton;
	wxButton* InfoLogsButton;
	wxButton* InfoTaskListButton;
	wxButton* InfoNetButton;
	wxPanel* Fix;
	wxStaticText* FixTitle;
	wxButton* FixSystemButton;
	wxButton* FixDiskButton;
	wxButton* FixOperationalMemoryButton;
	wxButton* FixDismButton;
	wxButton* FixNetSettingsResetButton;
	wxPanel* Cleaning;
	wxStaticText* CleaningTitle;
	wxButton* CleaningAllButton;
	wxButton* CleaningTempButton;
	wxButton* CleaningUserTempButton;
	wxButton* CleaningPrefetchButton;
	wxButton* CleaningSoftwareDistributionButton;
	wxButton* CleaningLogsButton;
	wxButton* CleaningPublicDownloadsButton;
	wxButton* CleaningRecycleBinCButton;
	wxButton* CleaningAllRecycleBinsButton;

	// Virtual event handlers, override them in your derived class
	virtual void InfoSystemButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void InfoIpButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void InfoResourcesButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void InfoLogsButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void InfoTaskListButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void InfoNetButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void FixSystemButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void FixDiskButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void FixOperationalMemoryButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void FixDismButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void FixNetSettingsResetButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningAllButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningTempButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningUserTempButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningPrefetchButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningSoftwareDistributionButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningLogsButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningPublicDownloadsButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningRecycleBinCButtonEvent(wxCommandEvent& event) { event.Skip(); }
	virtual void CleaningAllRecycleBinsButtonEvent(wxCommandEvent& event) { event.Skip(); }


public:

	ComputerHelper(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Computer Helper"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800, 500), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~ComputerHelper();

};

