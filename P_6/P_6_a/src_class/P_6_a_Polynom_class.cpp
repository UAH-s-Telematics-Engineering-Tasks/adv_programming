#include "../inc/Polynom_class.h"

Polynom_class::Polynom_class() : polynom_head{NULL} {}

Polynom_class::Polynom_class(double coeff, int exp = 0) : polynom_head{NULL} {
  if (coeff)
    this->polynom_head = new (std::nothrow) Term_class(coeff, exp);
  else
    std::cout << messages[0] << " Polynom Simple Term Constructor\n";
}

Polynom_class::Polynom_class(const Term_class& term) : polynom_head{NULL} {
  if (term.get_coeff())
  this->polynom_head = new (std::nothrow) Term_class(term.get_coeff(), term.get_exp());
else
  std::cout << messages[0] << " Polynom Term Based Constructor\n";
}

~Polynom_class() {
  Term_class* next = this->polynom_head, current;
  while(next) {
    current = next;
    next = (*current).get_next_term();
    delete current;
  }
}
