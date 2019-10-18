#include "../inc/P_5_Index_class.h"


Index_info::Index_class::Index_class(const std::string& name, int age, int hours, int minutes, int seconds, const std::string& time_format) : index_name{name}, index_age{age}, index_birth_time{hours, minutes, seconds, time_format} {}

inline void Index_info::Index_class::set_name(const std::string& name) {
  this->index_name = name;
}

inline std::string Index_info::Index_class::get_name(void) const {
  return this->index_name;
}

inline void Index_info::Index_class::set_age(int& age) {
  this->index_age = age;
}

inline int Index_info::Index_class::get_age(void) const {
  return this->index_age;
}

inline bool Index_info::Index_class::set_birth_time(int h, int m, int s, std::string& tf) {
  return this->index_birth_time.set_time(h, m, s, tf);
}

inline Hour::Hour_class Index_info::Index_class::get_birth_time(void) const {
  //This will invoke the copy constructor on main()!
  return this->index_birth_time;
}

void Index_info::view_index(const Index_class& index) {
  std::cout << "Name: " << index.get_name() << " Age: " << index.get_age() << " Birth time: ";
  Hour::view_time(index.get_birth_time());
}
