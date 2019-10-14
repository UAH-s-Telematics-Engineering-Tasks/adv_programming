#include "../inc/Library_includes.h"
#include "../inc/Utils.h"
#include "../inc/P_3_a_Hour_class.h"
#include "../inc/Aux_functions.h"
#include "../inc/Constants.h"

const char* menu[] = {
  "1. Set the time",
  "2. View time",
  "3. Quit"
};

int main(void) {
  Hour_class time;
  char recipient_string[STR_SIZE];

  while (true) {
    switch (show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        while(!time.set_time(read_int("Hours: "), read_int("Minutes: "), read_int("Seconds: "), read_C_string(recipient_string, sizeof(recipient_string), "Time format: ")))
          std::cout << "\nIncorrect time...\n\n";
        break;

      case 2:
        view_time(time);
        break;

      case 3:
        return 0;
    }
  }
}
