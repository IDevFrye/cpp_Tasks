#include <iostream>
#include "StackArray.h"
#include "QueueArray.h"
#include <string>
#include <typeinfo>

bool checkBalanceBrackets(const char* text, const int maxDeep) //�������� �� ���������� ����������� ��������� ������
{
	char cur = text[0];
	StackArray<char> stack;
	int deep = 0;
	int index = 0;
	char popped = text[0];
	while (cur != '\0' && maxDeep >= deep)
	{
		
		if (cur == '(' || cur == '{' || cur == '[')
		{
			stack.push(cur);
			deep++;
		}

		if ((cur == ')' || cur == '}' || cur == ']') )
		{
			if (stack.isStackEmpty())
				return false;
			popped = stack.pop();
			if (popped == '(' && cur == ')' || popped == '{' && cur == '}' || popped == '[' && cur == ']')
			{
				deep--;
			}
			else
				return false;
		}
		index++;
		cur = text[index];
	}
	
	return !deep;
}

int evaluatePostfix(const char* postfix, const size_t stackSize) 
{
	char op1 = 0;
	char op2 = 0;
	char op3 = 0;
	char cur = postfix[0];
	int size = stackSize;
	StackArray<char> stack(stackSize);
	int index = 0;
	int result = 0;
	while (cur != '\0')
	{
		if (cur >= 48 && cur <= 57)
		{
			stack.push(cur - '0');
		}
		if (cur == '+' || cur == '-' || cur == '*' || cur == '/')
		{
				op1 = stack.pop();
				op2 = stack.pop();
				if (cur == '+')
					op3 = op2 + op1;
				else if (cur == '-')
					op3 = op2 - op1;
				else if (cur == '*')
					op3 = op2 * op1;
				else if (cur == '/')
					op3 = op2 / op1;
			stack.push(op3);
		}
			if (postfix[index + 1] == '\0')
				result = stack.pop();
		index++;
		cur = postfix[index];
	}
	return result;
}

void test_Stack()
{
	std::cout << "==========================|Stack Tests|==========================\n";
	StackArray<int> stack1(4);
	std::cout << "| ������ ���� �� 4 ���������" << std::endl;
	std::cout << "| �������� �� ������� �����: ";
	std::cout << stack1.isStackEmpty() << std::endl;
	std::cout << "| �������� �� �������� �������� �� ������� �����: ";
	try
	{
		std::cout << stack1.pop() << std::endl;
		std::cout << stack1.pop() << std::endl;
	}
	catch (StackUnderflow& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "| �������� ������ ������� � ����" << std::endl;
	stack1.push(1);
	std::cout << "| �������� ������ ������� � ����" << std::endl;
	stack1.push(2);
	std::cout << "| �������� ������ ������� � ����" << std::endl;
	stack1.push(3);
	std::cout << "| �������� ��������� ������� � ����" << std::endl;
	stack1.push(4);
	std::cout << "| �������� �� ���������� �������� � ������ ����: ";
	try
	{
		stack1.push(5);
	}
	catch (StackOverflow& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "| �������� �� ������� �����: ";
	std::cout << stack1.isStackEmpty() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << stack1.pop() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << stack1.pop() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << stack1.pop() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << stack1.pop() << std::endl;
	std::cout << "| ������ ���� �� -5 ���������: ";
	try
	{
		StackArray<int> stack2(-5);
		stack2.push(2);
		stack2.isStackEmpty();
	}
	catch (WrongStackSize& e)
	{
		std::cout << e.what();
	}
}

void test_CheckBalanceBrackets()
{
	std::cout << "\n==================|CheckBalanceBrackets Tests|==================\n";
	std::cout << "| 1 ������ ((())) �������� 3: " << checkBalanceBrackets("((()))", 3) << std::endl;
	std::cout << "| 2 ������ ())) �������� 3: " << checkBalanceBrackets("()))", 3) << std::endl;
	std::cout << "| 3 ������ ((())) �������� 2: " << checkBalanceBrackets("((()))", 2) << std::endl;
	std::cout << "| 4 ������    �������� 3: " << checkBalanceBrackets("  ", 3) << std::endl;
	std::cout << "| 5 ������ lkjhg �������� 3: " << checkBalanceBrackets("lkjhg", 3) << std::endl;
	std::cout << "| 6 ������ ( �������� 3: " << checkBalanceBrackets("(", 3) << std::endl;
	std::cout << "| 7 ������ ) �������� 3: " << checkBalanceBrackets(")", 3) << std::endl;
	std::cout << "| 8 ������ (( �������� 0: " << checkBalanceBrackets("((", 0) << std::endl;
	std::cout << "| 9 ������ (3+3)*9-1 �������� 1: " << checkBalanceBrackets("(3+1)*2", 1) << std::endl;
	std::cout << "| 10 ������ ()()()()()() �������� 10: " << checkBalanceBrackets("()()()()()()", 10) << std::endl;
	std::cout << "| 11 ������ {}[]() �������� 3: " << checkBalanceBrackets("{}[]()", 3) << std::endl;
	std::cout << "| 12 ������ ({[]}) �������� 3: " << checkBalanceBrackets("({[]})", 3) << std::endl;
	std::cout << "| 13 ������ {}[]() �������� 2: " << checkBalanceBrackets("{}[]()", 2) << std::endl;
	std::cout << "| 14 ������ ({[]}) �������� 2: " << checkBalanceBrackets("({[]})", 2) << std::endl;
	std::cout << "| 15 ������ {[ �������� 3: " << checkBalanceBrackets("{[", 3) << std::endl;
	std::cout << "| 16 ������ {(] �������� 3:" << checkBalanceBrackets("{(]", 3) << std::endl;
}

void test_Queue()
{
	std::cout << "==========================|Queue Tests|==========================\n";
	std::cout << "| ������� ������� �� 4 ���������" << std::endl;
	QueueArray<int> queue1(4);
	std::cout << "| �������� �� ������� �������: ";
	std::cout << queue1.isQueueEmpty() << std::endl;
	std::cout << "| �������� �� �������� �������� �� ������ �������: ";
	try
	{
		queue1.deQueue();
	}
	catch (QueueUnderflow& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "| �������� ������ ������� � �������" << std::endl;
	queue1.enQueue(1);
	std::cout << "| �������� ������ ������� � �������" << std::endl;
	queue1.enQueue(2);
	std::cout << "| �������� ������ ������� � �������" << std::endl;
	queue1.enQueue(3);
	std::cout << "| �������� ��������� ������� � �������" << std::endl;
	queue1.enQueue(4);
	std::cout << "| �������� �� ���������� �������� � ������ �������: ";
	try
	{
		queue1.enQueue(5);
	}
	catch (QueueOverflow& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "| �������� �� ������� �������: ";
	std::cout << queue1.isQueueEmpty() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue1.deQueue() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue1.deQueue() << std::endl;
	std::cout << "| �������� ������ �������" << std::endl;
	queue1.enQueue(5);
	std::cout << "| ����� �������: ";
	std::cout << queue1.deQueue() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue1.deQueue() << std::endl;
	std::cout << "| �������� ������ �������" << std::endl;
	queue1.enQueue(6);
	std::cout << "| �������� ������ �������" << std::endl;
	queue1.enQueue(7);
	std::cout << "| �������� ��������� �������" << std::endl;
	queue1.enQueue(8);
	std::cout << "| ����� �������: ";
	std::cout << queue1.deQueue() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue1.deQueue() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue1.deQueue() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue1.deQueue() << std::endl;

	std::cout << "| ������� ������� �� 2 ���������" << std::endl;
	QueueArray<const char*> queue2(2);

	queue2.enQueue("sca");
	std::cout << "| �������� ������ ������� � �������" << std::endl;
	queue2.enQueue("safahajsckb");
	std::cout << "| �������� ������ ������� � �������" << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue2.deQueue() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue2.deQueue() << std::endl;
	std::cout << "| �������� �� ������� �������: ";
	std::cout << queue2.isQueueEmpty() << std::endl;
	std::cout << "| ������� ������� �� -5 ���������: ";
	try
	{
		QueueArray<int> queue3(-5);
		queue3.enQueue(3);
		queue3.isQueueEmpty();
	}
	catch(WrongQueueSize& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "==============================PRINT==============================\n";
	QueueArray<int> queue4(4);
	std::cout << "| ������� ������� �� 4 ���������: " << std::endl;
	std::cout << "| �������� ������� 1 � �������" << std::endl;
	queue4.enQueue(1);
	std::cout << "| �������� ������� 2 � �������" << std::endl;
	queue4.enQueue(2);
	std::cout << "| �������� ������� 3 � �������" << std::endl;
	queue4.enQueue(3);
	std::cout << "| �������� ������� 4 � �������" << std::endl;
	queue4.enQueue(4);
	std::cout << "| ����� �������: ";
	queue4.Print();
	std::cout << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue4.deQueue() << std::endl;
	std::cout << "| ����� �������: ";
	std::cout << queue4.deQueue() << std::endl;
	std::cout << "| �������� ������� 5 � �������" << std::endl;
	queue4.enQueue(5);
	std::cout << "| �������� ������� 6 � �������" << std::endl;
	queue4.enQueue(6);
	std::cout << "| ����� �������: ";
	queue4.Print();
	std::cout << std::endl;
	std::cout << "=================================================================\n";
}
	

int main()
{
	setlocale(LC_ALL, "ru");
	test_Stack();
	test_CheckBalanceBrackets();
	test_Queue();
	

	return 0;
}



/*std::cout << evaluatePostfix("23+4*56*-", 20) << std::endl;
	try {
		std::cout << evaluatePostfix("2-", 20) << std::endl;
	}
	catch (StackUnderflow& e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << evaluatePostfix(" ", 20) << std::endl;
	}
	catch (StackUnderflow& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << evaluatePostfix("53+9*7-5/", 20) << std::endl;
	std::cout << evaluatePostfix("48-2/23+3*+2*", 20) << std::endl;
	try {
		std::cout << evaluatePostfix("53+9*7-5/", 1) << std::endl;
	}
	catch (StackOverflow& e)
	{
		std::cout << e.what() << std::endl;
	}*/