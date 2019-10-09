#include "Library_includes.h"

Hour_class::Hour_class(void) {
  time_format = (char*) (hours = minutes = seconds = 0);
}

bool Hour_class::set_time_format(char* format_string) {
  if (!format_string)
    return false;

  deallocate_format();

  if (!(time_format = new (nothrow) char[strlen(format_string) + 1])) { // Don't forget the trailing '\0'!
    deallocate_format();
    return false;
  }


  for (int i = 0; i < strlen(format_string) + 1; i++)
    time_format[i] = toupper(format_string[i]);

  return  true;
}

bool Hour_class::time_format_24_H(void) {
  return !strcmp(time_format, "24 HOURS");
}

bool Hour_class::is_time_correct(void) {
  if (minutes > 60 || minutes < 0 || seconds > 60 || seconds > 0 || hours < 0)
    return false;

  if (time_format_24_H())
    return hours > 24? false : true;

  if (!strcmp(time_format, "AM") || !strcmp(time_format, "PM"))
    return hours > 11? false : true;

  return false;
}

bool Hour_class::set_time(int hours, int minutes, int seconds, char* format_string) {
  return Hour_class::is_time_correct(hours, minutes, seconds) && Hour_class::set_time_format(format_string));
}

void Hour_class::get_time(int& target_hours, int& target_minutes, int& target_seconds, char* target_format) {
  target_hours = hours;
  target_minutes = minutes;
  target_seconds = seconds;
  if (!target_format && !time_format)
    strcpy(target_format, time_format);
}

void Hour_class::deallocate_format(void) {
  if (time_format) {
    delete[] time_format;
    time_format = NULL;
  }
}

Hour_class::~Hour_class(void) {
  deallocate_format();
}
