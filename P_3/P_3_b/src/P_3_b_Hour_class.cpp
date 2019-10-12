#include "../inc/Library_includes.h"
#include "../inc/P_3_b_Hour_class.h"
#include "../inc/Utils.h"

Hour_class::Hour_class(void) {
  this->hours = this->minutes = this->seconds = 0;
  this->time_format = "";
}

bool Hour_class::time_format_24_H(void) const {
    return this->time_format == "24 HOURS";
}

bool Hour_class::is_time_correct(void) const {
  if (this->minutes > 60 || this->minutes < 0 || this->seconds > 60 || this->seconds < 0 || this->hours < 0)
    return false;

  if (time_format_24_H())
    return this->hours > 24? false : true;

  if (this->time_format == "AM" || this->time_format == "PM")
    return this->hours > 11? false : true;

  return false;
}

bool Hour_class::set_time(int h, int m, int s, std::string& format_string) {
  this->hours = h; this->minutes = m; this->seconds = s; this->time_format = capitalize(format_string);
  return Hour_class::is_time_correct();
}

void Hour_class::get_time(int& target_hours, int& target_minutes, int& target_seconds, std::string& target_format) const {
  target_hours = this->hours; target_minutes = this->minutes; target_seconds = this->seconds; target_format = this->time_format;
}
