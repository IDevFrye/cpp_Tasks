#ifndef STACKEXCEPTIONS_H
#define STACKEXCEPTIONS_H

#include <exception>

class StackOverflow : public std::exception
{

public:
	StackOverflow() : reason("Stack Overflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : reason("Stack Underflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason("WrongStackSize") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

#endif // !STACKEXCEPTIONS_H

