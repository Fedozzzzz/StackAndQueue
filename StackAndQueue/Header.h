#pragma once
#include"Stack.h"
#include"Queue.h"
#include"iostream"
using namespace std;
bool isCorrectString(string str);
int RPN(string str);
bool isNumber(char symbol);
bool isOperator(char symbol);
bool isParenthesis(char symbol);
int priority(char symbol);
void counting(char oper, Stack<double> & stack);
void operatorSolution(char oper, Stack<char> & stack, string & str);
void parenthesis(char symbol, Stack<char> & stack, string & tempStr);
int solutionRPN(string str);
string convertingRPN(string str);
