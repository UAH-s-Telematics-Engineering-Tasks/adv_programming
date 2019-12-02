#include "Library_includes.h"

#if !defined(__EXCEPTIONS___)
#define __EXCEPTIONS___

class wrong_n {
    private:
        std::string error_msg;

    public:
        wrong_n(std::string msg = "Error...") : error_msg{msg} {}
        std::string what(void) {return this->error_msg;}
};

#endif