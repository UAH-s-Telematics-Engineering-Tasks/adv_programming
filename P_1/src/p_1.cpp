#include "../inc/MemoryManager.h"
#include "../inc/funciones.h"

int main(void) {
  {
    mtx matrix = {0, 0, NULL};
    int option = -1;

    while (true) {
      std::cout << "1. Build matrix\n2. Fill matrix\n3. Show matrix\n4. Delete matrix\n5. Quit\nOption: ";

      do {
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } while (std::cin.fail() || option > 5 || option < 1);

      switch (option) {
        case 1:
          if (!matrix.mx) {
            std::cout << "Input the # of rows and colums (# #): ";
            do {
              std::cin >> matrix.rows >> matrix.cols; //This is the same as cin >> rows; cin >> cols;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }  while (std::cin.fail() || matrix.rows <= 0 || matrix.cols <= 0);
            matrix.mx = build_matrix(matrix.rows, matrix.cols);
          }
          else
            std::cout << "We already have a matrix!\n";
          break;

        case 2:
          if (matrix.mx)
            input_data(&matrix);
          break;

        case 3:
          if (matrix.mx)
            show_matrix(matrix);
          break;

        case 4:
          if (matrix.mx)
            free_matrix(&matrix);
          break;

        case 5:
          if (matrix.mx)
            free_matrix(&matrix);
          std::cout << "Bye!\n";
          if (!matrix.mx)
            std::cout << "Freed correctly!\n";
          return 0;
      }
    }
  }
  MemoryManager::dumpMemoryLeaks();
}
