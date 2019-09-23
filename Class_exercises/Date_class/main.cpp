#include "date_class.h"

int main(void) {
  Date_class date;
  int day, month, year;

  read_date(day, month, year);

  date.assign_date(day, month, year);

  show_date(date);

  return 0;

}

void read_date(int& d, int& m, int& y) {
  std::cout << "Input a date (d m y): ";
  std::cin >> d; std::cin >> m; std::cin >> y;
}

void show_date(/*const*/ Date_class& my_date) {
  int day, month, year;
  my_date.get_date(day, month, year);
  std::cout << "Today's date is: " << day << "/" << month << "/" << year << '\n';
}
