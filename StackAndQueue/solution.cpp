#include "Header.h"

int solutionRPN(string str) {//
	if (isCorrectString(str)) {
		string tempStr = convertingRPN(str);
		Stack<double> stack;
		for (int i = 0; tempStr[i] != '\0'; i++) {
			char temp = tempStr[i];
			if (isNumber(temp))
				stack.push(temp - '0');
			if (isOperator(temp))
				counting(temp, stack);
		}
		return stack.getTop();
	}
	return 0;
}