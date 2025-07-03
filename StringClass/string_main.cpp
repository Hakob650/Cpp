#include <iostream>
#include "string.hpp"

int main() {
    // Test default constructor
    std::cout << "Testing default constructor:" << std::endl;
    String s1;
    std::cout << "s1: ";
    s1.print();
    std::cout << "Length: " << s1.length() << std::endl;

    // Test parameterized constructor
    std::cout << "\nTesting parameterized constructor:" << std::endl;
    String s2("Hello, World!");
    std::cout << "s2: ";
    s2.print();
    std::cout << "Length: " << s2.length() << std::endl;

    // Test copy constructor
    std::cout << "\nTesting copy constructor:" << std::endl;
    String s3(s2);
    std::cout << "s3 (copy of s2): ";
    s3.print();
    std::cout << "Length: " << s3.length() << std::endl;

    // Test move constructor
    std::cout << "\nTesting move constructor:" << std::endl;
    String s4(std::move(s3));
    std::cout << "s4 (moved from s3): ";
    s4.print();
    std::cout << "s3 (after move): ";
    s3.print();  // Should be empty

    // Test copy assignment operator
    std::cout << "\nTesting copy assignment operator:" << std::endl;
    String s5;
    s5 = s2;
    std::cout << "s5 = s2: ";
    s5.print();

    // Test move assignment operator
    std::cout << "\nTesting move assignment operator:" << std::endl;
    String s6;
    s6 = std::move(s5);
    std::cout << "s6 (moved from s5): ";
    s6.print();
    std::cout << "s5 (after move): ";
    s5.print();  // Should be empty

    return 0;
}