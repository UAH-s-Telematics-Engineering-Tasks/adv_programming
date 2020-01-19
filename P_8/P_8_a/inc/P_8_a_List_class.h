#if !defined(__LIST_CLASS__)
#define __LIST_CLASS__

#include "Library_includes.h"
#include "P_8_a_Node_class.h"

template<typename T> class Node_class;

template <class T> class List_class {
    private:
        Node_class<T>* first_elm;
        Node_class<T>* curr_elm;
        Node_class<T>* last_elm;
    public:
        List_class();
        List_class(const T&);
        List_class(const List_class<T>&);

        List_class<T>& operator=(const List_class<T>&);
        bool am_i_empty(void) const {return !this->first_elm;}
        bool is_there_more(void) const {return this->curr_elm;}
        void add_element(const T&);
        void empty(void);
        void restart(void) const;
        T& get_curr(void) const;
        T& get_first(void) const;

        T& operator[](int);

        ~List_class();
};

#include "../template_src/P_8_a_List_class.cpp"

#endif