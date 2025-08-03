#include "CompareArrays.hpp"

int main()
{
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};
    int arr3[] = {1, 2, 4};
    int arr4[] = {1, 2};

    compareArrays<int, 3, 3>::compare(arr1, arr2);
    compareArrays<int, 3, 3>::compare(arr1, arr3);
    compareArrays<int, 3, 2>::compare(arr1, arr4);

    return 0;
}