#include "../inc/Library_includes.h"
#include "../inc/P_5_Hour_class.h"

void view_time(const class Hour_class& t) {
  int h, m, s;
  std::string tf;
  t.get_time(h, m, s, tf);
  std::cout << h << ":" << m << ":" << s << " Format: " << tf;
  std::getchar();
}
