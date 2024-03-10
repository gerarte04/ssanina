namespace numbers {
    constexpr int DFL_CAP = 16;
    
    class complex_stack
    {
        size_t sz;
        size_t cap;
        complex *arr = nullptr;
    public:
        complex_stack(size_t cap = DFL_CAP, size_t sz = 0) : sz(sz), cap(cap), arr(new complex[cap]) { }
        complex_stack(const complex_stack &stack) : sz(stack.sz), cap(stack.cap)
        {
            delete[] arr;
            arr = new complex[cap];

            for (size_t i = 0; i < sz; i++) {
                arr[i] = stack.arr[i];
            }
        }
        complex_stack & operator=(const complex_stack &stack)
        {
            sz = stack.sz;
            cap = stack.cap;
            
            delete[] arr;
            arr = new complex[cap];

            for (size_t i = 0; i < sz; i++) {
                arr[i] = stack.arr[i];
            }

            return *this;
        }
        ~complex_stack()
        {
            delete[] arr;
        }
        size_t size() const { return sz; }
        const complex operator[] (size_t i) const
        {
            return arr[i];
        }
        complex_stack operator<< (const complex &a) const
        {
            complex_stack new_st = (sz == cap) ? complex_stack(cap * 2, sz) : complex_stack(cap, sz);
            
            for (size_t i = 0; i < sz; i++) {
                new_st.arr[i] = arr[i];
            }

            new_st.arr[new_st.sz++] = a;
            
            return new_st;
        }
        complex operator+ () const
        {
            return arr[sz - 1];
        }
        complex_stack operator~ () const
        {
            complex_stack new_st = (sz - 1 <= cap / 2 && cap > DFL_CAP) ? complex_stack(cap / 2, sz - 1) : complex_stack(cap, sz - 1);
            
            for (size_t i = 0; i < new_st.sz; i++) {
                new_st.arr[i] = arr[i];
            }

            return new_st;
        }
    };
}
