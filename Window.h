#pragma once
#include "wx/wx.h"


class Window : public wxFrame
{
private:
	
	wxTextCtrl* textBox; // = nullptr;
	wxString fast;
	double Operand1 = 0;  
	double Operand2 = 0;   
	int Operators = 0;
	

public:
	Window();
	enum 
	{
		ID_BUTTON,
		ID_TEXT,
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
	//void CalculateResult(const wxString& expression);
	//wxString GetOperatorSymbol(int buttonId);
	//double ParseNumber(const wxString& token);
	wxDECLARE_EVENT_TABLE();
};

