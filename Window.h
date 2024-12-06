#pragma once
#include "wx/wx.h"


class Window : public wxFrame
{
private:
	//wxButton* button1; // = nullptr;
	//wxButton* button2; // = nullptr;
	wxTextCtrl* textBox; // = nullptr;
	
	void OnButtonClicked(wxCommandEvent& event);

public:
	Window();
	enum 
	{
		ID_BUTTON,
		
		ID_ONE,
		ID_TWO,
		ID_THREE,
		ID_FOUR,
		ID_FIVE,
		ID_SIX,
		ID_SEVEN,
		ID_EIGHT,
		ID_NINE,
		ID_ZERO,
	};
	wxDECLARE_EVENT_TABLE();
};

