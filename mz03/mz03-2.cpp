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
                copy->el = complex(source->el.re(), source->el.im());
                copy->next = nullptr;

                source = source->next;

                if (source != nullptr) {
                    copy->next = new elem;
                    copy = copy->next;
                }
            }
        }

        ~complex_stack()
        {
            elem *temp;

            while (st != nullptr) {
                temp = st;
                st = st->next;
                delete temp;
            }
        }
        size_t size() const { return sz; }
        const complex & operator[] (size_t i) const
        {
            elem *el = st;

            for (i++; i < sz; i++) {
                el = el->next;
            }

            return el->el;
        }
        friend complex_stack operator<< (const complex_stack &cs, const complex &a)
        {
            complex_stack new_st = cs;
            elem *new_elem = new elem;
            new_elem->el = complex(a.re(), a.im());
            new_elem->next = new_st.st;
            new_st.st = new_elem;
            new_st.sz++;
            return new_st;
        }
        complex & operator+ () const
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
