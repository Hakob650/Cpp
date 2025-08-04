#include <iostream>
#include "Matrix.hpp"

int main()
{
    MultiDimMatrix<int, 2> mat2d({3, 4}, 0);

    mat2d[0][0] = 1;
    mat2d[1][2] = 5;
    mat2d[2][3] = 9;

    std::cout << "2D Matrix: " << std::endl;
    std::cout << mat2d << std::endl;

    mat2d.fill(7);
    std::cout << "After fill(7): " << std::endl;
    std::cout << mat2d << std::endl;

    mat2d.apply([](int& x) { x += 1; });
    std::cout << "After apply([](int& x) { x += 1; }): " << std::endl;
    std::cout << mat2d << std::endl;

    std::cout << "Min: " << mat2d.min() << std::endl;
    std::cout << "Max: " << mat2d.max() << std::endl;
    std::cout << "Sum: " << mat2d.sum() << std::endl;

    MultiDimMatrix<int, 3> mat3d({2, 2, 2}, 3);
    mat3d[1][1][1] = 10;
    std::cout << "mat3d[1][1][1] = " << mat3d[1][1][1] << std::endl;
    std::cout << "3D Matrix: " << std::endl;
    std::cout << mat3d << std::endl;

    return 0;
}