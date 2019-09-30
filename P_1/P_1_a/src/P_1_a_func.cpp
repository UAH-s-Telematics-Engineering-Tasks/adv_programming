#include "../inc/funciones.h"

float** build_matrix(int rows, int cols) {
    int i;
    float** matx = NULL;
    bool success = false;

    try {
        matx = new float* [rows];
        success = true;

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
  bool err;
  std::cout << "Please introduce the data: ";
  for (int i = 0; i < mat->rows; i++)
    for (int k = 0; k < mat->cols; k++) {
        //std::cout << "Data for cell [" << i << "][" << k << "]: ";
        (mat->mx)[i][k] = read_float((char*)"");
    }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Tidy up the buffer!
  return;
}

void show_matrix(mtx mat) {
  for (int i = 0; i < mat.rows; i++) {
    std::cout << "Row " << i << ": ";

    for (int k = 0; k < mat.cols; k++)
      std::cout << *(*((mat.mx) + i) + k) << ' '; //Tricky but insightful!. We have an extra space but we won't see it!

    std::cout << '\n';
  }
  return; //I like it to be here...
}

void free_matrix(mtx* mat) {
  for (int i = 0; i < mat->rows; i++)
    delete[] (mat->mx)[i];

  delete[] (mat->mx);
  mat->mx = NULL;
  return;
}

int read_int(char* prompt) {
  int ret = 0;
  bool err;
  do  {
    std::cout << prompt;
    err = false;
    if (!(std::cin >> ret)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
      err = true;
    }
  } while(err);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return ret;
}

float read_float(char* prompt) {
  float ret = 0;
  bool err;
  do  {
    std::cout << prompt;
    err = false;
    if (!(std::cin >> ret)) {
      std::cin.clear();
      err = true;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
    }
  } while(err);
  return ret;
}
