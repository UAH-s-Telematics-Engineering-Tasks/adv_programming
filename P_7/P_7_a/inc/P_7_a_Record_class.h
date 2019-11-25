#include "Library_includes.h"
#include "P_7_a_Employee_class.h"
#include "P_7_a_Customer_class.h"

#if !defined(_RECORD_CLASS_)
#define _RECORD_CLASS_

class Record_class {
  private:
    Index_class** people;
    int max_elements;
    int next_free;

  public:
    Record_class(int = 0);
    Record_class(const Record_class&);
    Record_class& operator=(const Record_class&);

    int get_max_elements(void) {return this->max_elements;}
    int get_next_free(void) {return this->next_free;}
    bool am_i_full(void);
    bool add_person(Index_class*);


    void show_record(void);
    void show_employees(void);

    static bool is_employee(Index_class*);

    Index_class* operator[](int);

    ~Record_class();
};

#endif
