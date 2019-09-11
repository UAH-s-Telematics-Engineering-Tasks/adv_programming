#include "../inc/funciones.h"

float** build_matrix(int rows, int cols) {
    int success = 0, i;
    float** matx = NULL;

    try {
        matx = new float* [rows];
        success++;

        for (i = 0; i < rows; i++)
            matx[i] = new float [cols];

    } catch(std::bad_alloc& e) {
        std::cout << "Error!\n";
        if (!success)
                delete[] matx;
        else {
          for (int k = i - 1; k >= 0; k--)
            delete[] matx[k];
          delete[] matx;
        }
        return NULL;
    }

    for (int k = 0; k < rows; k++)
      for (i = 0; i < cols; i++)
        matx[k][i] = 0;
    return matx;
}

void input_data(mtx* mat) {
  float tmp;
  for (int i = 0; i < mat->rows; i++)
    for (int k = 0; k < mat->cols; k++) {
      do {
        std::cout << "Data for cell [" << i << "][" << k << "]: ";
        std::cin >> tmp;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Empty the buffer!
      } while (std::cin.fail()); //If we read an incorrect data type this will be TRUE!

      (mat->mx)[i][k] = tmp;
    }
  return;
}

void show_matrix(mtx mat) {
  for (int i = 0; i < mat.rows; i++) {
    std::cout << "Row #: " << i << '\n';

    for (int k = 0; k < mat.cols; k++)
      std::cout << *(*((mat.mx) + i) + k) << ' '; //Tricky but insightful!. We have an extra space but we won't see it!

    std::cout << '\n';
  }
  return; //I like it to be here...
}

void free_matrix(mtx* mat) {
  for (int i = 0; i < mat->rows; i++)
    for (int k = 0; k < mat->cols; k++)
      delete[] (mat->mx)[i];

  delete[] (mat->mx);
  mat->mx = NULL;
  return;
}
