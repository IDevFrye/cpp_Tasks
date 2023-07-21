#include"DictionaryList_Practice.h"
#include<iostream>
using namespace std;

template<typename T>
DictionaryList<T>::Node::Node(T value, Node* next) { //конструктор структуры элемента
	value_ = value;
	next_ = next;
}

template<typename T>
DictionaryList<T>::DictionaryList() { //создание пустого словаря
	head_ = nullptr;
	length_ = 0;
}

//template<typename T>
//DictionaryList<T>::DictionaryList(const DictionaryList& src) { //конструктор копирования
//	length_ = src.length_;
//	if (src.head_ == nullptr) { //проверка на нулевой указатель (пустой словарь)
//		head_ = nullptr;
//		return;
//	}
//	head_ = new Node(src.head_->value_);
//	Node* firstPtr = head_; // указатель на элемент
//	Node* secondPtr = src.head_->next_; //указатель на следующий элемент
//	while (secondPtr != nullptr)
//		firstPtr->next_ = new Node(secondPtr->value_, nullptr);
//	firstPtr = firstPtr->next_;
//	secondPtr = secondPtr->next_;
//}

template<typename T>
DictionaryList<T>::DictionaryList(DictionaryList&& dict) noexcept{ //конструктор перемещения
	length_ = dict.length_;
	head_ = dict.head_;
	dict.head_ = nullptr;
}

template<typename T>
DictionaryList<T>& DictionaryList<T>::operator=(DictionaryList&& dict) noexcept{ //оператор перемещающего присваивания
	if (this != &dict) {
		swapDictionaries(dict);
	}
	return *this;
}

template <typename T>
std::ostream& operator <<(std::ostream& stream, const DictionaryList<T>& dict) { //оператор вывода
	stream << "\nСписок: \n";
	if (!dict.head_) stream << "Пустой список \n";
	else {
		typename DictionaryList<T>::Node* current = dict.head_;
		while (current) {
			stream << current->value_ << " ";
			current = current = current->next_;
		}
		stream << std::endl;
	}
	return stream;
}
template<typename T>
void DictionaryList<T>::swapDictionaries(DictionaryList& other) { //метод замены словарей
	swap(head_, other.head_);
}

template<typename T>
void DictionaryList<T>::printDictionary() { //метод вывода словаря
	setlocale(LC_ALL, "ru");
	Node* current = head_;
	while (current != nullptr) {
		cout << current->value_ << "  ";
		current = current->next_;
	}
	cout << endl;
}

template<typename T>
bool DictionaryList<T>::search(T value) { //метод поиска элемента в списке
	Node* current = head_;
	bool flag = false;
	while (current != nullptr) {
		if (value == current->value_) {
			flag = true;
			break;
		}
		current = current->next_;
	}
	return flag;
}

template<typename T>
bool DictionaryList<T>::insert(T value) { //метод вставки элемента в список
	if (search(value) == false) {
		Node* newNode = new Node(value);
		if (length_ == 0) { //случай пустого словаря
			head_ = newNode;
		}
		else if (length_ == 1) { //случай словаря из одного элемента
			if (head_->value_ > value) {
				newNode->next_ = head_;
				head_ = newNode;
			}
			else {
				head_->next_ = newNode;
			}
		}
		else { //остальные случаи
			bool flag = false;
			Node* cur = head_;
			Node* prev_cur = head_;
			if (value < cur->value_) {
				newNode->next_ = head_;
				head_ = newNode;
				flag = true;
			}
			if (flag == false) {
				while (cur->next_ != nullptr) {
					if (value < cur->next_->value_) {
						newNode->next_ = cur->next_;
						cur->next_ = newNode;
						flag = true;
						break;
					}
					cur = cur->next_;
				}
			}
			if (flag == false) {
				cur->next_ = newNode;
			}
		}
		length_++;
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool DictionaryList<T>::deleteElement(T value) { //удаление элемента из списка
	if (search(value)) {
		Node* current = this->head_;
		if (this->head_->value_ == value) {
			this->head_ = this->head_->next_;
		}
		else {
			while (current->next_ != nullptr) {
				if (current->next_->value_ == value) {
					current->next_ = current->next_->next_;
					current = current->next_;
					break;
				}
				current = current->next_;
			}
		}
		length_--;
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
bool DictionaryList<T>::merge(DictionaryList<T>& dict) { //метод объединения словарей
	Node* current = dict.head_;
	while (current != nullptr) {
		if (search(current->value_) == false) {
			insert(current->value_);
		}
		current = current->next_;
	}
	dict.length_ = 0;
	dict.head_ = nullptr;
	return true;
}

template <typename T>
bool DictionaryList<T>::deleteDictionary(DictionaryList<T>& dict) { //метод удаления словаря
	Node* current = dict.head_;
	bool flag = false;
	while (current != nullptr) {
		if (search(current->value_) == true) {
			if (deleteElement(current->value_)) flag = true;
		}
		current = current->next_;
	}
	return flag;
}

template <typename T> DictionaryList<T> getIntersection(DictionaryList<T>& dict1, DictionaryList<T>& dict2) { //дружественная функция нахождения пересечения словарей
	typename DictionaryList<T>::Node* current = dict1.head_;
	DictionaryList<T> res;
	if (dict1.head_ != nullptr && dict2.head_ != nullptr) {
		while (current != nullptr) {
			if (dict2.search(current->value_)) {
				res.insert(current->value_);
			}
			current = current->next_;
		}
	}
	return res;
}


