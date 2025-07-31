#include <iostream>

template <typename T1, typename T2>
auto findMax(T1 arg1, T2 arg2) -> decltype(true ? arg1 : arg2) { return (arg1 > arg2) ? arg1 : arg2; }

template <typename T1, typename T2>
auto findMin(T1 arg1, T2 arg2) -> decltype(true ? arg1 : arg2) { return (arg1 < arg2) ? arg1 : arg2; }

int main()
{
    int x = 20, y = 30;
    double arg1 = 12.5, arg2 = 20.6;
    long a = 10L, b = 40L;
    std::string param1 = "Hello";
    std::string param2 = "Hello, World!";

    std::cout << "\\=== Instantiaitions For findMax ===/" << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<int, int>(int arg1, int arg2)->int& = " << findMax(x, y) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<double, double>(double arg1, double arg2)->double& = " << findMax(arg1, arg2) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<long, long>(long arg1, long arg2)->long& = " << findMax(a, b) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<std::string, std::string>(std::string arg1, std::string arg2)->std::string& = " << findMax(param1, param2) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<int, double>(int arg1, double arg2)->double = " << findMax(x, arg1) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<int, double>(int arg1, double arg2)->double = " << findMax(y, arg1) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<int, double>(int arg1, double arg2)->double = " << findMax(x, arg2) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<int, double>(int arg1, double arg2)->double = " << findMax(y, arg2) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<int, long>(int arg1, long arg2)->long = " << findMax(x, a) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<int, long>(int arg1, long arg2)->long = " << findMax(x, b) << std::endl;
    std::cout << "\n";
    
    std::cout << "auto findMax<int, long>(int arg1, long arg2)->long = " << findMax(y, a) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<int, long>(int arg1, long arg2)->long = " << findMax(y, b) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<double, long>(double arg1, long arg2)->double = " << findMax(arg1, a) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<double, long>(double arg1, long arg2)->double = " << findMax(arg1, b) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<double, long>(double arg1, long arg2)->double = " << findMax(arg2, a) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMax<double, long>(double arg1, long arg2)->double = " << findMax(arg2, b) << std::endl;
    
    std::cout << "\n";

    std::cout << "\\=== Instantiations for findMin ===/" << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<int, int>(int arg1, int arg2)->int&= " << findMin(x, y) << std::endl;
    std::cout << "\n";

    
    std::cout << "auto findMin<double, double>(double arg1, double arg2)->double& = " << findMin(arg1, arg2) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<long, long>(long arg1, long arg2)->long& = " << findMin(a, b) << std::endl;
    std::cout << "\n";
    
    std::cout << "auto findMin<std::string, std::string>(std::string arg1, std::string arg2)->std::string& = " << findMin(param1, param2) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<int, double>(int arg1, double arg2)->double = " << findMin(x, arg1) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<int, double>(int arg1, double arg2)->double = " << findMin(y, arg1) << std::endl;
    std::cout << "\n";
    
    std::cout << "auto findMin<int, double>(int arg1, double arg2)->double = " << findMin(x, arg2) << std::endl;
    std::cout << "\n";
    
    std::cout << "auto findMin<int, double>(int arg1, double arg2)->double = " << findMin(y, arg2) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<int, long>(int arg1, long arg2)->long = " << findMin(x, a) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<int, long>(int arg1, long arg2)->long = " << findMin(x, b) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<int, long>(int arg1, long arg2)->long = " << findMin(y, a) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<int, long>(int arg1, long arg2)->long = " << findMin(y, b) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<double, long>(double arg1, long arg2)->double = " << findMin(arg1, a) << std::endl;
    std::cout << "\n";

    std::cout << "auto findMin<double, long>(double arg1, long arg2)->double = " << findMin(arg1, b) << std::endl;
    std::cout << "\n";
    
    std::cout << "auto findMin<double, long>(double arg1, long arg2)->double = " << findMin(arg2, a) << std::endl;
    std::cout << "\n";
    
    std::cout << "auto findMin<double, long>(double arg1, long arg2)->double = " << findMin(arg2, b) << std::endl;

    return 0;
}


