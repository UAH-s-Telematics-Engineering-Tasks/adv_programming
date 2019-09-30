#include "CMatFloat.h"
#include "Library_includes.h"
#include "Utils.h"
#include "MemoryManager.h"

void C_matx_float_class::create_2d_mtx(int rows, int cols) {
    int i;
    n_rows = rows; n_cols = cols;
    bool success = false;

    try {
        C_matx_float_class::mtx = new float* [rows];
        success = true;

        for (i = 0; i < rows; i++)
            mtx[i] = new float [cols];

    } catch(std::bad_alloc& e) {
        std::cout << "Error!\n";
        if (!success)
                delete[] mtx;
        else {
          for (int k = i - 1; k >= 0; k--)
            delete[] mtx[k];
          delete[] mtx;
        }
        mtx = NULL;
    }

    for (int k = 0; k < rows; k++)
      for (i = 0; i < cols; i++)
        mtx[k][i] = 0;
}

void C_matx_float_class::populate(void) {
  if (!mtx) {
    std::cout << "We have an empty matrix!\n";
    return;
  }
  std::cout << "Input all the required data: ";
  for (int i = 0; i < n_rows; i++)
    for (int k = 0; k < n_cols; k++)
      mtx[i][k] = read_float((char*)"");
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void C_matx_float_class::show_mtx(void) {
  if (!mtx) {
    std::cout << "We have an empty matrix!\n";
    return;
  }

  for (int i = 0; i < n_rows; i++) {
    std::cout << "Row " << i << ": ";

    for (int k = 0; k < n_cols; k++)
      std::cout << *(*(mtx + i) + k) << ' '; //Tricky but insightful!. We have an extra space but we won't see it!

    std::cout << '\n';
  }
  std::getchar(); //Pause for reading!
}

void C_matx_float_class::deallocate(void) {
  if (!mtx) // We have an empty matrix!!
    return;

  for (int i = 0; i < n_rows; i++)
    delete[] mtx[i];

  delete[] mtx;

  C_matx_float_class::initialize();
}
