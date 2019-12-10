

#if !defined(__LIST_CLASS__)
#define __LIST_CLASS__

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
        bool am_i_empty(void) const {return !first_elm;}
        bool is_there_more(void) const {return curr_elm;}
        void add_object(const T&);
        void empty(void);
        void restart(void) const;
        T& get_first(void) const;
        T& get_curr(void) const;

        ~List_class();
};

#endif