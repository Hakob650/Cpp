#include <iostream>
#include <cstring>
#include <string>

template <typename T>
int compareValues(T a, T b)
{
    if(a < b) { return -1; }
    else if(a > b) { return 1; }
    else { return 0; }
}

template<>
int compareValues<const char*>(const char* arg1, const char* arg2)
{
    int result = std::strcmp(arg1, arg2);
    if( result < 0) { return -1; }
    else if(result > 0) { return 1; }
    else { return 0; }
}

template <>
int compareValues<std::string>(std::string arg1, std::string arg2)
{
    int result = arg1.compare(arg2);
    if(result < 0) { return -1; }
    if(result > 0) { return 1; }
    else { return 0; }
}

int main()
{
    int x = 10, y = 20;
    
    double d1 = 12.5, d2 = 22.4;

    std::string str1 = "hello", str2 = "abc";
    
    const char* ptr1 = "name1";

    const char* ptr2 = "name";

    std::cout << "compareValue<int>(int x, int y) = " << compareValues(x, y) << std::endl;

    std::cout << "compareValues<double>(double d1, double d2) = " << compareValues(d1, d2) << std::endl;

    std::cout << "compareValues<std::string>(std::string str1, std::string str2) = " << compareValues(str1, str2) << std::endl;

    std::cout << "compareValues<const char*>(const char* ptr1, const char* ptr2) = " << compareValues(ptr1, ptr2) << std::endl;

    return 0;
}

