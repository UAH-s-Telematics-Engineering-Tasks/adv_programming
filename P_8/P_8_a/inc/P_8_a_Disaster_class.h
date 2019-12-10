

#if !defined(__DISASTER_CLASS__)
#define __DISASTER_CLASS__

class CSiniestro {
    private:
        int code;
        static int next_code;
    protected:
        std::string descr;
        float repair_worked_hours;
        float piece_cost;
        float cost;
    public:
        Disaster_class(const string& = "No description...");

        virtual float get_budget() const = 0;
        int get_code() const {return this->code;}
        float get_cost() const {return this->cost;}
        virtual void compute_budget(float, float) = 0;
        virtual void show(ostream& = std::cout) const;
        virtual Disaster_class* clone() const = 0;

        virtual ~Disaster_class() {};
};

#endif