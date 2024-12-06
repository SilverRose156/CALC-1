#include "Window.h"
wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_BUTTON(ID_ONE, Window::OnButtonClicked)
EVT_BUTTON(ID_TWO, Window::OnButtonClicked)
EVT_BUTTON(ID_THREE, Window::OnButtonClicked)
EVT_BUTTON(ID_FOUR, Window::OnButtonClicked)
EVT_BUTTON(ID_FIVE, Window::OnButtonClicked)
EVT_BUTTON(ID_SIX, Window::OnButtonClicked)
EVT_BUTTON(ID_SEVEN, Window::OnButtonClicked)
EVT_BUTTON(ID_EIGHT, Window::OnButtonClicked)
EVT_BUTTON(ID_NINE, Window::OnButtonClicked)
EVT_BUTTON(ID_ZERO, Window::OnButtonClicked)
wxEND_EVENT_TABLE()
Window::Window ()
	: wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(600, 600))
{
	//numbers
	wxButton* button1 = new wxButton(this, ID_ONE, "1", wxPoint(0, 100), wxSize (100,100));
	wxButton* button2 = new wxButton(this, ID_TWO, "2", wxPoint(100, 100), wxSize(100,100));
	wxButton* button3 = new wxButton(this, ID_THREE, "3", wxPoint(200, 100), wxSize(100, 100));
	wxButton* button4 = new wxButton(this, ID_FOUR, "4", wxPoint(0, 200), wxSize(100, 100));
	wxButton* button5 = new wxButton(this, ID_FIVE, "5", wxPoint(100, 200), wxSize(100, 100));
	wxButton* button6 = new wxButton(this, ID_SIX, "6", wxPoint(200, 200), wxSize(100, 100));
	wxButton* button7 = new wxButton(this, ID_SEVEN, "7", wxPoint(0, 300), wxSize(100, 100));
	wxButton* button8 = new wxButton(this, ID_EIGHT, "8", wxPoint(100, 300), wxSize(100, 100));
	wxButton* button9 = new wxButton(this, ID_NINE, "9", wxPoint(200, 300), wxSize(100, 100));
	wxButton* button0 = new wxButton(this, ID_ZERO, "0", wxPoint(0, 400), wxSize(100, 100));

	//Unary Operator
	wxButton* buttonSin = new wxButton(this, wxID_ANY, "Sin", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonCos = new wxButton(this, wxID_ANY, "Cos", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonTan = new wxButton(this, wxID_ANY, "Tan", wxPoint(120, 10), wxSize(100, 100));

	//Binary Operator
	wxButton* buttonPlus = new wxButton(this, wxID_ANY, "+", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonMinus = new wxButton(this, wxID_ANY, "-", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonMultiply = new wxButton(this, wxID_ANY, "*", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonDivide = new wxButton(this, wxID_ANY, "/", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonModulo = new wxButton(this, wxID_ANY, "%", wxPoint(120, 10), wxSize(100, 100));

	//Others
	wxButton* buttonEqual = new wxButton(this, wxID_ANY, "=", wxPoint(300, 0), wxSize(100, 100));
	wxButton* buttonClear = new wxButton(this, wxID_ANY, "Clear", wxPoint(300, 100), wxSize(100, 100));
	wxButton* buttonDelete = new wxButton(this, wxID_ANY, "Back", wxPoint(300, 200), wxSize(100, 100));
	wxButton* buttonDecimal = new wxButton(this, wxID_ANY, ".", wxPoint(300, 300), wxSize(100, 100));
	wxButton* buttonNegative = new wxButton(this, wxID_ANY, "Neg", wxPoint(300, 400), wxSize(100, 100));

	//Text Control
	wxTextCtrl* textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(0, 0), wxSize(300, 100));
	
}

void Window::OnButtonClicked(wxCommandEvent& event)
{
	//get that lable
	wxString label = event.GetString();
	//numbers
	if (label.IsNumber()) { 
		textBox->AppendText(label); 
	}
	//clear
	else if (label == "Clear") {
		textBox->Clear();
	}
	//Equals
	else if (label == "=") {
		wxString expression = textBox->GetValue();
		textBox->Clear();
	}
	//Back
	else if (label == "Back") {
		wxString currentText = textBox->GetValue();
		if (!currentText.IsEmpty()) {
			currentText.RemoveLast();
			textBox->SetValue(currentText);
			//we need to add a catch here 
		}
	}
	else {
		textBox->AppendText(label);
	}
}
