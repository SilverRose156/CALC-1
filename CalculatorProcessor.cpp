#include "CalculatorProcessor.h"
//you need the instance
CalculatorProcessor& CalculatorProcessor::GetInstance() {
    static CalculatorProcessor instance;
    return instance;
}
//you need to make the results 
double CalculatorProcessor::Add(double a, double b)
{
    return a + b;
}
double CalculatorProcessor::Subtract(double a, double b)
{
    return a - b;
}
double CalculatorProcessor::Multiply(double a, double b)
{
    return a * b;
}
double CalculatorProcessor::Divide(double a, double b)
{
    return (b != 0) ? a / b : 0;
}
double CalculatorProcessor::Modulus(double a, double b)
{
    return std::fmod(a, b);
}
double CalculatorProcessor::Sin(double value)
{
    return std::sin(value);
}
double CalculatorProcessor::Cos(double value)
{
    return std::cos(value);
}
double CalculatorProcessor::Tan(double value)
{
    return std::tan(value);
}



// set another text box for all types in then shunting yard 
//

//this is to calculate 
double CalculatorProcessor::Calculate(const std::string& expression)
{
    std::string processedExpr = PreprocessExpression(expression);
    std::vector<std::string> tokens = Tokenize(processedExpr);
    std::vector<std::string> rpn = ConvertToRPN(tokens);
    return EvaluateRPN(rpn);
}

std::string CalculatorProcessor::PreprocessExpression(const std::string& expr)
{
    std::string result;
    for (char c : expr) {
        if (!std::isspace(c)) {
            result += c;
        }
    }
    return result;

}
//should seperae the tokens
std::vector<std::string> CalculatorProcessor::Tokenize(const std::string& expr)
{
    std::vector<std::string> tokens;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token) {
        tokens.push_back(token);
    }

    return tokens;

}

std::vector<std::string> CalculatorProcessor::ConvertToRPN(const std::vector<std::string>& tokens)
{
    std::stack<std::string> operators;
    std::vector<std::string> output;
    std::map<std::string, int> precedence = {
        {"sin", 4}, 
        {"cos", 4}, 
        {"tan", 4},
        {"*", 3}, 
        {"/", 3}, 
        {"%", 3},
        {"+", 2}, 
        {"-", 2},

    };
    for (const std::string& token : tokens) {
        if (isdigit(token[0])) {
            output.push_back(token);
        }
        else if (IsFunction(token)) {
            operators.push(token);
        }
        else {
            while (!operators.empty() && precedence[operators.top()] >= precedence[token]) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }
    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;

}
//need the functions 
bool CalculatorProcessor::IsFunction(const std::string& token)
{
    return token == "sin"
        || token == "cos"
        || token == "tan";
}

double CalculatorProcessor::EvaluateRPN(const std::vector<std::string>& rpn)
{
    std::stack<double> stack;

    for (const std::string& token : rpn) {
        if (isdigit(token[0])) {
            stack.push(std::stod(token));
        }
        else if (IsFunction(token)) {
            double value = stack.top();
            stack.pop();
            //function
            if (token == "sin") stack.push(Sin(value));
            if (token == "cos") stack.push(Cos(value));
            if (token == "tan") stack.push(Tan(value));
        }
        else {  //operator
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            if (token == "+") stack.push(Add(a, b));
            if (token == "-") stack.push(Subtract(a, b));
            if (token == "*") stack.push(Multiply(a, b));
            if (token == "/") stack.push(Divide(a, b));
            if (token == "%") stack.push(Modulus(a, b));
        }
    }

    return stack.top();
}





//bool CalculatorProcessor::IsOperator(const std::string& token)
//{
//    return (token == "+"
//  || token == "-"
//  || token == "*"
//  || token == "/"
//  || token == "%");
//function



//int CalculatorProcessor::GetOperatorPrecedence(const std::string& op)
//{
  //  if (op == "sin" || op == "cos" || op == "tan")
    //    return 4;
   // if (op == "+" || op == "-")
     //   return 1;
   // if (op == "*" || op == "/")
     //   return 2;
    //if (op == "%")
      //  return 3;
   // return 0;
//}



//symbol struct
//struct Symbol {
//    std::string value;
//    enum class Type : uint8_t {
//        Unknown,
//        Literal_Numeric,
//        Operator,
//        Parenthesis_Open,
//        Parenthesis_Close,
//        Function
//    } type = Type::Unknown;

//    int precedence = 0;
//    int arguments = 0;
//};
//precedance
//std::unordered_map<std::string, Symbol> operators = {
  //  {"+", {"", Symbol::Type::Operator, 2, 2}},
  //  {"-", {"", Symbol::Type::Operator, 2, 2}},
  //  {"*", {"", Symbol::Type::Operator, 3, 2}},
  //  {"/", {"", Symbol::Type::Operator, 3, 2}},
  //  {"%", {"", Symbol::Type::Operator, 3, 2}},
  //  {"sin", {"", Symbol::Type::Function, 4, 1}},
  //  {"cos", {"", Symbol::Type::Function, 4, 1}},
  //  {"tan", {"", Symbol::Type::Function, 4, 1}},
//};
//set the precedance 