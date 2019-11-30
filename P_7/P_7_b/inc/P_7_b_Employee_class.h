#include "Library_includes.h"
#include "P_7_b_Index_class.h"

#if !defined(_EMPLOYEE_CLASS_)
#define _EMPLOYEE_CLASS_

class Employee_class : public Index_class {
  private:
    std::string position;
    int worked_years;

  public:
    Employee_class(const std::string = "", int = 0, int = 12, int = 0, int = 0, const std::string& = "AM", const std::string& = "", int = 0);

    void set_position(const std::string& pos) {this->position = pos;}
    void set_worked_years(int w_y) {this->worked_years = w_y;}

    void show(void) override;
    inline Index_class* clone(void) override;
};

#endif
