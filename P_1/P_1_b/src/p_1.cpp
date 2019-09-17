#include "../inc/funciones.h"

int main(void) {
    int option = -1;
    std::vector<std::vector<float>> mtx;

    while (true) {
      std::cout << "1. Build matrix\n2. Fill matrix\n3. Show matrix\n4. Quit\n";

      while ((option = read_int((char*)"Option: ")) > 4 || option < 1);

      switch (option) {
        case 1:
            mtx = build_matrix(read_int((char*) "# of rows: ", true, 0), read_int((char*) "# of cols: ", true, 0));
          break;

        case 2:
          if (!mtx.empty())
            input_data(mtx);
          break;

        case 3:
          if (!mtx.empty())
            show_matrix(mtx);
          break;

        case 4:
          return 0;
      }
    }
}
