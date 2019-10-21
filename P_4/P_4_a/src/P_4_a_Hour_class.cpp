#include "../inc/Library_includes.h"
#include "../inc/P_4_a_Hour_class.h"
#include "../inc/Utils.h"

Hour_class::Hour_class(int h, int m, int s, const char* tf) : hours{h}, minutes{m}, seconds{s}, time_format{0} {
  std::cout << "Calling the regular constructor!\n";
  set_time_format(tf);
}

Hour_class::Hour_class(const Hour_class& init_obj) : hours{init_obj.hours}, minutes{init_obj.minutes}, seconds{init_obj.seconds}, time_format{NULL} {
  std::cout << "Calling the copy constructor!\n";
  set_time_format(init_obj.time_format);
}

Hour_class& Hour_class::operator =(const Hour_class& init_obj) {
  // We can't compare init_obj and *this because one is const and the other isn't. We are only comparing addresses in this way!
  // Note that if wee create an object with Hour_class time = existing_object the copy constructor will be called instead of the assignment operator! For the assignment to work both objects must exist. Kinda weird...
  if (&init_obj != this) {
    std::cout << "Calling the assignment operator!\n";
    this->hours = init_obj.hours; this->minutes = init_obj.minutes; this->seconds = init_obj.seconds;
    set_time_format(init_obj.time_format);
  }
  return *this;
}

bool Hour_class::set_time_format(const char* format_string) {
  if (!format_string)
    return false;

  deallocate_format();

  if (!(this->time_format = new (std::nothrow) char[strlen(format_string) + 1])) // Don't forget the trailing '\0'!
    return false;

  // Instead of writing a function we save time and call overhead
  for (size_t i = 0; i < strlen(format_string) + 1; i++) {
    this->time_format[i] = format_string[i];
    if(this->time_format[i] >= 'a' && this->time_format[i] <= 'z')
      this->time_format[i] += 'A' - 'a';
  }

  return  true;
}

bool Hour_class::time_format_24_H(void) const {
  if (this->time_format)
    return !static_cast<bool>(strcmp(this->time_format, "24 HOURS"));
  return false;
}

bool Hour_class::is_time_correct(void) const {
  if (this->minutes > 60 || this->minutes < 0 || this->seconds > 60 || this->seconds < 0 || this->hours < 0)
    return false;

  if (time_format_24_H())
    return this->hours > 24? false : true;

  if (!strcmp(this->time_format, "AM") || !strcmp(this->time_format, "PM"))
    return this->hours > 11? false : true;

  return false;
}

bool Hour_class::set_time(int h, int m, int s, char* format_string) {
  this->hours = h; this->minutes = m; this->seconds = s;
  // We are guaranteed the order of evaluation is left-to-right, otherwise we can trigger a NULL pointer access...
  return Hour_class::set_time_format(format_string) && Hour_class::is_time_correct();
}

void Hour_class::get_time(int& target_hours, int& target_minutes, int& target_seconds, char* target_format) const {
  target_hours = this->hours; target_minutes = this->minutes; target_seconds = this->seconds;
  if (target_format && this->time_format)
    strcpy(target_format, this->time_format);
}

void Hour_class::deallocate_format(void) {
  if (this->time_format) {
    delete[] this->time_format;
    this->time_format = 0;
  }
}

Hour_class::~Hour_class(void) {
  std::cout << "Calling the destructor!";
  std::getchar();
  deallocate_format();
}
