#include "Library_includes.h"

namespace utils {
  class C_utils {
    public:
      static bool read_int(int&, std::string);
      static int read_int(std::string);
      static int show_menu(const char**, int);
      static char* read_C_string(char*, int, std::string);
      static char* read_C_string_cmp(char*, int, std::string, const char**);
    private:
      static bool target_found(char*, const char**);
  };
};
