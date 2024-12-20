#pragma once
#include "wx/wx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <deque>

class CalculatorProcessor
{
public:
    static CalculatorProcessor& GetInstance();
    double Add(double a, double b);
    double Subtract(double a, double b);
    double Multiply(double a, double b);
    double Divide(double a, double b);
    double Modulus(double a, double b);

    double Sin(double value);
    double Cos(double value);
    double Tan(double value);
    CalculatorProcessor() {}
    CalculatorProcessor(const CalculatorProcessor&) = delete;
    CalculatorProcessor& operator=(const CalculatorProcessor&) = delete;

    double Calculate(const wxString& expression);


    struct Symbol {
        enum class Type {
            Number,
            Operator,
            Function,

        };

        Type type;
        std::string value;
        int precedence;

        Symbol(Type t, const std::string& v, int p = -1) : type(t), value(v), precedence(p) {}
    };
private:
    
   

    wxString PreprocessExpression(const wxString& expr);
    std::vector<wxString> Tokenize(const wxString& expr);
    int GetOperatorPrecedence(const wxString& op);
    std::vector<wxString> ConvertToRPN(const std::vector<wxString>& tokens);
    bool IsFunction(const wxString& token);
    bool IsOperator(const wxString& token);
    double EvaluateRPN(const std::vector<wxString>& rpn);

};

