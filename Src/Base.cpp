#include  <iostream>
#include "../include/Base.hpp"
#include "../include/TypeInfo.hpp"
#include "../include/VTable.hpp"

Base::Base()
{
    base_vptr = new VTable{new TypeInfo("Base"), new ThunkFunctions[1], 0, 0, 0};
    
    base_vptr->functions[0] = &Base::base_thunk; 
}

void Base::base_thunk(void* obj)
{
    Base* base_ptr = static_cast<Base*>(obj);
    
    base_ptr->foo();
}

void Base::call_virtual(int index)
{
    base_vptr->functions[0](this);
}

void Base::foo()
{
    std::cout << " Base::foo() " << std::endl;
}

void Base::print_type() const
{
    std::cout << base_vptr->type_info->className << std::endl;
}


