#include "mathParser.h"
#include <stack>
#include <cctype>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>


// Проверка, является ли символ оператором
bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "1/" || token == "^";
}

// Приоритет операций
int getPrecedence(const std::string& op) {
    if (op == "+" || op == "-" || op == "%") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;  // Унарная операция имеет более высокий приоритет
    return 0;
}

// Выполнение операции
double applyOperation(double a, double b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Деление на ноль.");
        return a / b; }
    if (op == "%") return a * (b / 100);
    if (op == "1/") return 1 / a;
    if (op == "^") return std::pow(a, b);  // Изменено на возведение a в степень b
    return 0;
}


std::vector<std::string> tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string num;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (c == '+' || c == '-') {
            // Если это первый символ или предшествующий символ - оператор или открывающая скобка
            if (i == 0 || isOperator(std::string(1, expression[i - 1])) || expression[i - 1] == '(') {
                // Это знак для числа, добавляем его к текущему числу
                num += c;
            }
            else {
                if (!num.empty()) {
                    tokens.push_back(num);
                    num.clear();
                }
                tokens.push_back(std::string(1, c));
            }
        }
        else if (isdigit(c) || c == '.') {
            num += c;  // Добавляем к текущему числу
        }
        else {
            if (!num.empty()) {
                tokens.push_back(num);  // Добавляем число в токены
                num.clear();  // Очищаем текущее число
            }
            if (c == '(' || c == ')' || isOperator(std::string(1, c))) {
                tokens.push_back(std::string(1, c));  // Добавляем операторы
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
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1) || (token[0] == '+' && token.size() > 1)) {
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
        else if (isOperator(token)) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token)) {
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
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1) || (token[0] == '+' && token.size() > 1)) {  // Число
            values.push(std::stod(token));
        }
        else if (isOperator(token)) {  // Оператор
            if (values.empty()) {
                throw std::runtime_error("Недостаточно значений для операции.");
            }

            double b = values.top(); values.pop();

            // Обрабатываем унарные операции
            if (token == "1/") {
                if (b == 0) {
                    throw std::runtime_error("Деление на ноль.");
                }
                values.push(applyOperation(b, 0, token));
            }
            else {
                if (values.empty()) {
                    throw std::runtime_error("Недостаточно значений для операции.");
                }
                double a = values.top(); values.pop();
                values.push(applyOperation(a, b, token));  // Бинарная операция
            }
        }
    }

    if (values.empty()) {
        throw std::runtime_error("Неизвестная ошибка при вычислении.");
    }

    return values.top();
}

