#include <iostream>
#include <string>

template <typename T>
std::size_t hashValue(const T& value) { return 0; }

template<>
std::size_t hashValue<int>(const int& value) { return value * 31; }

template<>
std::size_t hashValue<std::string>(const std::string& value)
{
    std::size_t sum = 0;

    for(char c : value)
    {
        sum += static_cast<int>(c);
    }

    return sum;
}

int main()
{
    int int_val = 50;
    std::string string_val = "Hello";
    float float_val = 3.14f;
    char char_val = 'A';

    std::cout << "Hash of integer value 42 = " << hashValue(int_val) << std::endl;
    std::cout << "Hash of string value 'Hello' = " << hashValue(string_val) << std::endl;
    std::cout << "Hash of float value 3.14f = " << hashValue(float_val) << std::endl;
    std::cout << "Hash of char value 'A' = " << hashValue(char_val) << std::endl;

    return 0;
}