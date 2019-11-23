#include "Library_includes.h"
#include "P_7_a_Index_class.h"

#if !defined(_CUSTOMER_CLASS_)
#define _CUSTOMER_CLASS_

class Customer_class : public Index_class {
  private:
    std::string DNI;

  public:
    Employee_class(const std::string = "", int = 0, int = 12, int = 0, int = 0, const std::string& = "AM", const std::string& = "");

    void set_DNI(const std::string& dni) {this->DNI = dni;}

    void show(void) override;
};

#endif
