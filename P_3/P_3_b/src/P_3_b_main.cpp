#include "../inc/Library_includes.h"
#include "../inc/Utils.h"
#include "../inc/P_3_b_Hour_class.h"
#include "../inc/Aux_functions.h"

const char* menu[] = {
  "1. Set the time",
  "2. View time",
  "3. Quit"
};

std::string target_strings[] = {
  "AM",
  "PM",
  "24 HOURS",
  "X"
};

int main(void) {
  Hour_class time;
  std::string recipient_string;
  bool valid_time = false;

  while (true) {
    switch (show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        valid_time = time.set_time(read_int("Hours: "), read_int("Minutes: "), read_int("Seconds: "), read_string_cmp(recipient_string, "Time format: ", target_strings));
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
