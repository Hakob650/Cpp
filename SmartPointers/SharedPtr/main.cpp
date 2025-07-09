#include <iostream>
#include "my_shared_ptr.hpp"
#include "my_shared_ptr_exceptions.hpp"

int main()
{
   try
   {
        SharedPtr p1;
        std::cout << "*p1 = " << *p1 << std::endl;

        SharedPtr p2(SharedPtr(new int(100)));
        std::cout << "*p2 = " << *p2 << std::endl;
   }
   catch(const SharedPtrException& e)
   {
        std::cerr << "Caught Shared Pointer Exception: " << e.what() << std::endl;
   }

   try
   {
     SharedPtr p2(SharedPtr(new int(100)));
    std::cout << "*p2 = " << *p2 << std::endl;
   }
   catch(const SharedPtrException& e)
   {
    std::cerr << "Shared Pointer Exception Caught" << e.what() << '\n';
   }
   
    return 0;
}