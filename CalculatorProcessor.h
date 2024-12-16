#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <stack>
#include <map>
class CalculatorProcessor
{
public:
    static CalculatorProcessor* GetInstance() {
        static CalculatorProcessor instance; 
        return &instance;
    }
    double Calculate(const std::string& expression) {
        std::vector<std::string> tokens = Tokenize(expression);
        std::vector<std::string> postfix = ShuntingYard(tokens);
        return EvaluatePostfix(postfix);
    }
private:
    //I have no clue what i am doibng wrong 
    CalculatorProcessor() {}
    ~CalculatorProcessor() {}
    std::vector<std::string> Tokenize(const std::string& expression) {
        std::vector<std::string> tokens;
        std::string currentToken;
        for (size_t i = 0; i < expression.size(); ++i) {
            char c = expression[i];

            if (isdigit(c) || c == '.') {
                currentToken += c;  
            }
            else if (c == ' ' || c == '\t') {
                continue;  
            }
            else if (IsOperator(c)) {
                if (!currentToken.empty()) {
                    tokens.push_back(currentToken);
                    currentToken.clear();
                }
                tokens.push_back(std::string(1, c));
            }
            else if (c == 's' || c == 'c' || c == 't') {
                if (i + 2 < expression.size() && expression[i + 1] == 'i' && expression[i + 2] == 'n') {
                    tokens.push_back("sin");
                    i += 2;
                }
                else if (i + 2 < expression.size() && expression[i + 1] == 'o' && expression[i + 2] == 's') {
                    tokens.push_back("cos");
                    i += 2;
                }
                else if (i + 2 < expression.size() && expression[i + 1] == 'a' && expression[i + 2] == 'n') {
                    tokens.push_back("tan");
                    i += 2;
                }
            }
        }
        if (!currentToken.empty()) {
            tokens.push_back(currentToken);
        }
        return tokens;
    }

    
    bool IsOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')');
    }

    
    int GetPrecedence(const std::string& op) {
        if 
            (op == "sin" || op == "cos" || op == "tan") 
            return 3;
        if 
            (op == "*" || op == "/" || op == "%") 
            return 2;
        if 
            (op == "+" || op == "-")
            return 1;
        return 0;
    }

   
    std::vector<std::string> ShuntingYard(const std::vector<std::string>& tokens) {
        std::vector<std::string> output;
        std::stack<std::string> operators;
        for (const auto& token : tokens) {
            if (isdigit(token[0]) || token[0] == '.') {
                output.push_back(token);  
            }
            else if (token == "(") {
                operators.push(token);  
            }
            else if (token == ")") {
                while (!operators.empty() && operators.top() != "(") {
                    output.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();  
            }
            else if (IsOperator(token[0])) {
                while (!operators.empty() && GetPrecedence(operators.top()) >= GetPrecedence(token)) {
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
    double EvaluatePostfix(const std::vector<std::string>& postfix) {
        std::stack<double> stack;

        for (const auto& token : postfix) {
            if (isdigit(token[0]) || token[0] == '.') {
                stack.push(std::stod(token));  
            }
            else if (token == "sin" || token == "cos" || token == "tan") {
                double value = stack.top();
                stack.pop();
                if (token == "sin") stack.push(sin(value));
                else if (token == "cos") stack.push(cos(value));
                else if (token == "tan") stack.push(tan(value));
            }
            else if (IsOperator(token[0])) {
                double rightOperand = stack.top(); stack.pop();
                double leftOperand = stack.top(); stack.pop();
                if (token == "+") stack.push(leftOperand + rightOperand);
                else if (token == "-") stack.push(leftOperand - rightOperand);
                else if (token == "*") stack.push(leftOperand * rightOperand);
                else if (token == "/") stack.push(leftOperand / rightOperand);
                else if (token == "%") stack.push(fmod(leftOperand, rightOperand));
            }
        }

        return stack.top();  
    }
};

