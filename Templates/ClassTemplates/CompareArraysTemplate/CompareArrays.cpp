#ifndef COMPARE_ARRAYS_CPP
#define COMPARE_ARRAYS_CPP

#include <iostream>
#include "CompareArrays.hpp"

template <typename T, std::size_t N1, std::size_t N2>
void compareArrays<T, N1 , N2>::compare(const T(&a)[N1], const T(&b)[N2])
{
    std::cout << "Arrays of different sizes: " << N1 << " ," << N2 << " " << "cannot be compared" << std::endl;
}

template <typename T, std::size_t N>
void compareArrays<T, N, N>::compare(const T(&a)[N], const T(&b)[N])
{
    std::cout << "Comparison between two equally-sized arrays\n" << std::endl;

    bool is_equal = true;

    for(std::size_t i = 0; i < N; ++i)
    {
        if(a[i] != b[i])
        {
            is_equal = false;
            break;
        }
    }
}

#endif