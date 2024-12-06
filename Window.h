#pragma once
#include "wx/wx.h"


class Window : public wxFrame
{
private:
	
	wxTextCtrl* textBox; // = nullptr;
	
	

public:
	Window();
	enum 
	{
		ID_BUTTON,
		ID_TEXT,
		ID_ONE = 1,
		ID_TWO = 2,
		ID_THREE = 3,
		ID_FOUR = 4,
		ID_FIVE = 5,
		ID_SIX = 6,
		ID_SEVEN = 7,
		ID_EIGHT = 8,
		ID_NINE = 9,
		ID_ZERO = 0,

		ID_PLUS,
		ID_MINUS,
		ID_MULTIPLY,
		ID_DIVIDE,
		ID_MODULO,
		ID_DECIMAL,

		ID_NEGATIVE,
		ID_EQUAL,
		ID_CLEAR,
		ID_BACKSPACE,

		ID_SIN,
		ID_COS,
		ID_TAN,
	};
	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;
	void OnButtonClicked(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

