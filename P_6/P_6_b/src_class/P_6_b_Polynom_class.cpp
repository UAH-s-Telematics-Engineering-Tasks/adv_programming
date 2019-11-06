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
  else
    for (int i = 0; i < this->poly.size(); i++)
      out_stream << poly[i] << ' ';
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
  if (this->poly.size())
    return this->poly[0].get_exp();
  else
    return 0;
}

bool Polynom_class::operator>(const Polynom_class& input) {
  return this->poly[0].get_exp() > input.poly.get_exp();
}

bool Polynom_class::operator<(const Polynom_class& input) {
  return this->poly[0].get_exp() < input.poly[0].get_exp();
}

bool Polynom_class::operator==(const Polynom_class& input) {
  return this->poly[0].get_exp() == input.poly[0].get_exp();
}

Polynom_class Polynom_class::operator-(void) const {
  std::vector<Monomial_class> poly_vec = this->poly;
  for (int i = 0; i < poly_vec.size(); i++)
    poly_vec[i].set_coeff(-poly_vec[i].get_coeff());
  return Polynom_class(poly_vec);
}

const Polynom_class Polynom_class::operator+(const Polynom_class& input) {
  Polynom_class new_poly(this->poly);
  for (int i = 0; i < input.poly.size(); i++)
    new_poly << input.poly[i];
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
  for (int i = 0; i < this->poly.size(); i++)
    if (this->poly[i].get_exp() == exp)
      return this->poly[i].get_coeff();
  return 0;
}

double Polynom_class::operator()(double x) {
  double sum = 0;
  for (int i = 0; i < this->poly.size(); i++)
    sum += (this->poly[i].get_coeff() * pow(x, this->poly[i].get_exp()));
  return sum;
}

const Polynom_class Polynom_class::operator*(const Polynom_class& input) {
  Term_class* in_ptr = input.polynom_head, *my_ptr = NULL;
  Polynom_class new_poly;
  for (int i = 0; i < input.poly.size(); i++)
    for (int k = 0; k < this->poly.size(); k++)
      new_poly << Monomial_class(input.poly[i].get_coeff() * this->poly[i].get_coeff(), input.poly[i].get_exp() + this->poly[i].get_exp());
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
