#include "../inc/Library_includes.h"
#include "../inc/Utils.h"

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

int read_compare_int(char* prompt, bool greater_than, int limit) {
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
  } while(err || (greater_than? (ret <= limit) : (ret > limit)));
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

std::string& read_string(std::string& target_str, std::string prompt) {
  std::cout << prompt;
  std::getline(std::cin, target_str, '\n');
  // If the input can't be interpreted as a string clean the buffer. getline() appends characters, so the input is guaranteed to fit in the String!
  if(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return target_str;
}

std::string& read_string_cmp(std::string& target_str, std::string prompt, std::string* targets) {
  do {
    std::cout << prompt;
    std::getline(std::cin, target_str, '\n');
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while(!target_found(target_str, targets));
  return target_str;
}

bool target_found(std::string str, std::string* targets) {
  capitalize(str);
  for (int i = 0; targets[i] != "X"; i++)
    if (str == targets[i])
      return true;
  return false;
}

std::string& capitalize(std::string& str) {
  try {
    for (unsigned long int i = 0; i < str.length(); i++)
      if (str.at(i) >= 'a' && str.at(i) <= 'z')
        str.at(i) += 'A' - 'a';
  } catch (const std::out_of_range& err) {
    std::cout << "Out of range: " << err.what() << '\n';
  }
  return str;
}
