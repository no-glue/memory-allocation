#define SAMPLES 1024
#define STRING_LENGTH 128

#include <iostream>
#include <string>
#include "memory_node.h"
#include "memory_list_best_fit.h"
#include "random_wrapper.h"
#include "time_wrapper.h"
#include "string_generator.h"
#include "cstring_wrapper.h"

int main() {
  TimeWrapper * time = new TimeWrapper();
  RandomWrapper<TimeWrapper> * random = new RandomWrapper<TimeWrapper>(time);
  CstringWrapper * str = new CstringWrapper();
  StringGenerator<
    CstringWrapper,
    RandomWrapper<TimeWrapper>
  > * generator = new StringGenerator<
    CstringWrapper,
    RandomWrapper<TimeWrapper>
  >(str, random);
  MemoryListBestFit<
    MemoryNode<string>,
    string
  > * list = new MemoryListBestFit<
    MemoryNode<string>,
    string
  >();
  char key_array[STRING_LENGTH];
  string key;
  int i = 0;
  cout<<"inserting samples"<<endl;
  for(; i < SAMPLES; i++) {
    if(!(i % 10)) cout<<"inserted samples "<<i<<endl;
    generator->generate(key_array, STRING_LENGTH);
    key = string(key_array);
    list->insert(key);
  }
  cout<<"done"<<endl;
  cout<<"size "<<list->get_size()<<endl;
  cout<<"blanks "<<list->get_blanks()<<endl;
  delete time;
  delete random;
  delete str;
  delete generator;
  delete list;
  return 0;
}