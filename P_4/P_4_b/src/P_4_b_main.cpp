#include "../inc/Library_includes.h"
#include "../inc/Utils.h"
#include "../inc/P_4_b_Hour_class.h"
#include "../inc/Aux_functions.h"

const char* menu[] = {
  "1. Create a local object",
  "2. Create a dynamic object",
  "3. Create an object with the copy constructor",
  "4. Create an objet with the assignment operator",
  "5. Quit"
};

const char* sub_menu[] = {
  "1. Default time",
  "2. Input the hours",
  "3. Input the hours and minutes",
  "4. Input the hours, minutes and seconds",
  "5. Input the hours, minutes, seconds and format",
  "6. Back to the main menu"
};

int main(void) {
  Hour_class* dynamic_time = NULL;
  bool stay_here;
  std::string recipient_str;

  while (true) {
    stay_here = true;
    switch (utils::General_utils::show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        while (stay_here) {
          switch (utils::General_utils::show_menu(sub_menu, sizeof(sub_menu) / sizeof(char*))) {
            case 1:
              {
                Hour_class local_time;
                view_time(local_time);
                break;
              }
            case 2:
              {
                Hour_class local_time {utils::General_utils::read_int("Hours: ")};
                view_time(local_time);
                break;
              }
            case 3:
              {
                Hour_class local_time {utils::General_utils::read_int("Hours: "), utils::General_utils::read_int("Minutes: ")};
                view_time(local_time);
                break;
              }
            case 4:
              {
                Hour_class local_time {utils::General_utils::read_int("Hours: "), utils::General_utils::read_int("Minutes: "), utils::General_utils::read_int("Seconds: ")};
                view_time(local_time);
                break;
              }
            case 5:
              {
                Hour_class local_time {utils::General_utils::read_int("Hours: "), utils::General_utils::read_int("Minutes: "), utils::General_utils::read_int("Seconds: "), utils::Cpp_utils::read_string(recipient_str, "Format: ")};
                view_time(local_time);
                break;
              }
            case 6:
              stay_here = false;
          }
        }
        break;

      case 2:
        if(!dynamic_time) {
          dynamic_time = new (std::nothrow) Hour_class(utils::General_utils::read_int("Hours: "), utils::General_utils::read_int("Minutes: "), utils::General_utils::read_int("Seconds: "), utils::Cpp_utils::read_string(recipient_str, "Format: "));
          view_time(*dynamic_time);
        }
        else {
          std::cout << "Free the current object!\n";
          std::getchar();
        }

        break;

      case 3:
        if (dynamic_time) {
          Hour_class local_time(*dynamic_time);
          view_time(local_time);
        }
        break;

      case 4:
          if (dynamic_time) {
            Hour_class local_time;
            view_time(local_time);
            local_time = *dynamic_time;
            view_time(local_time);
          }
          break;

      case 5:
        if (dynamic_time)
          delete dynamic_time;
        return 0;
    }
  }
}
