#include "../inc/Library_includes.h"
#include "../inc/P_7_a_Employee_class.h"
#include "../inc/P_7_a_Customer_class.h"
#include "../inc/P_7_a_Record_class.h"
#include "../inc/Exceptions.h"

Record_class::Record_class(int n_elms) : people{NULL}, max_elements{n_elms}, next_free{0} {
  //memset(this->people, 0, n_elms * sizeof(Index_class*));
  try {
    if (n_elms <= 0)
      throw wrong_n("The number of elements should be greater than 0!");
  } catch(wrong_n& exc) {
    std::cerr << exc.what() << '\n';
  }
  
    std::cout << "Wrong value for the elements! Initializing people to NULL. Fill me in manually.\n";
  if ((this->people = new (std::nothrow) Index_class*[n_elms]))
    for (int i = 0; i < this->max_elements; i++)
      this->people[i] = NULL;
  else
    std::cout << "Memory allocation error. Leaving max_elements with n_elms value";
}

Record_class::Record_class(const Record_class& init_obj) : people{NULL}, max_elements{0}, next_free{0} {
  *this = init_obj;
}

Record_class& Record_class::operator=(const Record_class& init_obj) {
  if (this != &init_obj) {
    /* Freeing the record here is okay if we are assigning an object that had some memory reserved already (i.e record = *backup). If we are bulding an object through the copy constructor we are making a mistake as we are trying to free memory based on the value of this->people within free_record()... That member hasn't been initialized yet! We could think that calling init_obj.free_record() or doing this->people = init_obj.people and then calling this->free_record() would do the trick. It would work if we wanted to free the assigned object but that's not the case with the copy constructor... We have no other alternative than to explicitly free the memory before the assignment if we want to implement the copy constructor through the assignment operator... As we don't know how to distinguish if the one calling the assignment operator is an object been built or one we have built already... */
    //this->free_record();
    if (!(this->people = new (std::nothrow) Index_class*[init_obj.max_elements]))
      std::cout << "Error while copying...\n";
    for (int i = 0; i < init_obj.max_elements; i++) {
      if (init_obj.people[i])
        this->people[i] = init_obj.people[i]->clone();
      else
        this->people[i] = NULL;
    }
    this->max_elements = init_obj.max_elements;
    this->next_free = init_obj.next_free;
  }
  return *this;
}

bool Record_class::am_i_full(void) {
  return this->people[this->max_elements - 1];
}

bool Record_class::add_person(Index_class* new_obj) {
  if (!new_obj || this->am_i_full())
    return false;
  this->people[this->next_free] = new_obj->clone();
  this->next_free++;
  return true;
}

void Record_class::show_record(void) {
  for (int i = this->next_free - 1; i >= 0; i--)
    this->people[i]->show();
}

bool Record_class::is_employee(Index_class* in_person) {
  /* This is the idea but it might be wrong... Check it! */
  return dynamic_cast<Employee_class*>(in_person);
}

void Record_class::show_employees(void) {
  for (int i = this->next_free - 1; i >= 0; i--)
    /* Can I call a static method like this? Better check... */
    if (Record_class::is_employee(this->people[i]))
      this->people[i]->show();
}

Index_class* Record_class::operator[](int index) {
  if (index < this->max_elements && index >= 0)
    return this->people[index];
  return NULL;
}

void Record_class::free_record(void) {
  if (this->people) {
      for (int i = 0; i < this->max_elements; i++)
        if(this->people[i])
          delete this->people[i];
      delete[] this->people;
      this->people = NULL;
    }
}

Record_class::~Record_class() {
  this->free_record();
}
