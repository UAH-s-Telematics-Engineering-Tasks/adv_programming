#if !defined(_DATE_H_)
#define _DATE_H_

class Date {
private:
  int day, month, year;

protected:
  bool leap_year(int);
  bool valid_date(int, int, int);

public:
  void assign_date(int, int, int);
  void get_date(int&, int&, int&);
};

#endif
