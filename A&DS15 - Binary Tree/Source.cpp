#include <iostream>
#include "BinarySearchTree.h"


void searchTest()
{
	std::cout << "============ÒÅÑÒ ÌÅÒÎÄÀ IterativeSearch============\n";
	BinarySearchTree<int> tree1;
	std::cout <<  tree1.insert(6) << "\n";
	std::cout <<  tree1.insert(4) << "\n";
	std::cout <<  tree1.insert(9) << "\n";
	std::cout <<  tree1.insert(2) << "\n";
	std::cout <<  tree1.insert(5) << "\n";
	std::cout <<  tree1.insert(8) << "\n";
	std::cout <<  tree1.insert(10) << "\n";
	std::cout << "Äîáàâëåíèå óæå ñóùåñòâóşùåãî ıëåìåíòà (8): " << tree1.insert(8) << "\n";
	tree1.print(std::cout);
	
	std::cout << "\n" << "Ïîèñê ñóùåñòâóşùåãî ıëåìåíòà (2): " << tree1.iterativeSearch(2) << "\n";
	std::cout << "Ïîèñê íåñóùåñòâóşùåãî ıëåìåíòà (11): " << tree1.iterativeSearch(11) << "\n";
}

void deleteTest()
{
	std::cout << "\n============ÒÅÑÒ ÌÅÒÎÄÀ deleteKey============\n";
	BinarySearchTree<int> tree1;
	tree1.insert(6);
	tree1.insert(4);
	tree1.insert(9);
	tree1.insert(2);
	tree1.insert(5);
	tree1.insert(8);
	tree1.insert(10);
	tree1.print(std::cout);

	std::cout << "\nÓäàëåíèå íåñóùåñòâóşùåãî ıëåìåíòà (11): ";
	std::cout << tree1.deleteKey(11) << "\n";

	std::cout << "\nÅñëè óçåë (10) íå èìååò ïîòîìêîâ\n";
	std::cout << tree1.deleteKey(10) << "\n";
	tree1.print(std::cout);

	std::cout << "\nÅñëè óçåë (9) èìååò îäíîãî ïîòîìêà - ëåâîãî\n";
	std::cout << tree1.deleteKey(9) << "\n";
	tree1.print(std::cout);

	std::cout << "\nÅñëè óçåë (4) èìååò îäíîãî ïîòîìêà - ïğàâîãî\n";
	tree1.deleteKey(2);
	std::cout << tree1.deleteKey(4) << "\n";
	tree1.print(std::cout);

	std::cout << "\nÅñëè óçåë (3) èìååò äâóõ ïîòîìêîâ\n";
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
	std::cout << "\n============ÒÅÑÒ ÌÅÒÎÄÎÂ getCount è getHeight============\n";
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

	std::cout << "\nÊîëè÷åñòâî óçëîâ äåğåâà: " << tree1.getCount();
	std::cout << "\nÂûñîòà äåğåâà: " << tree1.getHeight() << "\n";

}

void InorderWalkTest()
{
	std::cout << "\n============ÒÅÑÒ ÌÅÒÎÄÎÂ InorderWalk (èòåğàòèâíûé è ğåêóğñèâíûé)============\n";
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
	std::cout << "\n\n============ÒÅÑÒ ÌÅÒÎÄÀ walkByLevels============\n";
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
	std::cout << "\n\n============ÒÅÑÒ ÌÅÒÎÄÀ isSimilar============\n";
	BinarySearchTree<int> tree2;
	tree2.insert(10);
	tree2.insert(7);
	tree2.insert(15);
	tree2.insert(5);
	tree2.insert(8);
	tree2.insert(11);
	tree2.insert(17);
	tree2.insert(20);
	std::cout << "Äåğåâî tree1: "; 
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
	std::cout << "Äåğåâî tree2: ";
	tree3.print(std::cout);
	std::cout << "\n";

	std::cout << tree2.isSimilar(tree3);
	std::cout << "\nÓäàëèì îäèí êëş÷ (8) â tree2\n";
	tree3.deleteKey(8);
	std::cout << tree2.isSimilar(tree3);

}

void isIdenticalKeyTest()
{
	std::cout << "\n\n============ÒÅÑÒ ÌÅÒÎÄÀ isIdenticalKey============\n";
	BinarySearchTree<int> tree2;
	tree2.insert(5);
	tree2.insert(3);
	tree2.insert(7);
	tree2.insert(2);
	tree2.insert(4);
	tree2.insert(6);
	tree2.insert(8);
	std::cout << "Äåğåâî tree1: ";
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
	std::cout << "Äåğåâî tree2: ";
	tree3.print(std::cout);
	std::cout << "\n";

	std::cout << tree2.isIdenticalKey(tree3);
	std::cout << "\nÓäàëèì âñå îäèíàêîâûå êëş÷è èç tree2 (7,8,6,4)\n";
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