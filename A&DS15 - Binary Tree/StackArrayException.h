#ifndef STACKEXCEPTIONS_H
#define STACKEXCEPTIONS_H

#include <exception>

class StackOverFlow : public std::exception
{
public:
	StackOverFlow() : reason_("Error: StackOverFlow.") {}
	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

class StackUnderFlow : public std::exception
{
public:
	StackUnderFlow() : reason_("Error: StackUnderFlow.") {}
	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason_("Error: Wrong Stack Size.") {}
	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};
#endif STACKEXCEPTIONS_H

