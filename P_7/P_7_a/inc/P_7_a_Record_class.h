#include "Library_includes.h"
#include "P_7_a_Employee_class.h"
#include "P_7_a_Customer_class.h"

#if !defined(_RECORD_CLASS_)
#define _RECORD_CLASS_

class Record_class {
  private:
    Index_class* people;
    int max_elements;

  public:
    Record_class(int);

    void set_DNI(const std::string& dni) {this->DNI = dni;}

    void show(void) override;
};

#endif
