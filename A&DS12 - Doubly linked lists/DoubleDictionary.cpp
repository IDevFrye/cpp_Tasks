#include <iostream>

class DictionaryList {
public:
	DictionaryList():
		head_(nullptr)
	{}
	~DictionaryList() {
		while (head_) {
			Node* curNode = head_;
			head_ = head_->ptrNext_;
			delete curNode;
		}
	}
	DictionaryList(DictionaryList& list) = delete;
	DictionaryList(DictionaryList&& list) = delete;
	DictionaryList& operator= (DictionaryList& list) = delete;
	DictionaryList& operator= (DictionaryList&& list) = delete;

	void insert(int data) {
		if (head_ == nullptr) {
			head_ = new Node(data);
		}
		else {
			Node* curNode2 = head_;
			while (curNode2->ptrNext_ != nullptr) {
				curNode2 = curNode2->ptrNext_;
				
			}
			Node* curNode = new Node(data);
			curNode2->ptrNext_ = curNode;
			curNode->ptrPrev_ = curNode2;
			curNode->ptrNext_ = nullptr;
			
		}
	}

	void print() {
		std::cout << "\nСписок: \n";
		if (head_ == nullptr) std::cout << "Пустой список!\n";
		else {
			Node* curNode = head_;
			while (curNode != nullptr) {
				std::cout << curNode->data_ << " ";
				curNode = curNode->ptrNext_;
			}
			std::cout << std::endl;
		}
	}

	void removeMax() {
		if (head_ != nullptr && head_->ptrNext_ != nullptr) {
			int maxData = head_->data_;
			Node* curNode = head_;
			while (curNode != nullptr) {
				if (curNode->data_ > maxData) {
					maxData = curNode->data_;
				}
				curNode = curNode->ptrNext_;
			}
			Node* current = head_;
			while (current != nullptr) {
				if (current->data_ == maxData) {
					current->ptrPrev_->ptrNext_ = current->ptrNext_;
					if (current->ptrNext_ != nullptr) current->ptrNext_->ptrPrev_ = current->ptrPrev_;
					Node* temp = current->ptrNext_;
					delete current;
					current = temp;
				}
				else {
					current = current->ptrNext_;
				}
			}
		}
	}
	

private:
	struct Node {
	public:
		Node* ptrNext_;
		Node* ptrPrev_;
		int data_;
		Node(const int& data, Node* ptrNext = nullptr, Node* ptrPrev = nullptr) :
			data_(data),
			ptrNext_(ptrNext),
			ptrPrev_(ptrPrev)
		{};
	};
	Node* head_;
};

int main() {
	setlocale(LC_ALL, "ru");
	DictionaryList dict1;
	std::cout << "====ТЕСТ ЗАПОЛНЕННОГО СПИСКА====";
	dict1.insert(1);
	dict1.insert(9);
	dict1.insert(7);
	dict1.insert(5);
	dict1.insert(9);
	dict1.print();
	dict1.removeMax();
	std::cout << "\n- выполнен метод removeMax()\n";
	dict1.print();
	DictionaryList dict2;
	std::cout << "====ТЕСТ ПУСТОГО СПИСКА====";
	dict2.print();
	dict2.removeMax();
	std::cout << "\n- выполнен метод removeMax()\n";
	dict2.print();
}