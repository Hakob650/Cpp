#ifndef COMPARE_ARRAYS_HPP
#define COMPARE_ARRAYS_HPP

#include <cstddef>

template <typename T, std::size_t N1, std::size_t N2>
class compareArrays
{
public:
        static void compare(const T(&a)[N1], const T(&b)[N2]);
};

template <typename T, std::size_t N>
class compareArrays<T, N, N> 
{
public:
        static void compare(const T(&a)[N], const T(&b)[N]);
};

#include "CompareArrays.cpp"

#endif