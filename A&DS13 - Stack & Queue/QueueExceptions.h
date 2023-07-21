#ifndef QUEUEEXCEPTIONS_H
#define QUEUEEXCEPTIONS_H

#include <exception>

class QueueOverflow : public std::exception //исключение переполнение очереди
{

public:
	QueueOverflow() : reason("Queue Overflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

class QueueUnderflow : public std::exception //исключение удаление из пустой очереди
{
public:
	QueueUnderflow() : reason("Queue Underflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

class WrongQueueSize : public std::exception //исключение неверный размер очереди
{
public:
	WrongQueueSize() : reason("WrongQueueSize") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

#endif 
