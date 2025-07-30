#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <list>

template <typename Container>
auto sumContainer(Container& c) -> decltype(*c.begin() + *c.end())
{
    decltype(*c.begin() + *c.end()) sum = 0;

    for(const auto& elem : c)
    {
        sum += elem;
    }

    return sum;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    std::array<double, 5> arr = {1.2, 2.2, 3.2, 4.2, 5.2};

    std::list<long> list = {10L, 20L, 30L, 40L, 50L};

    auto vector_sum = sumContainer(v);

    auto array_sum = sumContainer(arr);

    auto list_sum = sumContainer(list);

    std::cout << "Vector Sum = " << vector_sum << std::endl;

    std::cout << "Array Sum = " << array_sum << std::endl;

    std::cout << "List Sum = " << list_sum << std::endl;

    return 0;
}