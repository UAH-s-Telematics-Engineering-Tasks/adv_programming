#include "Library_includes.h"

namespace utils {
  class General_utils {
    public:
      static bool read_int(int&, std::string);
      static int read_int(std::string);
      static int show_menu(const char**, int);
  };
  class C_utils {
    public:
      static char* read_C_string(char*, int, std::string);
  };
  class Cpp_utils {
    public:
      static std::string& capitalize(std::string&);
      static std::string& read_string(std::string&, std::string);
  };
};
