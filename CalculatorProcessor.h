#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
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

    double Calculate(const std::string& expression);
private:
    CalculatorProcessor() {}
    CalculatorProcessor(const CalculatorProcessor&) = delete;
    CalculatorProcessor& operator=(const CalculatorProcessor&) = delete;

    std::string PreprocessExpression(const std::string& expr);
    std::vector<std::string> Tokenize(const std::string& expr);
    std::vector<std::string> ConvertToRPN(const std::vector<std::string>& tokens);
    bool IsFunction(const std::string& token);
    double EvaluateRPN(const std::vector<std::string>& rpn);

};

