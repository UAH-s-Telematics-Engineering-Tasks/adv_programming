#include "../inc/Library_includes.h"
#include "../inc/Utils.h"

// We want to clean the buffer in every iteration so that data after a space is NOT used!

bool utils::C_utils::read_int(int& destination, std::string prompt) {
  bool err;
  do  {
    std::cout << prompt;
    std::cin >> destination;

    err = false;
    if (std::cin.eof())
      return false;

    if (std::cin.fail()) {
      std::cin.clear();
      err = true;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while(err);
  return true;
}

int utils::C_utils::read_int(std::string prompt) {
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

int utils::C_utils::show_menu(const char** options, int n_options) {
  int option = -1;

  std::system("clear");

  for (int i = 0; i < n_options; i++)
    std::cout << options[i] << '\n';

  while((option = read_int("Option: ")) < 0 || option > n_options);

  return option;
}

char* utils::C_utils::read_C_string(char* target_str, int max_size, std::string prompt) {
  if (!target_str)
    return NULL;
  std::cout << prompt;
  if (target_str)
    std::cin.getline(target_str, max_size, '\n');

  // If cin.getline() reaches the max_size limit it will set the failbit of the stream and we won't be able to perform successive reads with read_int()!
  if(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return target_str;
}
