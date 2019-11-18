#include "Library_includes.h"
#include "Animal_class.h"

#if !defined(__FISH_CLASS__)
#define __FISH_CLASS__

class Fish_class : public Animal_class {
  private:
    int number_of_fins;
    float length;

  public:
    Fish_class(int n_f = -1, float l = -1, int a = -1, std::string c = "No color...") : number_of_fins{n_f}, length{l}, Animal_class{a, c} {}

    void set_number_of_fins(int n_f) {this->number_of_fins = n_f;}
    int get_number_of_fins(void) const {return this->number_of_fins;}

    void set_length(float l) {this->length = l;}
    float get_length(void) const {return this->length;}

    void how_do_i_move(void) override {std::cout << "\tI swim!\n";}

    void show(void) const override {
      std::cout << "Fish";
      Animal_class::show();
      std::cout << "\n\tFins: " << this->number_of_fins << "\n\tLength: " << this->length << "\n\n";
    }

    // void show(void) const {
    //   std::cout << "Fish";
    //   Animal_class::show();
    //   std::cout << "\n\tFins: " << this->number_of_fins << "\n\tLength: " << this->length << "\n\n";
    // }

    Fish_class* clone(void) override {return new Fish_class(*this);}
};

#endif
