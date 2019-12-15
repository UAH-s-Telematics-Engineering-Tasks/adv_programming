#include "../inc/P_8_a_Node_class.h"

template <class T> Node_class<T>::Node_class(const T& d, Node_class<T>* ptr) : data{d}, next_node{ptr} {}

template <class T> Node_class<T>::Node_class(const Node_class<T>& in_obj) {
    *this = in_obj;
}

template <class T> Node_class<T>& Node_class<T>::operator=(const Node_class<T>& in_obj) {
    this->data = in_obj.data;
}