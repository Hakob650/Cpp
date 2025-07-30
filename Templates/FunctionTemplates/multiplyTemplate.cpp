#include <iostream>
#include <string>
#include <cmath>

template <typename T>
T multiply(T a, T b) { return a * b; }

template <>
double multiply(double arg1, double arg2)
{
    double res = arg1 * arg2;

    return std::round(res * 100.0) / 100.0;
}

template<>
std::string multiply(std::string arg1, std::string arg2)
{
    int n = std::stoi(arg2);
    std::string res;

    for(int i = 0; i < n; ++i)
    {
        res += arg1;
    }

    return res;
}

std::string multiply(const std::string& arg1, int arg2)
{
    std::string res;

    for(int i = 0; i < arg2; ++i)
    {
        res += arg1;
    }

    return res;
}

int main()
{
    int a = 3, b = 4;
    double x = 2.456, y = 3.14159;
    std::string str = "Hello";

    std::cout << "int mutilply(int, int) -> " << multiply(a, b) << std::endl;
    std::cout << "double multiply(double, double) -> " << multiply(x, y) << std::endl;
    std::cout << "std::string multiply(const std::string&, int) -> " << multiply(str, 3) << std::endl;

    return 0;
}
