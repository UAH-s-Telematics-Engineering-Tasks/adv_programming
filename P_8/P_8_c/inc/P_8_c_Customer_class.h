#if !defined(__CUSTOMER_CLAS__)
#define __CUSTOMER_CLAS__

#include "Library_includes.h"
#include "P_8_c_Contract_class.h"

class Customer_class {
    friend std::ostream& operator<<(std::ostream&, const Customer_class&);
    private:
        std::string name;
        std::vector<Contract_class> contracts;
    
    public:
        Customer_class(const std::string& n = "No name") : name{n} {};
        Customer_class(const std::string&, Contract_class&);
        void set_name(const std::string& n) {this->name = n;}
        std::string get_name(void) const {return this->name;}
        void add_contract(const Contract_class&);

        operator long();
};

std::ostream& operator<<(std::ostream&, const Customer_class&);

#endif