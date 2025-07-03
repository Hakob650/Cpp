#ifndef TYPEINFO_HPP
#define TYPEINFO_HPP

#include <string>

struct TypeInfo
{
    std::string className;
    TypeInfo(const std::string& name);
};

#endif