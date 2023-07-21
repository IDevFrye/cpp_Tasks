#include <iostream>
#include "StackArray.h"
#include "typeinfo"


bool checkBalanceBrackets(const char* text, const int maxDeep)
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

		if ((cur == ')' || cur == '}' || cur == ']'))
		{
			if (stack.isEmpty())
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

//void test_CheckBalanceBrackets()
//{
//	std::cout << "------------ÒÅÑÒÛ CheckBalanceBrackets------------\n";
//	std::cout << "1:" << checkBalanceBrackets("((()))", 3) << std::endl;
//	std::cout << "2:" << checkBalanceBrackets("()))", 3) << std::endl;
//	std::cout << "3:" << checkBalanceBrackets("((()))", 2) << std::endl;
//	std::cout << "4:" << checkBalanceBrackets("  ", 3) << std::endl;
//	std::cout << "5:" << checkBalanceBrackets("g", 3) << std::endl;
//	std::cout << "6:" << checkBalanceBrackets("(", 3) << std::endl;
//	std::cout << "7:" << checkBalanceBrackets(")", 3) << std::endl;
//	std::cout << "8:" << checkBalanceBrackets(" ", 0) << std::endl;
//	std::cout << "9:" << checkBalanceBrackets("(", 0) << std::endl;
//	std::cout << "10:" << checkBalanceBrackets("((", 0) << std::endl;
//	std::cout << "11:" << checkBalanceBrackets("(3+1)*2", 1) << std::endl;
//	std::cout << "12:" << checkBalanceBrackets("()()()()()()", 10) << std::endl;
//	std::cout << "13:" << checkBalanceBrackets("{}[]()", 3) << std::endl;
//	std::cout << "14:" << checkBalanceBrackets("({[]})", 3) << std::endl;
//	std::cout << "15:" << checkBalanceBrackets("{}[]()", 2) << std::endl;
//	std::cout << "16:" << checkBalanceBrackets("({[]})", 2) << std::endl;
//	std::cout << "17:" << checkBalanceBrackets("{[", 3) << std::endl;
//	std::cout << "18:" << checkBalanceBrackets("{(]", 3) << std::endl;
//}

void test_Stack()
{
	std::cout << "\n------------ÒÅÑÒÛ Stack------------\n";
	StackArray<int> stack1(4);
	std::cout << stack1.isEmpty() << std::endl;

	try
	{
		std::cout << stack1.pop() << std::endl;
		std::cout << stack1.pop() << std::endl;
	}
	catch (StackUnderflow& e)
	{
		std::cout << e.what() << std::endl;
	}

	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);

	try
	{
		stack1.push(5);
	}
	catch (StackOverflow& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << stack1.isEmpty() << std::endl;
	std::cout << stack1.pop() << std::endl;
	std::cout << stack1.pop() << std::endl;
	std::cout << stack1.pop() << std::endl;
	std::cout << stack1.pop() << std::endl;
	try
	{
		StackArray<int> stack2(-4);
		stack2.push(2);
		stack2.isEmpty();
	}
	catch (WrongStackSize& e)
	{
		std::cout << e.what() << std::endl;
	}
}

//void test_Queue()
//{
//	std::cout << "\n------------ÒÅÑÒÛ Queue------------\n";
//	QueueArray<int> queue1(4);
//	std::cout << queue1.isEmpty() << std::endl;
//
//	try
//	{
//		queue1.deQueue();
//	}
//	catch (QueueUnderflow& e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//
//	queue1.enQueue(1);
//	queue1.enQueue(2);
//	queue1.enQueue(3);
//	queue1.enQueue(4);
//
//	try
//	{
//		queue1.enQueue(5);
//	}
//	catch (QueueOverflow& e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//
//	std::cout << queue1.isEmpty() << std::endl;
//	std::cout << queue1.deQueue() << std::endl;
//	std::cout << queue1.deQueue() << std::endl;
//	queue1.enQueue(5);
//	std::cout << queue1.deQueue() << std::endl;
//	std::cout << queue1.deQueue() << std::endl;
//	queue1.enQueue(6);
//	queue1.enQueue(7);
//	queue1.enQueue(8);
//	std::cout << queue1.deQueue() << std::endl;
//	std::cout << queue1.deQueue() << std::endl;
//	std::cout << queue1.deQueue() << std::endl;
//	std::cout << queue1.deQueue() << std::endl;
//
//
//	QueueArray<const char*> queue2(2);
//	queue2.enQueue("sca");
//	queue2.enQueue("safahajsckb");
//	std::cout << queue2.deQueue() << std::endl;
//	std::cout << queue2.deQueue() << std::endl;
//	std::cout << queue2.isEmpty() << std::endl;
//
//	try
//	{
//		QueueArray<int> queue3(-4);
//		queue3.enQueue(3);
//		queue3.isEmpty();
//	}
//	catch (WrongQueueSize& e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//
//}

//int evaluatePostfix(const string& postfix, const size_t stackSize = 100) {
//	StackArray<int> pf;
//	int index = 0;
//	char cur = postfix[index];
//	int res = 0;
//	while (cur != '\0') {
//		if (cur >= 48 && cur <= 57) {
//			pf.push(cur - '0');
//		}
//		if (!pf.isEmpty() && cur == '+') {
//			int op1 = pf.pop();
//			int op2 = pf.pop();
//			pf.push(op2 + op1);
//		}
//		if (!pf.isEmpty() && cur == '-') {
//			int op1 = pf.pop();
//			int op2 = pf.pop();
//			pf.push(op2 - op1);
//		}
//		if (!pf.isEmpty() && cur == '*') {
//			int op1 = pf.pop();
//			int op2 = pf.pop();
//			pf.push(op2 * op1);
//		}
//		if (!pf.isEmpty() && cur == '/') {
//			int op1 = pf.pop();
//			int op2 = pf.pop();
//			pf.push(op2 / op1);
//		}
//		cur = postfix[index++];
//	}
//	if (!pf.isEmpty()) {
//		res = pf.pop();
//	}
//	else {
//		std::cout << "Îøèáêà ââîäà, íåâîçìîæíî ïîñ÷èòàòü ";
//	}
//	return res;
//}

int evaluatePostfix(const char* postfix, const size_t stackSize)
{
	if (postfix == "") {
		throw StackUnderflow();
	}
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

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "==============ÒÅÑÒÈÐÎÂÀÍÈÅ ÂÛÐÀÆÅÍÈÉ==============" << std::endl;
	std::cout << "((4-8)/2 + 3*(2+3))*2 = " << evaluatePostfix("48-2/23+3*+2*", 20) << std::endl;
	std::cout << "((5+3)*9-7)/5 = " << evaluatePostfix("53+9*7-5/", 20)<< std::endl;
	std::cout << "(2+3)*4-5*6 = " << evaluatePostfix("23+4*56*-", 20)<< std::endl;
	try {
		std::cout << evaluatePostfix("2-", 20) << std::endl;
	}
	catch (StackUnderflow& e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << evaluatePostfix("", 20) << std::endl;
	}
	catch (StackUnderflow& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}