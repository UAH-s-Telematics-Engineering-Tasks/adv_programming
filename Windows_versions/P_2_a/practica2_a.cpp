#include "CMatFloat.h"
#include "Library_includes.h"
#include "Utils.h"
#include "MemoryManager.h"

const char* menu[] = {
  "1. Build 1D matrix",
  "2. Build 2D matrix",
  "3. Populate matrix",
  "4. Show matrix",
  "5. Delete matrix",
  "6. Quit"
};

int main(void) {
  {
  C_matx_float_class matrix;
  int n_r, n_c;
  bool flag = true;

  while(flag)
    switch(show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        if (!matrix.exists())
          matrix.create_1d_mtx(read_compare_int((char*) "Number of cols: ", true, 0));
        break;

      case 2:
        if (!matrix.exists()) {
          //matrix.create_2d_mtx(read_compare_int((char*) "Number of rows: ", true, 0), read_compare_int((char*) "Number of cols: ", true, 0));
          std::cout << "Input the number of rows and cols: ";
          //Declaring them here makes them go out of scope and disappear!
          n_r = read_compare_int((char*)"", true, 0);
          n_c = read_compare_int((char*)"", true, 0);
          matrix.create_2d_mtx(n_r, n_c);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Tidy the input buffer!
        }
        break;

      case 3:
        matrix.populate();
        break;

      case 4:
        matrix.show_mtx();
        break;

      case 5:
        matrix.deallocate();
        break;

      case 6:
        std::cout << "Bye!\n";
        flag = false;
    }
  }
  MemoryManager::dumpMemoryLeaks();
}
