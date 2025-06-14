#include <iostream>
#include "Vector.hpp"

int main() {
    MyVector v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    MyVector v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;

    MyVector sum = v1 + v2;
    std::cout << "v1 + v2 = " <<" "<< sum <<" "<< std::endl;

    MyVector diff = v1 - v2;
    std::cout << "v1 - v2 = " <<" "<< diff <<" "<< std::endl;

    MyVector prod = v1 * v2;
    std::cout << "v1 * v2 = " << " "<<prod <<" "<< std::endl;

    MyVector div = v2 / v1;
    std::cout << "v2 / v1 = " <<" "<< div <<" "<< std::endl;

    ++v1;
    std::cout << "++v1 = " << v1 << std::endl;

    MyVector temp = v2++;
    std::cout << "v2++ = " << temp << " and now v2 = " << v2 << std::endl;


    if (v1 == v2) {
        std::cout << "v1 == v2" << std::endl;
    } else {
        std::cout << "v1 != v2" << std::endl;
    }

    return 0;
}
