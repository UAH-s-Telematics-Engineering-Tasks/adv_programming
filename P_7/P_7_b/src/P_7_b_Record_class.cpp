#include "../inc/Library_includes.h"
#include "../inc/P_7_b_Employee_class.h"
#include "../inc/P_7_b_Customer_class.h"
#include "../inc/P_7_b_Record_class.h"

Record_class::Record_class(int n_elms) {
  if (n_elms <= 0)
    std::cout << "Wrong value for the elements! Initializing people to NULL. Fill me in manually.\n";
  this->people.reserve(n_elms);
}

Record_class::Record_class(const Record_class& init_obj) {
  *this = init_obj;
}

Record_class& Record_class::operator=(const Record_class& init_obj) {
  if (this != &init_obj) {
    this->people.resize(init_obj.people.size());
    for (long unsigned int i = 0; i < init_obj.people.size(); i++)
      if (init_obj.people[i])
        this->people[i] = init_obj.people[i]->clone();
  }
  return *this;
}

int Record_class::get_entries(void) {
  return this->people.size();
}

bool Record_class::add_person(Index_class* new_obj) {
  if (!new_obj)
    return false;
  this->people.push_back(new_obj->clone());
  return true;
}

void Record_class::show_record(void) {
  for (long unsigned int i = 0; i < this->people.size(); i++)
    this->people[i]->show();
}

bool Record_class::is_employee(Index_class* in_person) {
  return dynamic_cast<Employee_class*>(in_person);
}

void Record_class::show_employees(void) {
  for (long unsigned int i = 0; i < this->people.size(); i++)
    if (Record_class::is_employee(this->people[i]))
      this->people[i]->show();
}

Index_class* Record_class::operator[](int index) {
  if (static_cast<long unsigned int>(index) < this->people.size() && index >= 0)
    return this->people[index];
  return NULL;
}

void Record_class::free_record(void) {
  if (this->people.size())
    for (long unsigned int i = 0; i < this->people.size(); i++)
      if(this->people[i])
        delete this->people[i];
}

Record_class::~Record_class() {
  this->free_record();
}
