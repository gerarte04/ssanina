template <class T>
typename T::value_type process(const T &s)
{
    typename T::value_type sum{};
    typename T::const_iterator it = s.end();

    for (int i = 0; i < 3 && it != s.begin(); ++i) {
        sum += *(--it);

        if (it != s.begin()) {
            --it;
        }
    }

    return sum;
}
