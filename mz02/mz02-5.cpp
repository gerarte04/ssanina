#include <iostream>

class Row {
    int m[3] = {};
public:
    int & operator[] (int i)
    {
        return m[i];
    }
    
    int * begin() {
        return &m[0];
    }
    int * end() {
        return &m[2];   
    }
};

class Matrix
{
    Row rows[3];
public:
    int & operator[] (int i, int j)
    {
        return rows[i][j];
    }
    
    Row * begin() const {
        return &rows[0];   
    }
    
    Row * end() const {
        return &rows[2];   
    }
};

int main()
{
   Matrix m;
   m[1, 1] = 5;

   for (const auto &row : m) {
        for (auto cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
   }
}
