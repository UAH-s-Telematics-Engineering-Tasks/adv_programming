#include "../inc/P_8_c_Normal_disaster_class.h"

float Normal_disaster_class::worked_hour_price = 2.5;

Normal_disaster_class::Normal_disaster_class(const std::string& d) : Disaster_class{d} {}

Normal_disaster_class* Normal_disaster_class::clone(void) const {
    return new (std::nothrow) Normal_disaster_class(*this);
}

void Normal_disaster_class::show(std::ostream& o_s) const {
    Disaster_class::show(o_s);
    o_s << "\nLabour cost per hour: " << this->worked_hour_price << "\n\n";
}

/* If we are to access a variable directly using "dot notation" (i.e through "this") then we need to be using a PROTECTED attribute, otherwise it won't be accessible to the derived classes... The thing is we could declare "cost" as a private member in the base class because we happen to have a method that lets us retreive its value: get_cost(). Nevertheless this approach would let us GET the value of said attribute but we wouldn't be able to assign a new value to it... Unless we declare a method like set_cost() OR we use the default assignment operator explicitly through Disaster_class::operator=(). Summing up: If we want to declare "cost" as a private attribute we MUST define a set_cost() method or we need to use the default assignment operator to achieve the desired functionality. */

void Normal_disaster_class::compute_budget(float hours, float pieces) {
    this->repair_worked_hours = hours;
    this->piece_cost = pieces;
    this->cost = this->repair_worked_hours * this->worked_hour_price + this->piece_cost;
}

float Normal_disaster_class::get_budget(void) const {
    return this->cost;
}