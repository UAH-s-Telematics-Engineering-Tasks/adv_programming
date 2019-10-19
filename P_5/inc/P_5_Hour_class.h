#include "../inc/Library_includes.h"

#if !defined(_HOUR_CLASS_)
#define _HOUR_CLASS_

namespace Hour {
  class Hour_class {
    private:
      int hours, minutes, seconds;
      std::string time_format;

      inline bool time_format_24_H(void) const;

    public:
      Hour_class(int h = 0, int m = 0, int s = 0, const std::string& tf = "24 HOURS");
      Hour_class(const Hour_class&);
      Hour_class& operator = (const Hour_class&);
      bool is_time_correct(void) const;
      bool set_time (int h, int min, int sec, std::string& format);
      void get_time(int& h, int& min, int& sec, std::string& format) const;
  };

  void view_time(const Hour_class&);
}
#endif
