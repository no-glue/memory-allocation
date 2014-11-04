#include <time.h>
class TimeWrapper {
public:
  TimeWrapper() {}
  unsigned int the_time() {return time(NULL);}
};