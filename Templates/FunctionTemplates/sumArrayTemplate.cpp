#include <iostream>

template <typename T>
T sumArray(T* arr, int size)
{
    T sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int int_arr[] = {10, 20, 30, 40, 50};
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);

    std::cout << "int sumArray<int>(int* arr, int size) instantiaiton returns: " << sumArray(int_arr, int_size);
    std::cout << "\n";
    
    double double_arr[] = {10.5, 20.5, 30.5, 40.5, 50.5};
    int double_size = sizeof(double_arr) / sizeof(double_arr[0]);

    std::cout << "double sumArray<double>(double* arr, int size) instantiaiton returns: " << sumArray(double_arr, double_size);
    std::cout << "\n";

    float float_arr[] = {10.6f, 20.6f, 30.6f, 40.6f, 50.6f};
    int float_size = sizeof(float_arr) / sizeof(float_arr[0]);

    std::cout << "float sumArray<int>(float* arr, int size) instantiaiton returns: " << sumArray(float_arr, float_size);

    return 0;
}