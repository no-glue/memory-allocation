#include "memory_list.h"
template<class Node, typename Type>class MemoryListFirstFit:public MemoryList<Node, Type> {
public:
  MemoryListFirstFit() {MemoryList<Node, Type>();}
  MemoryListFirstFit(unsigned int max_size, unsigned int size):MemoryList<Node, Type>(max_size, size) {}
  void insert(Type key) {insert(key, this->size, this->max_size, this->blanks, this->head, this->tail);}
private:
  void insert(Type key, unsigned int & size, unsigned int max_size, unsigned int & blanks, Node * & head, Node * & tail) {
    // insert key to list
    Node * new_one = new Node(key), * blank, * temp = head;

    while(temp) {
      // find empty hole
      if(temp->is_blank() && new_one->size <= temp->max_size) {
        // can fit
        blank = new Node("", temp->max_size - new_one->size);
        this->replace_node(temp, new_one, blanks);
        this->insert_after_node(temp, blank, size, max_size, blanks, tail);
        return;
      }
      temp = temp->right;
    }
    blank = new Node("", new_one->remaining());
    this->insert_right_node(new_one, size, max_size, blanks, head, tail);
    this->insert_right_node(blank, size, max_size, blanks, head, tail);
  }
};
