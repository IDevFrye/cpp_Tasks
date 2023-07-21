#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual void enQueue(const T& data) = 0;
	virtual T deQueue() = 0;
	virtual bool isEmpty() = 0;
};
#endif // !QUEUE_H