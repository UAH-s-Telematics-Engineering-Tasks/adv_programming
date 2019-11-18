#include "Library_includes.h"
#include "Mammal_class.h"

#if !defined(__DOG_CLASS__)
#define __DOG_CLASS__

class Dog_class : public Mammal_class {
  private:
    std::string race;

  public:
    Dog_class(std::string r = "Not defined...", float h = -1, int a = -1, std::string c = "No color...") : race{r}, Mammal_class{h, a, c} {}

    void set_race(std::string r) {this->race = r;}
    std::string get_race(void) const {return this->race;}

    void how_do_i_move(void) override {std::cout << "\tI walk!\n";}

    // void show(void) const override {
    //   std::cout << "Dog: ";
    //   Mammal_class::show();
    //   std::cout << "\b \b\tRace: " << this->race << "\n\n";
    // }

    void show(void) const {
      std::cout << "Dog: ";
      Mammal_class::show();
      std::cout << "\b \b\tRace: " << this->race << "\n\n";
    }
};

#endif
