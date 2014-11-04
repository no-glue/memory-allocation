#define SAMPLES 1024
#define STRING_LENGTH 128

#include <iostream>
#include "memory_node.h"
#include "memory_list_best_fit.h"
#include "random_wrapper.h"
#include "time_wrapper.h"
#include "string_generator.h"
#include "cstring_wrapper.h"

int main() {
  TimeWrapper * time = new TimeWrapper();
  cout<<time->the_time()<<endl;
  delete time;
  return 0;
}