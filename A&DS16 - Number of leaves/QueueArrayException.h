#ifndef QUEUEEXCEPTION_H
#define QUEUEEXCEPTION_H
#include <exception>

class QueueOverFlow : public std::exception
{
public:
	QueueOverFlow() : reason_("Error: QueueOverFlow.") {}
	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

class QueueUnderFlow : public std::exception
{
public:
	QueueUnderFlow() : reason_("Error: QueueUnderFlow.") {}
	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize() : reason_("Error: Wrong Queue Size.") {}
	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

#endif // !QUEUEEXCEPTION_H
