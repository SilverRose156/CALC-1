#include "ButtonFactory.h"

wxButton* ButtonFactory::CreateButton()
{
	return nullptr;
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateOperatorButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}
