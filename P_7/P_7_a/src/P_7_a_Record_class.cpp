#include "Library_includes.h"
#include "P_7_a_Employee_class.h"
#include "P_7_a_Customer_class.h"

Record_class::Record_class(int n_elms) : max_elements{n_elms}, people{NULL}, next_free{0} {
  if (n_elms <= 0)
    std::cout << "Wrong value for the elements! Initializing people to NULL. Fill me in manually.\n"
  if (this->people = new (std::nothrow) Index_class*[n_elms])
    memset(this->people, 0, n_elms * sizeof(Index_class*));
  else
    std::cout << "Memory allocation error. Leaving max_elements with n_elms value";
}

Record_class::Record_class(const Record_class& init_obj) {
  *this = init_obj;
}

Record_class& Record_class::operator=(const Record_class& init_obj) {
  if (this != &init_obj) {
    if (!(this->people = new (std::nothrow) Index_class*[init_obj.max_elements]))
      std::cout << "Error while copying...\n";
    for (int i = 0; i < init_obj.max_elements; i++)
      if (init_obj.people[i])
        this->people[i] = init_obj.people[i]->clone();
    this->max_elements = init_obj.max_elements;
    this->next_free = init_obj.next_free;
  }
  return *this;
}

bool Record_class::am_i_full(void) {
  return this->people[this->max_elements - 1];
}

bool Record_class::add_person(Index_class* new_obj) {
  if (!new_obj || am_i_full())
    return false;
  this->people[this->next_free] = new_obj->clone();
  this->next_free++;
  return true;
}

void Record_class::show_record(void) {
  for (int i = this->next_free - 1; i <= 0; i++)
    this->people[i]->show();
}

static bool Record_class::is_employee(Index_class* in_person) {
  /* This is the idea but it might be wrong... Check it! */
  return dynamic_cast<Employee_class*>(in_person);
}

void Record_class::show_employees(void) {
  for (int i = this->next_free - 1; i <= 0; i++)
    /* Can I call a static method like this? Better check... */
    if (is_employee(this->people[i]))
      this->people[i]->show();
}

Index_class* Record_class::operator[](int index) {
  if (index < this->next_free && index > 0)
    return this->people[index];
  return NULL;
}

Record_class::~Record_class(void) {
  if (this->people) {
    for (int i = this->next_free - 1; i <= 0; i--)
        delete this->people[i];
    delete[] this->people;
    this->people = NULL;
  }
}
