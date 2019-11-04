#include "Library_includes.h"
#include "Animal_class.h"

#if !defined(__BIRD_CLASS__)
#define __BIRD_CLASS__

class Bird_class : public Animal_class {
  private:
    float wingspan;

  public:
    Bird_class(float ws = -1, int a = -1, std::string c = "No color...") : wingspan{ws}, Animal_class{a, c} {}

    void set_wingspan(float ws) {this->wingspan = ws;}
    float get_wingspan(void) const {return this->wingspan;}

    void show(void) const {
      std::cout << "Bird";
      Animal_class::show();
      std::cout << "\n\tWingspan: " << this->wingspan << "\n\n";
    }
};

#endif
