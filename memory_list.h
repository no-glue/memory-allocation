#include "double_list.h"
// SPIROS DIONIS 
template<class Node, typename Type>class MemoryList:public <Node, Type>DoubleList {
public:
  MemoryList():DoubleList(), max_size(1024) {}
  MemoryList(unsigned int max_size, unsigned int size):DoubleList(), max_size(max_size), size(size) {}
  void insert_after_node(Node * new_one, Node * this_one) {
    // insert after this one
    insert_after_node(new_one, this_one, size, max_size, head, tail);
  }
  void insert_right_node(Node * new_one) {
    // insert node to the right
    insert_right_node(new_one, size, max_size, head, tail);
  }
private:
  unsigned int max_size;
  // maximum size of list
  void insert_after_node(Node * new_one, Node * this_one, unsigned int & size, unsigned int max_size, Node * & head, Node * & tail) {
    // insert after this one
    if(size >= max_size) return;
    if(!new_one->max_size) return;
    if(this_one == tail) {
      tail->right = new_one;
      new_one->left = tail;
      tail = new_one;
      size++;
      return;
    }
    new_one->right = this_one->right;
    new_one->left = this_one;
    this_one->right = new_one;
    size++;
  }
  void insert_right_node(Node * new_one, unsigned int & size, unsigned int max_size, Node * & head, Node * & tail) {
    // insert node to the right
    if(size >= max_size) return;
    if(!new_one->max_size) return;
    if(!size) {head = tail = new_one; size++; return;}
    tail->right = new_one;
    new_one->left = tail;
    tail = new_one;
    size++;    
  }
};