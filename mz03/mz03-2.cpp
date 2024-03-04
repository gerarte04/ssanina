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
        const complex & operator[] (int i) const
        {
            elem *el = st;

            for (i++; i < sz; i++) {
                el = el->next;
            }

            return el->el;
        }
        friend complex_stack & operator<< (complex_stack &cs, const complex &a)
        {
            elem *new_elem = new elem;
            new_elem->el = complex(a.re(), a.im());
            new_elem->next = cs.st;
            cs.st = new_elem;
            cs.sz++;
            return cs;
        }
        complex & operator+ () const
        {
            return st->el;
        }
        complex_stack & operator~ ()
        {
            elem *new_top = st->next;
            delete st;
            st = new_top;
            sz--;
            return *this;
        }
    };
}
