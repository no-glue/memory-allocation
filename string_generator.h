template<class Wrapper, class Random>class StringGenerator {
// generates random strings
public:
  StringGenerator() {}
  StringGenerator(Wrapper * & wrapper, Random * & random):wrapper(wrapper), random(random) {}
  void generate(char * destination, unsigned int length) {generate(destination, length, wrapper, random);}
private:
  Wrapper * wrapper;
  Random * random;
  void generate(char * destination, unsigned int length, Wrapper * & wrapper, Random * & random) {
    wrapper->clear(destination, length);
    random->seed();
    for(int i = 0; i < length; i++) destination[i] = random->number(128);
    destination[length] = '\0';
  }
};