#include "Stack.h"

void parenthesis(char symbol, Stack<char> & stack, string & tempStr) {
	switch (symbol) {
	case '(': {
		stack.push(symbol);
		break; }
	case ')': {
		while (!stack.isEmpty() && stack.getTop() != '(')
			tempStr += stack.pop();
		stack.pop();
		break;
	}
	}
}