#include "P_7_a_Index_class.h"
#include "P_7_a_Employee_class.h"

Employee_class::Employee_class(const std::string name, int age, int h, int m, int s, const std::string& t_f, const std::string& pos, int w_c) : Index_class{name, age, h, m, s, t_f}, position{pos}, worked_years{w_c} {}

Employee_class::show(void) override {
  std::cout << "+ Position: " << this->position << '\n' << "\tWorked for: " << this->worked_years << " years\n":
  this->view_index();
}
