#include <iostream>

#include "../include/Base.hpp"
#include "../include/Derived.hpp"

int main()
{
    Base base_obj;
    base_obj.call_virtual(0);

    Derived derived_obj;
    derived_obj.call_virtual(0);

    return 0;
}
