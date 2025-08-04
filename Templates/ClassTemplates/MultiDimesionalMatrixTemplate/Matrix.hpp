#ifndef MULTIDIMENSIONAL_MATRIX_HPP
#define MULTIDIMENSIONAL_MATRIX_HPP

#include <cstddef>
#include <vector>
#include <array>

template <typename T, std::size_t N>
class MultiDimMatrix
{
private:
        static_assert(N > 1, "N must be greater than 1 for multi-dimesnional matrix");
        std::vector<MultiDimMatrix<T, N - 1>> mat;
        std::array<std::size_t, N> dim;
public:
        using size_type = std::size_t;

        MultiDimMatrix(const std::array<std::size_t, N>& dimensions, const T& value = T());

        MultiDimMatrix<T, N - 1>& operator[](size_type index);

        const MultiDimMatrix<T, N - 1>& operator[](size_type index) const;

        const std::array<std::size_t, N>& dimensions() const;

        void fill(const T& value);

        bool operator==(const MultiDimMatrix<T, N>& other) const;
        
        bool operator!=(const MultiDimMatrix<T, N>& other) const;

        template <typename Func>
        void apply(Func func);

        T min() const;
        
        T max() const;

        T sum() const;
};

template <typename T>
class MultiDimMatrix<T, 1>
{
private:
        std::vector<T> mat;
        std::array<std::size_t, 1> dim;
public:
        using size_type = std::size_t;

        MultiDimMatrix(const std::array<std::size_t, 1>& dimension, const T& value = T());;

        T& operator[](size_type index);
        
        const T& operator[](size_type index) const;

        const std::array<std::size_t, 1>& dimensions() const;

        void fill(const T& value);
        
        bool operator==(const MultiDimMatrix<T, 1>& other) const;

        bool operator!=(const MultiDimMatrix<T, 1>& other) const;

        template <typename Func>
        void apply(Func func);

        T min() const;
        
        T max() const;

        T sum() const;
};

// operator<< overloads (outside the class)
template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const MultiDimMatrix<T, N>& mat)
{
    os << "[";
    for(size_t i = 0; i < mat.dimensions()[0]; ++i)
    {
        os << mat[i];
        if(i + 1 != mat.dimensions()[0])
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MultiDimMatrix<T, 1>& mat)
{
    os << "[";

    for(size_t i = 0; i < mat.dimensions()[0]; ++i)
    {
        os << mat[i];

        if(i + 1 != mat.dimensions()[0])
        {
            os << ", ";
        }
    }

    os << "]";

    return os;
}

#include "Matrix.cpp"
#endif