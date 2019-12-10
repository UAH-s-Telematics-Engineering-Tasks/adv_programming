

#if !defined(__URGENT_DISASTER_CLASS__)
#define __URGENT_DISASTER_CLASS__

enum locations {
    local, nacional, internacional
};

class Urgent_disaster_class : public Disaster_class {
    private:
        locations location;
        static float urgency_cost;
        static float worked_hour_price;

    public:
        Urgent_disaster_class(locations, const string& = "No description...");

        void compute_budget(float = 0.5f, float = 0) override;
        void show (ostream& = std::cout) const override;
        Urgent_disaster_class* clone(void) const override;
        float get_budget(void) const;
};

#endif