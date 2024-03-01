class Matrix
{
    class Row
    {
        int * const r = new int[3];
    public:
        ~Row() { delete[] r; }
        int & operator[] (int i) const { return r[i]; }
        int * begin() const { return r; }
        int * end() const { return r + 3; }
    };
    
    const Row m[3];
public:
    int & operator[] (int i, int j) { return m[i][j]; }
    const Row * begin() { return m; }
    const Row * end() { return m + 3; }
};
