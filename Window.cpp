#include "Window.h"

Window::Window() : wxFrame(nullptr, wxID_ANY, "calculator", wxPoint(200, 200), wxSize(100, 100)){

	button1 = new wxButton(this, wxID_ANY, "Hello", wxPoint(10,10), wxSize (100,100));
	button2 = new wxButton(this, wxID_ANY, "Hello", wxPoint(120,10), wxSize(100,100));
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 120), wxSize(100, 100));

}