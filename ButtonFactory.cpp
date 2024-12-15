#include "ButtonFactory.h"
//extra
wxButton* ButtonFactory::CreateButton()
{
	return nullptr;
}

wxButton* ButtonFactory::CreateNumberButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateOperatorButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateUnaryButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateEqualButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateBackButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}

wxButton* ButtonFactory::CreateNegativeButton(wxWindow* parent, int id, const wxString& label, const wxPoint& pos, const wxSize& size)
{
	return new wxButton(parent, id, label, pos, size);
}
