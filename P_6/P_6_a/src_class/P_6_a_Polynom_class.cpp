#include "../inc_class/P_6_a_Monomial_class.h"
#include "../inc_class/P_6_a_Term_class.h"
#include "../inc_class/P_6_a_Polynom_class.h"
#include "../inc/Messages.h"
#include "../inc/Library_includes.h"

/* 1 */
Polynom_class::Polynom_class() : polynom_head{NULL} {}

/* 2 */
Polynom_class::Polynom_class(const Polynom_class& init_poly) : polynom_head{NULL} {
  *this = init_poly;
}

/* 3 */
Polynom_class::Polynom_class(double coeff, int exp) : polynom_head{NULL} {
  if (coeff)
    this->polynom_head = new (std::nothrow) Term_class(coeff, exp);
  else
    std::cout << messages[0] << " Polynom Simple Term Constructor\n";
}

/* 4 */
Polynom_class::Polynom_class(std::vector<Monomial_class> mon_vec) : polynom_head{NULL} {
  for (long unsigned int i = 0; i < mon_vec.size(); i++)
    (*this) << mon_vec[i];
}

/* 5 */
Polynom_class::Polynom_class(const Monomial_class& monomial) : polynom_head{NULL} {
  if (monomial.get_coeff())
  this->polynom_head = new (std::nothrow) Term_class(monomial.get_coeff(), monomial.get_exp());
else
  std::cout << messages[0] << " Polynom Term Based Constructor\n";
}

/* 7 */
Polynom_class& Polynom_class::operator=(const Polynom_class& in_poly) {
  if (this != &in_poly) {
      Term_class* curr = in_poly.polynom_head;
      if (!this->polynom_head) {
        Term_class* next = this->polynom_head, *current;
        while(next) {
          current = next;
          next = current->get_next_term();
          delete current;
        }
        this->polynom_head = NULL;
      }
      while(curr) {
        (*this) << curr->get_monomial();
        curr = curr->get_next_term();
    }
  }
  return *this;
}

void Polynom_class::show_polynom(std::ostream& out_stream) const {
  Term_class* term_ptr = this->polynom_head;
  if(!term_ptr)
    out_stream << "0 ";

  while(term_ptr) {
    out_stream << term_ptr->get_monomial() << ' ';
    term_ptr = term_ptr->get_next_term();
  }
}

Polynom_class& Polynom_class::operator<<(const Monomial_class& monomial) {
  Term_class* curr_ptr = this->polynom_head, *prev_ptr = this->polynom_head, *new_elm = NULL;
  int exp = monomial.get_exp(); // Reduce the number of accesses...

  if (!monomial.get_coeff())
    return (*this);

  if (!curr_ptr) {
    this->polynom_head = new (std::nothrow) Term_class(monomial.get_coeff(), exp);
    return (*this);
  }
  else if (curr_ptr->get_exp() < exp) {
    this->polynom_head = new (std::nothrow) Term_class(monomial.get_coeff(), exp, curr_ptr);
    return (*this);
  }
  else
    while(prev_ptr) {
      if (prev_ptr && !curr_ptr) {
          if ((new_elm = new (std::nothrow) Term_class(monomial.get_coeff(), exp))) {
            prev_ptr->set_next_term(new_elm);
            return (*this);
          }
        }

      else if (curr_ptr->get_exp() == exp) {
        double new_coeff = monomial.get_coeff() + curr_ptr->get_coeff();
        if (new_coeff) {
          curr_ptr->set_coeff(new_coeff);
          return (*this);
        }
      else {
          prev_ptr->set_next_term(curr_ptr->get_next_term());
          if (curr_ptr == this->polynom_head)
            this->polynom_head = curr_ptr->get_next_term();
          delete curr_ptr;
          return (*this);
        }
      }

      else if (prev_ptr->get_exp() > exp && curr_ptr->get_exp() < exp) {
        if ((new_elm = new (std::nothrow) Term_class(monomial.get_coeff(), exp, curr_ptr))) {
          prev_ptr->set_next_term(new_elm);
          return (*this);
        }
      }

      prev_ptr = curr_ptr;
      curr_ptr = curr_ptr->get_next_term();
    }
  std::cout << messages[0] << " Polynom Insertion Operator\n";
  return (*this);
}

/* 6 */
Polynom_class::~Polynom_class() {
  Term_class* next = this->polynom_head, *current;
  while(next) {
    current = next;
    next = current->get_next_term();
    delete current;
  }
}

std::ostream& operator<<(std::ostream& o_stream, const Polynom_class& poly) {
  poly.show_polynom(o_stream);
  return o_stream;
}
