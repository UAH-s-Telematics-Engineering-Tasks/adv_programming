#include "../inc/Library_includes.h"
#include "../inc/P_5_Hour_class.h"
#include "../inc/P_5_Index_class.h"
#include "../inc/Utils.h"

const char* menu[] = {
  "1. Create an index card",
  "2. View the index card",
  "3. Quit"
};

int main(void) {
  Index_info::Index_class* dynamic_info = NULL;
  std::string recipient_str;

  while(true) {
    switch(utils::General_utils::show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        if (!dynamic_info)
          dynamic_info = new (std::nothrow) Index_info::Index_class(utils::Cpp_utils::read_string(recipient_str, "Name: "), utils::General_utils::read_int("Age: "), utils::General_utils::read_int("Hours: "), utils::General_utils::read_int("Minutes: "), utils::General_utils::read_int("Seconds: "), utils::Cpp_utils::read_string(recipient_str, "Time format: "));
        else
          std::cout << "Free the current object...\n";
        break;

      case 2:
        Index_info::view_index(*dynamic_info);
        break;

      case 3:
        if (dynamic_info)
          delete dynamic_info;
        return 0;
    }
  }
}
