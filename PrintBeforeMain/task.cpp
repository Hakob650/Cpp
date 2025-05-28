#include <iostream>

struct Printer
{
        Printer()
        {
                std::cout<<"Hello before main!\n";
        }
};

Printer p;

int main()
{
        std::cout<<"Inside main\n";

        return 0;
}
