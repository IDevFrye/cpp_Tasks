#ifndef __DICTIONARY_LIST
#define __DICTIONARY_LIST
#include <iostream>
template <typename T>
class DictionaryList
{
private:
	struct Node { // структура элемента списка
		T value_; //значение элемента
		Node* next_; //указатель на следующий элемент списка
		Node(T, Node* = nullptr); //элемент состоит из значени€ и указател€
	};
	Node* head_; //первый элемент списка (голова)
	int length_; //длина списка (количество элементов)
public:
	DictionaryList(); //конструктор пустого словар€
	DictionaryList(DictionaryList&& dict) noexcept; //конструктор перемещени€
	DictionaryList(const DictionaryList&) = delete; //конструктор копировани€
	~DictionaryList(); //деструктор
	DictionaryList& operator=(DictionaryList&&) noexcept; //оператор перемещающего присваивани€
	template <typename T>
	friend std::ostream& operator <<(std::ostream&, const DictionaryList<T>&); //оператор вывода
	void swapDictionaries(DictionaryList&); //метод замены списков
	void printDictionary(); //вывод списка
	bool search(T); //метод поиска элемента в списке
	bool insert(T); //метод вставки элемента в список
	bool deleteElement(T); //удаление элемента из списка
	bool merge(DictionaryList<T>&); //метод объединени€ словарей
	bool deleteDictionary(DictionaryList<T>&); //метод удалени€ словар€
	template <typename T>
	friend  DictionaryList<T> getIntersection(DictionaryList<T>& dict1, DictionaryList<T>& dict2); //дружественна€ функци€ нахождени€ пересечени€ двух словарей
};

#endif#pragma once

