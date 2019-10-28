#include "../inc/P_6_a_Monomial_class.h"

std::ostream& operator<<(std::ostream& out_stream, const Monomial_class& monomial) {
  switch (monomial.get_exp()) {
    case 0:
      return (monomial.get_coeff() > 0 ? out_stream << "+" << monomial.get_coeff() : out_stream << monomial.get_coeff());

    case 1:
      return (monomial.get_coeff() > 0 ? out_stream << "+" << monomial.get_coeff() << "*" << "X" : out_stream << monomial.get_coeff() << "*" << "X");

    default:
      return (monomial.get_coeff() > 0 ? out_stream << "+" << monomial.get_coeff() << "*" << "X^" << monomial.get_exp() : out_stream << monomial.get_coeff() << "*" << "X^" << monomial.get_exp());
  }
}
