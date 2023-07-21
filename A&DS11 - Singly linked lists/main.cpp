//#include<iostream>
//#include"DictionaryList_Practice.h"
//#include"DictionaryList_Practice.cpp"
//#include<string>
//using namespace std;
//
//bool isDigit(string a) {
//	int start = a[0] == 45 ? 1 : 0;
//	bool flag = true;
//	for (start ; start < a.length(); start++) {
//		if (a[start] < 48 || a[start] > 57) {
//			flag = false;
//			break;
//		}
//	}
//	return flag;
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	string data;
//	cout << "�����������" << endl << "---------------" << endl;
//	DictionaryList <int> test2_int;
//	cout << "������� �������� ������ (�����) ������� �������." << endl 
//		<< "����� ��������� ���� �������� end_data:" << endl;
//	while (true) {
//		cin >> data;
//		if (data != "end_data") {
//			if (isDigit(data)) {
//				test2_int.insert(stoi(data));
//			}
//		}
//		else {
//			break;
//		}
//	}
//	cout << endl << "������ �������:" << endl;
//	test2_int.printDictionary();
//
//	DictionaryList<int> test3_int;
//	cout << endl << "������� �������� ������ (�����) ������� �������." << endl
//		<< "����� ��������� ���� �������� end_data:" << endl;
//	while (true) {
//		cin >> data;
//		if (data != "end_data") {
//			if (data != "end_data") {
//				test3_int.insert(stoi(data));
//			}
//		}
//		else {
//			break;
//		}
//	}
//	cout << endl << "������ �������:" << endl;
//	test3_int.printDictionary();
//
//	test2_int.merge(test3_int);
//	cout << endl << "������� ����� �����������:" << endl;
//	test2_int.printDictionary();
//
//	cout << endl << "��������" << endl << "---------------" << endl;
//
//	DictionaryList<int> test5_int;
//	cout << "������� �������� ������ (�����) ���������� �������." << endl
//		<< "����� ��������� ���� �������� end_data:" << endl;
//	while (true) {
//		cin >> data;
//		if (data != "end_data") {
//			if (data != "end_data") {
//				test5_int.insert(stoi(data));
//			}
//		}
//		else {
//			break;
//		}
//	}
//	cout << endl << "��������� �������:" << endl;
//	test5_int.printDictionary();
//	test2_int.deleteDictionary(test5_int);
//	cout << endl << "������� ����� ��������:" << endl;
//	test2_int.printDictionary();
//	cout << endl << "��������� ������� ������� ����������:" << endl;
//	test5_int.printDictionary();
//
//	cout << endl << "�����������" << endl << "---------------" << endl;
//	DictionaryList<int> test6_int;
//	cout << "������� �������� ������ (�����) ������� �������." << endl
//		<< "����� ��������� ���� �������� end_data:" << endl;
//	while (true) {
//		cin >> data;
//		if (data != "end_data") {
//			if (data != "end_data") {
//				test6_int.insert(stoi(data));
//			}
//		}
//		else {
//			break;
//		}
//	}
//	cout << endl << "������ �������:" << endl;
//	test6_int.printDictionary();
//
//	DictionaryList<int> test7_int;
//	cout << endl << "������� �������� ������ (�����) ������� �������." << endl
//		<< "����� ��������� ���� �������� end_data:" << endl;
//	while (true) {
//		cin >> data;
//		if (data != "end_data") {
//			if (data != "end_data") {
//				test7_int.insert(stoi(data));
//			}
//		}
//		else {
//			break;
//		}
//	}
//	cout << endl << "������ �������:" << endl;
//	test7_int.printDictionary();
//	DictionaryList<int> res = getIntersection(test6_int, test7_int);
//	cout << endl << "�����������:" << endl;
//	res.printDictionary();
//	cout << "�������� �������:" << endl;
//	test6_int.printDictionary();
//	test7_int.printDictionary();
//
//	cout << endl << "������ ������" << endl << "---------------" << endl;
//	DictionaryList<string> test1_str;
//	cout << "������� ����� �������." << endl
//		<< "����� ��������� ���� �������� end_data:" << endl;
//	while (true) {
//		cin >> data;
//		if (data != "end_data") {
//			test1_str.insert(data);
//		}
//		else {
//			break;
//		}
//	}
//	cout << endl << "�������:" << endl;
//	test1_str.printDictionary();
//	cout << endl << "������� ����� ��� ������:   ";
//	cin >> data;
//	if (test1_str.search(data)) {
//		cout << "����� " << data << " ���� � �������" << endl;
//	}
//	else {
//		cout << "����� " << data << " ���������� � �������" << endl;
//	}
//	cout << endl << "������� ����� ��� �������:  ";
//	cin >> data;
//	if (test1_str.insert(data)) {
//		cout << "����������� �������:" << endl;
//		test1_str.printDictionary();
//	}
//	else {
//		cout << "��������� �������� ����� " << data << ", ��� ��� ���������� � �������." << endl;
//	}
//
//	cout << endl << "������� ����� ��� ��������:  ";
//	cin >> data;
//	if (test1_str.deleteElement(data)) {
//		cout << "����������� �������:" << endl;
//		test1_str.printDictionary();
//	}
//	else {
//		cout << "��������� ������� ����� " << data << ", ��� ��� � �������." << endl;
//	}
//	return 0;
//}
#include <iostream>
#include <string>
#include "DictionaryList_Practice.h"
#include "DictionaryList_Practice.cpp"

void dictionaryTest()
{
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-������-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	std::cout << "===================INSERT()===================\n";
	DictionaryList<int> dictInt;

	std::cout << "\n====������� ������ ��������:====\n";
	if (dictInt.insert(9))
		std::cout << "- �������� ������� 9\n";
	if (dictInt.insert(2))
		std::cout << "- �������� ������� 2\n";
	if (dictInt.insert(5))
		std::cout << "- �������� ������� 5\n";
	if (dictInt.insert(1))
		std::cout << "- �������� ������� 1\n";
	if (dictInt.insert(7))
		std::cout << "- �������� ������� 7\n";

	std::cout << "\n====������� ������������� ��������:====\n";
	if (!dictInt.insert(5))
		std::cout << "������� 5 ��� ����������\n";


	std::cout << dictInt << '\n';

	std::cout << "===================SEARCH()===================\n";
	std::cout << "\n====������������ ��������:====\n";
	if (dictInt.search(1))
	{
		std::cout << "- ������� 1 - �������\n";
	}
	if (dictInt.search(5))
	{
		std::cout << "- ������� 5 - �������\n";
	}
	if (dictInt.search(9))
	{
		std::cout << "- ������� 9 - �������\n";
	}
	std::cout << "\n====�������������� ��������:====\n";
	if (!dictInt.search(-8))
	{
		std::cout << "- ������� -8 - �� �������\n";
	}
	if (!dictInt.search(4))
	{
		std::cout << "- ������� 4 - �� �������\n";
	}
	if (!dictInt.search(15))
	{
		std::cout << "- ������� 15 - �� �������\n";
	}

	std::cout << "\n===================DELETE_ELEMENT()===================\n";
	std::cout << "\n====������������ ��������:====\n";
	if (dictInt.deleteElement(5))
	{
		std::cout << "- ������� 5 - �������\n";
	}
	if (dictInt.deleteElement(1))
	{
		std::cout << "- ������� 1 - �������\n";
	}
	if (dictInt.deleteElement(9))
	{
		std::cout << "- ������� 9 - �������\n";
	}

	std::cout << dictInt << '\n';
	std::cout << "\n====�������������� ��������:====\n";
	if (!dictInt.deleteElement(15))
	{
		std::cout << "- ������� 15 - �� �������\n";
	}

	std::cout << "\n====�������� ���������� ���������:====\n";
	if (dictInt.deleteElement(2))
	{
		std::cout << "- ������� 2 - �������\n";
	}
	if (dictInt.deleteElement(7))
	{
		std::cout << "- ������� 7 - �������\n";
	}

	std::cout << dictInt << '\n';

	std::cout << "\n====�������� �� ������� ������:====\n";

	if (!dictInt.deleteElement(5))
		std::cout << "��� ��������� ��� ��������. ������ ����!\n";
	std::cout << dictInt;
}

void operationTest()
{
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-����� ��������-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

	std::cout << "\n===================MERGE()===================\n";
	DictionaryList<std::string> dictStr;
	dictStr.insert("789");
	dictStr.insert("345");
	dictStr.insert("567");
	dictStr.insert("321");
	dictStr.insert("82");

	std::cout << "====BEFORE:====\n";
	std::cout << dictStr << '\n';

	DictionaryList<std::string> dictStr2;
	dictStr2.insert("81");
	dictStr2.insert("123");
	dictStr2.insert("456");
	dictStr2.insert("9");
	dictStr2.insert("987");
	// ������������� �������
	dictStr2.insert("567");

	std::cout << dictStr2 << '\n';

	dictStr.merge(dictStr2);

	std::cout << "====AFTER:====\n";
	std::cout << dictStr << '\n';
	std::cout << dictStr2 << '\n';

	std::cout << "\n====����������� � ������ �������:====\n          [filled + empty]";

	dictStr.merge(dictStr2);
	std::cout << dictStr << '\n';
	std::cout << dictStr2 << '\n';
	std::cout << "\n         [swapping places]\n";
	dictStr2.merge(dictStr);
	std::cout << dictStr << '\n';
	std::cout << dictStr2 << '\n';
	std::cout << "\n         [swapping places]\n";
	dictStr.merge(dictStr2);
	std::cout << dictStr << '\n';
	std::cout << dictStr2 << '\n';
	DictionaryList<std::string> dict1;
	DictionaryList<std::string> dict2;
	if (dict1.merge(dict2))
		std::cout << "\n====���������� 2 ������ ������:====\n          [empty + empty]\n";
	std::cout << dict1;





	std::cout << "\n===================DELETE_DICTIONARY()===================\n";
	dictStr2.insert("81");
	dictStr2.insert("123");
	dictStr2.insert("456");
	dictStr2.insert("9");
	dictStr2.insert("987");
	dictStr2.insert("888");
	dictStr2.insert("777");
	dictStr2.insert("444");

	std::cout << "====BEFORE:====\n";
	std::cout << dictStr << '\n';
	std::cout << dictStr2 << '\n';

	dictStr.deleteDictionary(dictStr2);

	std::cout << "====AFTER:====\n";
	std::cout << dictStr << '\n';
	std::cout << dictStr2 << '\n';

	std::cout << "\n====��������� ������� ������:====\n";
	DictionaryList<std::string> dict;
	dictStr.deleteDictionary(dict);

	std::cout << dictStr << '\n';

	std::cout << "\n====��������� �� ������� ������:====\n";
	if (!DictionaryList<std::string>().deleteDictionary(dictStr))
		std::cout << "\nDeleteDictionary �� ������� ������ ���������.\n";
	std::cout << dict << '\n';


	std::cout << "\n===================GET_INTERSECTION()===================\n";

	DictionaryList<std::string> dictStr3;
	dictStr3.insert("789");
	dictStr3.insert("345");
	dictStr3.insert("567");
	//��������������� ��������
	dictStr3.insert("589");
	dictStr3.insert("467");

	std::cout << "\n====BEFORE:====\n";
	std::cout << dictStr << '\n';
	std::cout << dictStr3 << '\n';


	DictionaryList<std::string> dictStr4 = getIntersection(dictStr, dictStr3);

	std::cout << "\n====AFTER:====\n";
	std::cout << dictStr << '\n';
	std::cout << dictStr3 << '\n';
	std::cout << dictStr4 << '\n';

}

int main()
{
	setlocale(LC_ALL, "ru");

	dictionaryTest();
	operationTest();


	return 0;
}