#include "../inc/P_8_a_Exceptions.h"
#include "../inc/Library_includes.h"

template <class T> List_class<T>::List_class() : first_elm{NULL}, curr_elm{NULL}, last_elm{NULL} {}

template <class T> List_class<T>::List_class(const T& in_obj) {
    this->first_elm = this->curr_elm = this->last_elm = new (std::nothrow) Node_class<T>(in_obj);
}

template <class T> List_class<T>::List_class(const List_class<T>& in_obj) {
    *this = in_obj;
}

template <class T> List_class<T>& List_class<T>::operator=(const List_class<T>& in_obj) {
    this->empty();
    if (!in_obj.am_i_empty() && this != &in_obj) {
        this->first_elm = this->curr_elm = this->last_elm = new (std::nothrow) Node_class<T>(in_obj.get_first());
        while (in_obj.is_there_more()) {
            this->curr_elm->set_next_node(new (std::nothrow) Node_class<T>(in_obj.get_curr()));
            this->last_elm = this->curr_elm = this->curr_elm->get_next_node();
        }
    }
    return *this;
}

template <class T> void List_class<T>::add_element(const T& in_obj) {
    if (this->am_i_empty())
        this->first_elm = this->curr_elm = this->last_elm = new (std::nothrow) Node_class<T>(in_obj);
    else {
        this->last_elm->set_next_node(new (std::nothrow) Node_class<T>(in_obj));
        this->last_elm = this->last_elm->get_next_node();
    }
    return;
}

template <class T> void List_class<T>::empty(void) {
    Node_class<T>* tmp = this->first_elm, * aux = NULL;
    while(tmp) {
        aux = tmp->get_next_node();
        delete tmp;
        tmp = aux;
    }
    this->first_elm = this->curr_elm = this->last_elm = NULL;
}

template <class T> void List_class<T>::restart(void) const {
    const_cast<List_class<T>*>(this)->curr_elm = this->first_elm;
}

template <class T> T& List_class<T>::get_curr(void) const {
    Node_class<T>* tmp = this->curr_elm;
    /* We need to remove the constantness with const_cast() or we won't be able to change any attributes... */
    const_cast<List_class<T>*>(this)->curr_elm = this->curr_elm->get_next_node();
    return tmp->get_data();
}

template <class T> T& List_class<T>::get_first(void) const {
    const_cast<List_class<T>*>(this)->curr_elm = this->first_elm->get_next_node();
    return this->first_elm->get_data();
}

template <class T> T& List_class<T>::operator[](int index) {
    Node_class<T>* tmp = this->first_elm;
    int traversed_elms = 0;
    if (index >= 0) {
        while (tmp) {
            if (traversed_elms == index)
                return tmp->get_data();
            tmp = tmp->get_next_node();
            traversed_elms++;
        }
        throw incorrect_index_ex("Index " + std::to_string(index) + " is out of bounds...");
    }
    else
        throw incorrect_index_ex("The index should be greater than 0...");
}

template <class T> List_class<T>::~List_class() {
    if (!this->am_i_empty())
        this->empty();
}
