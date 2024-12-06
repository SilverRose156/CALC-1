#include "App.h"
#include "Window.h"



wxIMPLEMENT_APP(App);


bool App::OnInit() {
	//Window = new Window();
	//window->Show();
	//return true;
	Window* window = new Window("Calculator", wxDefaultPosition, wxSize(300, 400));
	window->Show();
	return true;
}