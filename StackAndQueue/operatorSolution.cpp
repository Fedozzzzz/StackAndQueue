#include "Header.h"

void operatorSolution(char oper, Stack<char> & stack, string & str) {
	while ((priority(oper) <= priority(stack.getTop())
		&& (!stack.isEmpty())))
		str += stack.pop();
	stack.push(oper);
}