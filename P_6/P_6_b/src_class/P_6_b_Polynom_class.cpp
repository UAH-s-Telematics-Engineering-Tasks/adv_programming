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
    for (long unsigned int i = 0; i < this->poly.size(); i++)
      out_stream << poly[i] << ' ';
}

Polynom_class& Polynom_class::operator<<(const Monomial_class& monomial) {
  int exp = monomial.get_exp(); // Reduce the number of accesses...

  if (!monomial.get_coeff())
    return *this;

  if (!this->poly.size()) {
    this->poly.push_back(monomial);
    return *this;
  }
  else
    for (long unsigned int i = 0; i < this->poly.size(); i++) {
      if (this->poly[i].get_exp() < exp) {
        this->poly.insert(this->poly.begin() + i, monomial);
        return *this;
      }
      if (this->poly[i].get_exp() == exp) {
        double new_coeff = this->poly[i].get_coeff() + monomial.get_coeff();
        if (new_coeff)
          this->poly[i].set_coeff(new_coeff);
        else
          this->poly.erase(this->poly.begin() + i);
        return *this;
      }
    }
  this->poly.push_back(monomial);
  return *this;
}

Polynom_class::operator int() {
  if (this->poly.size())
    return this->poly[0].get_exp();
  else
    return 0;
}

bool Polynom_class::operator>(const Polynom_class& input) {
  return this->poly[0].get_exp() > input.poly[0].get_exp();
}

bool Polynom_class::operator<(const Polynom_class& input) {
  return this->poly[0].get_exp() < input.poly[0].get_exp();
}

bool Polynom_class::operator==(const Polynom_class& input) {
  return this->poly[0].get_exp() == input.poly[0].get_exp();
}

Polynom_class Polynom_class::operator-(void) const {
  std::vector<Monomial_class> poly_vec = this->poly;
  for (long unsigned int i = 0; i < poly_vec.size(); i++)
    poly_vec[i].set_coeff(-poly_vec[i].get_coeff());
  return Polynom_class(poly_vec);
}

const Polynom_class Polynom_class::operator+(const Polynom_class& input) {
  Polynom_class new_poly(this->poly);
  for (long unsigned int i = 0; i < input.poly.size(); i++)
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
  for (long unsigned int i = 0; i < this->poly.size(); i++)
    if (this->poly[i].get_exp() == exp)
      return this->poly[i].get_coeff();
  return 0;
}

double Polynom_class::operator()(double x) {
  double sum = 0;
  for (long unsigned int i = 0; i < this->poly.size(); i++)
    sum += (this->poly[i].get_coeff() * pow(x, this->poly[i].get_exp()));
  return sum;
}

const Polynom_class Polynom_class::operator*(const Polynom_class& input) {
  Polynom_class new_poly;
  for (long unsigned int i = 0; i < input.poly.size(); i++)
    for (long unsigned int k = 0; k < this->poly.size(); k++)
      new_poly << Monomial_class(input.poly[i].get_coeff() * this->poly[k].get_coeff(), input.poly[i].get_exp() + this->poly[k].get_exp());
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
