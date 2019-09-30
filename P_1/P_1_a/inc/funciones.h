#include <iostream> //Include cin and cout
#include <new>
#include <limits> //For stream limits!
#include <string>

struct mtx {
  int rows, cols;
  float** mx;
};

float** build_matrix(int, int);
void input_data(mtx*);
void show_matrix(mtx);
void free_matrix(mtx*);
float read_float(char*);
int read_int(char*);
