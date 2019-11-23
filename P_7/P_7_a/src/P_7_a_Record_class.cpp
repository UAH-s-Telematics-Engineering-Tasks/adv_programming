#include "Library_includes.h"
#include "P_7_a_Employee_class.h"
#include "P_7_a_Customer_class.h"

Record_class::Record_class(int n_elms) : max_elements{n_elms}, people{NULL} {
  if (n_elms <= 0)
    std::cout << "Wrong value for the elements! Initializing people to NULL. Fill me in manually.\n"
  if (this->people = new (std::nothrow) Index_class*[n_elms])
    memset(this->people, 0, n_elms * sizeof(Index_class*));
  else
    std::cout << "Memory allocation error. Leaving max_elements with n_elms value";
}
