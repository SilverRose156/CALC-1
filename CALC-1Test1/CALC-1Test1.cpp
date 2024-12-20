#include "pch.h"
#include "CppUnitTest.h"
#include "../ButtonFactory.h"
#include "../CalculatorProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CALC1Test1
{
	TEST_CLASS(CALC1Test1)
	{
	public:
		//add
		TEST_METHOD(TestMethodAdd)
		{
			CalculatorProcessor processor;
			double result = processor.Add(5, 3);
			Assert::AreEqual(8.0, result, 0.0001);
		}
		//subtract
		TEST_METHOD(TestMethodSubtract)
		{
			CalculatorProcessor processor;
			double result = processor.Subtract(5, 3);
			Assert::AreEqual(2.0, result, 0.0001);
		}
		//multiply
		TEST_METHOD(TestMethodMultiply)
		{
			CalculatorProcessor processor;
			double result = processor.Multiply(5, 3);
			Assert::AreEqual(15.0, result, 0.0001);
		}
		//divide
		TEST_METHOD(TestMethodDivide)
		{
			CalculatorProcessor processor;
			double result = processor.Divide(6, 2);
			Assert::AreEqual(3.0, result, 0.0001);
		}
		//divide 0
		TEST_METHOD(TestMethodDivideZero)
		{
			CalculatorProcessor processor;
			double result = processor.Divide(5, 0);
			Assert::AreEqual(0.0, result, 0.0001);
		}
		//negative
		TEST_METHOD(TestMethodNegative)
		{
			CalculatorProcessor processor;
			double result = processor.Add(-5, -3);
			Assert::AreEqual(-8.0, result, 0.0001);
		}
	//make a negative 
		TEST_METHOD(TestMethodSubtractNegative)
		{
			CalculatorProcessor processor;
			double result = processor.Subtract(3, 5);
			Assert::AreEqual(-2.0, result, 0.0001);
		}
		//multiply 0
		TEST_METHOD(TestMethodMultiplyByZero)
		{
			CalculatorProcessor processor;
			double result = processor.Multiply(5, 0);
			Assert::AreEqual(0.0, result, 0.0001);
		}
		//negative second
		TEST_METHOD(TestMethodDivideNegative)
		{
			CalculatorProcessor processor;
			double result = processor.Divide(5, -3);
			Assert::AreEqual(-1.6666667, result, 0.0001);
		}
		//negative first
		TEST_METHOD(TestMethodNegativeDivisionResult)
		{
			CalculatorProcessor processor;
			double result = processor.Divide(-6, 3);
			Assert::AreEqual(-2.0, result, .000001);
		}


		//Button factory



		




		
	};
}
