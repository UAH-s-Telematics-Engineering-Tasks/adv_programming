#include "../inc_class/P_6_b_Monomial_class.h"
#include "../inc_class/P_6_b_Polynom_class.h"
#include "../inc/Messages.h"
#include "../inc/Library_includes.h"

/* 1 */
Polynom_class::Polynom_class() {}

/* 2 */
Polynom_class::Polynom_class(const Polynom_class& init_poly) : poly{init_poly.poly} {}

/* 3 */
Polynom_class::Polynom_class(double coeff, int exp) {
  if (coeff)
    this->poly.push_back(Monomial_class(coeff, exp));
}

/* 4 */
Polynom_class::Polynom_class(std::vector<Monomial_class> mon_vec) : poly{mon_vec} {}

/* 5 */
Polynom_class::Polynom_class(const Monomial_class& monomial) {
  if (monomial.get_coeff())
    this->poly.push_back(monomial);
}

/* 7 */
Polynom_class& Polynom_class::operator=(const Polynom_class& in_polynom) {
  if (this != &in_polynom)
    this->poly = in_polynom.poly;
  return *this;
}

void Polynom_class::show_polynom(std::ostream& out_stream) const {
  if(!this->poly.size())
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

Polynom_class::operator int() {
  return this->polynom_head->get_exp();
}

bool Polynom_class::operator>(const Polynom_class& input) {
  return this->polynom_head->get_exp() > input.polynom_head->get_exp();
}

bool Polynom_class::operator<(const Polynom_class& input) {
  return this->polynom_head->get_exp() < input.polynom_head->get_exp();
}

bool Polynom_class::operator==(const Polynom_class& input) {
  return this->polynom_head->get_exp() == input.polynom_head->get_exp();
}

Polynom_class Polynom_class::operator-(void) const {
  Polynom_class new_poly;
  Term_class* ptr = this->polynom_head;
  while(ptr) {
    new_poly << Monomial_class(-(ptr->get_coeff()), ptr->get_exp());
    ptr = ptr->get_next_term();
  }
  return new_poly;
}

const Polynom_class Polynom_class::operator+(const Polynom_class& input) {
  Polynom_class new_poly = *this;
  Term_class* ptr = input.polynom_head;
  while (ptr) {
    new_poly << ptr->get_monomial();
    ptr = ptr->get_next_term();
  }
  return new_poly;
}

const Polynom_class Polynom_class::operator-(const Polynom_class& input) {
  return *this + (-input);
}

Polynom_class& Polynom_class::operator+=(const Polynom_class& input) {
  *this = *this + input;
  return *this;
}

Polynom_class& Polynom_class::operator-=(const Polynom_class& input) {
  *this = *this - input;
  return *this;
}

double Polynom_class::operator[](int exp) {
  Term_class* ptr = this->polynom_head;
  while (ptr) {
    if (ptr->get_exp() == exp)
      return ptr->get_coeff();
    ptr = ptr->get_next_term();
  }
  return 0;
}

double Polynom_class::operator()(double x) {
  double sum = 0;
  Term_class* ptr = this->polynom_head;
  while(ptr) {
    sum += (ptr->get_coeff() * pow(x, ptr->get_exp()));
    ptr = ptr->get_next_term();
  }
  return sum;
}

const Polynom_class Polynom_class::operator*(const Polynom_class& input) {
  Term_class* in_ptr = input.polynom_head, *my_ptr = NULL;
  Polynom_class new_poly;
  while(in_ptr) {
    my_ptr = this->polynom_head;
    while(my_ptr) {
      new_poly << Monomial_class(in_ptr->get_coeff() * my_ptr->get_coeff(), in_ptr->get_exp() + my_ptr->get_exp());
      my_ptr = my_ptr->get_next_term();
    }
    in_ptr = in_ptr->get_next_term();
  }
  return new_poly;
}

Polynom_class& Polynom_class::operator*=(const Polynom_class& input) {
  *this = *this * input;
  return *this;
}


std::ostream& operator<<(std::ostream& o_stream, const Polynom_class& poly) {
  poly.show_polynom(o_stream);
  return o_stream;
}
