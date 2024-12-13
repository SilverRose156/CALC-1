#pragma once
#include "wx/wx.h"
class ButtonFactory
{
	static wxButton* CreateGenericButton;

	static wxButton* CreateNumberButton;
	static wxButton* CreateOperatorButton;
	static wxButton* CreateUrnaryButton;
	static wxButton* CreateOtherButton;
	

};

