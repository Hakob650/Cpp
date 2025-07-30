#include <iostream>

template <typename Func, typename Arg>
auto applyFunction(Func func, Arg arg) -> decltype(func(arg)) { return func(arg); }

int add(int a, int b) { return a + b; }
double add(double first_arg, double second_arg) { return first_arg + second_arg; }
int multiply(int x, int y) { return x * y; }
double multiply(double first, double second, double third) { return first * second * third; }

int main()
{
    auto square = [](int a) { return a * a; };
    auto multiplyByTwo = [](int x) {return 2 * x; };
    auto multiplyByThree = [](double b) { return 3.0 * b; }; 
    
    std::cout << " add(3, 4) = " << add(3, 4) << std::endl;

    std::cout << " add(3.0, 4.0) = " << add(3.0, 4.0) << std::endl;

    std::cout << " multiply(3, 4) = " << multiply(3, 4) << std::endl;

    std::cout << " multiply(3.0, 4.0, 5.0) = " << multiply(3.0, 4.0, 5.0) << std::endl;

    std::cout << " applyFunction(square, 5) = " << applyFunction(square, 5) << std::endl;

    std::cout << " applyFunction(multiplyByTwo, 5) = " << applyFunction(multiplyByTwo, 5) << std::endl;

    std::cout << " applyFunction(multiplyByThree, 5) = " << applyFunction(multiplyByThree, 5) << std::endl;

    return 0;
}
