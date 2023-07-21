#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "Stack.h"
#include "StackArrayException.h"




template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int size = 100) :
		size_(size),
		top_(-1)
	{
		if (size <= 0)
		{
			throw WrongStackSize();
		}
		else
		{
			stack_ = new T[size];
		}
	}

	~StackArray()
	{
		delete[] stack_;
	}

	void push(const T& data)
	{

		if (top_ == size_ - 1)
		{
			throw StackOverFlow();
		}
		else
		{
			top_++;
			stack_[top_] = data;
		}
	}

	T pop()
	{

		if (top_ == -1)
		{
			throw StackUnderFlow();
		}
		else
		{
			T temp = stack_[top_];
			top_--;
			return temp;
		}
	}

	bool isEmpty()
	{
		if (top_ == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	T top()
	{
		return stack_[top_];
	}



private:
	T* stack_;
	int size_;
	int top_;

};

#endif
