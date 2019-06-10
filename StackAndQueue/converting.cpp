#include "Header.h"

string convertingRPN(string str) {//
		Stack<char> stackExpr;
		string tempStr;
		for (int i = 0; str[i] != '\0'; i++) {
			char temp = str[i];
			if (isNumber(temp))
				tempStr += temp;
			if (isParenthesis(temp))
				parenthesis(temp, stackExpr, tempStr);
			if (isOperator(temp))
				operatorSolution(temp, stackExpr, tempStr);
		}
		while (!stackExpr.isEmpty())
			tempStr += stackExpr.pop();
		return tempStr;
}