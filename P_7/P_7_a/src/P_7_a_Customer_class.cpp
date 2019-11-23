#include "P_7_a_Index_class.h"
#include "P_7_a_Employee_class.h"

Customer_class::Customer_class(const std::string name, int age, int h, int m, int s, const std::string& t_f, const std::string& dni) : Index_class{name, age, h, m, s, t_f}, DNI{dni} {}

Customer_class::show(void) override {
  std::cout << "+ DNI: " << this->DNI << '\n';
  this->view_index();
}
