#include "../inc/P_2_b_Vector_float_class.h"
#include "../inc/Library_includes.h"
#include "../inc/Utils.h"

const char* menu[] = {
  "1. Build 1D matrix",
  "2. Build 2D matrix",
  "3. Populate matrix",
  "4. Show matrix",
  "5. Quit"
};

int main(void) {
  Vector_float_class matrix;
  bool ready_for_input = false;
  int n_r, n_c;

  while(true)
    switch(show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        if (!ready_for_input) {
          matrix.create_1d_mtx(read_compare_int((char*) "Number of cols: ", true, 0));
          ready_for_input = true;
        }
        break;

      case 2:
        if (!ready_for_input) {
          //matrix.create_2d_mtx(read_compare_int((char*) "Number of rows: ", true, 0), read_compare_int((char*) "Number of cols: ", true, 0));
          std::cout << "Input the number of rows and cols: ";
          n_r = read_compare_int((char*)"", true, 0);
          n_c = read_compare_int((char*)"", true, 0);
          matrix.create_2d_mtx(n_r, n_c);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Tidy the input buffer!
          ready_for_input = true;
        }
        break;

      case 3:
        if (ready_for_input) {
          matrix.populate();
          ready_for_input = false;
        }
        break;

      case 4:
        matrix.show_mtx();
        break;

      case 5:
        std::cout << "Bye!\n";
        return 0;
    }
}
