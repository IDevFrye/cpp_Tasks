#include <iostream>
#include "BinarySearchTree.h"

void countLeavesTest()
{
	std::cout << "============ÒÅÑÒ ÌÅÒÎÄÀ countLeaves============\n";
	BinarySearchTree<int> tree1;
	tree1.insert(8);
	tree1.insert(3);
	tree1.insert(10);
	tree1.insert(1);
	tree1.insert(6);
	tree1.insert(14);
	tree1.insert(4);
	tree1.insert(7);
	tree1.insert(13);
	std::cout << "Äåðåâî tree1: \n";
	tree1.print(std::cout);
	std::cout << "\n";
	std::cout << tree1.countLeaves() << "\n";
	std::cout << tree1.iterativeCountLeaves() << "\n";
	BinarySearchTree<int> tree2;
	tree2.insert(6);
	tree2.insert(4);
	tree2.insert(9);
	tree2.insert(2);
	tree2.insert(5);
	tree2.insert(8);
	tree2.insert(10);
	std::cout << "Äåðåâî tree2: \n";
	tree2.print(std::cout);
	std::cout << "\n";
	std::cout << tree2.countLeaves() << "\n";
	std::cout << tree2.iterativeCountLeaves() << "\n";
	BinarySearchTree<int> tree3;
	tree3.insert(5);
	tree3.insert(3);
	tree3.insert(7);
	tree3.insert(2);
	tree3.insert(4);
	tree3.insert(6);
	tree3.insert(8);
	tree3.insert(9);
	std::cout << "Äåðåâî tree3: \n";
	tree3.print(std::cout);
	std::cout << "\n";
	std::cout << tree3.countLeaves() << "\n";
	std::cout << tree3.iterativeCountLeaves() << "\n";
	BinarySearchTree<int> tree4;
	tree4.insert(9);
	tree4.insert(7);
	tree4.insert(15);
	tree4.insert(13);
	tree4.insert(18);
	tree4.insert(1);
	tree4.insert(3);
	tree4.insert(11);
	tree4.insert(17);
	std::cout << "Äåðåâî tree4: \n";
	tree4.print(std::cout);
	std::cout << "\n";
	std::cout << tree4.countLeaves() << "\n";
	std::cout << tree4.iterativeCountLeaves() << "\n";
	BinarySearchTree<int> tree5;
	tree5.insert(6);
	tree5.insert(3);
	tree5.insert(8);
	tree5.insert(1);
	tree5.insert(4);
	tree5.insert(7);
	tree5.insert(9);
	std::cout << "Äåðåâî tree5: \n";
	tree5.print(std::cout);
	std::cout << "\n";
	std::cout << tree5.countLeaves() << "\n";
	std::cout << tree5.iterativeCountLeaves() << "\n";
	BinarySearchTree<int> tree6;
	tree6.insert(15);
	tree6.insert(10);
	tree6.insert(7);
	tree6.insert(11);
	tree6.insert(13);
	tree6.insert(8);
	tree6.insert(5);
	tree6.insert(25);
	tree6.insert(21);
	tree6.insert(27);
	tree6.insert(30);
	tree6.insert(18);
	tree6.insert(23);
	tree6.insert(35);
	std::cout << "Äåðåâî tree6: \n";
	tree6.print(std::cout);
	std::cout << "\n";
	std::cout << tree6.countLeaves() << "\n";
	std::cout << tree6.iterativeCountLeaves() << "\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	countLeavesTest();
	return 0;
}