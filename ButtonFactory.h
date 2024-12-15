#pragma once
#include "wx/wx.h"
class ButtonFactory
{
public:
	//Basic
	static wxButton* CreateButton();
	//Specific
	static wxButton* CreateNumberButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	//in case everything needs to be seperate
	static wxButton* CreateAddButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	static wxButton* CreateOperatorButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	static wxButton* CreateUnaryButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	static wxButton* CreateEqualButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	static wxButton* CreateClearButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	static wxButton* CreateBackButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	static wxButton* CreateDecimalButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	static wxButton* CreateNegativeButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size);
	

};

