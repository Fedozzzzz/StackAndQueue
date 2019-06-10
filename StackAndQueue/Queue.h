#pragma once
#include"iostream"
using namespace std;

template<typename Type>
class Queue
{
private:
	Type * queue_ptr;
	int last_, first_;
	const int MAX_QUEUE_SIZE = 1024;
	int size_;
public:
	Queue()
	{
		queue_ptr = new Type[MAX_QUEUE_SIZE];
		size_ = 0;
		first_ = 0;
		last_ = 0;

	}
	Queue(const Queue & obj)
	{
		queue_ptr_first = new Type[MAX_QUEUE_SIZE];
		size_ = obj.size_;
		first_ = obj.first_;
		last_ = obj.last_;
		for (int i = 0; i < size_; i++)
			queue_ptr[i] = obj.queue_ptr[i];
	}
	~Queue()
	{
		if (queue_ptr != 0)
			delete[] queue_ptr;
	}
	void enQueue(Type value)
	{
		queue_ptr[last_] = value;
		last_ = (last_ + 1) % MAX_QUEUE_SIZE;
		size_++;
	}
	template<typename Type>
	Type deQueue()
	{
		return queue_ptr[first_++];
	}
	Type front()
	{
		return queue_ptr[first_];
	}
	Type back()
	{
		return queue_ptr[last_];
	}
	bool isEmpty()
	{
		return size_ == 0;
	}
	void printQueue()
	{
		for (int i = first_; i < size_; i++)
			cout << queue_ptr[i];
	}
};

