#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <list>

template <typename Container>
auto sumContainer(const Container& container)
{
    typename Container::value_type sum = 0;
    
    for(const auto& elem : container)
    {
        sum += elem;
    }

    return sum;
}

template<>
auto sumContainer<std::vector<int>>(const std::vector<int>& container)
{
    int sum = 0;
    for(const auto& elem : container)
    {
        sum += elem;
    }
    return sum;
}

template <>
auto sumContainer<std::vector<std::string>>(const std::vector<std::string>& container)
{
    std::string concatenated = " ";

    for(const auto& elem : container)
    {
        concatenated += elem;
    }

    return concatenated;
}

template<>
auto sumContainer<std::list<int>>(const std::list<int>& container)
{
    int sum = 0;
    
    for(const auto& elem : container)
    {
        sum += elem;
    }

    return sum;
}

int main()
{
    std::vector<int> int_vec = {1, 2, 3, 4, 5, 6 , 7};
    std::cout << "Sum of vector<int> = " << sumContainer(int_vec) << std::endl;
    
    std::vector<double> double_vec = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    std::cout << "Sum of vector<double> " << std::fixed << std::setprecision(2) << sumContainer(double_vec) << std::endl;

    std::vector<std::string> string_vec = {"Hello", "," , "World", "!"}; 
    std::cout << "Concatenation of vector<string>: " << sumContainer(string_vec) << std::endl;

    std::list<int> int_list = {10, 20, 30, 40, 50, 60, 70};
    std::cout << "Sum of list<int> = " << sumContainer(int_list) << std::endl;

    return 0;
}
