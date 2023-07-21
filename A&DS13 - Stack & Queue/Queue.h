#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual void enQueue(const T& e) = 0; // метод добавления элемента в очередь
	virtual T deQueue() = 0; // метод удаления элемента из очереди
	virtual bool isQueueEmpty() = 0; // Проверка очереди на пустоту 
};

#endif 


