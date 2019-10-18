#include"Library_includes.h"
#include"P_5_Hour_class.h"

#if !defined(_INDEX_CLASS_)
#define _INDEX_CLASS_

namespace Index_info {
  class Index_class {
    private:
      std::string index_name;
      int index_age;
      Hour::Hour_class index_birth_time;

    public:
      Index_class(const std::string& = "", int = 0, int = 12, int = 0, int = 0, const std::string& = "AM");
      inline void set_name(const std::string&);
      inline std::string get_name(void) const;
      inline void set_age(int&);
      inline int get_age(void) const;
      inline bool set_birth_time(int, int, int, std::string&);
      inline Hour::Hour_class get_birth_time(void) const;
  };
  void view_index(const Index_class&);
}
#endif
