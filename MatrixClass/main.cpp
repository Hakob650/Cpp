#include <iostream>
#include "Matrix.hpp"

int main() {
    // Test default constructor
    std::cout << "Testing default constructor:" << std::endl;
    Matrix m1;
    std::cout << "Default matrix size: " << m1.GetRows() << "x" << m1.GetCols() << std::endl;
    
    // Test parameterized constructor
    std::cout << "\nTesting parameterized constructor:" << std::endl;
    Matrix m2(2, 3);
    m2.set(0, 0, 1.0);
    m2.set(0, 1, 2.0);
    m2.set(0, 2, 3.0);
    m2.set(1, 0, 4.0);
    m2.set(1, 1, 5.0);
    m2.set(1, 2, 6.0);
    std::cout << "Matrix m2:" << std::endl;
    m2.print();
    
    // Test copy constructor
    std::cout << "\nTesting copy constructor:" << std::endl;
    Matrix m3(m2);
    std::cout << "Copied matrix m3:" << std::endl;
    m3.print();
    
    // Test move constructor
    std::cout << "\nTesting move constructor:" << std::endl;
    Matrix m4(std::move(m3));
    std::cout << "Moved matrix m4:" << std::endl;
    m4.print();
    std::cout << "m3 after move (should be empty):" << std::endl;
    m3.print();
    
    // Test copy assignment operator
    std::cout << "\nTesting copy assignment operator:" << std::endl;
    Matrix m5;
    m5 = m2;
    std::cout << "Copy assigned matrix m5:" << std::endl;
    m5.print();
    
    // Test move assignment operator
    std::cout << "\nTesting move assignment operator:" << std::endl;
    Matrix m6;
    m6 = std::move(m5);
    std::cout << "Move assigned matrix m6:" << std::endl;
    m6.print();
    std::cout << "m5 after move assignment (should be empty):" << std::endl;
    m5.print();
    
    return 0;
}
