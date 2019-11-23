#include "../inc/P_7_a_Index_class.h"


Index_class::Index_class(const std::string& name, int age, int hours, int minutes, int seconds, const std::string& time_format) : index_name{name}, index_age{age}, index_birth_time{hours, minutes, seconds, time_format} {}

void Index_class::view_index(const Index_class& index) {
  std::cout << "\tName: " << this->name << '\n' << "\tAge: " << this->age << '\n' << "\tBirth time: ";
  this->index_birth_time.view_time() << '\n';
}
