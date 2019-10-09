#include "../inc/Library_includes.h"

// We want to clean the buffer in every iteration so that data after a space is NOT used!

int read_int(std::string prompt) {
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

int show_menu(const char** options, int n_options) {
  int option = -1;

  std::system("clear");

  for (int i = 0; i < n_options; i++)
    std::cout << options[i] << '\n';

  while((option = read_int("Option: ")) < 0 || option > n_options);

  return option;
}

char* read_C_string(char* target_str, int max_size, std::string prompt) {
  std::cout << prompt;
  if (target_str)
    std::cin.getline(target_str, max_size, '\n');

  return target_str;
}
