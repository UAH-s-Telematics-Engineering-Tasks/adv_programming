#include "../inc/Library_includes.h"
#include "../inc/Utils.h"
#include "../inc/P_3_a_Hour_class.h"
#include "../inc/Aux_functions.h"

#define STR_SIZE 10

const char* menu[] = {
  "1. Set the time",
  "2. View time",
  "3. Quit"
};

int main(void) {
  Hour_class time;
  char recipient_string[STR_SIZE];
  bool valid_time = false;

  while (true) {
    switch (show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        valid_time = time.set_time(read_int("Hours: "), read_int("Minutes: "), read_int("Seconds: "), read_C_string(recipient_string, sizeof(recipient_string), "Time format: "));
        break;

      case 2:
        view_time(time);
        if (valid_time)
          std::cout << "Valid time!";
        else
          std::cout << "Wrong time...";
        std::getchar();
        break;

      case 3:
        return 0;
    }
  }
}
