#ifndef CROSS_REFERENCES_REDBLACKTREE_H
#define CROSS_REFERENCES_REDBLACKTREE_H

enum color_t //тип цвета узлов
{
  RED = false,
  BLACK = true
};

template <typename K, typename V>
struct Node //структура узла
{
  K key; //ключ - слово
  V value; //информационная часть - частота встречаемости
  color_t color; //цвет узла (для балансировки КЧД)
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

  void insertNode(const K& key, const V& value); //вставка узла

  void deleteNode(const K& key); //удаление узла

  bool containsNode(const K& key) const; //проверка содержания узла

  Node<K, V>* searchNode(const K& key) const; //поиск узла

  V& operator[](const K& key);

  const V& operator[](const K& key) const;

  iterator begin();

  iterator end();

  iterator preend();

  bool isEmpty(); //проверка на пустоту КЧД

private:

  void deleteNode(Node<K, V>* node); //удаление узла

  void deleteFixUp(Node<K, V>* p, Node<K, V>* parent); //балансировка после удаления

  void leftRotate(Node<K, V>* x); //левый поворот

  void rightRotate(Node<K, V>* x); //правый поворот

  void insertFixUp(Node<K, V>* z); //балансировка после вставки

  void destroy(Node<K, V>*& node); //удаление дерева

  Node<K, V>* root_; //корень КЧД
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


