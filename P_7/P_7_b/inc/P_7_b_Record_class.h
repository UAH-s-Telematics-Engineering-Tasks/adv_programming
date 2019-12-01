#include "Library_includes.h"
#include "P_7_b_Employee_class.h"
#include "P_7_b_Customer_class.h"

#if !defined(_RECORD_CLASS_)
#define _RECORD_CLASS_

class Record_class {
  private:
    std::vector<Index_class*> people;

  public:
    Record_class(int = 0);
    Record_class(const Record_class&);
    Record_class& operator=(const Record_class&);

    int get_entries(void);

    bool add_person(Index_class*);

    void show_record(void);
    void show_employees(void);

    static bool is_employee(Index_class*);

    Index_class* operator[](int);

    void free_record(void);
    ~Record_class();
};

#endif
