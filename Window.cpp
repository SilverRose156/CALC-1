#include "Window.h"
//wxBEGIN_EVENT_TABLE(Window, wxFrame)
//EVT_BUTTON(WX_ID_ANY, Window::OnButtonClicked)
//wxEND_EVENT_TABLE()
Window::Window (const wxString& title)
	: wxFrame(nullptr, wxID_ANY, title) 
{
	//numbers
	wxButton* button1 = new wxButton(this, wxID_ANY, "Hello", wxPoint(10, 10), wxSize (100,100));
	wxButton* button2 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100,100));
	wxButton* button3 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* button4 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* button5 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* button6 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* button7 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* button8 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* button9 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* button0 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));

	//Unary Operator
	wxButton* buttonSin = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonCos = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonTan = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));

	//Binary Operator
	wxButton* buttonPlus = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonMinus = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonMultiply = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonDivide = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonModulo = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));

	//Others
	wxButton* buttonEqual = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonClear = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonDelete = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonDecimal = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonNegative = new wxButton(this, wxID_ANY, "Hello", wxPoint(120, 10), wxSize(100, 100));

	//Text Control
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 120), wxSize(100, 100));
	
}


