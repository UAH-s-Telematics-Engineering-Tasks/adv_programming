#include "../inc/P_8_a_Customer_class.h"

std::ostream& operator<<(std::ostream& o_s, const Customer_class& cust) {
    o_s << "Customer data:\n\tName: " << cust.get_name() << "\nContracts:\n";
    o_s << this->contracts.get_first();
    while(this->contracts.is_there_more())
        o_s << this->contracts.get_curr();
    return o_s;
}

void Customer_class::add_contract(const Contract_class& cont) {
    this->contracts.add_element(cont);
}

Customer_class::operator long() {
    long n_elms = 0;
    if (!this->contracts.am_i_empty()) {
        n_elms++;
        this->contracts.get_first();
        while (this->contracts.is_there_more()) {
            n_elms++;
            this->contracts.get_curr();
        }
        return n_elms++;
    }
    return n_elms;
}