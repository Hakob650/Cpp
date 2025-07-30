#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>

template <typename T>
void printValue(T arg) { std::cout << "Unknown Type " << std::endl; }

template<>
void printValue<int>(int arg) { std::cout << "Integer: " << arg << std::endl; }

template<>
void printValue<double>(double arg) { std::cout << "Double: " << std::fixed << std::setprecision(2) << arg << std::endl; }

template<>
void printValue<char*>(char* arg) { std::cout << "Char*: " << arg << std::endl; }

int main()
{
    int x = 10;
    double y = 12.5;
    char str[] = "hello";

    printValue(x);
    printValue(y);
    printValue(str);

    float z = 2.5f;
    
    printValue(z);

    return 0;
}
