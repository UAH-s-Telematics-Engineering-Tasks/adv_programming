

#if !defined(__NORMAL_DISASTER_CLASS__)
#define __NORMAL_DISASTER_CLASS__

class Normal_disaster_class : public Disaster_class {
    private:
        static float worked_hour_price;
    public:
        Normal_disaster_class(const string& = "No description...");

        void compute_budget(float = 0.5f, float = 0) override;
        void show(ostream& os = cout) const override;
        Normal_disaster_class* clone() const override;
        float get_budget(void) const override;
};

#endif