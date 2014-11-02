#include "double_list.h"
// SPIROS DIONIS 
template<class Node, typename Type>class MemoryList:public <Node, Type>DoubleList {
public:
  MemoryList():size(1024) {}
  void insert_after(char * key, Node * & this_one) {
    // insert after this one
    insert_after(key, this_one, size, max_size);
  }
private:
  unsigned int max_size;
  // maximum size of list
  unsigned int size;
  // current size of list
  void insert_after(char * key, Node * & this_one, unsigned int size, unsigned int max_size) {
    // insert after this one
    if(size >= max_size) return;
    Node * new_one = new Node(key);
    if(new_one->size >= new_one->max_size) {delete new_one; return;}
    new_one->left = this_one;
    new_one->right = this_one->right;
    this_one->right->left = this_one->right = new_one; 
  }
};