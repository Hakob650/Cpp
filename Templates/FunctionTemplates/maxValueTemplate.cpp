#include <iostream>
#include <string>

template <typename T1, typename T2>
auto maxValue(const T1& a, const T2& b) -> decltype((a > b) ? a : b)
{
    return (a > b) ? a : b;
}

int main()
{
    int x = 12;
    double y = 13.5;
    
    std::string str1 = "hello, world!";
    std::string str2 = "hello";

    std::cout << "maxValue(x, y) = " << maxValue(x, y) << std::endl;

    std::cout << "maxValue(y, x) = " << maxValue(y, x) << std::endl;

    std::cout << "maxValue(str1, str2) = " << maxValue(str1, str2) << std::endl;

    std::cout << "maxValue(str2, str1) = " << maxValue(str2, str1) << std::endl;

    return 0;
}