

#if !defined(__CONTRACT_CLASS__)
#define __CONTRACT_CLASS__

class Contract_class {
    private:
        int serial_number;
        std::string descr;
        std::string end_date;
        long policy;
        long purchase_value;
        List_class<Disaster_class *> disasters;

    public:
        Contract_class(int, const std::string& = "", const string& = "", long = 0, long = 0);
        Contract_class(const Contract_class& c);
        Contract_class& operator=(const Contract_class& c);
        
        void set_serial_number(int sn) {this->serial_number = sn;}
        void set_descr(const std::string& d) {this->descr = d;}
        void set_end_date(const std::string& ed) {this->end_date = ed;}
        void set_policy(long p) {this->policy = p;}
        void set_purchase_value(long pv) {this->purchase_value = pv;}

        int get_serial_number(void) const {return this->serial_number;}
        std::string get_descr(void) const {return this->descr;}
        std::string get_end_date(void) const {return this->end_date;}
        long get_policy(void) const {return this->policy;}
        long get_purchase_value(void) const {return this->purchase_value;}

        void add_disaster(Disaster_class&);
        void show_disasters(std::ostream& = std::cout);

        ~CContrato();
};

#endif