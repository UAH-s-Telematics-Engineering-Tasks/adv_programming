#include "../inc/Library_includes.h"
#include "../inc_class/P_6_a_Monomial_class.h"
#include "../inc_class/P_6_a_Term_class.h"
#include "../inc_class/P_6_a_Polynom_class.h"

int main(void) {
  Polynom_class B, P, Q, R, S, T, U, V, W, X, Y, Z, N;
  Monomial_class m1, m2(2,2), m3(3,3), m4(4,4);

  std::cout << "Testing the insertion operator (<<)\n\n";
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

  std::cout << "\tP = " << P << '\n';
  std::cout << "\tQ = " << Q << '\n';
  std::cout << "\tR = " << R << '\n';
  std::cout << "\tS = " << S << '\n';
  std::cout << "\tT = " << T << '\n';
  std::cout << "\tU = " << U << '\n';
  std::cout << "\tV = " << V << '\n';
  std::cout << "\tW = " << W << '\n';
  std::cout << "\tX = " << X << '\n';
  std::cout << "\tY = " << Y << '\n';
  std::cout << "\tZ = " << Z << '\n';
  std::cout << "\tN = " << N << '\n';

  std::cout << "Testing the copy constructor\n\n";
  Polynom_class A = P;
  std::cout << "\tA = " << A << '\n';

  std::cout << "Testing the assignment operator\n\n";
  B = Q;
  std::cout << "\tB = " << B << '\n';

  std::cout << "Avoiding an auto-assignment\n\n";
  P = P;
  std::cout << "\tP = " << P << '\n';

  std::cout << "Testing constructor with a coefficient and an exponent\n\n";
  Polynom_class C(2.5, 0);
  Polynom_class D(2.5, 5);
  std::cout << "\tC = " << C << '\n';
  std::cout << "\tD = " << D << '\n';

  std::cout << "Testing the constructor with a monomial\n\n";
  Polynom_class E(Monomial_class(4, 4));
  std::cout << "\tE = " << E << '\n';

  std::cout << "Getting the degree\n\n";
  int deg = U;
  std::cout << "\tPolynom degree: " << deg << '\n';

  std::cout << "Testing the copy constructor\n\n";
  Polynom_class A = P;
  std::cout << "\tA = " << A << '\n';

  /*P << m2;
  std::cout << P << '\n';
  P << m3;
  std::cout << P << '\n';
  P << m4;
  std::cout << P << '\n';
  P << -m4;
  std::cout << P << '\n';*/

}
