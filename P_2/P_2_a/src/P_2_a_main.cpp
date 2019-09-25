#include "../inc/P_2_a_C_matx_float_class.h"
#include "../inc/Library_includes.h"
#include "../inc/Utils.h"

const char* menu[] = {
  "1. Build 1D matrix",
  "2. Build 2D matrix",
  "3. Populate matrix",
  "4. Show matrix",
  "5. Delete matrix",
  "6. Quit"
};

int main(void) {
  C_matx_float_class matrix;

  while(true)
    switch(show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        matrix.create_1d_mtx(read_compare_int((char*) "Number of cols: ", true, 0));
        break;

      case 2:
        matrix.create_2d_mtx(read_compare_int((char*) "Number of rows: ", true, 0), read_compare_int((char*) "Number of cols: ", true, 0));
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
        /*if (matrix.exists())
          matrix.deallocate();*/
        std::cout << "Bye!\n";
        return 0;
    }
}
