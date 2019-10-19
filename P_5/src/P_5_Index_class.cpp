#include "../inc/P_5_Index_class.h"


Index_info::Index_class::Index_class(const std::string& name, int age, int hours, int minutes, int seconds, const std::string& time_format) : index_name{name}, index_age{age}, index_birth_time{hours, minutes, seconds, time_format} {}

void Index_info::view_index(const Index_class& index) {
  std::cout << "Name: " << index.get_name() << " Age: " << index.get_age() << " Birth time: ";
  Hour::view_time(index.get_birth_time());
}
