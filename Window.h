#pragma once
#include "wx/wx.h"


class Window : public wxFrame
{
private:
	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;
	wxTextCtrl* textBox = nullptr;

public:
	Window();
};

