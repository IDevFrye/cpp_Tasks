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
//	cout << "ОБЪЕДИНЕНИЕ" << endl << "---------------" << endl;
//	DictionaryList <int> test2_int;
//	cout << "Введите значения ключей (числа) первого словаря." << endl 
//		<< "Чтобы закончить ввод напишите end_data:" << endl;
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
//	cout << endl << "Первый словарь:" << endl;
//	test2_int.printDictionary();
//
//	DictionaryList<int> test3_int;
//	cout << endl << "Введите значения ключей (числа) второго словаря." << endl
//		<< "Чтобы закончить ввод напишите end_data:" << endl;
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
//	cout << endl << "Второй словарь:" << endl;
//	test3_int.printDictionary();
//
//	test2_int.merge(test3_int);
//	cout << endl << "Словарь после объединения:" << endl;
//	test2_int.printDictionary();
//
//	cout << endl << "УДАЛЕНИЕ" << endl << "---------------" << endl;
//
//	DictionaryList<int> test5_int;
//	cout << "Введите значения ключей (числа) удаляемого словаря." << endl
//		<< "Чтобы закончить ввод напишите end_data:" << endl;
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
//	cout << endl << "Удаляемый словарь:" << endl;
//	test5_int.printDictionary();
//	test2_int.deleteDictionary(test5_int);
//	cout << endl << "Словарь после удаления:" << endl;
//	test2_int.printDictionary();
//	cout << endl << "Удаляемый словарь остался неизменным:" << endl;
//	test5_int.printDictionary();
//
//	cout << endl << "ПЕРЕСЕЧЕНИЕ" << endl << "---------------" << endl;
//	DictionaryList<int> test6_int;
//	cout << "Введите значения ключей (числа) первого словаря." << endl
//		<< "Чтобы закончить ввод напишите end_data:" << endl;
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
//	cout << endl << "Первый словарь:" << endl;
//	test6_int.printDictionary();
//
//	DictionaryList<int> test7_int;
//	cout << endl << "Введите значения ключей (числа) второго словаря." << endl
//		<< "Чтобы закончить ввод напишите end_data:" << endl;
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
//	cout << endl << "Второй словарь:" << endl;
//	test7_int.printDictionary();
//	DictionaryList<int> res = getIntersection(test6_int, test7_int);
//	cout << endl << "Пересечение:" << endl;
//	res.printDictionary();
//	cout << "Исходные словари:" << endl;
//	test6_int.printDictionary();
//	test7_int.printDictionary();
//
//	cout << endl << "МЕТОДЫ КЛАССА" << endl << "---------------" << endl;
//	DictionaryList<string> test1_str;
//	cout << "Введите ключи словаря." << endl
//		<< "Чтобы закончить ввод напишите end_data:" << endl;
//	while (true) {
//		cin >> data;
//		if (data != "end_data") {
//			test1_str.insert(data);
//		}
//		else {
//			break;
//		}
//	}
//	cout << endl << "Словарь:" << endl;
//	test1_str.printDictionary();
//	cout << endl << "Введите слово для поиска:   ";
//	cin >> data;
//	if (test1_str.search(data)) {
//		cout << "Слово " << data << " есть в словаре" << endl;
//	}
//	else {
//		cout << "Слово " << data << " отсутсвует в словаре" << endl;
//	}
//	cout << endl << "Введите слово для вставки:  ";
//	cin >> data;
//	if (test1_str.insert(data)) {
//		cout << "Обновленный словарь:" << endl;
//		test1_str.printDictionary();
//	}
//	else {
//		cout << "Неудалось вставить слово " << data << ", оно уже содержится в словаре." << endl;
//	}
//
//	cout << endl << "Введите слово для удаления:  ";
//	cin >> data;
//	if (test1_str.deleteElement(data)) {
//		cout << "Обновленный словарь:" << endl;
//		test1_str.printDictionary();
//	}
//	else {
//		cout << "Неудалось удалить слово " << data << ", его нет в словаре." << endl;
//	}
//	return 0;
//}
#include <iostream>
#include <string>
#include "DictionaryList_Practice.h"
#include "DictionaryList_Practice.cpp"

void dictionaryTest()
{
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-МЕТОДЫ-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	std::cout << "===================INSERT()===================\n";
	DictionaryList<int> dictInt;

	std::cout << "\n====Вставка нового элемента:====\n";
	if (dictInt.insert(9))
		std::cout << "- Вставлен элемент 9\n";
	if (dictInt.insert(2))
		std::cout << "- Вставлен элемент 2\n";
	if (dictInt.insert(5))
		std::cout << "- Вставлен элемент 5\n";
	if (dictInt.insert(1))
		std::cout << "- Вставлен элемент 1\n";
	if (dictInt.insert(7))
		std::cout << "- Вставлен элемент 7\n";

	std::cout << "\n====Вставка существующего элемента:====\n";
	if (!dictInt.insert(5))
		std::cout << "Элемент 5 уже существует\n";


	std::cout << dictInt << '\n';

	std::cout << "===================SEARCH()===================\n";
	std::cout << "\n====Существующие элементы:====\n";
	if (dictInt.search(1))
	{
		std::cout << "- Элемент 1 - найдено\n";
	}
	if (dictInt.search(5))
	{
		std::cout << "- Элемент 5 - найдено\n";
	}
	if (dictInt.search(9))
	{
		std::cout << "- Элемент 9 - найдено\n";
	}
	std::cout << "\n====Несуществующие элементы:====\n";
	if (!dictInt.search(-8))
	{
		std::cout << "- Элемент -8 - не найдено\n";
	}
	if (!dictInt.search(4))
	{
		std::cout << "- Элемент 4 - не найдено\n";
	}
	if (!dictInt.search(15))
	{
		std::cout << "- Элемент 15 - не найдено\n";
	}

	std::cout << "\n===================DELETE_ELEMENT()===================\n";
	std::cout << "\n====Существующие элементы:====\n";
	if (dictInt.deleteElement(5))
	{
		std::cout << "- Элемент 5 - удалено\n";
	}
	if (dictInt.deleteElement(1))
	{
		std::cout << "- Элемент 1 - удалено\n";
	}
	if (dictInt.deleteElement(9))
	{
		std::cout << "- Элемент 9 - удалено\n";
	}

	std::cout << dictInt << '\n';
	std::cout << "\n====Несуществующие элементы:====\n";
	if (!dictInt.deleteElement(15))
	{
		std::cout << "- Элемент 15 - не найдено\n";
	}

	std::cout << "\n====Удаление оставшихся элементов:====\n";
	if (dictInt.deleteElement(2))
	{
		std::cout << "- Элемент 2 - удалено\n";
	}
	if (dictInt.deleteElement(7))
	{
		std::cout << "- Элемент 7 - удалено\n";
	}

	std::cout << dictInt << '\n';

	std::cout << "\n====Удаление из пустого списка:====\n";

	if (!dictInt.deleteElement(5))
		std::cout << "Нет элементов для удаления. Список пуст!\n";
	std::cout << dictInt;
}

void operationTest()
{
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-ТЕСТЫ ОПЕРАЦИЙ-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

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
	// повторяющийся элемент
	dictStr2.insert("567");

	std::cout << dictStr2 << '\n';

	dictStr.merge(dictStr2);

	std::cout << "====AFTER:====\n";
	std::cout << dictStr << '\n';
	std::cout << dictStr2 << '\n';

	std::cout << "\n====Объединение с пустым списком:====\n          [filled + empty]";

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
		std::cout << "\n====Объединены 2 пустых списка:====\n          [empty + empty]\n";
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

	std::cout << "\n====Вычитание пустого списка:====\n";
	DictionaryList<std::string> dict;
	dictStr.deleteDictionary(dict);

	std::cout << dictStr << '\n';

	std::cout << "\n====Вычитание из пустого списка:====\n";
	if (!DictionaryList<std::string>().deleteDictionary(dictStr))
		std::cout << "\nDeleteDictionary из пустого списка выполнено.\n";
	std::cout << dict << '\n';


	std::cout << "\n===================GET_INTERSECTION()===================\n";

	DictionaryList<std::string> dictStr3;
	dictStr3.insert("789");
	dictStr3.insert("345");
	dictStr3.insert("567");
	//неповторяющиеся элементы
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