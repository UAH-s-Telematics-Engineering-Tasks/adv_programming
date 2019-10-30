#include "P_6_a_Monomial_class.h"

#if !defined(__TERM_CLASS__)
#define __TERM_CLASS__

class Term_class {
  private:
    Monomial_class monomial;
    Term_class* next_term;

  public:
    Term_class(double coeff = 0, int exp = 0, Term_class* next = NULL) : monomial{coeff, exp}, next_term{next} {}
    Term_class(const Monomial_class& mono, Term_class* next = NULL) : monomial{mono.get_coeff(), mono.get_exp()}, next_term{next} {}
    Term_class(const Term_class& term, Term_class* next = NULL) : monomial{term.get_monomial()}, next_term{next} {}

    double get_coeff(void) const {return this->monomial.get_coeff();}
    int get_exp(void) const {return this->monomial.get_exp();}
    Monomial_class get_monomial(void) const {return this->monomial;}
    Term_class* get_next_term(void) const {return this->next_term;}

    void set_coeff(double coeff) {this->monomial.set_coeff(coeff);}
    void set_exp(int exp) {this->monomial.set_coeff(coeff);}
    void set_monomial(const Monomial_class& mono) {this->monomial = mono;}
    void set_next_term(Term_class* next) {this->next_term = next;}
};

#endif
