#include "Stack.h"
 
void counting(char oper, Stack<double>  & stack) {
	switch (oper) {
	case'^': {
		int tempVal = stack.pop();
		tempVal = pow(stack.pop(), tempVal);
		stack.push(tempVal);
		break;
	}
	case'*': {
		int tempVal = stack.pop();
		tempVal *= stack.pop();
		stack.push(tempVal);
		break;
	}
	case'/': {

		int tempVal = stack.pop();
		tempVal = stack.pop() / tempVal;
		stack.push(tempVal);
		break;
	}
	case'+': {
		int tempVal = stack.pop();
		tempVal += stack.pop();
		stack.push(tempVal);
		break;
	}
	case'-': {
		int tempVal = stack.pop();
		tempVal = stack.pop() - tempVal;
		stack.push(tempVal);
		break;
	}
	}
}