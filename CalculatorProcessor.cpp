#include "CalculatorProcessor.h"
#include <wx/math.h>



CalculatorProcessor* CalculatorProcessor::instance = nullptr;

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	if (instance == nullptr) {
		instance = new CalculatorProcessor();
	}
	return instance;
}
CalculatorProcessor::CalculatorProcessor() {}




double CalculatorProcessor::Calculate(const std::string& expression)
{
	std::vector<std::string> tokens = Tokenize(expression);

    
    std::stack<std::string> operators;
    std::vector<std::string> postfix;

	for (const std::string& token : tokens) {
		if (IsOperator(token)) {
			while (!operators.empty() && GetOperatorPrecedence(operators.top()) >= GetOperatorPrecedence(token)) {
				postfix.push_back(operators.top());
				operators.pop();
			}
			operators.push(token);
		}
		else if (IsFunction(token)) {
			operators.push(token);
		}
		else if (token == "(") {
			operators.push(token);
		}
		else if (token == ")") {
			while (operators.top() != "(") {
				postfix.push_back(operators.top());
				operators.pop();
			}
			operators.pop();
		}
		else {
			postfix.push_back(token);
		}
	}

	while (!operators.empty()) {
		postfix.push_back(operators.top());
		operators.pop();
	}
	std::stack<double> evaluationStack;
	for (const std::string& token : postfix) {
		if (IsOperator(token)) {
			double operand2 = evaluationStack.top(); evaluationStack.pop();
			double operand1 = evaluationStack.top(); evaluationStack.pop();
			double result = ApplyOperation(operand1, operand2, token);
			evaluationStack.push(result);
		}
		else if (IsFunction(token)) {
			double operand = evaluationStack.top(); evaluationStack.pop();
			double result = ApplyTrigonometricFunction(token, operand);
			evaluationStack.push(result);
		}
		else {
			evaluationStack.push(std::stod(token));
		}
	}

	return evaluationStack.top();
}






std::vector<std::string> CalculatorProcessor::Tokenize(const std::string& expression)
{
	std::vector<std::string> tokens;
	std::string token;
	bool lastWasOperator = true;

	for (size_t i = 0; i < expression.length(); ++i) {
		char ch = expression[i];

		if (isdigit(ch) || ch == '.') {
			token += ch;
			lastWasOperator = false;
		}
		else if (isalpha(ch)) {
			token += ch;
			lastWasOperator = false;
			if (i + 1 < expression.length() && isalpha(expression[i + 1])) {
				continue; 
			}
			tokens.push_back(token);
			token.clear();
		}
		else if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
			if (ch == '-' && (lastWasOperator || expression[i - 1] == '(')) {
				token += ch;
			}
			else {
				if (!token.empty()) {
					tokens.push_back(token);
					token.clear();
				}
				tokens.push_back(std::string(1, ch));
			}
			lastWasOperator = true;
		}
	}

	if (!token.empty()) {
		tokens.push_back(token);  
	}

	return tokens;
}












// operations 
double CalculatorProcessor::ApplyOperation(double operand1, double operand2, const std::string& op)
{
	if (op == "+") return operand1 + operand2;
	if (op == "-") return operand1 - operand2;
	if (op == "*") return operand1 * operand2;
	if (op == "/") return operand1 / operand2;
	if (op == "%") return fmod(operand1, operand2);
}
//trig function
double CalculatorProcessor::ApplyTrigonometricFunction(const std::string& func, double angle)
{
	angle = DegreesToRadians(angle);
	if (func == "sin") return sin(angle);
    if (func == "cos") return cos(angle);
    if (func == "tan") return tan(angle);

}
//which go firsy
int CalculatorProcessor::GetOperatorPrecedence(const std::string& op)
{
	if (op == "sin" || op == "cos" || op == "tan")
		return 4;
	if (op == "+" || op == "-") 
		return 1;
	if (op == "*" || op == "/") 
		return 2;
	if (op == "%") 
		return 3;
	return 0;
}
//operator
bool CalculatorProcessor::IsOperator(const std::string& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/" || token == "%");
}
//function
bool CalculatorProcessor::IsFunction(const std::string& token)
{
	 return (token == "sin" || token == "cos" || token == "tan");
}
//needed
double CalculatorProcessor::DegreesToRadians(double angle)
{
	return angle * (M_PI / 180.0);
}
