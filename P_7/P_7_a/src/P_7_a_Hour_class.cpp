#include "../inc/Library_includes.h"
#include "../inc/P_7_a_Hour_class.h"
#include "../inc/Utils.h"

Hour_class::Hour_class(int h, int m, int s, const std::string& tf) : hours{h}, minutes{m}, seconds{s}, time_format{tf} {
  // We can't get around this line... If we try to capitalize tf we will get an error, as it's a const String... We cannot define tf as a regular String as the compiler will complain. If we were capable of defining it as a regular String we would be making an error if we call capitalize() on it, because we woud be modifying the constants area, so calling capitalize(tf) would be an error all around... What we have to do is copy (or assign) tf to the time_format attribute which is in fact a normal String and then capitalize it. We don't have to assign the output of the capitalize() function to anything, but we can check that it'll in fact perform its job!
  std::cout << "Regular constructor!\n";
  if (tf != "24 HOURS")
    utils::Cpp_utils::capitalize(this->time_format);
}

Hour_class::Hour_class(const Hour_class& init_obj) : hours{init_obj.hours}, minutes{init_obj.minutes}, seconds{init_obj.seconds}, time_format{init_obj.time_format} {std::cout << "Copy constructor!\n";}

Hour_class& Hour::Hour_class::operator =(const Hour_class& init_obj) {
  // We can't compare init_obj and *this because one is const and the other isn't. We are only comparing addresses in this way!
  // Note that if wee create an object with Hour_class time = existing_object the copy constructor will be called instead of the assignment operator! For the assignment to work both objects must exist. Kinda weird...
  if (&init_obj != this) {
    std::cout << "Assignment operator!\n";
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

Hour_class::~Hour_class() {
  std::cout << "Destructor!\n";
}

void Hour_class::view_time(const class Hour_class& t) {
  std::cout << this->hours << ":" << this->minutes << ":" << this->seconds << " Format: " << this->time_format;
}
