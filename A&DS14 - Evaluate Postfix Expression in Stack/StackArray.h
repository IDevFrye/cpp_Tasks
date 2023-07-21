#ifndef STACKARRAY_H
#define STACKARRAY_H
#include "Stack.h"
#include "StackExceptions.h"

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int size = 100) :
		size_(size),
		top_(-1)
	{
		if (size_ <= 0)
			throw WrongStackSize();
		array_ = new T[size];
	}
	~StackArray() { delete array_; }
	void push(const T& e); // Добавление элемента в стек
	T pop(); // Удаление верхнего элемента 
	bool isEmpty(); // Проверка стека на пустоту 

private:
	int size_;
	T* array_;
	int top_;
};

template <class T>
void StackArray<T>::push(const T& e)
{
	if (top_ == size_ - 1)
		throw StackOverflow();
	array_[++top_] = e;
}

template <class T>
T StackArray<T>::pop()
{
	if (top_ == -1)
		throw StackUnderflow();
	else
	{
		T popped = array_[top_];
		top_--;
		return popped;
	}
}

template <class T>
bool StackArray<T>::isEmpty()
{
	if (top_ == -1)
	{
		return true;
	}
	return false;
}
#endif // !STACKARRAY_H
