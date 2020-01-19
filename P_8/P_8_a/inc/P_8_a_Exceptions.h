#if !defined(__EXCEPTIONS__)
#define __EXCEPTIONS__

#include "Library_includes.h"

class incorrect_index_ex {
    private:
        std::string err_msg;
    
    public:
        incorrect_index_ex(std::string msg = "Index Exception...") : err_msg{msg} {}
        std::string what(void) {return this->err_msg;}
};

#endif