#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>
#include <vector>

// Проверка, является ли символ оператором
bool isOperator(char c);

// Приоритет операций
int getPrecedence(char op);

// Выполнение операции
double applyOperation(double a, double b, char op);

// Разбор строки на токены (числа и операторы)
std::vector<std::string> tokenize(const std::string& expression);

// Преобразование инфиксного выражения в обратную польскую нотацию (RPN)
std::vector<std::string> toRPN(const std::vector<std::string>& tokens);

// Вычисление выражения в обратной польской нотации (RPN)
double evaluateRPN(const std::vector<std::string>& rpn);

#endif // EXPRESSION_PARSER_H
