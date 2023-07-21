#ifndef STACK_H
#define STACK_H

template <class T>
class Stack //класс стэка
{
public:
	virtual ~Stack() {}
	virtual void push(const T& e) = 0 ; // метод добавления элемента в стэк
	virtual T pop() = 0; //  метод удаления элемента из стэка
	virtual bool isStackEmpty() = 0; // Проверка стека на то, является ли он пустым 
};

#endif // !STACK_H
