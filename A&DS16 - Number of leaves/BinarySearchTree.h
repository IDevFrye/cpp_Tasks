#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <fstream>
#include "BinarySearchTree.h"
#include "StackArray.h"
#include "QueueArray.h"

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree(): // "по умолчанию" создает пустое дерево
		root_(nullptr)
	{};
		
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr) noexcept :
		root_(scr.root_)
	{
		scr.root_ = nullptr;
	}
	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) noexcept
	{
		if (this != &src)
		{
			swap(src);
		}
		return *this;
	}

	void swap(BinarySearchTree <T>& src) noexcept
	{
		std::swap(root_, src.root_);
	}

	virtual ~BinarySearchTree()
	{
		delete root_;
	}
	// 1.1 Функция поиска по ключу в бинарном дереве поиска
	bool iterativeSearch(const T& key) const
	{
		Node<T>* current = root_;
		while (current != nullptr)
		{
			if (current->key_ == key)
			{
				return true;
			}
			else if (current->key_ > key)
			{
				current = current->left_;
			}
			else
			{
				current = current->right_;
			}
		}
		return false;
	}


	// 2 Вставка нового элемента в дерево: true, если элемент добавлен;
	// false, если элемент уже был
	bool insert(const T& key)
	{
		if (root_ == nullptr)
		{
			root_ = new Node<T>(key);
			return true;
		}
		Node<T>* curr = root_;
		while (curr != nullptr)
		{
			if (key == curr->key_)
			{
				return false; //элемент уже существует
			}
			else if (key < curr->key_)
			{
				if (curr->left_ == nullptr)
				{
					curr->left_ = new Node<T>(key);
					return true;
				}
				else
				{
					curr = curr->left_;
				}
			}
			else // key > curr.key_
			{
				if (curr->right_ == nullptr)
				{
					curr->right_ = new Node<T>(key);
					return true;
				}
				else
				{
					curr = curr->right_;
				}
			}
		}
	};


	// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
	// true, если элемент удален; false, если элемента не было
	bool deleteKey(const T& key)
	{
		Node<T>* curr = root_;
		Node<T>* parent = nullptr;
		while (curr != nullptr)
		{
			if (key == curr->key_)
			{
				if (curr->left_ == nullptr && curr->right_ == nullptr)
				//узел не имеет потомков
				{
					if (parent == nullptr)
					{
						root_ = nullptr;
					}
					else if (curr == parent->left_)
					{
						parent->left_ = nullptr;
					}
					else
					{
						parent->right_ = nullptr;
					}
					delete curr;
				}
				else if (curr->left_ == nullptr)
				//узел имеет одного ребенка - правого
				{
					if (parent == nullptr)
					{
						root_ = curr->right_;
					}
					else if (curr == parent->left_)
					{
						parent->left_ = curr->right_;
					}
					else
					{
						parent->right_ = curr->right_;
					}
					delete curr;
				}
				else if (curr->right_ == nullptr)
				//узел имеет одного ребенка - левого
				{
					if (parent == nullptr)
					{
						root_ = curr->left_;
					}
					else if (curr == parent->left_)
					{
						parent->left_ = curr->left_;
					}
					else
					{
						parent->right_ = curr->left_;
					}
					delete curr;
				}
				else // если узел имеет двух детей
				{
					Node<T>* successor = curr->right_;
					Node<T>* successorParent = curr;
					while (successor->left_ != nullptr)
					{
						successorParent = successor;
						successor = successor->left_;
					}
					curr->key_ = successor->key_;
					if (successor == curr->right_)
					{
						curr->right_ = successor->right_;
					}
					else
					{
						successorParent->left_ = successor->right_;
					}
					delete successor;
				}
				return true;
			}
			else if (key < curr->key_)
			{
				parent = curr;
				curr = curr->left_;
			}
			else // key > curr->key_
			{
				parent = curr;
				curr = curr->right_;
			}
		}
		return false;
	}


	// 4.1 Печать строкового изображения дерева в выходной поток out,
	// использовать скобки, чтобы показать структуру дерева
	void print(std::ostream& out) const
	{
		printNode(out, root_);
	}

	
	// 5.1 Определение количества узлов дерева
	int getCount() const
	{
		return getCount(root_);
	};


	// 6.1 Определение высоты дерева
	int getHeight() const
	{
		return getHeight(root_)-1;
	}


	// 7 Инфиксный обход дерева (итеративный)
	void iterativeInorderWalk() const
	{
		if (root_ == nullptr)
		{
			return;
		}

		StackArray<Node<T>*> stack;
		Node<T>* node = root_;

		while (!stack.isEmpty() || node != nullptr)
		{
			if (node != nullptr)
			{
				stack.push(node);
				node = node->left_;
			}
			else
			{
				node = stack.pop();
				std::cout << node->key_ << " ";
				node = node->right_;
			}
		}
	}


	// 8.1 Инфиксный обход дерева (рекурсивный)
	void inorderWalk() const
	{
		inorderWalk(root_);
	}

	// 12 
	int countLeaves() const
	{
		return countLeaves(root_);
	}

	void search(const T& key)
	{
		std::cout << iterativeSearchNode(key);
	}
	// 9 Обход двоичного дерева по уровням (в ширину).
	void walkByLevels() const
	{
		if (root_ == nullptr)
		{
			return;
		}

		QueueArray<Node<T>*> queue;
		queue.enQueue(root_);

		while (!queue.isEmpty())
		{
			Node<T>* node = queue.deQueue();
			std::cout << node->key_ << " ";

			if (node->left_ != nullptr)
			{
				queue.enQueue(node->left_);
			}
			if (node->right_ != nullptr)
			{
				queue.enQueue(node->right_);
			}
		}
	}


	// 10 Являются ли два дерева похожими
	bool isSimilar(const BinarySearchTree<T>& other) const
	{
		StackArray<const Node<T>*> stack1, stack2;
		const Node<T>* curr1 = root_;
		const Node<T>* curr2 = other.root_;

		while (curr1 != nullptr || curr2 != nullptr || !stack1.isEmpty() || !stack2.isEmpty())
		{

			while (curr1 != nullptr)
			{
				stack1.push(curr1);
				curr1 = curr1->left_;
			}
			while (curr2 != nullptr)
			{
				stack2.push(curr2);
				curr2 = curr2->left_;
			}

			if (stack1.isEmpty() || stack2.isEmpty())
			{
				return false;
			}

			curr1 = stack1.pop();
			curr2 = stack2.pop();

			if (curr1->key_ != curr2->key_)
			{
				return false;
			}

			curr1 = curr1->right_;
			curr2 = curr2->right_;
		}

		return true;
	}


	// 11 Есть одинаковые ключи в двух деревьях поиска
	bool isIdenticalKey(const BinarySearchTree<T>& other) const
	{
		StackArray<Node<T>*> S1;
		StackArray<Node<T>*> S2;


		Node<T>* p1 = root_;
		Node<T>* p2 = other.root_;

		while ((p1 != nullptr || !S1.isEmpty()) && (p2 != nullptr || !S2.isEmpty()))
		{
			while (p1 != nullptr || p2 != nullptr)
			{
				if (p1 != nullptr)
				{
					S1.push(p1);
					p1 = p1->left_;
				}
				if (p2 != nullptr)
				{
					S2.push(p2);
					p2 = p2->left_;
				}
			}

			p1 = S1.pop();
			p2 = S2.pop();

			if (p1->key_ > p2->key_)
			{
				p2 = p2->right_;
				S1.push(p1);
				p1 = nullptr;
			}
			else if (p1->key_ < p2->key_)
			{
				p1 = p1->right_;
				S2.push(p2);
				p2 = nullptr;
			}
			else
				return true;
		}
		return false;

	}

	int iterativeCountLeaves() const
	{
		int count = 0;
		if (root_ != nullptr)
		{
			QueueArray <Node<T>*> queue;
			queue.enQueue(root_);
			Node<T>* curNode = root_;
			while (!queue.isEmpty())
			{
				curNode = queue.deQueue();
				if (curNode->left_ == nullptr && curNode->right_ == nullptr)
				{
					count++;
				}
				if (curNode->left_ != nullptr)
					queue.enQueue(curNode->left_);
				if (curNode->right_ != nullptr)
					queue.enQueue(curNode->right_);
			}
		}
		return count;
	}
private:
	template <class T>
	struct Node {
		T key_; // значение ключа, содержащееся в узле
		Node<T>* left_; // указатель на левое поддерево
		Node<T>* right_; // указатель на правое поддерево
		Node<T>* p_; // указатель на родителя !!! не используется
		// Конструктор узла
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{ }

		/*~Node()
		{
			delete left_;
			delete right_;
		}*/
	};
	// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
	Node<T>* iterativeSearchNode(const T& key) const
	{
		Node<T>* current = root_;
		while (current != nullptr)
		{
			if (current->key_ == key)
			{
				return current;
			}
			else if (current->key_ > key)
			{
				current = current->left_;
			}
			else
			{
				current = current->right_;
			}
		}
	}


	// 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
	void printNode(std::ostream& out, Node<T>* root) const
	{
		if (root != nullptr)
		{
			out << "[" << root->key_;
			printNode(out, root->left_);
			printNode(out, root->right_);
			out << "]";
		}
		else
			return;
		
	}

	// 5.2 Рекурсивная функция определения количества узлов дерева
	int getCount(const Node<T>* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}
		return (1 + getCount(node->left_) + getCount(node->right_));
	};


	// 6.2 Рекурсивная функция определения высоты дерева
	int getHeight(const Node<T>* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}
		int leftHeight = getHeight(node->left_);
		int rightHeight = getHeight(node->right_);
		return std::max(1+leftHeight, rightHeight+1);
	}


	// 8.2 Рекурсивная функция для инфиксного обхода узлов дерева.
	void inorderWalk(Node<T>* node) const
	{
		if (node != nullptr)
		{
			inorderWalk(node->left_);
			std::cout << node->key_ << " ";
			inorderWalk(node->right_);
		}
	}

	// 12 Рекурсивная функция для подсчета количества листьев дерева.
	int countLeaves(const Node<T>* node) const
	{
		/*if (node == nullptr)
		{
			return 0;
		}
		int nRet = 0;

		if (node->left_ != nullptr)
			nRet += countLeaves(node->left_);
		else
			nRet++;

		if (node->right_ != nullptr)
			nRet += countLeaves(node->right_);
		else
			nRet++;

		return nRet;*/
		if (node == nullptr) {
			return 0;
		}
		if (node->right_ == nullptr && node->left_ != nullptr) {
			return (countLeaves(node->left_));
		}
		else if (node->right_ != nullptr && node->left_ == nullptr) {
			return (countLeaves(node->right_));
		}
		else if (node->right_ != nullptr && node->left_ != nullptr) {
			return (countLeaves(node->left_) + countLeaves(node->right_));
		}
		else if (node->right_ == nullptr && node->left_ == nullptr) {
			return 1;
		}
	}

	void destroyTree(Node<T>* node)
	{
		if (node == nullptr)
		{
			return;
		}

		destroyTree(node->left_);
		destroyTree(node->right_);
		delete node;
	}
	Node<T>* root_; // Указатель на корневой узел
};

#endif