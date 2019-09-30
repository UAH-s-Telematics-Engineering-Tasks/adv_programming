#include "VecFloat.h"
#include "Library_includes.h"
#include "Utils.h"
#include "MemoryManager.h"

void Vector_float_class::populate(void) {
  if (mtx.empty()) {
    std::cout << "We have an empty matrix... Create it first!\n";
    return;
  }
  std::cout << "Input all needed data: ";
  for (long unsigned int i = 0; i < mtx.size(); i++)
    for (long unsigned int k = 0; k < mtx.at(i).size(); k++)
      mtx.at(i).at(k) = read_float((char*)"");
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Vector_float_class::show_mtx(void) {
  if (mtx.empty()) {
    std::cout << "We have an empty matrix... Create it first!\n";
    return;
  }
  for (long unsigned int i = 0; i < mtx.size(); i++) {
    std::cout << "Row " << i << ": ";
    for (long unsigned int k = 0; k < mtx.at(i).size(); k++)
      std::cout << mtx.at(i).at(k) << ' '; //Tricky but insightful!. We have an extra space but we won't see it!
    std::cout << '\n';
  }
  std::getchar(); //Pause for visualization!
}
