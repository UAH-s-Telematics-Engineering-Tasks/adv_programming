#include "../inc/P_8_a_Contract_class.h"

Contract_class::Contract_class(int s_n, const std::string& d, const std::string& e_d, long p, long p_v) : serial_number{s_n}, descr{d}, end_date{e_d}, policy{p}, purchase_value{p_v} {}

Contract_class::Contract_class(const Contract_class& in_obj) {
    *this = in_obj;
}

Contract_class& Contract_class::operator=(const Contract_class& in_obj) {
    if (this != &in_obj) {
        this->serial_number = in_obj.serial_number;
        this->descr = in_obj.descr;
        this->end_date = in_obj.end_date;
        this->policy = in_obj.policy;
        this->purchase_value = in_obj.purchase_value;
        this->disasters = in_obj.disasters;
    }
    return *this;
}

void Contract_class::add_disaster(Disaster_class& disaster) {
    // Clone needs to be a virtual method so that we can invoke the method for
    // a reference to the base class and still clone the appropriate object. In
    // other words, we need virtual methods to implement polymorphism!
    this->disasters.add_element(*(disaster.clone()))
}

void Contract_class::show_disasters(std::ostream& o_s) {
    if (this->disasters.am_i_empty())
        o_s << "No disasters in this contract\n";
    else {
        this->disasters.get_first()->show(o_s);
        while(this->disasters.is_there_more())
            this->disasters.get_curr()->show(o_s);
    }
}

Contract_class::~Contract_class() {
    if (!this->disasters.am_i_empty()) {
        delete this->disasters.get_first();
        while(this->disasters.is_there_more())
            delete this->disasters.get_curr();
    }
}

std::ostream& operator<<(std::ostream& o_s, Contract_class& c) {
    o_s << "\tSerial number: " << c.serial_number << "\n\tDescription: " << c.descr << "\n\tEnd date: " << c.end_date << "\n\tPolicy: " << c.policy << "\t\nPurchase value: " << c.purchase_value;
    c.show_disasters();
    return o_s;
}