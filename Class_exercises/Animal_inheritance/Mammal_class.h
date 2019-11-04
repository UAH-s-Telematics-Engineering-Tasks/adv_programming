#include "Library_includes.h"
#include "Animal_class.h"

#if !defined(__MAMMAL_CLASS__)
#define __MAMMAL_CLASS__

class Mammal_class : public Animal_class {
  private:
    float height;

  public:
    Mammal_class(float h = -1, int a = -1, std::string c = "No color...") : height{h}, Animal_class{a, c} {}

    void set_height(float h) {this->height = h;}
    float get_height(void) const {return this->height;}

    void show(void) const {
      std::cout << "Mammal";
      Animal_class::show();
      std::cout << "\n\tHeight: " << this->height << "\n\n";
    }
};

#endif
