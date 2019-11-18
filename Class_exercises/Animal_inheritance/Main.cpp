#include "Library_includes.h"
#include "Animal_class.h"
#include "Fish_class.h"
#include "Mammal_class.h"
#include "Bird_class.h"
#include "Dog_class.h"

int main(void) {

  Animal_class* animal_array[6] = {new Fish_class(2, 15, 12, "Green"), new Bird_class(5.5, 3, "White"), new Dog_class("Shin-Tzu", 50, 7, "Pink"), new Mammal_class(150, 5, "Black")};

  animal_array[4] = animal_array[0]->clone();
  // This one will call Animal_class' clone() method as it hasn't been overridden in Bird_class...
  animal_array[5] = animal_array[1]->clone();

  for (int i = 0; i < 6; i++) {
    animal_array[i]->show();
    animal_array[i]->how_do_i_move();
  }

  // Fish_class fish;
  // Mammal_class mammal;
  // Bird_class bird;
  // Dog_class dog;
  //
  // fish.show();
  // mammal.show();
  // bird.show();
  // dog.show();
}
