#include "matrix.h"
#include <iostream>

int main() {
    Matrix m(6, 6);
    for(size_t i = 0; i < m.GetRows(); ++i)
    {
	    for(size_t j = 0; j < m.GetRows(); ++j)
	    {
		    m.set(i, j, static_cast<double>(i*6 + j));
	    }
    }

    std::cout << "Matrix content:\n";
    m.print();

    return 0;
}

