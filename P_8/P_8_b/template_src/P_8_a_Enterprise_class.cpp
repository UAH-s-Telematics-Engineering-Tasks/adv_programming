template <class T> Enterprise_class<T>::Enterprise_class(const Enterprise_class<T>& in_obj): elm_ptr{NULL}, n_elm{0} {
    *this = in_obj;
}

template <class T> Enterprise_class<T>& Enterprise_class<T>::operator=(const Enterprise_class<T>& in_obj) {
    if (this != &in_obj) {
        this->free_arr();
        this->n_elm = in_obj.n_elm;
        this->elm_ptr = new (std::nothrow) T[this->n_elm];
        for (int i = 0; i < this->n_elm; i++)
            this->elm_ptr[i] = in_obj.elm_ptr[i];
    }
    return *this;
}

template <class T> void Enterprise_class<T>::free_arr(void) {
    if (this->elm_ptr) {
        delete[] this->elm_ptr;
        this->elm_ptr = NULL;
    }
}

template <class T> void Enterprise_class<T>::add_element(const T& new_elm) {
    if (this->n_elm) {
        Enterprise_class tmp(*this);
        this->free_arr();
        this->n_elm += 1;
        this->elm_ptr = new (std::nothrow) T[this->n_elm];
        for (int i = 0; i < this->n_elm - 1; i++)
            this->elm_ptr[i] = tmp.elm_ptr[i];
        this->elm_ptr[this->n_elm - 1] = new_elm;
    }
    else {
        this->n_elm = 1;
        this->elm_ptr = new (std::nothrow) T[this->n_elm];
        this->elm_ptr[0] = new_elm;
    }
}

template <class T> T& Enterprise_class<T>::get_elm(int index) const {
    if (index >= 0 && index < this->n_elm)
        return this->elm_ptr[index];
    return this->elm_ptr[this->n_elm - 1];
}

template <class T> T& Enterprise_class<T>::operator[](int index) const {
    return this->get_elm(index);
}

template <class T> Enterprise_class<T>::~Enterprise_class() {
    this->free_arr();
}

