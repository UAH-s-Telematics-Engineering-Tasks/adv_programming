#if !defined(__NORMAL_DISASTER_CLASS__)
#define __NORMAL_DISASTER_CLASS__

#include "P_8_b_Disaster_class.h"

class Normal_disaster_class : public Disaster_class {
    private:
        static float worked_hour_price;
    public:
        Normal_disaster_class(const std::string& = "No description...");

        void compute_budget(float = 0.5f, float = 0) override;
        void show(std::ostream& os = std::cout) const override;
        Normal_disaster_class* clone() const override;
        float get_budget(void) const override;
};

#endif