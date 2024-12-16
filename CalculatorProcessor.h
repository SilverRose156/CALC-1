#pragma once
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#define SHUNTING _YARD

class CalculatorProcessor
{
	static CalculatorProcessor* GetInstance();
	double Calculate(const std::string& expression);
private:
	CalculatorProcessor();
	static CalculatorProcessor* instance;

	std::vector<std::string> Tokenize(const std::string& expression);
	double ApplyOperation(double operand1, double operand2, const std::string& op);
	double ApplyTrigonometricFunction(const std::string& func, double angle);
	
	
	int GetOperatorPrecedence(const std::string& op);
	bool IsOperator(const std::string& token);
	bool IsFunction(const std::string& token);

	double DegreesToRadians(double angle);
};

