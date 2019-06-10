
int priority(char symbol) {
	switch (symbol)
	{
	case '^': return 3;
	case '*': 
	case '/': return 2;
	case '+': 
	case '-': return 1;
	case '(': 
	case ')': return 0;
	}
}