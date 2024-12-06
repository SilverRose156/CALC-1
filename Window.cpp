#include "Window.h"
#include <wx/tokenzr.h>
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
	: wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(600, 600))
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
	wxButton* buttonSin = new wxButton(this, ID_SIN, "Sin", wxPoint(0, 0), wxSize(100, 100));
	wxButton* buttonCos = new wxButton(this, ID_COS, "Cos", wxPoint(100, 100), wxSize(100, 100));
	wxButton* buttonTan = new wxButton(this, ID_TAN, "Tan", wxPoint(200, 200), wxSize(100, 100));

	//Binary Operator
	wxButton* buttonPlus = new wxButton(this, ID_PLUS, "+", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonMinus = new wxButton(this, ID_MINUS, "-", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonMultiply = new wxButton(this, ID_MULTIPLY, "*", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonDivide = new wxButton(this, ID_DIVIDE, "/", wxPoint(120, 10), wxSize(100, 100));
	wxButton* buttonModulo = new wxButton(this, ID_MODULO, "%", wxPoint(120, 10), wxSize(100, 100));

	//Others
	wxButton* buttonEqual = new wxButton(this, ID_EQUAL, "=", wxPoint(300, 0), wxSize(100, 100));
	wxButton* buttonClear = new wxButton(this, ID_CLEAR, "Clear", wxPoint(300, 100), wxSize(100, 100));
	wxButton* buttonBack = new wxButton(this, ID_BACKSPACE, "Back", wxPoint(300, 200), wxSize(100, 100));
	wxButton* buttonDecimal = new wxButton(this, ID_DECIMAL, ".", wxPoint(300, 300), wxSize(100, 100));
	wxButton* buttonNegative = new wxButton(this, ID_NEGATIVE, "Negative", wxPoint(300, 400), wxSize(100, 100));

	//Text Control
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(0, 0), wxSize(300, 100));
	
}

void Window::OnButtonClicked(wxCommandEvent& event)
{
	wxString label = event.GetString();
	wxString currentText = textBox->GetValue();
	
	//number
		if (label.IsNumber()) {
			wxString currentText = textBox->GetValue();
			currentText += label;
			textBox->SetValue(currentText);
		}
		//clear
		else if (label == "Clear") {
			textBox->Clear();
		}

		//back
		else if (label == "Back") {
			if (!currentText.IsEmpty()) {
				currentText.Remove(currentText.Len() - 1);
				textBox->SetValue(currentText);
			}
		}

		//equal
		else if (label == "=") {
			if (currentText.IsEmpty()) {
				throw std::invalid_argument("Empty");
				return;
			}
			double result = 0;
			bool validExpression = true;


			//Add
			if (currentText.Contains("+")) {
				wxStringTokenizer tokenizer(currentText, "+");//strtok()
				wxString left = tokenizer.GetNextToken();
				wxString right = tokenizer.GetNextToken();
				result = wxAtof(left) + wxAtof(right);
			}
			else if (currentText.Contains("-")) {
				wxStringTokenizer tokenizer(currentText, "-");//strtok()
				wxString left = tokenizer.GetNextToken();
				wxString right = tokenizer.GetNextToken();
				result = wxAtof(left) - wxAtof(right);
			}
			else if (currentText.Contains("*")) {
				wxStringTokenizer tokenizer(currentText, "*");//strtok()
				wxString left = tokenizer.GetNextToken();
				wxString right = tokenizer.GetNextToken();
				result = wxAtof(left) * wxAtof(right);
			}
			else if (currentText.Contains("/")) {
				wxStringTokenizer tokenizer(currentText, "/");//strtok()
				wxString left = tokenizer.GetNextToken();
				wxString right = tokenizer.GetNextToken();
				//result = wxAtof(left) + wxAtof(right); what do I do here instead
			}

		}
}

 