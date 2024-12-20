#include "pch.h"
#include "CppUnitTest.h"
#include "../ButtonFactory.h"
#include "../CalculatorProcessor.h"
enum
{
	ID_BUTTON,
	ID_TEXT,
	ID_ONE,
	ID_TWO,
	ID_THREE,
	ID_FOUR,
	ID_FIVE,
	ID_SIX,
	ID_SEVEN,
	ID_EIGHT,
	ID_NINE,
	ID_ZERO,

	ID_PLUS,
	ID_MINUS,
	ID_MULTIPLY,
	ID_DIVIDE,
	ID_MODULO,
	ID_DECIMAL,

	ID_NEGATIVE,
	ID_EQUAL,
	ID_CLEAR,
	ID_BACKSPACE,

	ID_SIN,
	ID_COS,
	ID_TAN,
};
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CALC1Test1
{
	TEST_CLASS(CALC1Test1)
	{
	public:
		//add
		TEST_METHOD(TestMethodAddID)
		{
			int result;
			wxFrame temp(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 600));
			wxButton* buttonPlus = ButtonFactory::CreateAddButton(&temp, ID_PLUS, "+", wxPoint(300, 0), wxSize(100, 100));
			result = buttonPlus -> GetId();// get,label to get label "="
			Assert::AreEqual(int (ID_PLUS), result);
		}
		//TEST_METHOD(TestMethodAddLabel)
		//{

		//	wxString result;


		//	wxFrame temp(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 600));


		//	wxButton* buttonPlus = ButtonFactory::CreateAddButton(&temp, ID_PLUS, "+", wxPoint(300, 0), wxSize(100, 100));


		//	result = buttonPlus->GetLabel();


		//	Assert::AreEqual(wxString("+"), result);
		//}

		//subtract
		TEST_METHOD(TestMethodSubtractID)
		{
			int result;
			wxFrame temp(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 600));
			wxButton* buttonSubtract = ButtonFactory::CreateOperatorButton(&temp, ID_MINUS, "-", wxPoint(300, 0), wxSize(100, 100));
			result = buttonSubtract->GetId();// get,label to get label "="
			Assert::AreEqual(int(ID_MINUS), result);
		}
		//TEST_METHOD(TestMethodSubtractLabel)
		//{
		//	wxString result;
		//	wxFrame temp(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 600));
		//	wxButton* buttonSubtract = ButtonFactory::CreateOperatorButton(&temp, ID_MINUS, "-", wxPoint(300, 0), wxSize(100, 100));
		//	result = buttonSubtract->GetLabel();// get,label to get label "="
		//	Assert::AreEqual(wxString("-"), result);
		//}


		//multiply
		TEST_METHOD(TestMethodMultiplyID)
		{
			int result;
			wxFrame temp(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 600));
			wxButton* buttonMultiply = ButtonFactory::CreateOperatorButton(&temp, ID_MULTIPLY, "*", wxPoint(300, 0), wxSize(100, 100));
			result = buttonMultiply->GetId();// get,label to get label "="
			Assert::AreEqual(int(ID_MINUS), result);
		}
		//TEST_METHOD(TestMethodMultiplyLabel)
		//{
		//	wxString result;
		//	wxFrame temp(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 600));
		//	wxButton* buttonMultiply = ButtonFactory::CreateOperatorButton(&temp, ID_MULTIPLY, "*", wxPoint(300, 0), wxSize(100, 100));
		//	result = buttonMultiply->GetLabel();// get,label to get label "="
		//	Assert::AreEqual(wxString("*"), result);
		//}
	};
}
