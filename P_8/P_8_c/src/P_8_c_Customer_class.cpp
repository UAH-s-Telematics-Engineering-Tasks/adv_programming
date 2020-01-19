#include "../inc/P_8_c_Customer_class.h"

std::ostream& operator<<(std::ostream& o_s, const Customer_class& cust) {
    o_s << "Customer data:\n\tName: " << cust.get_name() << "\nContracts:\n";
    for (long unsigned int i = 0; i < cust.contracts.size(); i++)
        o_s << cust.contracts[i];
    return o_s;
}

void Customer_class::add_contract(const Contract_class& cont) {
    this->contracts.push_back(cont);
}

Customer_class::operator long() {
    return static_cast<long>(this->contracts.size());
}