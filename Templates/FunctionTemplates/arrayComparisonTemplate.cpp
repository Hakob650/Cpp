#include <iostream>

template <typename T>
bool compareArrays(T* arr1, T* arr2, int size)
{
    for(int i = 0; i < size; ++i)
    {
        if(arr1[i] != arr2[i])
        {
                return false;
        }
    }
    return true;
}

int main()
{
    int int_arr1[] = {1, 2, 3, 4, 5};
    int int_arr2[] = {1, 2, 3, 4, 6};
    int int_arr3[] = {1, 3, 2, 4, 6};
    int int_arr4[] = {1, 2, 3, 4, 5};

    char char_arr1[] = {'a', 'b', 'c'};
    char char_arr2[] = {'a', 'c', 'b'};
    char char_arr3[] = {'c', 'b', 'a'};
    char char_arr4[] = {'a', 'b', 'c'};

    std::cout << "bool compareArrays(int* arr1, int* arr2, int size) returns : " << ((compareArrays(int_arr1,int_arr2,5)) ? "true" : "false") << std::endl;
    std::cout << "bool compareArrays(int* arr1, int* arr3, int size) returns : " << ((compareArrays(int_arr1,int_arr3,5)) ? "true" : "false") << std::endl;
    std::cout << "bool compareArrays(int* arr1, int* arr4, int size) returns : " << ((compareArrays(int_arr1,int_arr4,5)) ? "true" : "false") << std::endl;

    std::cout << "\n";

    std::cout << "bool compareArrays(char* char_arr1, char* char_arr2, int size) returns : " << ((compareArrays(char_arr1,char_arr2,3)) ? "true" : "false") << std::endl;
    std::cout << "bool compareArrays(char* char_arr1, char* char_arr3, int size) returns : " << ((compareArrays(char_arr1,char_arr3,3)) ? "true" : "false") << std::endl;
    std::cout << "bool compareArrays(char* char_arr1, char* char_arr4, int size) returns : " << ((compareArrays(char_arr1,char_arr4,3)) ? "true" : "false") << std::endl;

    return 0;
}   