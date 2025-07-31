#include <iostream>
#include <iomanip>

template <typename T, size_t N>
void printArray(const T(&arr)[N])
{
    std::cout << "Array of type: " << typeid(T).name() << ":";
    
    for(size_t i = 0; i < N; ++i) { std::cout << arr[i] << " "; }
    
    std::cout << std::endl;
}

template <size_t N>
void printArray(const int(&arr)[N])
{
    for(size_t i = 0; i < N; ++i) { std::cout << arr[i] << " "; }
    
    std::cout << std::endl;
}

template<size_t N>
void printArray(const double(&arr)[N])
{
    for(size_t i = 0; i < N; ++i) { std::cout << std::fixed << std::setprecision(2) << arr[i] << " "; }

    std::cout << std::endl;
}

template <size_t N>
void printArray(const char(&arr)[N])
{
    std::cout << arr << std::endl;
}

int main()
{
    int int_arr[] = {1, 2, 3, 4, 5};
    double double_arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char char_arr[] = "Hello, World!";

    printArray(int_arr);
    printArray(double_arr);
    printArray(char_arr);

    return 0;
}



