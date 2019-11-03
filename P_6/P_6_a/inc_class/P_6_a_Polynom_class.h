#include "P_6_a_Monomial_class.h"
#include "P_6_a_Term_class.h"
#include "../inc/Library_includes.h"

#if !defined(__POLYNOM_CLASS__)
#define __POLYNOM_CLASS__

class Polynom_class {
  private:
    Term_class* polynom_head;

  public:
    Polynom_class();
    Polynom_class(const Polynom_class&);
    Polynom_class(double coeff, int exp = 0);
    Polynom_class(const Monomial_class&);

    void show_polynom(std::ostream&) const;
    Polynom_class& operator<<(const Monomial_class&);

    ~Polynom_class();

};

std::ostream& operator<<(std::ostream&, const Polynom_class&);

#endif
