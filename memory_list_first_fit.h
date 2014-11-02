#include "memory_list.h"
template<class Node, typename Type>class MemoryListFirstFit:public <Node, Type>MemoryList {
public:
  MemoryListFirstFit():MemoryList() {}
  MemoryListFirstFit(unsigned int max_size, unsigned int size):MemoryList(max_size, size) {}
  void insert(char * key) {insert(key, size, max_size, head, tail);}
private:
  void insert(char * key, unsigned int & size, unsigned int max_size, Node * & head, Node * & tail) {
    // insert key to list
    Node * new_one = new Node(key);
    Node * blank;
    Node * temp = head;
    while(temp) {
      if(temp->is_blank() && new_one->size > temp->max_size) {
        temp = temp->right;
        continue;
      }
      if(temp->is_blank() && new_one->size <= temp->max_size) {
        blank = new Node("", temp->max_size - new_one->size);
        replace_node(temp, new_one, size, max_size, head, tail);
        insert_after_node(new_one, blank, size, max_size, head, tail);
        delete temp;
        return;
      }
    }
    blank = new Node("", new_one->remaining());
    insert_right_node(new_one, size, max_size, head, tail);
    insert_right_node(blank, size, max_size, head, tail);
  }
};