#ifndef CROSS_REFERENCES_REDBLACKTREE_H
#define CROSS_REFERENCES_REDBLACKTREE_H

enum color_t //��� ����� �����
{
  RED = false,
  BLACK = true
};

template <typename K, typename V>
struct Node //��������� ����
{
  K key; //���� - �����
  V value; //�������������� ����� - ������� �������������
  color_t color; //���� ���� (��� ������������ ���)
  Node<K, V>* parent;
  Node<K, V>* left;
  Node<K, V>* right;
  Node(K key, V value, color_t color, Node* parent, Node* left, Node* right) :
    key(key), value(value), color(color), parent(parent),
    left(left), right(right)
  {}
};

template <typename K, typename V>
class RBTree
{
public:
  RBTree() :
    root_(nullptr)
  {
    root_ = nullptr;
  }

  ~RBTree();

  class iterator;

  void insertNode(const K& key, const V& value); //������� ����

  void deleteNode(const K& key); //�������� ����

  bool containsNode(const K& key) const; //�������� ���������� ����

  Node<K, V>* searchNode(const K& key) const; //����� ����

  V& operator[](const K& key);

  const V& operator[](const K& key) const;

  iterator begin();

  iterator end();

  iterator preend();

  bool isEmpty(); //�������� �� ������� ���

private:

  void deleteNode(Node<K, V>* node); //�������� ����

  void deleteFixUp(Node<K, V>* p, Node<K, V>* parent); //������������ ����� ��������

  void leftRotate(Node<K, V>* x); //����� �������

  void rightRotate(Node<K, V>* x); //������ �������

  void insertFixUp(Node<K, V>* z); //������������ ����� �������

  void destroy(Node<K, V>*& node); //�������� ������

  Node<K, V>* root_; //������ ���
};

template <typename K, typename V>
class RBTree<K, V>::iterator
{
public:

  explicit iterator(Node<K, V>* node) :
    node_{ node }
  {}

  bool operator!=(const iterator& rhs) const
  {
    return node_ != rhs.node_;
  }

  iterator operator++()
  {
    move_next();
    return *this;
  }

  iterator operator+(int val)
  {
    for (int i = 0; i < val; i++)
    {
      move_next();
    }
    return *this;
  }

  K& key()
  {
    return node_->key;
  }

  V& value()
  {
    return node_->value;
  }

private:

  void move_next()
  {
    if (node_->right)
    {
      node_ = node_->right;
      while (node_->left)
      {
        node_ = node_->left;
      }
    }
    else if (node_->parent && (node_->parent->left == node_))
    {
      node_ = node_->parent;
    }
    else {
      while (node_->parent && (node_->parent->right == node_))
      {
        node_ = node_->parent;
      }
      node_ = node_->parent;
    }
  }
  Node<K, V>* node_;
};

#endif


