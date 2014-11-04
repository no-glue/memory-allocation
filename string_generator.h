template<class Wrapper, class Random>class StringGenerator {
// generates random strings
public:
  StringGenerator() {}
  StringGenerator(Wrapper * & wrapper, Random * & random):wrapper(wrapper), random(random) {}
  void generate(char * destination, unsigned int length) {generate(destination, length, wrapper, random);}
  void generate_variable(char * destination, unsigned int length) {generate_variable(destination, length, wrapper, random);}
private:
  Wrapper * wrapper;
  Random * random;
  void generate(char * destination, unsigned int length, Wrapper * & wrapper, Random * & random) {
    // fixed size string
    wrapper->clear(destination, length);
    random->seed();
    for(int i = 0; i < length; i++) {
      destination[i] = random->number(128);
      if(destination[i] < 97) destination[i] = 97;
      if(destination[i] > 122) destination[i] = 122;
    }
    destination[length] = '\0';
  }
  void generate_variable(char * destination, unsigned int length, Wrapper * & wrapper, Random * & random) {
    // variable size string
    wrapper->clear(destination, length);
    random->seed();
    length = random->number(length);
    if(!length) length++;
    for(int i = 0; i < length; i++) {
      destination[i] = random->number(128);
      if(destination[i] < 97) destination[i] = 97;
      if(destination[i] > 122) destination[i] = 122;
    }
    destination[length] = '\0';
  }
};