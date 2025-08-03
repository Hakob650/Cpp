#include <iostream>
#include "FixedArray.hpp"

int main()
{
    FixedArray<int ,10> arr;

    for(std::size_t i = 0; i < arr.size(); ++i)
    {
        arr[i] = static_cast<int>(i * 10);
    }

    std::cout << "Arrays elements: ";
    for(const auto& val : arr)
    {
        std::cout << val << " ";
    }

    std::cout << "\nSize = " << arr.size() << "\n";

    return 0;
}
