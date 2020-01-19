#if !defined(__ENTERPRISE_CLASS__)
#define __ENTERPRISE_CLASS__

#include "Library_includes.h"

template <class T> class Enterprise_class {
    private:
        T* elm_ptr;
        int n_elm;

    public:
        Enterprise_class() : elm_ptr{NULL}, n_elm{0} {}
        Enterprise_class(const Enterprise_class<T>&);
        Enterprise_class<T>& operator=(const Enterprise_class<T>&);

        void add_element(const T&);
        int size(void) const {return this->n_elm;}
        T& get_elm(int) const;
        T& operator[](int) const;
        void free_arr(void);

        ~Enterprise_class();
};

#include "../template_src/P_8_a_Enterprise_class.cpp"

#endif