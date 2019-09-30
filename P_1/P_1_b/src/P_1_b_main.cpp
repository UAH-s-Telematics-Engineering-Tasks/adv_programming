#include "../inc/funciones.h"

int main(void) {
    int option = -1, n_r, n_c;
    bool ready_for_input = false;
    std::vector<std::vector<float>> mtx;

    while (true) {
      std::cout << "1. Build matrix\n2. Fill matrix\n3. Show matrix\n4. Quit\n";

      while ((option = read_int((char*)"Option: ")) > 4 || option < 1);

      switch (option) {
        case 1:
            //mtx = build_matrix(read_int((char*) "# of rows: ", true, 0), read_int((char*) "# of cols: ", true, 0));
            std::cout << "Input the number of rows and cols: ";
            //Declaring them here makes them go out of scope and disappear!
            n_r = read_int((char*)"", true, 0);
            n_c = read_int((char*)"", true, 0);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Tidy the input buffer!
            mtx = build_matrix(n_r, n_c);
            ready_for_input = true;
          break;

        case 2:
          if (!mtx.empty() && ready_for_input) {
            input_data(mtx);
            ready_for_input = false;
          }
          else
            std::cout << "We have an empty vector...\n";
          break;

        case 3:
          if (!mtx.empty())
            show_matrix(mtx);
          else
            std::cout << "We have an empty vector...\n";
          break;

        case 4:
          return 0;
      }
    }
}
