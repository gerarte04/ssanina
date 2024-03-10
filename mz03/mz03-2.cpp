namespace numbers {
    class complex_stack
    {
        struct elem
        {
            complex el;
            elem *next;
        };
        
        size_t sz = 0;
        elem *st = nullptr;
    public:
        complex_stack() { }
        complex_stack(const complex_stack &stack)
        {
            sz = stack.sz;
            elem *source = stack.st;
            elem *copy = nullptr;

            if (source != nullptr) {
                copy = new elem;
            }

            st = copy;

            while (source != nullptr) {
                copy->el = source->el;
                copy->next = nullptr;

                source = source->next;

                if (source != nullptr) {
                    copy->next = new elem;
                    copy = copy->next;
                }
            }
        }
        complex_stack & operator= (const complex_stack &stack)
        {
            sz = stack.sz;
            elem *source = stack.st;
            elem *copy = nullptr;

            if (source != nullptr) {
                copy = new elem;
            }

            st = copy;

            while (source != nullptr) {
                copy->el = source->el;
                copy->next = nullptr;

                source = source->next;

                if (source != nullptr) {
                    copy->next = new elem;
                    copy = copy->next;
                }
            }

            return *this;
        }
        ~complex_stack()
        {
            elem *temp, *cur = st;

            while (cur != nullptr) {
                temp = cur->next;
                delete cur;
                cur = temp;
            }
        }
        size_t size() const { return sz; }
        const complex operator[] (size_t i) const
        {
            elem *temp = st;

            for (i++; i < sz; i++) {
                temp = temp->next;
            }

            return temp->el;
        }
        complex_stack operator<< (const complex &a) const
        {
            complex_stack new_st = *this;
            elem *new_elem = new elem;
            new_elem->el = a;
            new_elem->next = new_st.st;
            new_st.st = new_elem;
            new_st.sz++;
            return new_st;
        }
        complex operator+ () const
        {
            return st->el;
        }
        complex_stack operator~ () const
        {
            complex_stack new_st = *this;
            elem *new_top = new_st.st->next;
            delete new_st.st;
            new_st.st = new_top;
            new_st.sz--;
            return new_st;
        }
    };
}
