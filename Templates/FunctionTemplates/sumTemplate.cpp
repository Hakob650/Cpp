#include <iostream>

template <typename T1, typename T2>
auto sum(const T1& num1, const T2& num2) -> decltype(num1 + num2) { return num1 + num2; }

template <typename T1, typename T2, typename T3>
auto sum(const T1& num1, const T2& num2, const T3& num3) -> decltype(num1 + num2 + num3) { return num1 + num2 + num3; }

int main()
{
    int x = 10, y = 20, z = 30;
 
    double a = 5.5, b = 6.5, c = 7.5;

    std::cout << "sum(x, y) = " << sum(x, y) << std::endl;

    std::cout << "sum(y, x) = " << sum(y, x) << std::endl;

    std::cout << "sum(x, z) = " << sum(x, z) << std::endl;

    std::cout << "sum(y, z) = " << sum(y, z) << std::endl;

    std::cout << "sum(x, y, z) = " << sum(x, y, z) << std::endl;

    std::cout << "sum(z, y, x) = " << sum(z, y, x) << std::endl;

    return 0;
}
