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
    Node * blank = new Node("", new_one->remaining());
    Node * temp;
    if(size >= max_size) {
      // todo scan here for empty spot
      delete new_one;
      delete blank;
      return;
    }
    if(!size) {
      insert_right_node(new_one, size, max_size, head, tail);
      insert_right_node(blank, size, max_size, head, tail);
      return;
    }
    temp = head;
    while(temp) {
      if(temp->is_blank() && temp->max_size <= new_one->size) {
        
      }
    }
  }
};