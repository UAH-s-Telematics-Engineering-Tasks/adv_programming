#include "../inc/P_7_a_Index_class.h"


Index_class::Index_class(const std::string& name, int age, int hours, int minutes, int seconds, const std::string& time_format) : index_name{name}, index_age{age}, index_birth_time{hours, minutes, seconds, time_format} {}

void Index_class::view_index(void) {
  std::cout << "\tName: " << this->index_name << '\n' << "\tAge: " << this->index_age << '\n' << "\tBirth time: ";
  this->index_birth_time.view_time();
  std::cout << '\n';
}
