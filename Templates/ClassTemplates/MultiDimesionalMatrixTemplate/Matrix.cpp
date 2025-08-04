#ifndef MULTIDIMENSIONAL_MATRIX_CPP
#define MULTIDIMENSIONAL_MATRIX_CPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include "Matrix.hpp"

template <typename T, std::size_t N>
MultiDimMatrix<T, N>::MultiDimMatrix(const std::array<std::size_t, N>& dimensions, const T& value)
    : dim(dimensions)
{
    std::array<std::size_t, N - 1> sub_dims;
    std::copy(dim.begin() + 1, dim.end(), sub_dims.begin());
    mat.resize(dim[0], MultiDimMatrix<T, N - 1>(sub_dims, value));
}

template <typename T, std::size_t N>
typename ::MultiDimMatrix<T, N - 1>& MultiDimMatrix<T, N>::operator[](size_type index)
{
    if(index >= dim[0])
    {
        throw std::out_of_range("Index out of range");
        
    }
    return mat[index];
}

template <typename T, std::size_t N>
const typename ::MultiDimMatrix<T, N - 1>& MultiDimMatrix<T, N>::operator[](size_type index) const 
{
    if(index >= dim[0])
    {
        throw std::out_of_range("Index out of range");
    }
    return mat[index];
}

template <typename T, std::size_t N>
const std::array<std::size_t, N>& MultiDimMatrix<T, N>::dimensions() const
{
    return dim;
}

template <typename T, std::size_t N>
void MultiDimMatrix<T, N>::fill(const T& value)
{
    for(auto& sub_matrix : mat)
    {
        sub_matrix.fill(value);
    }
}

template <typename T, std::size_t N>
bool MultiDimMatrix<T, N>::operator==(const MultiDimMatrix<T, N>& other) const
{
   return dim == other.dim && mat == other.mat;
}

template <typename T, std::size_t N>
bool MultiDimMatrix<T, N>::operator!=(const MultiDimMatrix<T, N>& other) const
{
    return !(*this == other);
}

template <typename T, std::size_t N>
template <typename Func>
void MultiDimMatrix<T, N>::apply(Func func)
{
    for(auto& sub_matrix : mat)
    {
        sub_matrix.apply(func);
    }
}

template <typename T, std::size_t N>
T MultiDimMatrix<T, N>::min() const
{
    T min_value = mat[0].min();
    
    for(size_type i = 1; i < mat.size(); ++i)
    {
        min_value = std::min(min_value, mat[i].min());
    }
    
    return min_value;
}

template <typename T, std::size_t N>
T MultiDimMatrix<T, N>::max() const
{
    T max_value = mat[0].max();
    
    for(size_type i = 1; i < mat.size(); ++i)
    {
        max_value = std::max(max_value, mat[i].max());
    }
    
    return max_value;
}

template <typename T, std::size_t N>
T MultiDimMatrix<T, N>::sum() const
{
    T total = mat[0].sum();
    
    for(const auto& sub_matrix : mat)
    {
        total += sub_matrix.sum();
    }

    return total;
}

template <typename T>
MultiDimMatrix<T, 1>::MultiDimMatrix(const std::array<std::size_t, 1>& dimension, const T& value)
    : dim(dimension), mat(dimension[0], value) { } 
    
template <typename T>
T& MultiDimMatrix<T, 1>::operator[](size_type index)
{
    return mat[index];
}

template <typename T>
const T& MultiDimMatrix<T, 1>::operator[](size_type index) const
{
    return mat[index];
}

template <typename T>
const std::array<std::size_t, 1>& MultiDimMatrix<T, 1>::dimensions() const
{
    return dim;
}

template <typename T>
void MultiDimMatrix<T, 1>::fill(const T& value)
{
    std::fill(mat.begin(), mat.end(), value);
}

template <typename T>
bool MultiDimMatrix<T, 1>::operator==(const MultiDimMatrix<T, 1>& other) const
{
    return dim == other.dim && mat == other.mat;
}

template <typename T>
bool MultiDimMatrix<T, 1>::operator!=(const MultiDimMatrix<T, 1>& other) const
{
    return !(*this == other);
}

template <typename T>
template <typename Func>
void MultiDimMatrix<T, 1>::apply(Func func)
{
    for(auto& value : mat)
    {
        func(value);
    }
}

template <typename T>
T MultiDimMatrix<T, 1>::min() const
{
    return *std::min_element(mat.begin(), mat.end());
}

template <typename T>
T MultiDimMatrix<T, 1>::max() const
{
    return *std::max_element(mat.begin(), mat.end());
}

template <typename T>
T MultiDimMatrix<T, 1>::sum() const
{
    return std::accumulate(mat.begin(), mat.end(), T{});
}

#endif
