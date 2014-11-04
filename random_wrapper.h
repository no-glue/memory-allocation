#include <stdlib.h>
template<class Time>class RandomWrapper {
public:
  RandomWrapper() {}
  RandomWrapper(Time * & time):time(time) {}
  void seed() {seed(time);}
  unsigned int number(unsigned int max) {return rand() % max;}
private:
  Time * time;
  void seed(Time * & time) {srand(time->the_time());}
};