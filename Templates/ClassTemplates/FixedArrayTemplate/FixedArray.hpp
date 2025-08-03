#ifndef FIXED_ARRAY_HPP
#define FIXED_ARRAY_HPP

#include <cstddef>

template <typename T, std::size_t N>
class FixedArray
{
private:
        T data[N];
public:
        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;

        constexpr std::size_t size() const noexcept;

        T* begin() noexcept;
        const T* begin() const noexcept;

        T* end() noexcept;
        const T* end() const noexcept;
};

#include "FixedArray.cpp"

#endif