#include "../inc/Library_includes.h"
#include "../inc/P_3_a_Hour_class.h"
#include "../inc/Constants.h"

void view_time(const class Hour_class& t) {
  int h, m, s;
  char tf[STR_SIZE];
  t.get_time(h, m, s, tf);
  std::cout << h << ":" << m << ":" << s << " Format: " << tf;
  std::getchar();
}
