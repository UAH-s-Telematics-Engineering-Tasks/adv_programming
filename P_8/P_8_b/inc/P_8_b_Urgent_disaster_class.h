

#if !defined(__URGENT_DISASTER_CLASS__)
#define __URGENT_DISASTER_CLASS__

#include "P_8_b_Disaster_class.h"

enum locations {
    local, national, international
};

class Urgent_disaster_class : public Disaster_class {
    private:
        locations location;
        static float urgency_cost;
        static float worked_hour_price;

    public:
        Urgent_disaster_class(const std::string& = "No description...", locations = local);

        void compute_budget(float = 0.5f, float = 0) override;
        void show (std::ostream& = std::cout) const override;
        Urgent_disaster_class* clone(void) const override;
        float get_budget(void) const override;
};

#endif