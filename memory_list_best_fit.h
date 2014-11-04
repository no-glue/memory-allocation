#include "memory_list.h"
template<class Node, typename Type>class MemoryListBestFit:public MemoryList<Node, Type> {
// add to smallest hole
public:
  MemoryListBestFit() {MemoryList<Node, Type>();}
  MemoryListBestFit(unsigned int max_size, unsigned int size):MemoryList<Node, Type>(max_size, size) {}
  void insert(Type key) {insert(key, this->size, this->max_size, this->blanks, this->head, this->tail);}
private:
  void insert(Type key, unsigned int & size, unsigned int max_size, unsigned int & blanks, Node * & head, Node * & tail) {
    // insert key to list
    Node * new_one = new Node(key), * blank, * temp = head;
    Node * smallest = NULL;

    while(temp) {
      // look for smallest
      if(temp->is_blank() && new_one->size <= temp->max_size) {
        // can fit
        if(smallest && smallest->max_size > temp->max_size) smallest = temp;
        else if(!smallest) smallest = temp;
      }
      temp = temp->right;
    }
    if(smallest) {
      // replace smallest
      blank = new Node("", smallest->max_size - new_one->size);
      this->replace_node(smallest, new_one, head, tail);
      this->insert_after_node(new_one, blank, size, max_size, blanks, tail);
      delete smallest;
      return;
    }
    blank = new Node("", new_one->remaining());
    this->insert_right_node(new_one, size, max_size, blanks, head, tail);
    this->insert_right_node(blank, size, max_size, blanks, head, tail);
    // add to list tail
  }
};