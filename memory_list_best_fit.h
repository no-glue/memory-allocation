#include "memory_list.h"
template<class Node, typename Type>class MemoryListBestFit:public MemoryList<Node, Type> {
// add to smallest hole
public:
  MemoryListBestFit() {MemoryList<Node, Type>();}
  MemoryListBestFit(unsigned int max_size, unsigned int size):MemoryList<Node, Type>(max_size, size) {}
  void insert(char * key) {insert(key, this->size, this->max_size, this->head, this->tail);}
private:
  void insert(char * key, unsigned int & size, unsigned int max_size, Node * & head, Node * & tail) {
    // insert key to list
    Node * new_one = new Node(key), * blank, smallest = NULL, * temp = head;
    while(temp) {
      // look for smallest
      if(temp->is_blank() && new_one->size <= temp->max_size) {
        // can fit
        if(!smallest || (smallest->max_size > temp->max_size)) smallest = temp;
      }
      temp = temp->right;
    }
    if(smallest) {
      // replace smallest
      blank = new Node("", smallest->max_size - new_one->size);
      replace_node(smallest, new_one, size, max_size, head, tail);
      insert_after_node(new_one, blank, size, max_size, head, tail);
      delete smallest;
      return;
    }
    blank = new Node("", new_one->remaining());
    insert_right_node(new_one, size, max_size, head, tail);
    insert_right_node(blank, size, max_size, head, tail);
    // add to list tail
  }
};