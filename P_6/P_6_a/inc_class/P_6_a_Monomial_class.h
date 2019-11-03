#include "../inc/Library_includes.h"

#if !defined(__MONOMIAL_CLASS__)
#define __MONOMIAL_CLASS__

class Monomial_class {
  private:
    double coefficient;
    int exponent;

  public:
    Monomial_class(double coeff = 0, int exp = 0) : coefficient{coeff}, exponent{exp} {}

    double get_coeff(void) const {return this->coefficient;}
    int get_exp(void) const {return this->exponent;}
    void set_coeff(double coeff) {this->coefficient = coeff;}
    void set_exp(int exp) {this->exponent = exp;}

    Monomial_class operator-(void) const {return Monomial_class(-(this->coefficient), this->exponent);}
};

std::ostream& operator<<(std::ostream&, const Monomial_class&);

#endif
