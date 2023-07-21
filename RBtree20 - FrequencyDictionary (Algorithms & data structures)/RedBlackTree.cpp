#include "RedBlackTree.h"

#include <iostream>

template<typename K, typename V>
RBTree<K, V>::~RBTree()
{
  destroy(root_);
}

template<typename K, typename V>
void RBTree<K, V>::insertNode(const K& key, const V& value) //вставка узла
{
  Node<K, V>* z = new Node<K, V>(key, value, RED, nullptr, nullptr, nullptr);
  Node<K, V>* y = nullptr; // указатель на родителя 
  Node<K, V>* x = root_; // указатель на текущий узел

  while (x != nullptr)
  {
    y = x; // запоминаем родителя
    if (z->key < x->key) // если ключ z меньше ключа x, то идем влево
    {
      x = x->left;
    }
    else // если ключ z больше или равен ключу x, то идем вправо
    {
      x = x->right;
    }
  }

  z->parent = y;

  if (y == nullptr)
  {
    root_ = z;
  }
  else if (z->key < y->key) // если ключ z меньше ключа y, то z становится левым потомком y
  {
    y->left = z;
  }
  else // если ключ z больше или равен ключу y, то z становится правым потомком y
  {
    y->right = z;
  }
  z->color = RED;
  insertFixUp(z);
}

template<typename K, typename V>
void RBTree<K, V>::deleteNode(const K& key) //удаление узла
{
  Node<K, V>* dNode = searchNode(key);
  if (dNode != nullptr)
  {
    deleteNode(dNode);
  }
}

template<typename K, typename V>
bool RBTree<K, V>::containsNode(const K& key) const //содержит ли КЧД искомый узел
{
  Node<K, V>* current = root_;

  while (current)
  {
    if (current->key == key)
    {
      return true;
    }
    else if (current->key > key)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }

  return false;
}

template<typename K, typename V>
Node<K, V>* RBTree<K, V>::searchNode(const K& key) const //поиск узла
{
  Node<K, V>* current = root_;

  while (current)
  {
    if (current->key == key)
    {
      return current;
    }
    else if (current->key > key)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
}

template<typename K, typename V>
V& RBTree<K, V>::operator[](const K& key)
{
  Node<K, V>* node = searchNode(key);
  if (node)
  {
    return node->value;
  }
  throw std::invalid_argument{ "No such key in the RBTree!" };
}

template<typename K, typename V>
const V& RBTree<K, V>::operator[](const K& key) const
{
  Node<K, V>* node = searchNode(key);
  if (node)
  {
    return node->value;
  }
  throw std::invalid_argument{ "No such key in the RBTree!" };
}

template<typename K, typename V>
typename RBTree<K, V>::iterator RBTree<K, V>::begin()
{
  Node<K, V>* c = root_;
  if (root_ == nullptr)
  {
    return iterator(c);
  }

  while (c->left)
  {
    c = c->left;
  }
  return iterator(c);
}

template<typename K, typename V>
typename RBTree<K, V>::iterator RBTree<K, V>::end()
{
  return iterator(nullptr);
}

template<typename K, typename V>
typename RBTree<K, V>::iterator RBTree<K, V>::preend()
{
  Node<K, V>* c = root_;
  if (root_ == nullptr)
  {
    return iterator(c);
  }

  while (c->right)
  {
    c = c->right;
  }
  return iterator(c);
}

template<typename K, typename V>
bool RBTree<K, V>::isEmpty() //проверка на пустоту КЧД
{
  if (root_ == nullptr)
  {
    return true;
  }
  else
    return false;
}

template<typename K, typename V>
void RBTree<K, V>::deleteNode(Node<K, V>* node) //удаление узла
{
  Node<K, V>* child;
  Node<K, V>* parent;
  color_t color;

  if (node->left != nullptr && node->right != nullptr) {
    // Два потомка

    // Найти замещающий узел (самый левый узел в правом поддереве)
    Node<K, V>* replace = node->right;
    while (replace->left != nullptr) {
      replace = replace->left;
    }

    // Заменить значение удаляемого узла значением замещающего узла
    node->key = replace->key;
    node->value = replace->value;

    node = replace; 
  }

  // Запомнить потомка удаляемого узла
  if (node->left != nullptr) {
    child = node->left;
  }
  else {
    child = node->right;
  }

  parent = node->parent;
  color = node->color;

  // Удалить узел, обновив связи его родителя с потомком
  if (child != nullptr) {
    child->parent = parent;
  }

  if (parent == nullptr) {
    root_ = child; // Удаляемый узел - корень дерева
  }
  else if (node == parent->left) {
    parent->left = child;
  }
  else {
    parent->right = child;
  }

  if (color == BLACK) {
    deleteFixUp(child, parent); //балансировка КЧД после удаления узла
  }

  delete node; 
}

template<typename K, typename V>
void RBTree<K, V>::deleteFixUp(Node<K, V>* node, Node<K, V>* parent) { //балансировка после удаления узла
  Node<K, V>* sibling;
  while (node != root_ && (node == nullptr || node->color == BLACK)) {
    if (node == parent->left) {
      sibling = parent->right;

      if (sibling->color == RED) {
        // #1: Брат узла node - красный
        sibling->color = BLACK;
        parent->color = RED;
        leftRotate(parent);
        sibling = parent->right;
      }

      if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
        (sibling->right == nullptr || sibling->right->color == BLACK)) {
        // #2: Оба потомка брата черные
        sibling->color = RED;
        node = parent;
        parent = node->parent;
      }
      else {
        if (sibling->right == nullptr || sibling->right->color == BLACK) {
          // #3: Правый потомок брата черный
          sibling->left->color = BLACK;
          sibling->color = RED;
          rightRotate(sibling);
          sibling = parent->right;
        }

        // #4: Правый потомок брата красный
        sibling->color = parent->color;
        parent->color = BLACK;
        sibling->right->color = BLACK;
        leftRotate(parent);
        node = root_;
        break;
      }
    }
    else {
      sibling = parent->left;

      if (sibling->color == RED) {
        // #1: Брат узла node - красный
        sibling->color = BLACK;
        parent->color = RED;
        rightRotate(parent);
        sibling = parent->left;
      }

      if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
        (sibling->right == nullptr || sibling->right->color == BLACK)) {
        // #2: Оба потомка брата черные
        sibling->color = RED;
        node = parent;
        parent = node->parent;
      }
      else {
        if (sibling->left == nullptr || sibling->left->color == BLACK) {
          // #3: Левый потомок брата черный
          sibling->right->color = BLACK;
          sibling->color = RED;
          leftRotate(sibling);
          sibling = parent->left;
        }

        // #4: Левый потомок брата красный
        sibling->color = parent->color;
        parent->color = BLACK;
        sibling->left->color = BLACK;
        rightRotate(parent);
        node = root_;
        break;
      }
    }
  }

  if (node != nullptr) {
    node->color = BLACK;
  }
}

template<typename K, typename V>
void RBTree<K, V>::leftRotate(Node<K, V>* x) //левый поворот
{
  Node<K, V>* y = x->right;
  x->right = y->left;
  if (y->left != nullptr)
  {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr)
  {
    root_ = y;
  }
  else if (x == x->parent->left)
  {
    x->parent->left = y;
  }
  else
  {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;

}

template<typename K, typename V>
void RBTree<K, V>::rightRotate(Node<K, V>* x) //правый поворот
{
  Node<K, V>* y = x->left;
  x->left = y->right;
  if (y->right != nullptr)
  {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr)
  {
    root_ = y;
  }
  else if (x == x->parent->right)
  {
    x->parent->right = y;
  }
  else
  {
    x->parent->left = y;
  }

  y->right = x;
  x->parent = y;
}

template<typename K, typename V>
void RBTree<K, V>::insertFixUp(Node<K, V>* z) //балансировка КЧД после удаления узла
{
  Node<K, V>* parent = z->parent;
  while (z != root_ && parent->color == RED)
  {
    Node<K, V>* grandparent = parent->parent;
    if (grandparent->left == parent)
    {
      Node<K, V>* uncle = grandparent->right;
      if (uncle != nullptr && uncle->color == RED)
      {
        parent->color = BLACK;
        uncle->color = BLACK;
        grandparent->color = RED;
        z = grandparent;
        parent = z->parent;
      }
      else
      {
        if (parent->right == z)
        {
          leftRotate(parent);
          std::swap(z, parent);
        }
        rightRotate(grandparent);
        grandparent->color = RED;
        parent->color = BLACK;
        break;
      }
    }
    else
    {
      Node<K, V>* uncle = grandparent->left;
      if (uncle != nullptr && uncle->color == RED)
      {
        parent->color = BLACK;
        uncle->color = BLACK;
        grandparent->color = RED;
        z = grandparent;
        parent = z->parent;
      }
      else
      {
        if (parent->left == z)
        {
          rightRotate(parent);
          std::swap(parent, z);
        }
        leftRotate(grandparent);
        grandparent->color = RED;
        parent->color = BLACK;
        break;
      }
    }
  }
  root_->color = BLACK;
}

template<typename K, typename V>
void RBTree<K, V>::destroy(Node<K, V>*& node) //удаление дерева
{
  if (node == nullptr)
    return;
  destroy(node->left);
  destroy(node->right);
  delete node;
  node = nullptr;
}
