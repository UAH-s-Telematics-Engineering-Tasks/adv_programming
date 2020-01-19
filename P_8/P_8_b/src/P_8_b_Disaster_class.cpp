#include "../inc/P_8_b_Disaster_class.h"

/* We need to initialize the attribute in the global scope so that we can access it from each and every method. It also needs to be static so that each object we instantiate uses a coherent value */
int Disaster_class::next_code = 1;

Disaster_class::Disaster_class(const std::string& d) : code{next_code}, descr{d} {
    next_code++;
}

void Disaster_class::show(std::ostream& o_s) const {
    o_s << "\nDisaster code: " << this->code << "\n\tDescription: " << this->descr << "\n\tLabour hours: " << this->repair_worked_hours << "\n\tPiece cost: " << this->piece_cost << "\n\tRepair cost: " << this->cost << "\n";
}