#include "Window.h"
#include <wx/tokenzr.h>
#include <string>
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

EVT_BUTTON(ID_PLUS, Window::OnButtonClicked)
EVT_BUTTON(ID_MINUS, Window::OnButtonClicked)
EVT_BUTTON(ID_MULTIPLY, Window::OnButtonClicked)
EVT_BUTTON(ID_DIVIDE, Window::OnButtonClicked)
EVT_BUTTON(ID_MODULO, Window::OnButtonClicked)
EVT_BUTTON(ID_DECIMAL, Window::OnButtonClicked)

EVT_BUTTON(ID_NEGATIVE, Window::OnButtonClicked)
EVT_BUTTON(ID_EQUAL, Window::OnButtonClicked)
EVT_BUTTON(ID_CLEAR, Window::OnButtonClicked)
EVT_BUTTON(ID_BACKSPACE, Window::OnButtonClicked)

EVT_BUTTON(ID_SIN, Window::OnButtonClicked)
EVT_BUTTON(ID_COS, Window::OnButtonClicked)
EVT_BUTTON(ID_TAN, Window::OnButtonClicked)

wxEND_EVENT_TABLE()
Window::Window ()
	: wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 600))
{
	//numbers
	button1 = new wxButton(this, ID_ONE, "1", wxPoint(0, 100), wxSize (100,100));
	button2 = new wxButton(this, ID_TWO, "2", wxPoint(100, 100), wxSize(100,100));
	wxButton* button3 = new wxButton(this, ID_THREE, "3", wxPoint(200, 100), wxSize(100, 100));
	wxButton* button4 = new wxButton(this, ID_FOUR, "4", wxPoint(0, 200), wxSize(100, 100));
	wxButton* button5 = new wxButton(this, ID_FIVE, "5", wxPoint(100, 200), wxSize(100, 100));
	wxButton* button6 = new wxButton(this, ID_SIX, "6", wxPoint(200, 200), wxSize(100, 100));
	wxButton* button7 = new wxButton(this, ID_SEVEN, "7", wxPoint(0, 300), wxSize(100, 100));
	wxButton* button8 = new wxButton(this, ID_EIGHT, "8", wxPoint(100, 300), wxSize(100, 100));
	wxButton* button9 = new wxButton(this, ID_NINE, "9", wxPoint(200, 300), wxSize(100, 100));
	wxButton* button0 = new wxButton(this, ID_ZERO, "0", wxPoint(0, 400), wxSize(100, 100));

	//Unary Operator
	wxButton* buttonSin = new wxButton(this, ID_SIN, "Sin", wxPoint(0, 500), wxSize(100, 100));
	wxButton* buttonCos = new wxButton(this, ID_COS, "Cos", wxPoint(100, 500), wxSize(100, 100));
	wxButton* buttonTan = new wxButton(this, ID_TAN, "Tan", wxPoint(200, 500), wxSize(100, 100));

	//Binary Operator
	wxButton* buttonPlus = new wxButton(this, ID_PLUS, "+", wxPoint(300, 0), wxSize(100, 100));
	wxButton* buttonMinus = new wxButton(this, ID_MINUS, "-", wxPoint(300, 100), wxSize(100, 100));
	wxButton* buttonMultiply = new wxButton(this, ID_MULTIPLY, "*", wxPoint(300, 200), wxSize(100, 100));
	wxButton* buttonDivide = new wxButton(this, ID_DIVIDE, "/", wxPoint(300, 300), wxSize(100, 100));
	wxButton* buttonModulo = new wxButton(this, ID_MODULO, "%", wxPoint(300, 400), wxSize(100, 100));

	//Others
	wxButton* buttonEqual = new wxButton(this, ID_EQUAL, "=", wxPoint(100, 400), wxSize(200, 100));
	wxButton* buttonClear = new wxButton(this, ID_CLEAR, "Clear", wxPoint(400, 100), wxSize(100, 100));
	wxButton* buttonBack = new wxButton(this, ID_BACKSPACE, "Back", wxPoint(400, 200), wxSize(100, 100));
	wxButton* buttonDecimal = new wxButton(this, ID_DECIMAL, ".", wxPoint(400, 300), wxSize(100, 100));
	wxButton* buttonNegative = new wxButton(this, ID_NEGATIVE, "Negative", wxPoint(400, 400), wxSize(100, 100));

	//Text Control
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(0, 0), wxSize(300, 100));
	
}

void Window::OnButtonClicked(wxCommandEvent& event)
{
	wxString currentText = textBox->GetValue();
	int buttonId = event.GetId();
	//button 1
	//if (textBox->GetValue() == "0") {
	//	textBox->SetValue(button1->GetLabel());
	//}
	//else {
	//	textBox->AppendText(button1->GetLabel());
	//}
	//button 2
	//if (textBox->GetValue() == "0") {
	//	textBox->SetValue(button2->GetLabel());
	//}
	//else {
	//	textBox->AppendText(button2->GetLabel());
	//}
	if (currentText == "0") {
		switch (buttonId) {
		case ID_ONE:
			textBox->SetValue("1");
			break;
		case ID_TWO:
			textBox->SetValue("2");
			break;
		case ID_THREE:
			textBox->SetValue("3");
			break;
		case ID_FOUR:
			textBox->SetValue("4");
			break;
		case ID_FIVE:
			textBox->SetValue("5");
			break;
		case ID_SIX:
			textBox->SetValue("6");
			break;
		case ID_SEVEN:
			textBox->SetValue("7");
			break;
		case ID_EIGHT:
			textBox->SetValue("8");
			break;
		case ID_NINE:
			textBox->SetValue("9");
			break;
		case ID_ZERO:
			textBox->SetValue("0");
			break;
			//case ID_DECIMAL:
			//	textBox->SetValue("."); 
			//	break;

		default:
			break;
		}
	}
	else {
		switch (buttonId) {
		case ID_ONE:
			textBox->AppendText("1");
			break;
		case ID_TWO:
			textBox->AppendText("2");
			break;
		case ID_THREE:
			textBox->AppendText("3");
			break;
		case ID_FOUR:
			textBox->AppendText("4");
			break;
		case ID_FIVE:
			textBox->AppendText("5");
			break;
		case ID_SIX:
			textBox->AppendText("6");
			break;
		case ID_SEVEN:
			textBox->AppendText("7");
			break;
		case ID_EIGHT:
			textBox->AppendText("8");
			break;
		case ID_NINE:
			textBox->AppendText("9");
			break;
		case ID_ZERO:
			textBox->AppendText("0");
			break;


			//sin cos tan
		case ID_SIN:
			textBox->SetValue("sin(" + currentText + ")");
			break;
		case ID_COS:
			textBox->SetValue("cos(" + currentText + ")");
			break;
		case ID_TAN:
			textBox->SetValue("tan(" + currentText + ")");
			break;


			//+-*/.%
		case ID_PLUS:
			textBox->AppendText("+");
			break;
		case ID_MINUS:
			textBox->AppendText("-");
			break;
		case ID_MULTIPLY:
			textBox->AppendText("*");
			break;
		case ID_DIVIDE:
			textBox->AppendText("/");
			break;
		case ID_MODULO:
			textBox->AppendText("%");
			break;
		case ID_DECIMAL:
			if (!currentText.Contains(".")) {
				textBox->AppendText(".");
				break;
				//Calculation and special things 
		case ID_CLEAR:
			textBox->Clear();
			break;
			//backspace
		case ID_BACKSPACE:
			if (!currentText.IsEmpty()) {
				currentText = currentText.Left(currentText.Length() - 1);
				//textBox->Remove(currentText.Length() - 1, 1);
				textBox->SetValue(currentText);
			}
			break;
			//negative
		case ID_NEGATIVE:
			textBox->SetValue("-" + currentText);
			break;
			//equal needs a seperate equation
		case ID_EQUAL:
			
			break;

			//default
		default:
			break;
			}

		}
	}
}

		//seperate equation with tokenizer which is in fact needed 


