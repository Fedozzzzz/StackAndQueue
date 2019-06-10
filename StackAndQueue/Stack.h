#pragma once
#include"iostream"
using namespace std;

template <typename Type>
class Stack
{
private:
	Type * stack_;
	static const int MAX_STACK_SIZE = 1024;
	int top_;
public:
	Stack()
	{
		stack_ = new Type[MAX_STACK_SIZE];
		top_ = 0;
	}
	Stack(int size) {
		if (size > 0 && size <= MAX_STACK_SIZE) {
			stack_ = new Type[size];
			top_ = 0;
		}
	}
    Stack(const Stack & obj)
	{
		stack_ = new Type[MAX_STACK_SIZE];
		top_ = obj.getTop();
		for (int i = 0; i < top_; i++)
			stack_[i] = obj.stack_[i];
	}
	~Stack()
	{
		if (stack_ != 0)
			delete[] stack_;
	}
	inline Type getTop()const
	{
		return stack_[top_];
	}
	inline Type * getStackPtr()const
	{
		return stack_;
	}
	inline void push(Type value)
	{
		if (top_ < MAX_STACK_SIZE) {
			top_++;
			stack_[top_] = value;
		}
	}
	inline void printStack() const
	{
		for (int i = top_; i > 0; i--)
			cout << stack_[i] << endl;
	}
	inline bool isEmpty() const
	{
		return top_ == 0;
	}
	inline Type peek(int i) const
	{
		if (i <= top_)
			return stack_[top_ - i];
	}
	inline Type pop()
	{
		if (top_ > 0) {
			stack_[--top_];
			return stack_[top_ + 1];
		}
	}
};

