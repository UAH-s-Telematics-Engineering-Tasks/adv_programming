#include "../inc/funciones.h"

std::vector<std::vector<float>> build_matrix(int n_rows, int n_cols) {
  // Vectors have a strong exception safety, so in case of error no values are changed! It'll still be empty!
  std::vector<std::vector<float>> mtx(n_rows, std::vector<float>(n_cols, 0));
  return mtx;
}

void input_data(std::vector<std::vector<float>>& matrix) {
  for (int i = 0; i < matrix.size(); i++)
    for (int k = 0; k < matrix[i].size(); k++)
      (matrix.at(i)).at(k) = read_float(std::string("[") + std::to_string(i) + std::string("][") + std::to_string(k) + std::string("]: "));
  return;
}

void show_matrix(const std::vector<std::vector<float>>& matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    std::cout << "Row " << i << ": ";
    for (int k = 0; k < (matrix.at(i)).size(); k++)
      std::cout << (matrix.at(i)).at(k) << ' ';
    std::cout << '\n';
  }
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
      err = true;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while(err);
  return ret;
}

int read_int(char* prompt, bool greater_than, int limit) {
  int ret = 0;
  bool err;
  do  {
    std::cout << prompt;
    err = false;
    if (!(std::cin >> ret)) {
      std::cin.clear();
      err = true;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while(err || (greater_than? (ret < limit) : (ret > limit)));
  return ret;
}

float read_float(std::string prompt) {
  float ret = 0;
  bool err;
  do  {
    std::cout << prompt;
    err = false;
    if (!(std::cin >> ret)) {
      std::cin.clear();
      err = true;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while(err);
  return ret;
}
