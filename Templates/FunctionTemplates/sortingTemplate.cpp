#include <iostream>

template <typename T>
void sortArray(T* arr, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = 0; j < size -1 - i; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void printArray(T* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int int_arr[] = {10, 20, 80, 15, 40, 50, 70, 30};
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);

    sortArray(int_arr, int_size);
    printArray(int_arr, int_size);

    double double_arr[] = {10.5, 20.5, 80.5, 15.5, 40.5, 50.5, 70.5, 30.5};
    int double_size = sizeof(double_arr) / sizeof(double_arr[0]);

    sortArray(double_arr, double_size);
    printArray(double_arr, double_size);

    char char_array[] = {'A','S','D','F','E'};
    int char_size = sizeof(char_array) / sizeof(char_array[0]);

    sortArray(char_array, char_size);
    printArray(char_array, char_size);

    return 0;
}