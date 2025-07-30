#include <iostream>

template <typename T1, typename T2>
void printPair(const T1& first, const T2& second)
{
    std::cout << "(" << first << "," << second << ")" << std::endl;
}

int main()
{
    int x = 12;
    
    double y = 7.5;
    
    std::string str = "hello, world!";
    
    char c = 'A';

    printPair(x, y);

    printPair(y, x);

    printPair(str, c);

    printPair(c, str);

    return 0;
}