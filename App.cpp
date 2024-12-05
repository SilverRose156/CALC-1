#include "App.h"
#include "Window.h"


//starting point first thing that runs
wxIMPLEMENT_APP(App);


bool App::OnInit() {
	window = new Window();
	window->Show();
	return true;
}