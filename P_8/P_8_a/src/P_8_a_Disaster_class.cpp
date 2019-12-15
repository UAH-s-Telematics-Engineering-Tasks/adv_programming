#include "../inc/P_8_a_Disaster_class.h"

/* We need to initialize the attribute in the global scope so that we can access it from each and every method. It also needs to be static so that each object we instantiate uses a coherent value */
int Disasaster_class::next_code = 1;

void Disasaster_class::show(std::ostream& o_s) const {
    os << "\nDisaster code: " << this->code << "\n\tDescription: " << this->descr << "\n\tLabour hours: " << this->repair_worked_hours << "\n\tPiece cost: " << this->piece_cost << "\n\tRepair cost: " << this->cost << "\n";
}