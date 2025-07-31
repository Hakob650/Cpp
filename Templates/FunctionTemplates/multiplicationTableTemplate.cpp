#include <iostream>
#include <iomanip>

void print(int value)
{
    std::cout << std::setw(4) << value;;
}

void print(double value)
{
    std::cout <<  std::fixed << std::setprecision(2) << std::setw(6) << value;
}

template <typename T>
void generateMultiplicationTable(int num)
{
    for(int i = 1; i <= num; ++i)
    {
        for(int j = 1; j <= num; ++j)
        {
            T product = static_cast<T>(i) * static_cast<T>(j);
            print(product);
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "Mutilplication Table(int) :\n";
    generateMultiplicationTable<int>(5);

    std::cout << "Multiplication Table(double):\n";
    generateMultiplicationTable<double>(5);

    return 0;
}



