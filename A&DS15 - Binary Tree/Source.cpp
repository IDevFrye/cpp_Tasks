#include <iostream>
#include "BinarySearchTree.h"


void searchTest()
{
	std::cout << "============���� ������ IterativeSearch============\n";
	BinarySearchTree<int> tree1;
	std::cout <<  tree1.insert(6) << "\n";
	std::cout <<  tree1.insert(4) << "\n";
	std::cout <<  tree1.insert(9) << "\n";
	std::cout <<  tree1.insert(2) << "\n";
	std::cout <<  tree1.insert(5) << "\n";
	std::cout <<  tree1.insert(8) << "\n";
	std::cout <<  tree1.insert(10) << "\n";
	std::cout << "���������� ��� ������������� �������� (8): " << tree1.insert(8) << "\n";
	tree1.print(std::cout);
	
	std::cout << "\n" << "����� ������������� �������� (2): " << tree1.iterativeSearch(2) << "\n";
	std::cout << "����� ��������������� �������� (11): " << tree1.iterativeSearch(11) << "\n";
}

void deleteTest()
{
	std::cout << "\n============���� ������ deleteKey============\n";
	BinarySearchTree<int> tree1;
	tree1.insert(6);
	tree1.insert(4);
	tree1.insert(9);
	tree1.insert(2);
	tree1.insert(5);
	tree1.insert(8);
	tree1.insert(10);
	tree1.print(std::cout);

	std::cout << "\n�������� ��������������� �������� (11): ";
	std::cout << tree1.deleteKey(11) << "\n";

	std::cout << "\n���� ���� (10) �� ����� ��������\n";
	std::cout << tree1.deleteKey(10) << "\n";
	tree1.print(std::cout);

	std::cout << "\n���� ���� (9) ����� ������ ������� - ������\n";
	std::cout << tree1.deleteKey(9) << "\n";
	tree1.print(std::cout);

	std::cout << "\n���� ���� (4) ����� ������ ������� - �������\n";
	tree1.deleteKey(2);
	std::cout << tree1.deleteKey(4) << "\n";
	tree1.print(std::cout);

	std::cout << "\n���� ���� (3) ����� ���� ��������\n";
	BinarySearchTree<int> tree2;
	tree2.insert(8);
	tree2.insert(3);
	tree2.insert(10);
	tree2.insert(1);
	tree2.insert(6);
	tree2.insert(14);
	tree2.insert(4);
	tree2.insert(7);
	tree2.insert(13);
	tree2.print(std::cout);
	std::cout << "\n" << tree2.deleteKey(3) << "\n";
	tree2.print(std::cout);
	std::cout << "\n";
}

void CountHeightTest()
{
	std::cout << "\n============���� ������� getCount � getHeight============\n";
	BinarySearchTree<int> tree1;
	tree1.insert(5);
	tree1.insert(3);
	tree1.insert(7);
	tree1.insert(2);
	tree1.insert(4);
	tree1.insert(6);
	tree1.insert(8);
	tree1.insert(10);
	tree1.deleteKey(5);
	tree1.print(std::cout);

	std::cout << "\n���������� ����� ������: " << tree1.getCount();
	std::cout << "\n������ ������: " << tree1.getHeight() << "\n";

}

void InorderWalkTest()
{
	std::cout << "\n============���� ������� InorderWalk (����������� � �����������)============\n";
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
	tree1.print(std::cout);

	std::cout << "\n";
	tree1.iterativeInorderWalk();
	std::cout << "\n";
	tree1.inorderWalk();
}

void WalkByLevelsTest()
{
	std::cout << "\n\n============���� ������ walkByLevels============\n";
	BinarySearchTree<int> tree1;
	tree1.insert(5);
	tree1.insert(3);
	tree1.insert(7);
	tree1.insert(2);
	tree1.insert(4);
	tree1.insert(6);
	tree1.insert(8);
	tree1.print(std::cout);

	std::cout << "\n";
	tree1.walkByLevels();
}

void isSimilarTest()
{
	std::cout << "\n\n============���� ������ isSimilar============\n";
	BinarySearchTree<int> tree2;
	tree2.insert(10);
	tree2.insert(7);
	tree2.insert(15);
	tree2.insert(5);
	tree2.insert(8);
	tree2.insert(11);
	tree2.insert(17);
	tree2.insert(20);
	std::cout << "������ tree1: "; 
	tree2.print(std::cout);
	std::cout << "\n";

	BinarySearchTree<int> tree3;
	tree3.insert(15);
	tree3.insert(7);
	tree3.insert(17);
	tree3.insert(5);
	tree3.insert(10);
	tree3.insert(8);
	tree3.insert(11);
	tree3.insert(20);
	std::cout << "������ tree2: ";
	tree3.print(std::cout);
	std::cout << "\n";

	std::cout << tree2.isSimilar(tree3);
	std::cout << "\n������ ���� ���� (8) � tree2\n";
	tree3.deleteKey(8);
	std::cout << tree2.isSimilar(tree3);

}

void isIdenticalKeyTest()
{
	std::cout << "\n\n============���� ������ isIdenticalKey============\n";
	BinarySearchTree<int> tree2;
	tree2.insert(5);
	tree2.insert(3);
	tree2.insert(7);
	tree2.insert(2);
	tree2.insert(4);
	tree2.insert(6);
	tree2.insert(8);
	std::cout << "������ tree1: ";
	tree2.print(std::cout);
	std::cout << "\n";

	BinarySearchTree<int> tree3;
	tree3.insert(8);
	tree3.insert(3);
	tree3.insert(10);
	tree3.insert(1);
	tree3.insert(6);
	tree3.insert(14);
	tree3.insert(4);
	tree3.insert(7);
	tree3.insert(13);
	std::cout << "������ tree2: ";
	tree3.print(std::cout);
	std::cout << "\n";

	std::cout << tree2.isIdenticalKey(tree3);
	std::cout << "\n������ ��� ���������� ����� �� tree2 (7,8,6,4)\n";
	tree3.deleteKey(3);
	tree3.deleteKey(7);
	tree3.deleteKey(8);
	tree3.deleteKey(6);
	tree3.deleteKey(4);
	std::cout << tree2.isIdenticalKey(tree3);
}

int main()
{
	setlocale(LC_ALL, "ru");
	searchTest();
	deleteTest();
	CountHeightTest();
	InorderWalkTest();
	WalkByLevelsTest();
	isSimilarTest();
	isIdenticalKeyTest();
	return 0;

}