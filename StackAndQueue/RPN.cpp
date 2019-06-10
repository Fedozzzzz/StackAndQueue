#include "Stack.h"

int RPN(string str) {
	Stack<char> stackExpr;
	string tempStr;
	for (int i = 0; str[i] != '\0'; i++) {
		char temp = str[i];
		if (temp >= '0' && temp <= '9')
			tempStr += temp;
		static bool flag;
		if (temp == '(') {
			flag = true;
			stackExpr.push(temp);
		}
		else if (temp == ')')
			while (!stackExpr.isEmpty() && flag ) {
				tempStr += stackExpr.getTop();
				stackExpr.pop();
				if (stackExpr.getTop() == '(') {
					flag = false;
					stackExpr.pop();
				}
			}
		if (temp == '^') {
			if (!stackExpr.isEmpty())
				if (stackExpr.getTop() == '^') {
					tempStr += stackExpr.getTop();
					stackExpr.pop();
				}
			stackExpr.push(temp);
		}
		else
			if (temp == '*' || temp == '/') {
				if (!stackExpr.isEmpty())
					if (stackExpr.getTop() == '^')
					{
						tempStr += stackExpr.getTop();
						stackExpr.pop();
					}
					else
						if (stackExpr.getTop() == '/' || stackExpr.getTop() == '*') {
							tempStr += stackExpr.getTop();
							stackExpr.pop();
						}
				stackExpr.push(temp);
			}
			else if (temp == '+' || temp == '-') {
				if (!stackExpr.isEmpty())
					if (stackExpr.getTop() == '^')
					{
						tempStr += stackExpr.getTop();
						stackExpr.pop();
					}
					else if (stackExpr.getTop() == '/' || stackExpr.getTop() == '*')
						while (stackExpr.getTop() != '+'
							&& stackExpr.getTop() != '-'
							&& stackExpr.getTop() != '('
							&& !stackExpr.isEmpty()) {
							tempStr += stackExpr.getTop();
							stackExpr.pop();
						}
					else if ((stackExpr.getTop() == '+' || stackExpr.getTop() == '-')) {
						tempStr += stackExpr.getTop();
						stackExpr.pop();
					}
					stackExpr.push(temp);
			}
			if (str[i + 1] == '\0')
				while (!stackExpr.isEmpty()) {
					tempStr += stackExpr.getTop();
					stackExpr.pop();
				}
	}
	//Stack<char> stackExpr1;
	//Stack<char> stackExpr2;
	////for (int i = 0; str[i] != '\0'; i++) {
	//	if (str[i] != '^')
	//		if ((str[i] != '*')
	//			&& (str[i] != '/'))
	//			if ((str[i] != '+')
	//				&& (str[i] != '-'))
	//				if ((str[i] != '(')
	//					&& (str[i] != ')'))
	//					stackExpr1.push(str[i]);
	//				else {
	//					if ((str[i] == '(') || (str[i] == '('))
	//						continue;
	//					//stackExpr2.push(str[i]);
	//					//else {
	//					//	stackExpr1.push(stackExpr2.getTop());
	//					//	stackExpr2.pop();
	//					//	stackExpr2.pop();
	//					//}
	//				}
	//			else {
	//				if (!stackExpr2.isEmpty()) {
	//					stackExpr1.push(stackExpr2.getTop());
	//					stackExpr2.pop();
	//				}
	//				stackExpr2.push(str[i]);
	//			}
	//		else {
	//			if (!stackExpr2.isEmpty()) {
	//				stackExpr1.push(stackExpr2.getTop());
	//				stackExpr2.pop();
	//			}
	//			stackExpr2.push(str[i]);
	//		}
	//	else {
	//		if (!stackExpr2.isEmpty()) {
	//			stackExpr1.push(stackExpr2.getTop());
	//			stackExpr2.pop();
	//		}
	//		stackExpr2.push(str[i]);
	//	}
	//	if (str[i + 1] == '\0') {
	//		stackExpr1.push(stackExpr2.getTop());
	//		stackExpr2.pop();
	//	}
	//}
	//stackExpr1.printStack();
	//Stack<char> tempStack;
	//for (int i = 0; !stackExpr1.isEmpty(); i++) {
	//	tempStack.push(stackExpr1.getTop());
	//	stackExpr1.pop();
	//}
//	tempStack.printStack();
	Stack<int> stack;
	for(int i=0;tempStr[i]!='\0';i++){
		char temp = tempStr[i];
		if (temp != '^')
			if ((temp != '*')
				&& (temp != '/'))
				if ((temp != '+')
					&& (temp != '-')) 
					stack.push(temp - '0');
				else { 
					if (temp == '+') {
						int tempVal = stack.getTop();
						stack.pop();
						tempVal += stack.getTop();
						stack.pop();
						stack.push(tempVal);
					}
					else if (temp == '-')
					{
						int tempVal = stack.getTop();
						stack.pop();
						tempVal = stack.getTop() - tempVal;
						stack.pop();
						stack.push(tempVal);
					}
				}
			else{
				if (temp == '*') {
					int tempVal = stack.getTop();
					stack.pop();
					tempVal *= stack.getTop();
					stack.pop();
					stack.push(tempVal);
				}
				else if (temp == '/')
				{
					int tempVal = stack.getTop();
					stack.pop();
					tempVal = stack.getTop() / tempVal;
					stack.pop();
					stack.push(tempVal);
				}
			}
		else {
			int tempVal = stack.getTop();
			stack.pop();
			tempVal = pow(stack.getTop(), tempVal);
			stack.pop();
			stack.push(tempVal);
		}
	}
	return stack.getTop();
 }