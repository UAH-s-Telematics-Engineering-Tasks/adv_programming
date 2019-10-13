#include "../inc/Library_includes.h"
#include "../inc/P_4_a_Hour_class.h"

#define STR_SIZE 15

void view_time(const class Hour_class& t) {
  int h, m, s;
  char tf[STR_SIZE];
  t.get_time(h, m, s, tf);
  std::cout << h << ":" << m << ":" << s << " Format: " << tf;
  std::getchar();
}
