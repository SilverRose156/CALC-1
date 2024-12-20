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
    if (b == 0) {
        throw std::invalid_argument("Cant divide by 0");
    }
    return a / b;
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
double CalculatorProcessor::Calculate(const wxString& expression)
{
    wxString processedExpr = PreprocessExpression(expression);
    std::vector<wxString> tokens = Tokenize(processedExpr);
    std::vector<wxString> rpn = ConvertToRPN(tokens);
    return EvaluateRPN(rpn);
}

wxString CalculatorProcessor::PreprocessExpression(const wxString& expr)
{
    wxString result;
    for (wxChar c : expr) {
        if (c != wxChar(' ') && c != wxChar('(') && c != wxChar(')')) {
            result += c;
        } 
    } 
    return result;

}

//  –   new negative
//should seperae the tokens
std::vector<wxString> CalculatorProcessor::Tokenize(const wxString& expr)
{
    const wxString endash = "–";
    std::vector<wxString> tokens;
    wxString currentToken = "";
    bool negative = false; 
    bool letter = false;
    for (wxChar c : expr) {
        if (c == endash[0]) {
            negative = true;
            if (letter == true) {
                letter = false;
                tokens.push_back(currentToken);
                currentToken.clear();
            }
        }
        else if (std::isdigit(c) || c == wxChar('.')) {
            if (letter == true) {
                letter = false;
                tokens.push_back(currentToken);
                currentToken.clear();
            }
            if (negative == true) {
                negative = false; 
                // adds the negative to the number
                currentToken += "-";
            }
             
                currentToken += c;
            
        }
       // else if (c == wxChar(' ')) {
          //  if (!currentToken.empty()) {
           //     tokens.push_back(currentToken);  
           //     currentToken.clear();            
          //  }
            //need to check if next is a number 
       // }
        else {
            
                letter = true;
                currentToken += c;
            
              
        }
    }
    if (!currentToken.empty()) {
        tokens.push_back(currentToken); 
    }

    return tokens;
}



std::vector<wxString> CalculatorProcessor::ConvertToRPN(const std::vector<wxString>& tokens)
{
    std::stack<wxString> operators;
    std::vector<wxString> output;
    std::map<wxString, int> precedence = {
        {"sin", 4}, 
        {"cos", 4}, 
        {"tan", 4},
        {"*", 3}, 
        {"/", 3}, 
        {"%", 3},
        {"+", 2}, 
        {"-", 2},

    };
    for (const wxString& token : tokens) {
        //function
        if (IsFunction(token)) {
            operators.push(token);
        }
        else if (IsOperator(token)){
            //operator

            while (!operators.empty() && precedence[operators.top()] >= precedence[token]) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
        else {
            //number
            output.push_back(token);
        }

    }
    //left over
    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;

}
//need the functions 
bool CalculatorProcessor::IsFunction(const wxString& token)
{
    return token == "sin"
        || token == "cos"
        || token == "tan";
}

bool CalculatorProcessor::IsOperator(const wxString& token)
{
    return token == "+"
        || token == "-"
        || token == "*"
        || token == "/"
        || token == "%";
}

double CalculatorProcessor::EvaluateRPN(const std::vector<wxString>& rpn)
{
    double temp;
    std::stack<double> stack;

    for (const wxString& token : rpn) {
        
        if (IsFunction(token)) {
            double value = stack.top();
            stack.pop();
            //function
            if (token == "sin") stack.push(Sin(value));
            if (token == "cos") stack.push(Cos(value));
            if (token == "tan") stack.push(Tan(value));
        }
        else if (IsOperator(token)){  //operator
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();//this line is issue
            if (token == "+") stack.push(Add(a, b));
            if (token == "-") stack.push(Subtract(a, b));
            if (token == "*") stack.push(Multiply(a, b));
            if (token == "/") stack.push(Divide(a, b));
            if (token == "%") stack.push(Modulus(a, b));
        }
        else  {
            // if not a token will return error
            //todouble returns non zero value if there is an error
            token.ToDouble(&temp);
            stack.push(temp);
        }
    }

    return stack.top();
}


//negative  do not work 






































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