#include "mathParser.h"
#include <stack>
#include <cctype>
#include <cmath>

// Проверка, является ли символ оператором
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// Приоритет операций
int getPrecedence(char op) {
    if (op == '+' || op == '-' || op == '%') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Выполнение операции
double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return a * (b / 100);
    }
    return 0;
}

// Разбор строки на токены (числа и операторы)
std::vector<std::string> tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string num;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (isdigit(c) || c == '.') {  // Число
            num += c;
        }
        else {
            if (!num.empty()) {
                tokens.push_back(num);  // Добавляем число в токены
                num.clear();
            }
            if (c == '(' || c == ')' || isOperator(c)) {
                tokens.push_back(std::string(1, c));  // Добавляем операторы и скобки
            }
        }
    }

    if (!num.empty()) {
        tokens.push_back(num);  // Добавляем последнее число
    }

    return tokens;
}

// Преобразование инфиксного выражения в обратную польскую нотацию (RPN)
std::vector<std::string> toRPN(const std::vector<std::string>& tokens) {
    std::vector<std::string> output;
    std::stack<std::string> operators;

    for (const auto& token : tokens) {
        if (isdigit(token[0])) {  // Число
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
            operators.pop();  // Убираем "("
        }
        else if (isOperator(token[0])) {  // Оператор
            while (!operators.empty() && getPrecedence(operators.top()[0]) >= getPrecedence(token[0])) {
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

// Вычисление выражения в обратной польской нотации (RPN)
double evaluateRPN(const std::vector<std::string>& rpn) {
    std::stack<double> values;

    for (const auto& token : rpn) {
        if (isdigit(token[0])) {  // Число
            values.push(std::stod(token));
        }
        else if (isOperator(token[0])) {  // Оператор
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            values.push(applyOperation(a, b, token[0]));
        }
    }

    return values.top();
}
