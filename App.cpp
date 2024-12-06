#include "App.h"
#include "Window.h"


// the starting point 
wxIMPLEMENT_APP(App);


bool App::OnInit() {
	//Window = new Window();
	//window->Show();
	//return true;
	Window* window = new Window("Calculator");
	window->Show(true);
	return true;
}