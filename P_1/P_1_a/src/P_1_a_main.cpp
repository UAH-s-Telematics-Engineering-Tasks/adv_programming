#include "../inc/funciones.h"

int main(void) {
    mtx matrix = {0, 0, NULL};
    int option = -1;
    bool read_error;

    while (true) {
      std::cout << "1. Build matrix\n2. Fill matrix\n3. Show matrix\n4. Delete matrix\n5. Quit\n";

      while ((option = read_int((char*)"Option: ")) > 5 || option < 1);

      switch (option) {
        case 1:
          if (!matrix.mx) {
            do {
              read_error = false;
              std::cout << "Input the # of rows and colums (# #): ";
              if (!(std::cin >> matrix.rows)) {
                std::cin.clear();
                read_error = true;
              }
              if (!(std::cin >> matrix.cols)) {
                std::cin.clear();
                read_error = true;
              }
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }  while (read_error || matrix.rows <= 0 || matrix.cols <= 0);
            matrix.mx = build_matrix(matrix.rows, matrix.cols);
          }
          else
            std::cout << "We already have a matrix, delete it first!\n";
          break;

        case 2:
          if (matrix.mx)
            input_data(&matrix);
          else
            std::cout << "We don't have a matrix yet...\n";
          break;

        case 3:
          if (matrix.mx)
            show_matrix(matrix);
          else
            std::cout << "We don't have a matrix yet...\n";
          break;

        case 4:
          if (matrix.mx)
            free_matrix(&matrix);
          else
            std::cout << "We don't have a matrix yet...\n";
          break;

        case 5:
          if (matrix.mx)
            free_matrix(&matrix);
          return 0;
      }
    }
}
