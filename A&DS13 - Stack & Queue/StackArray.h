#ifndef STACKARRAY_H
#define STACKARRAY_H
#include "Stack.h"
#include "StackExceptions.h"

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(int size = 100):
		size_(size),
		top_(-1)
	{
		if (size_ <= 0)
			throw WrongStackSize();
		array_ = new T [size];
	}
	~StackArray() { //деструктор
		delete array_; 
	}
	void push(const T& e); // метод добавления элемента в стек
	T pop(); // метод удаления верхнего элемента 
	bool isStackEmpty(); // проверка стека на пустоту 

private:
	int size_;
	T* array_;
	int top_;
};

template <class T>
void StackArray<T>::push(const T& e) // реализация метода добавления элемента в стек
{
	if (top_ == size_ - 1)
		throw StackOverflow(); //переполнение стека
	array_[++top_] = e;
}

template <class T>
T StackArray<T>::pop() // реализация метода удаления верхнего элемента стека
{
	if (top_ == -1)
		throw StackUnderflow(); //удаление из пустого стека приводит к ошибке
	else
	{
		T popped = array_[top_];
		top_--;
		return popped;
	}
}

template <class T>
bool StackArray<T>::isStackEmpty() //реализация проверки на пустоту стека
{
	if (top_ == -1)
	{
		return true;
	}
	return false;
}
#endif // !STACKARRAY_H

