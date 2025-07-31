#include <iostream>

template <typename T>
void reverseArray(T* array, int size)
{
    int start = 0;
    int end = size - 1;

    while(start < end)
    {
        T temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

template <typename T>
void printArray(T* array, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int int_array[] = {1, 2, 3, 4, 5};
    int int_size = sizeof(int_array) / sizeof(int_array[0]);

    reverseArray(int_array, int_size);
    printArray(int_array, int_size);

    double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int double_size = sizeof(double_array) / sizeof(double_array[0]);

    reverseArray(double_array, double_size);
    printArray(double_array, double_size);

    float float_array[] = {1.2f, 2.4f, 3.6f, 4.8f, 6.0f};
    int float_size = sizeof(float_array) / sizeof(float_array[0]);

    reverseArray(float_array, float_size);
    printArray(float_array, float_size);

    char char_array[] = {'A', 'B', 'C', 'D', 'E'};
    int char_size = sizeof(char_array) / sizeof(char_array[0]);

    reverseArray(char_array, char_size);
    printArray(char_array, char_size);

    return 0;
}
