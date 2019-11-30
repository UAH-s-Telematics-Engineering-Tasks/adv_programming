#include "../inc/P_7_b_Index_class.h"
#include "../inc/P_7_b_Employee_class.h"

Employee_class::Employee_class(const std::string name, int age, int h, int m, int s, const std::string& t_f, const std::string& pos, int w_c) : Index_class{name, age, h, m, s, t_f}, position{pos}, worked_years{w_c} {}

void Employee_class::show(void) {
  std::cout << "+ Record entry:\n" << "\tPosition: " << this->position << '\n' << "\tWorked for: " << this->worked_years << " years\n";
  this->view_index();
}

inline Index_class* Employee_class::clone(void) {
  return new (std::nothrow) Employee_class(*this);
}
