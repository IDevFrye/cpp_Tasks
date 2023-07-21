#ifndef STACK_H
#define STACK_H


template <class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual void push(const T& data) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};

#endif 
