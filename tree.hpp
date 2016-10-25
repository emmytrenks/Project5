#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <memory>

template <class T>
class TreeIterator {
private:
  std::vector<T> v;
public:
  TreeIterator(std::vector<T> v) : v(std::move(v)) { }

  typename std::vector<T>::const_iterator begin() const { return v.cbegin(); }

  typename std::vector<T>::const_iterator end() const { return v.cend(); }
};

template <class T>
struct Node {
  T data;
  Node<T> *child = nullptr, *sibling = nullptr;

  Node(const T &data) {
    this->data = data;
  }

  ~Node() {
    delete child;
    delete sibling;
  }

  std::vector<T> & pre_order(std::vector<T> &v) {
    //First, record the current node's value
    v.push_back(data);
    //Second, recursively call pre_order on the left of the current node
    if (child != nullptr) child->pre_order(v);
    //Third, recursively call pre_order on the right of the current node
    if (sibling != nullptr) sibling->pre_order(v);
    return v;
  }

  std::vector<T> & in_order(std::vector<T> &v) {
    //First, recursively call in_order on the left of the current node
    if (child != nullptr) child->in_order(v);
    //Second, record the current node's value
    v.push_back(data);
    //Third, recursively call in_order on the right of the current node
    if (sibling != nullptr) sibling->in_order(v);
    return v;
  }

  std::vector<T> & post_order(std::vector<T> &v) {
    //First, recursively call post_order on the left of the current node
    if (child != nullptr) child->post_order(v);
    //Second, recursively call post_order on the right of the current node
    if (sibling != nullptr) sibling->post_order(v);
    //Third, record the current node's value
    v.push_back(data);
    return v;
  }
};

template <class T>
class Tree {
private:
  Node<T> *root = nullptr;

public:
  ~Tree() {
    if (root) delete root;
  }

  Node<T> * getRoot() { return root; }

  void setRoot(const T &t) {
    if (root == nullptr) root = new Node<T>(t);
    else root->data = t;
  }

  Node<T> * insert(Node<T> *n, const T &t) {
    Node<T> *n2 = new Node<T>(t);
    if (n->child == nullptr) {
      n->child = n2;
    } else {
      Node<T> *temp = n->child;
      for (; temp->sibling != nullptr;) temp = temp->sibling;
      temp->sibling = n2;
    }
    return n2;
  }

  TreeIterator<T> pre_order() {
    std::vector<T> v;
    if (root != nullptr) {
      root->pre_order(v);
    }
    return TreeIterator<T>(std::move(v));
  }

  TreeIterator<T> in_order() {
    std::vector<T> v;
    if (root != nullptr) {
      root->in_order(v);
    }
    return TreeIterator<T>(std::move(v));
  }

  TreeIterator<T> post_order() {
    std::vector<T> v;
    if (root != nullptr) {
      root->post_order(v);
    }
    return TreeIterator<T>(std::move(v));
  }
};

#endif
