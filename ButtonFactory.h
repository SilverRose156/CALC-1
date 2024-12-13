#pragma once
#include "wx/wx.h"
class ButtonFactory
{
public:
	//Basic
	static wxButton* CreateButton();
	//Specific
	static wxButton* CreateAddButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	static wxButton* CreateOperatorButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	

};

