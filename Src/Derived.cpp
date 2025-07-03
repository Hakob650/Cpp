#include <iostream>
#include "../include/Derived.hpp"

Derived::Derived()
{
    derived_vptr = new VTable{new TypeInfo("Derived"), new ThunkFunctions[1], 0, 0, 0};
    
    derived_vptr->functions[0] = &Derived::derived_thunk;
}   

void Derived::foo()
{
    std::cout << "Derived::foo()" << std::endl;
}

void Derived::derived_thunk(void* obj)
{
    Derived* derived = static_cast<Derived*>(obj);
    derived->foo();
}

void Derived::print_type() const
{
    std::cout << derived_vptr->type_info->className << std::endl;

}