#include "../inc/Library_includes.h"

#if !defined(_HOUR_CLASS_)
#define _HOUR_CLASS_

class Hour_class {
  private:
    int hours, minutes, seconds;
    std::string time_format;

    bool time_format_24_H(void) const;

  protected:
    bool is_time_correct(void) const;

  public:
    Hour_class();
    bool set_time (int, int, int, std::string&);
    void get_time(int&, int&, int&, std::string&) const;
};

#endif
