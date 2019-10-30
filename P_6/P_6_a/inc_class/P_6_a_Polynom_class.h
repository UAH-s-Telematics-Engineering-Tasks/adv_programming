#include ".h"

#if !defined(__POLYNOM_CLASS__)
#define __POLYNOM_CLASS__

class Polynom_class {
  private:
    Term_class* polynom_head;

  public:
    Polynom_class();
    Polynom_class(double coeff, int exp = 0) : polynom_head{NULL} {}
    Polynom_class(const Term_class&);

    ~Polynom_class();

};

std::ostream& operator<<(std::ostream&, const Polynom_class&);

#endif
