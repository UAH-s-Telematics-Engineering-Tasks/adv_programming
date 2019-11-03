#include "../inc/Library_includes.h"
#include "../inc_class/P_6_a_Monomial_class.h"
#include "../inc_class/P_6_a_Term_class.h"
#include "../inc_class/P_6_a_Polynom_class.h"

int main(void) {
  Polynom_class P, Q, R, S, T, U, V, W, X, Y, Z, N;
  Monomial_class m1, m2(2,2), m3(3,3), m4(4,4);

  P << m1 << m2 << -m4 << m3;
  Q << m4 << m1 << m2 << -m3;
  R << m3 << m4 << -m2;
  S << m2 << m3 << m4 << -m2;
  T << -m2 << -m3 << -m4 << m3;
  U << m2 << m3 << m4 << -m4;
  V << m2 << m3 << m4 << -m2 << -m3 << -m4;
  W << m2 << m3 << -m2 << -m3;
  X << m2 << -m2;
  Y << m2 << m3 << m4 << m2;
  Z << -m2 << -m3 << -m4 << -m3;
  N << m2 << m3 << m4 << m4;

  std::cout << "P = " << P << '\n';
  std::cout << "Q = " << Q << '\n';
  std::cout << "R = " << R << '\n';
  std::cout << "S = " << S << '\n';
  std::cout << "T = " << T << '\n';
  std::cout << "U = " << U << '\n';
  std::cout << "V = " << V << '\n';
  std::cout << "W = " << W << '\n';
  std::cout << "X = " << X << '\n';
  std::cout << "Y = " << Y << '\n';
  std::cout << "Z = " << Z << '\n';
  std::cout << "N = " << N << '\n';

  /*P << m2;
  std::cout << P << '\n';
  P << m3;
  std::cout << P << '\n';
  P << m4;
  std::cout << P << '\n';
  P << -m4;
  std::cout << P << '\n';*/

}
