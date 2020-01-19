#include "../inc/P_8_c_Contract_class.h"

Contract_class::Contract_class(int s_n, const std::string& d, const std::string& e_d, long p, long p_v) : serial_number{s_n}, descr{d}, end_date{e_d}, policy{p}, purchase_value{p_v} {}

Contract_class::Contract_class(const Contract_class& in_obj) {
    *this = in_obj;
}

Contract_class& Contract_class::operator=(const Contract_class& in_obj) {
    if (this != &in_obj) {
        if (!this->disasters.empty())
            this->delete_contracts();
        this->serial_number = in_obj.serial_number;
        this->descr = in_obj.descr;
        this->end_date = in_obj.end_date;
        this->policy = in_obj.policy;
        this->purchase_value = in_obj.purchase_value;
        for (long unsigned int i = 0; i < in_obj.disasters.size(); i++)
            this->add_disaster(*in_obj.disasters[i]);
    }
    return *this;
}

void Contract_class::add_disaster(const Disaster_class& disaster) {
    this->disasters.push_back(std::unique_ptr<Disaster_class>(disaster.clone()));
}

void Contract_class::show_disasters(std::ostream& o_s) const {
    if (this->disasters.empty())
        o_s << "No disasters in this contract!\n";
    else
        for (long unsigned int i = 0; i < this->disasters.size(); i++)
            this->disasters[i]->show(o_s);
}

void Contract_class::delete_contracts(void) {
    this->disasters.clear();
}

std::ostream& operator<<(std::ostream& o_s, const Contract_class& c) {
    o_s << "\tSerial number: " << c.serial_number << "\n\tDescription: " << c.descr << "\n\tEnd date: " << c.end_date << "\n\tPolicy: " << c.policy << "\t\nPurchase value: " << c.purchase_value;
    c.show_disasters();
    return o_s;
}