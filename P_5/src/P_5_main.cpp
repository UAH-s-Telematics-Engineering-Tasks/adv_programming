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
  /* Important note: Due to how read_string() is implemented we cannot use it twice in the same function call! If we do so, the first call will write something in the string. The second call will overwrite it, as we would expect. The thing is that the function returns a reference to the string where the contents have been read! As we are reading into the same string that reference is the same... Thus, even though we have written to the string twice we are passing a reference to an string whose content is what we set it to in the last call... That's why we were getting the same string in the name and time format fields... The function will only be called oonce all the needed parameters have been set! */

  Index_info::Index_class* dynamic_info = NULL;
  std::string recipient_str_a, recipient_str_b;

  while(true) {
    switch(utils::General_utils::show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1:
        if (!dynamic_info)
          dynamic_info = new (std::nothrow) Index_info::Index_class(utils::Cpp_utils::read_string(recipient_str_a, "Name: "), utils::General_utils::read_int("Age: "), utils::General_utils::read_int("Hours: "), utils::General_utils::read_int("Minutes: "), utils::General_utils::read_int("Seconds: "), utils::Cpp_utils::read_string(recipient_str_b, "Time format: "));
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
