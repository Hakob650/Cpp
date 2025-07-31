#include <iostream>
#include <utility>

template <typename T>
void swapValues(T arg1, T arg2)
{
    T temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

int main()
{
    int x = 10, y = 20;
    std::cout << "Before void swapValues<int>(int& x, int& y) instantiation: " << "x = " << " " << x << " ," << "y = " << " " << y << std::endl;
    swapValues(x, y);
    std::cout << "After void swapValues<int>(int& x, int& y) instantiation: " << "x = " << " " << x << " ," <<  "y = " << " " << y << std::endl;
    std::cout << "\n";

    double arg1 = 10.24, arg2 = 20.48;
    std::cout << "Before void swapValues<double>(double& arg1,double& arg2) instantiaition: " << "arg1 = " << " " << arg1 << " ," << "arg2 = " << " " << arg2 << std::endl;
    swapValues(arg1, arg2);
    std::cout << "After void swapValues<double>(double& arg1, double& arg2) instantiation: " << "arg1 = "<< " " << arg1 << " ," << "arg2 = " << " " << arg2 << std::endl;
    std::cout << "\n";

    char param1 = 'A', param2 = 'B';
    std::cout << "Before void swapValues<char>(char& param1, char& param2) instantiation: " << "param1 = " << " " << param1 << " ," << "param2 = " << " " << param2 << std::endl;
    swapValues(param1, param2);
    std::cout << "After void swapValues<char>(char& param1, char& param2) instantiation: " << "param1 = " << " " << param1 << " ," << "param2 = " << " " << param2 << std::endl;

    return 0;
}