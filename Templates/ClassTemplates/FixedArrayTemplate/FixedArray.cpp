#ifndef FIXED_ARRAY_CPP
#define  FIXED_ARRAY_CPP

#include <iostream>
#include <stdexcept>
#include "FixedArray.hpp"

template <typename T, std::size_t N>
T& FixedArray<T, N>::operator[](std::size_t index)
{
    if(index >= N) { throw std::out_of_range("Fixed Array: index is out of range"); }
    return data[index];
}

template <typename T, std::size_t N>
const T& FixedArray<T, N>::operator[](std::size_t index) const
{
    if(index >= N) { throw std::out_of_range("Fixed Array: index is out of range"); }
    return data[index];
}

template <typename T, std::size_t N>
constexpr std::size_t FixedArray<T, N>::size() const noexcept
{
    return N;
}

template <typename T, std::size_t N>
T* FixedArray<T, N>::begin() noexcept
{
    return data;
}

template <typename T, std::size_t N>
const T* FixedArray<T, N>::begin() const noexcept
{
    return data;
}

template <typename T, std::size_t N>
T* FixedArray<T, N>::end() noexcept
{
    return data + N;
}

template <typename T, std::size_t N>
const T* FixedArray<T, N>::end() const noexcept
{
    return  data + N;
}

#endif