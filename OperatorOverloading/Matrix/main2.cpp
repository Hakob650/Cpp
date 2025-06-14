#include <iostream>
#include "Matrix.hpp"

int main()
{
    Matrix A(2,2);
    Matrix B(2,2);

    A.set(0,0,1.0);
    A.set(0,1,2.0);
    A.set(1,0,3.0);
    A.set(1,1,4.0);

    B.set(0,0,5.0);
    B.set(0,1,6.0);
    B.set(1,0,7.0);
    B.set(1,1,8.0);

    std::cout<<"A\n"<<A;
    std::cout<<"B\n"<<B;

    Matrix C = A + B;
    
    std::cout<<"A + B:\n"<<C;

    Matrix D = A - B;

    std::cout<<"A - B:\n"<<D;

    Matrix E = A * B;

    std::cout<<"A * B:\n"<<E;

    Matrix F = A;
    
    std::cout<<"Copy Ctor Called\n"<<F;

    Matrix G = std::move(B);

    std::cout<<"Move Ctor Called\n"<<G;

    return 0;
}