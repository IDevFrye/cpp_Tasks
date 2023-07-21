#ifndef __DICTIONARY_LIST
#define __DICTIONARY_LIST
#include <iostream>
template <typename T>
class DictionaryList
{
private:
	struct Node { // ��������� �������� ������
		T value_; //�������� ��������
		Node* next_; //��������� �� ��������� ������� ������
		Node(T, Node* = nullptr); //������� ������� �� �������� � ���������
	};
	Node* head_; //������ ������� ������ (������)
	int length_; //����� ������ (���������� ���������)
public:
	DictionaryList(); //����������� ������� �������
	DictionaryList(DictionaryList&& dict) noexcept; //����������� �����������
	DictionaryList(const DictionaryList&) = delete; //����������� �����������
	~DictionaryList(); //����������
	DictionaryList& operator=(DictionaryList&&) noexcept; //�������� ������������� ������������
	template <typename T>
	friend std::ostream& operator <<(std::ostream&, const DictionaryList<T>&); //�������� ������
	void swapDictionaries(DictionaryList&); //����� ������ �������
	void printDictionary(); //����� ������
	bool search(T); //����� ������ �������� � ������
	bool insert(T); //����� ������� �������� � ������
	bool deleteElement(T); //�������� �������� �� ������
	bool merge(DictionaryList<T>&); //����� ����������� ��������
	bool deleteDictionary(DictionaryList<T>&); //����� �������� �������
	template <typename T>
	friend  DictionaryList<T> getIntersection(DictionaryList<T>& dict1, DictionaryList<T>& dict2); //������������� ������� ���������� ����������� ���� ��������
};

#endif#pragma once

