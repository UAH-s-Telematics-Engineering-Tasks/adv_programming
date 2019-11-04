#include "../inc/Library_includes.h"
#include "../inc_class/P_6_a_Monomial_class.h"
#include "../inc_class/P_6_a_Term_class.h"
#include "../inc_class/P_6_a_Polynom_class.h"

int main(void) {
  Polynom_class B, P, Q, R, S, T, U, V, W, X, Y, Z, N;
  Monomial_class m1, m2(2,2), m3(3,3), m4(4,4);

  std::cout << "Testing the insertion operator (<<)\n";
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
  std::cout << "\tN = " << N << "\n\n";

  std::cout << "Testing the copy constructor (A = P)\n";
  Polynom_class A = P;
  std::cout << "\tA = " << A << "\n\n";

  std::cout << "Testing the assignment operator (B = Q)\n";
  B = Q;
  std::cout << "\tB = " << B << "\n\n";

  std::cout << "Avoiding an auto-assignment (P = P)\n";
  P = P;
  std::cout << "\tP = " << P << "\n\n";

  std::cout << "Testing constructor with a coefficient and an exponent\n";
  Polynom_class C(2.5, 0);
  Polynom_class D(2.5, 5);
  std::cout << "\tC = " << C << '\n';
  std::cout << "\tD = " << D << "\n\n";

  std::cout << "Testing the constructor with a monomial\n";
  Polynom_class E(Monomial_class(4, 4));
  std::cout << "\tE = " << E << "\n\n";

  std::cout << "Getting the degree\n";
  int deg = U;
  std::cout << "\tPolynom degree (U): " << deg << "\n\n";

  std::cout << "Testing the vector constructor\n";
  std::vector<Monomial_class> m_v {m4, m3, m2};
  Polynom_class F(m_v);
  std::cout << "\tF = " << F << "\n\n";

  std::cout << "Testing the > operator\n";
  std::cout << "\tP = " << P << '\n';
  std::cout << "\tU = " << U << '\n';
  if (P > U)
    std::cout << "\tP has a higher degree than U\n\n";
  else
    std::cout << "\tU has a higher degree than P\n\n";

  std::cout << "Testing the == operator\n";
  std::cout << "\tP = " << P << '\n';
  std::cout << "\tQ = " << Q << '\n';
  if (P == Q)
    std::cout << "\tP has the same degree as Q\n\n";
  else
    std::cout << "\tP doesn't have the same degree as Q\n\n";

  std::cout << "Testing the - unary operator\n";
  std::cout << "\tQ = " << Q << '\n';
  std::cout << "\t-Q = " << -Q << "\n\n";

  std::cout << "Testing the + operator\n";
  std::cout << "\tN = " << N << '\n';
  std::cout << "\tU = " << U << '\n';
  std::cout << "\tN + U = " << N + U << "\n\n";

  std::cout << "Testing the - and += operators\n";
  std::cout << "\tR = " << R << '\n';
  std::cout << "\tS = " << S << '\n';
  std::cout << "\tR - S = " << R - S << '\n';
  std::cout << "\tR += S = " << (R += S) << "\n\n";

  std::cout << "Testing the -= operator\n";
  std::cout << "\tN = " << N << '\n';
  std::cout << "\tY = " << Y << '\n';
  std::cout << "\tN -= Y" << (N -= Y) << "\n\n";

  std::cout << "Testing the [] operator\n";
  std::cout << "\tP = " << P << '\n';
  std::cout << "\tCoefficient @ P[4]: " << P[4] << "\n\n";

  std::cout << "Testing the () operator\n";
  std::cout << "\tU = " << U << '\n';
  std::cout << "\tU(0.5) = " << U(0.5) << "\n\n";

  std::cout << "Testing the * operator\n";
  std::cout << "\tP = " << P << '\n';
  std::cout << "\tS = " << S << '\n';
  std::cout << "\tP * S = " << P * S << "\n\n";

  std::cout << "Testing the *= operator\n";
  std::cout << "\tP = " << P << '\n';
  std::cout << "\tQ = " << Q << '\n';
  std::cout << "\tP *= Q: " << (P *= Q) << "\n\n";


  /*P << m2;
  std::cout << P << '\n';
  P << m3;
  std::cout << P << '\n';
  P << m4;
  std::cout << P << '\n';
  P << -m4;
  std::cout << P << '\n';*/

}
