#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <memory>

template <class T>
class BNode {
public:
  BNode *left = nullptr, *right = nullptr;
  T data;

  BNode(const T &data) {
    this->data = data;
  }

  ~BNode() {
    if (left) delete left;
    if (right) delete right;
  }

  std::vector<T> pre_order() {
    std::vector<T> v;
    pre_order(v);
    return v;
  }

  std::vector<T> in_order() {
    std::vector<T> v;
    in_order(v);
    return v;
  }

  std::vector<T> post_order() {
    std::vector<T> v;
    post_order(v);
    return v;
  }

private:
  std::vector<T> & pre_order(std::vector<T> &v) {
    v.push_back(data);
    if (left != nullptr) left->pre_order(v);
    if (right != nullptr) right->pre_order(v);
  }

  std::vector<T> & in_order(std::vector<T> &v) {
    if (left != nullptr) left->in_order(v);
    v.push_back(data);
    if (right != nullptr) right->in_order(v);
  }

  std::vector<T> & post_order(std::vector<T> &v) {
    if (left != nullptr) left->post_order(v);
    if (right != nullptr) right->post_order(v);
    v.push_back(data);
  }
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

  std::pair<typename std::vector<T>::const_iterator, typename std::vector<T>::const_iterator> pre_order() {
    std::vector<T> v;
    auto b = toBTree();
    if (b != nullptr) {
      v = b->pre_order();
      delete b;
    }
    return std::move(std::make_pair(v.cbegin(), v.cend()));
  }

  std::pair<typename std::vector<T>::const_iterator, typename std::vector<T>::const_iterator> in_order() {
    std::vector<T> v;
    auto b = toBTree();
    if (b != nullptr) {
      v = b->in_order();
      delete b;
    }
    return std::move(std::make_pair(v.cbegin(), v.cend()));
  }

  std::pair<typename std::vector<T>::const_iterator, typename std::vector<T>::const_iterator> post_order() {
    std::vector<T> v;
    auto b = toBTree();
    if (b != nullptr) {
      v = b->post_order();
      delete b;
    }
    return std::move(std::make_pair(v.cbegin(), v.cend()));
  }

private:
  BNode<T> * toBTree() {
    if (this->root == nullptr) return nullptr;
    BNode<T> *root = new BNode<T>(this->root->data);
    bify(root, this->root);
    return root;
  }

  BNode<T> * bify(BNode<T> *bnode, Node<T> *node) {
    if (node->child != nullptr) {
      bnode->left = new BNode<T>(node->child->data);
      bify(bnode->left, node->child);
    }
    if (node->sibling != nullptr) {
      bnode->right = new BNode<T>(node->sibling->data);
      bify(bnode->right, node->sibling);
    }
    return bnode;
  }
};

#endif
