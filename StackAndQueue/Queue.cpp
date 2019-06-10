#include "Queue.h"


//template<typename Type>
//Queue::Queue()
//{
//	queue_ptr = new Type[max_queue_size];
//	top_ = 0;
//}
//template<typename Type>
//Queue<Type>::Queue(const Queue & obj)
//{
//	queue_ptr = new Type[max_queue_size];
//	top_ = obj.top_;
//	for (int i = 0; i < top_; i++)
//		queue_ptr[i] = obj.queue_ptr[i];
//}
//template<typename Type>
//Queue::~Queue()
//{
//	if (queue_ptr != 0)
//		delete[] queue_ptr;
//}
//
//template<typename Type>
//void Queue<Type>::push(Type value)
//{
//	queue_ptr[top++] = value;
//}
//
//template<typename Type>
//void Queue<Type>::pop()
//{
//	queue_ptr[0];
//}
//