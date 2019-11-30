#include "../inc/Library_includes.h"
#include "../inc/P_7_b_Hour_class.h"
#include "../inc/Utils.h"

Hour_class::Hour_class(int h, int m, int s, const std::string& tf) : hours{h}, minutes{m}, seconds{s}, time_format{tf} {
  if (tf != "24 HOURS")
    utils::Cpp_utils::capitalize(this->time_format);
}

Hour_class::Hour_class(const Hour_class& init_obj) : hours{init_obj.hours}, minutes{init_obj.minutes}, seconds{init_obj.seconds}, time_format{init_obj.time_format} {}

Hour_class& Hour_class::operator =(const Hour_class& init_obj) {
  if (&init_obj != this) {
    this->hours = init_obj.hours; this->minutes = init_obj.minutes; this->seconds = init_obj.seconds; this->time_format = init_obj.time_format;
  }
  return *this;
}

inline bool Hour_class::time_format_24_H(void) const {
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
  this->hours = h; this->minutes = m; this->seconds = s; this->time_format = utils::Cpp_utils::capitalize(format_string);
  return Hour_class::is_time_correct();
}

void Hour_class::get_time(int& target_hours, int& target_minutes, int& target_seconds, std::string& target_format) const {
  target_hours = this->hours; target_minutes = this->minutes; target_seconds = this->seconds; target_format = this->time_format;
}

Hour_class::~Hour_class() {}

void Hour_class::view_time(void) {
  std::cout << this->hours << ":" << this->minutes << ":" << this->seconds << " Format: " << this->time_format;
}
