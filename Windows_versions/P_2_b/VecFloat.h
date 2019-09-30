#include "Library_includes.h"

#if !defined(_VECTOR_FLOAT_CLASS_)
#define _VECTOR_FLOAT_CLASS_

class Vector_float_class {
  private:
    std::vector<std::vector<float>> mtx;

  public:
    Vector_float_class() {
      std::cout << "Initializing object...\n";
    }

    void create_2d_mtx(int n_rows, int n_cols) {
      mtx = std::vector<std::vector<float>>(n_rows, std::vector<float>(n_cols, 0));
    }

    void create_1d_mtx(int n_cols) {
      create_2d_mtx(1, n_cols);
    }

    void populate(void);
    void show_mtx(void);
    ~Vector_float_class() {
      std::cout << "Destroying the object!\n";
    }
};

#endif
