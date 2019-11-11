#include "Library_includes.h"

#if !defined(__ANIMAL_CLASS__)
#define __ANIMAL_CLASS__

/*enum color {
  undefined, red, green, blue
};*/

class Animal_class {
  private:
    int age;
    /*color col;*/
    std::string color;

  public:
    /*Animal_class(int a = 0, color c = undefined) : age{a}, col{c} {}*/
    Animal_class(int a, std::string c) : age{a}, color{c} {}

    void set_age(int a) {this->age = a;}
    int get_age(void) const {return this->age;}

    void set_color(std::string c) {this->color = c;}
    std::string get_color(void) const {return this->color;}
    virtual void how_do_i_move(void) {};

    void show(void) const {
      std::cout << "\n\tAge: " << this->age << "\n\tColor: " << this->color;
    }
};

#endif
