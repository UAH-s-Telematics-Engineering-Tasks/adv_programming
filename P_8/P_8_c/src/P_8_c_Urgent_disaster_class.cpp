#include "../inc/P_8_c_Urgent_disaster_class.h"

float Urgent_disaster_class::urgency_cost = 5;
float Urgent_disaster_class::worked_hour_price = 3.5;

Urgent_disaster_class::Urgent_disaster_class(const std::string& descr, locations l) : Disaster_class{descr}, location{l} {}

Urgent_disaster_class* Urgent_disaster_class::clone(void) const {
    return new (std::nothrow) Urgent_disaster_class(*this);
}

void Urgent_disaster_class::show(std::ostream& o_s) const {
    Disaster_class::show(o_s);
    o_s << "\tLocation: " << this->location << "\n\tUrgency cost: " << this->urgency_cost << "\n\tPrice per hour: " << this->worked_hour_price << "\n\n";
}

void Urgent_disaster_class::compute_budget(float hours, float pieces) {
    this->repair_worked_hours = hours;
    this->piece_cost = pieces;
    this->cost = this->repair_worked_hours * this->worked_hour_price + this->piece_cost + this->urgency_cost;
}

float Urgent_disaster_class::get_budget(void) const {
    return this->cost;
}