#include <iostream>

#define STR_SIZE 15

const char* menu[] = {
  "1. Set the time",
  "2. View time",
  "3. Quit"
};

int main(void) {
  Hour_class time;
  char recipient_string[STR_SIZE];
  int h = 0, m = 0, s = 0;

  while (true) {
    switch (show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        time.set_time(read_int("Hours: "), read_int("Minutes"), read_int("Seconds"), read_C_string(recipient_string, sizeof(recipient_string)));
        break;

      case 2:
        time.get_time(h, m, s, recipient_string);
        break;

      case 3:
        return 0;
    }
  }
}
