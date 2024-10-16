#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>
#include <vector>

// ��������, �������� �� ������ ����������
bool isOperator(char c);

// ��������� ��������
int getPrecedence(char op);

// ���������� ��������
double applyOperation(double a, double b, char op);

// ������ ������ �� ������ (����� � ���������)
std::vector<std::string> tokenize(const std::string& expression);

// �������������� ���������� ��������� � �������� �������� ������� (RPN)
std::vector<std::string> toRPN(const std::vector<std::string>& tokens);

// ���������� ��������� � �������� �������� ������� (RPN)
double evaluateRPN(const std::vector<std::string>& rpn);

#endif // EXPRESSION_PARSER_H
