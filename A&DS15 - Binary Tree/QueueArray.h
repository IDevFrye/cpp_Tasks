#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include "QueueArrayException.h"
#include "Queue.h"
template <class T>
class QueueArray : public Queue<T>
{
public:
	QueueArray(int size = 100) :
		size_(size),
		front_(-1),
		rear_(-1)
	{
		if (size <= 0)
		{
			throw WrongQueueSize();
		}
		else
		{
			queue_ = new T[size];
		}
	}

	~QueueArray()
	{
		delete[] queue_;
	}

	void enQueue(const T& data)
	{
		/*if (count_ == size_)
		{
			throw QueueOverFlow();
		}
		else
		{
			top_++;
			queue_[top_] = data;
			count_++;
		}*/

		if ((front_ == rear_ + 1) || (front_ == 0 && rear_ == size_ - 1))
		{
			throw QueueOverFlow();
		}
		else
		{
			if (front_ == -1)
			{
				front_ = 0;
			}
			rear_ = (rear_ + 1) % size_;
			queue_[rear_] = data;
		}
	}

	T deQueue()
	{
		/*if (count_ == 0)
		{
			throw QueueUnderFlow();
		}
		else
		{
			T temp = queue_[0];

			top_--;
			T* newQueue = new T[size_];
			for (int i = 0; i < count_; i++)
			{
				newQueue[i] = queue_[i + 1];
			}
			count_--;
			delete[] queue_;

			queue_ = newQueue;
			return temp;
		}*/

		if (front_ == -1)
		{
			throw QueueUnderFlow();
		}
		else
		{
			T temp = queue_[front_];
			if (front_ == rear_) //если в очереди 1 элемент
			{
				front_ = -1;
				rear_ = -1;
			}
			else
			{
				front_ = (front_ + 1) % size_;
			}
			return temp;

		}
	}

	bool isEmpty()
	{
		if (front_ == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Print()
	{
		for (int i = 0; i < size_; i++)
		{
			std::cout << queue_[i];
		}
		std::cout << std::endl;
	}

private:
	int size_;
	T* queue_;
	int front_;
	int rear_;
};
#endif
