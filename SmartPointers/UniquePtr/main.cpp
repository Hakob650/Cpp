#include <iostream>
#include "my_unique_ptr.hpp"
#include "my_unique_ptr_exceptions.hpp"


int main() {
    try 
    {
        MyUniquePtr p1(new int(99));
        std::cout << "*p1 = " << *p1 << "\n";

        MyUniquePtr p2 = std::move(p1);
        
        if (!p1) 
        {
            std::cout << "p1 is now null (moved)\n";
        }
        
        std::cout << "*p2 = " << *p2 << "\n";

        p2.reset(new int(123));
        
        std::cout << "After reset: *p2 = " << *p2 << "\n";

        p2.release();

        std::cout << "*p2 = " << *p2 << "\n";
    }
    catch (const UniquePtrException& e) 
    {
        std::cerr << "Caught UniquePtrException: " << e.what() << "\n";
    }

    return 0;
}
