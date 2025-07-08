#include <iostream>
#include "my_auto_ptr.hpp"
#include "my_auto_ptr_exceptions.hpp"

int main()
{
    try
    {
        my_auto_ptr p1(new int(100));
        std::cout << "*p1 = " << *p1 << std::endl;

        my_auto_ptr p2 = p1;

        if(!p1)
        {
            std::cout << "p1 is empty for transfer!" << std::endl;
        }

        std::cout <<"*p2 = " << *p2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught my_auto_ptr exception"<< e.what() << '\n';
    }
    
    return 0;
}