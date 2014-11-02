#include <string.h>

template<typename Type>class MemoryNode {
public:
  char * key;
  // key for a node
  unsigned int size;
  // strlen(key) * sizeof(char)
  unsigned int max_size;
  // max size in bytes
  // default 1024 bytes 1kb
  bool is_hole;
  // true if is hole, false if not (it's partition)
  MemoryNode * left;
  // left node
  MemoryNode * right;
  // right node
  MemoryNode():left(NULL), right(NULL) {}
  MemoryNode(Type node_key):max_size(1024), is_hole(false), left(NULL), right(NULL) {
    int key_len = node_key.length();
    key = new char[key_len];
    strcpy(key, node_key.c_str());
    size = actual_size(key);
  }
  MemoryNode(Type node_key, unsigned int max_size, bool is_hole, MemoryNode * left, MemoryNode * right): max_size(max_size), is_hole(is_hole), left(left), right(right) {
    int key_len = node_key.length();
    key = new char[key_len];
    strcpy(key, node_key.c_str());
    size = actual_size(key);
  }
  unsigned int remaining() {return max_size - size;}
  unsigned int actual_size(char * key) {return strlen(key) * sizeof(char);}
};