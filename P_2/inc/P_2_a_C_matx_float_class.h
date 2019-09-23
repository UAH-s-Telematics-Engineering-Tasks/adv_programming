#include "../inc/Library_includes.h"

#if !defined(_C_MATX_FLOAT_CLASS_)
#define _C_MATX_FLOAT_CLASS_

class C_matx_float_class {
  private:
    float** mtx;
    int n_rows, n_cols;

  public:
    C_matx_float_class() {
      std::cout << "Calling initialize()...\n";
      initialize();
    }
    void initialize(void) {
      mtx = (float**) (n_rows = n_cols = 0);
    }
    void create_2d_mtx(int, int);
    void create_1d_mtx(int);
    void populate(void);
    void show_mtx(void);
    void deallocate(void);
    bool exists(void) {
      return static_cast<bool>(mtx);
    }
};

#endif
