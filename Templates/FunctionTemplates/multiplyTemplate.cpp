#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
T multiply(const T& arg1, const T& arg2) { return arg1 * arg2; }

template<>
double multiply<double>(const double& arg1, const double& arg2) { return arg1 * arg2; }

template<>
std::string multiply<std::string>(const std::string& arg1, const std::string& arg2)
{
    int arg = std::stoi(arg2);

    std::string result = " ";

    for(int i = 0; i < arg; ++i)
    {
        result += arg1;
    }

    return result;
}

template<>
long multiply<long>(const long& arg1, const long& arg2) { return arg1 * arg2; }

int main()
{
    int x = 10, y = 20;
    std::cout << "Multiply 2 integer values: " << multiply(x, y) << std::endl;

    double a = 20.5, b = 12.4;
    std::cout << "Multiply 2 double values : " << std::fixed << std::setprecision(2) <<  multiply(a, b) << std::endl;

    std::string str = "hello";
    std::string times = "5";
    std::cout << "Duplicate string 5 times : " << multiply(str, times) << std::endl;

    long arg1 = 10000L, arg2 = 20000L;
    std::cout << "Multiply 2 long values : " << multiply(arg1, arg2) << std::endl;

    return 0;
}

