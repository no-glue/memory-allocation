#include "memory_list.h"
template<class Node, typename Type>class MemoryListWorstFit:public <Node, Type>MemoryList {
public:
  MemoryListWorstFit:MemoryList() {}
  MemoryListWorstFit(unsigned int max_size, unsigned int size):MemoryList(max_size, size), position(NULL) {}
  void insert(char * key) {insert(key, size, max_size, head, tail);}
private:
  void insert(char * key, unsigned int & size, unsigned int max_size, Node * & head, Node * & tail) {
    // insert key to list
    Node * new_one = new Node(key), largest = NULL, * temp = head;
    while(temp) {
      // look for largest
      if(temp->is_blank() && new_one->size <= temp->max_size) {
        // can fit
        if(!largest || (largest->max_size < temp->max_size)) largest = temp;
      }
      temp = temp->right;
    }
    if(largest) {
      // replace largest
      blank = new Node("", largest->max_size - new_one->size);
      replace_node(largest, new_one, size, max_size, head, tail);
      insert_after_node(new_one, blank, size, max_size, head, tail);
      delete largest;
      return;
    }
    blank = new Node("", new_one->remaining());
    insert_right_node(new_one, size, max_size, head, tail);
    insert_right_node(blank, size, max_size, head, tail);
    // add to list tail
  }
};