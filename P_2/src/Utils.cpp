#include "../inc/Library_includes.h"

// We want to clean the buffer in every iteration so that data after a space is NOT used!

int read_compare_int(char* prompt, bool greater_than, int limit) {
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

float read_float(char* prompt) {
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

int show_menu(const char** options, int n_options) {
  int option = -1;
  for (int i = 0; i < n_options - 1; i++)
    std::cout << options[i] << '\n';

  while((option = read_int((char*)"Option: ")) < 0 || option > n_options);

  return option;
}
