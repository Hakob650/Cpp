#ifndef VTABLE_HPP
#define VTABLE_HPP

#include "TypeInfo.hpp"

using ThunkFunctions = void(*)(void*);

struct VTable
{
    TypeInfo* type_info;
    ThunkFunctions* functions;

    int callOffset;
    int topOffset;
    int baseOffset;
};

#endif