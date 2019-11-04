#include "Library_includes.h"
#include "Animal_class.h"
#include "Fish_class.h"
#include "Mammal_class.h"
#include "Bird_class.h"
#include "Dog_class.h"

int main(void) {
  Fish_class fish;
  Mammal_class mammal;
  Bird_class bird;
  Dog_class dog;

  fish.show();
  mammal.show();
  bird.show();
  dog.show();
}
