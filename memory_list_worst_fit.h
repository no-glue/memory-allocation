#include "memory_list.h"
template<class Node, typename Type>class MemoryListWorstFit:public MemoryList<Node, Type> {
// add to largest hole
public:
  MemoryListWorstFit() {MemoryList<Node, Type>();}
  MemoryListWorstFit(unsigned int max_size, unsigned int size):MemoryList<Node, Type>(max_size, size) {}
  void insert(Type key) {insert(key, this->size, this->max_size, this->blanks, this->head, this->tail);}
private:
  void insert(Type key, unsigned int & size, unsigned int max_size, unsigned int & blanks, Node * & head, Node * & tail) {
    // insert key to list
    Node * new_one = new Node(key), * blank, * temp = head;
    Node * largest = NULL;

    while(temp) {
      // look for largest
      if(temp->is_blank() && new_one->size <= temp->max_size) {
        // can fit
        if((largest && largest->max_size < temp->max_size) || !largest) largest = temp;
      }
      temp = temp->right;
    }
    if(largest) {
      // replace largest
      blank = new Node("", largest->max_size - new_one->size);
      this->replace_node(largest, new_one, blanks);
      this->insert_after_node(largest, blank, size, max_size, blanks, tail);
      return;
    }
    blank = new Node("", new_one->remaining());
    this->insert_right_node(new_one, size, max_size, blanks, head, tail);
    this->insert_right_node(blank, size, max_size, blanks, head, tail);
    // add to list tail
  }
};
