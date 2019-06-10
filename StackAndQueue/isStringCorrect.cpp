#include"Stack.h"

bool isCorrectString(string str) {
	Stack<char> stack(15);
	for(int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == '{') || (str[i] == '(') || (str[i] == '['))
			stack.push(str[i]);
		else 
		if ((str[i] == '}') || (str[i] == ')') || (str[i] == ']')) {
			if (stack.isEmpty())
				return false;
			char topStackVal = stack.getTop();
			if (((topStackVal == '[') && (str[i] != ']'))
				|| ((topStackVal == '{') && (str[i] != '}'))
				|| ((topStackVal == '(') && (str[i] != ')')))
				return false;
			stack.pop();  
		}
	}
	return stack.isEmpty();
}
