#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <utility>
#include <initializer_list>

namespace wiklvrain {

const bool RED = false;
const bool BLACK = true;

template<typename K, typename V = int>
struct rb_tree_node {
  typedef rb_tree_node<K, V> Node;
  typedef Node* pNode;
  
  K key;
  V value;
  bool color;
  pNode left, right, parent;
  
  rb_tree_node(K _key, V _value, bool _color = BLACK): key(_key), value(_value), color(_color) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  }
};

template<typename K, typename V = int>
class rb_tree {
protected:
  typedef K key_type;
  typedef V value_type;
  typedef rb_tree_node<K, V> Node;
  typedef Node* pNode;
public:
  rb_tree();
  rb_tree(key_type key);
  rb_tree(key_type key, value_type value);
  rb_tree(std::initializer_list<key_type> ilk);
  rb_tree(std::initializer_list<std::pair<key_type, value_type>> ilkv);
  
  ~rb_tree();
  
  bool insert(key_type key);
  bool insert(key_type key, value_type value);
  
  bool erase(key_type key);
  pNode lower_bound(key_type key);
  pNode find(key_type key);
private:
  void left_rotate(pNode _node);
  void right_rotate(pNode _node);

  pNode root;
};

template<typename K, typename V>
rb_tree<K, V>::rb_tree() {
  this->root = nullptr;
}

template<typename K, typename V>
rb_tree<K, V>::rb_tree(key_type key) {
  this->root = new Node(key, value_type(0));
}

template<typename K, typename V>
rb_tree<K, V>::rb_tree(key_type key, value_type value) {
  this->root = new Node(key, value);
}

template<typename K, typename V>
rb_tree<K, V>::rb_tree(std::initializer_list<key_type> ilk) {
  for (auto it = ilk.begin(); it != ilk.end(); ++it) 
    insert(*it);
}

template<typename K, typename V>
rb_tree<K, V>::rb_tree(std::initializer_list<std::pair<key_type, value_type>> ilk) {
  for (auto it = ilk.begin(); it != ilk.end(); ++it) 
    insert((*it).first, (*it).second);
}

template<typename K, typename V>
rb_tree<K, V>::~rb_tree() {
	// ...
}

template<typename K, typename V>
bool rb_tree<K, V>::insert(key_type key) {
	return insert(key, value_type(0));
}

template<typename K, typename V>
bool rb_tree<K, V>::insert(key_type key, value_type value) {
	// ...
}

template<typename K, typename V>
bool rb_tree<K, V>::erase(key_type key) {
	
}

template<typename K, typename V>
typename rb_tree<K, V>::pNode rb_tree<K, V>::lower_bound(key_type key) {
	
}

template<typename K, typename V>
typename rb_tree<K, V>::pNode rb_tree<K, V>::find(key_type key) {
	
}

template<typename K, typename V>
void rb_tree<K, V>::left_rotate(pNode _node) {
  pNode _parent = _node->parent;
  if (_parent->parent->left == _parent) {
    _parent->parent->left = _node;
  } else {
    _parent->parent->right = _node;
  }
  _node->parent = _parent->parent;
  _parent->right = _node->left;
  _node->left->parent = _parent;
  _node->left = _parent;
  _parent->parent = _node;
}

template<typename K, typename V>
void rb_tree<K, V>::right_rotate(pNode _node) {
  pNode _parent = _node->parent;
  if (_parent->parent->left == _parent) {
    _parent->parent->left = _node;
  } else {
    _parent->parent->right = _node;
  }
  _node->parent = _parent->parent;
  _parent->left = _node->right;
  _node->right->parent = _parent;
  _node->right = _parent;
  _parent->parent = _node;
}

}
#endif
