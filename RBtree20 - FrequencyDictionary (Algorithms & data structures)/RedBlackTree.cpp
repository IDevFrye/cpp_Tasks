#include "RedBlackTree.h"

#include <iostream>

template<typename K, typename V>
RBTree<K, V>::~RBTree()
{
  destroy(root_);
}

template<typename K, typename V>
void RBTree<K, V>::insertNode(const K& key, const V& value) //������� ����
{
  Node<K, V>* z = new Node<K, V>(key, value, RED, nullptr, nullptr, nullptr);
  Node<K, V>* y = nullptr; // ��������� �� �������� 
  Node<K, V>* x = root_; // ��������� �� ������� ����

  while (x != nullptr)
  {
    y = x; // ���������� ��������
    if (z->key < x->key) // ���� ���� z ������ ����� x, �� ���� �����
    {
      x = x->left;
    }
    else // ���� ���� z ������ ��� ����� ����� x, �� ���� ������
    {
      x = x->right;
    }
  }

  z->parent = y;

  if (y == nullptr)
  {
    root_ = z;
  }
  else if (z->key < y->key) // ���� ���� z ������ ����� y, �� z ���������� ����� �������� y
  {
    y->left = z;
  }
  else // ���� ���� z ������ ��� ����� ����� y, �� z ���������� ������ �������� y
  {
    y->right = z;
  }
  z->color = RED;
  insertFixUp(z);
}

template<typename K, typename V>
void RBTree<K, V>::deleteNode(const K& key) //�������� ����
{
  Node<K, V>* dNode = searchNode(key);
  if (dNode != nullptr)
  {
    deleteNode(dNode);
  }
}

template<typename K, typename V>
bool RBTree<K, V>::containsNode(const K& key) const //�������� �� ��� ������� ����
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
Node<K, V>* RBTree<K, V>::searchNode(const K& key) const //����� ����
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
bool RBTree<K, V>::isEmpty() //�������� �� ������� ���
{
  if (root_ == nullptr)
  {
    return true;
  }
  else
    return false;
}

template<typename K, typename V>
void RBTree<K, V>::deleteNode(Node<K, V>* node) //�������� ����
{
  Node<K, V>* child;
  Node<K, V>* parent;
  color_t color;

  if (node->left != nullptr && node->right != nullptr) {
    // ��� �������

    // ����� ���������� ���� (����� ����� ���� � ������ ���������)
    Node<K, V>* replace = node->right;
    while (replace->left != nullptr) {
      replace = replace->left;
    }

    // �������� �������� ���������� ���� ��������� ����������� ����
    node->key = replace->key;
    node->value = replace->value;

    node = replace; 
  }

  // ��������� ������� ���������� ����
  if (node->left != nullptr) {
    child = node->left;
  }
  else {
    child = node->right;
  }

  parent = node->parent;
  color = node->color;

  // ������� ����, ������� ����� ��� �������� � ��������
  if (child != nullptr) {
    child->parent = parent;
  }

  if (parent == nullptr) {
    root_ = child; // ��������� ���� - ������ ������
  }
  else if (node == parent->left) {
    parent->left = child;
  }
  else {
    parent->right = child;
  }

  if (color == BLACK) {
    deleteFixUp(child, parent); //������������ ��� ����� �������� ����
  }

  delete node; 
}

template<typename K, typename V>
void RBTree<K, V>::deleteFixUp(Node<K, V>* node, Node<K, V>* parent) { //������������ ����� �������� ����
  Node<K, V>* sibling;
  while (node != root_ && (node == nullptr || node->color == BLACK)) {
    if (node == parent->left) {
      sibling = parent->right;

      if (sibling->color == RED) {
        // #1: ���� ���� node - �������
        sibling->color = BLACK;
        parent->color = RED;
        leftRotate(parent);
        sibling = parent->right;
      }

      if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
        (sibling->right == nullptr || sibling->right->color == BLACK)) {
        // #2: ��� ������� ����� ������
        sibling->color = RED;
        node = parent;
        parent = node->parent;
      }
      else {
        if (sibling->right == nullptr || sibling->right->color == BLACK) {
          // #3: ������ ������� ����� ������
          sibling->left->color = BLACK;
          sibling->color = RED;
          rightRotate(sibling);
          sibling = parent->right;
        }

        // #4: ������ ������� ����� �������
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
        // #1: ���� ���� node - �������
        sibling->color = BLACK;
        parent->color = RED;
        rightRotate(parent);
        sibling = parent->left;
      }

      if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
        (sibling->right == nullptr || sibling->right->color == BLACK)) {
        // #2: ��� ������� ����� ������
        sibling->color = RED;
        node = parent;
        parent = node->parent;
      }
      else {
        if (sibling->left == nullptr || sibling->left->color == BLACK) {
          // #3: ����� ������� ����� ������
          sibling->right->color = BLACK;
          sibling->color = RED;
          leftRotate(sibling);
          sibling = parent->left;
        }

        // #4: ����� ������� ����� �������
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
void RBTree<K, V>::leftRotate(Node<K, V>* x) //����� �������
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
void RBTree<K, V>::rightRotate(Node<K, V>* x) //������ �������
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
void RBTree<K, V>::insertFixUp(Node<K, V>* z) //������������ ��� ����� �������� ����
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
void RBTree<K, V>::destroy(Node<K, V>*& node) //�������� ������
{
  if (node == nullptr)
    return;
  destroy(node->left);
  destroy(node->right);
  delete node;
  node = nullptr;
}
