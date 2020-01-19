#if !defined(__NODE_CLASS__)
#define __NODE_CLASS__

#include "P_8_a_List_class.h"

template<typename T> class List_class;

template <class T> class Node_class {
    friend List_class<T>;
    private:
        T data;
        Node_class<T>* next_node;
    public:
        Node_class(){this->next_node = NULL;}
        Node_class(const T&, Node_class<T>* = NULL);
        Node_class(const Node_class<T>&);

        Node_class<T>& operator=(const Node_class<T>&);
        Node_class<T>* get_next_node(void) const {return this->next_node;}
        T& get_data() {return this->data;}
        void set_next_node(Node_class<T>* node_ptr) {this->next_node = node_ptr;}
};

#include "../template_src/P_8_a_Node_class.cpp"

#endif