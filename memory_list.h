#include "double_list.h"
// SPIROS DIONIS 
template<class Node, typename Type>class MemoryList:public <Node, Type>DoubleList {
public:
  MemoryList():DoubleList(), max_size(1024) {}
  MemoryList(unsigned int max_size, unsigned int size):DoubleList(), max_size(max_size), size(size) {}
  void insert_after_node(Node * this_one, Node * new_one) {
    // insert after this one
    insert_after_node(this_one, new_one, size, max_size, head, tail);
  }
  void insert_right_node(Node * new_one) {
    // insert node to the right
    insert_right_node(new_one, size, max_size, head, tail);
  }
  void replace_node(Node * this_one, Node * new_one) {
    // replace this one with new one
    replace_node(this_one, new_one, size, max_size, head, tail);
  }
private:
  unsigned int max_size;
  // maximum size of list
  void insert_after_node(Node * this_one, Node * new_one, unsigned int & size, unsigned int max_size, Node * & head, Node * & tail) {
    // insert after this one
    if(size >= max_size) return;
    if(new_one->is_full()) return;
    if(this_one == tail) {
      tail->right = new_one;
      new_one->left = tail;
      tail = new_one;
      size++;
      return;
    }
    new_one->right = this_one->right;
    new_one->left = this_one;
    this_one->right = this_one->right->left = new_one;
    size++;
  }
  void insert_right_node(Node * new_one, unsigned int & size, unsigned int max_size, Node * & head, Node * & tail) {
    // insert node to the right
    if(size >= max_size) return;
    if(new_one->is_full()) return;
    if(!size) {head = tail = new_one; size++; return;}
    tail->right = new_one;
    new_one->left = tail;
    tail = new_one;
    size++;    
  }
  void replace_node(Node * this_one, Node * new_one, unsigned int & size, unsigned int max_size, Node * & head, Node * & tail) {
    // replace this one with new one
    if(this_one == tail) {
      new_one->left = tail->left;
      tail->left->right = new_one;
      tail = new_one;
      return;
    }
    if(this_one == head) {
      new_one->right = head->right;
      head->right->left = new_one;
      head = new_one;
      return;
    }
    this_one->left->right = this_one->right->left = new_one;
    new_one->left = this_one->left;
    new_one->right = this_one->right;
  }
};