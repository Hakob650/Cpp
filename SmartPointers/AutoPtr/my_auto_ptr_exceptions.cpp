#include <iostream>
#include "my_auto_ptr_exceptions.hpp"

auto_ptr_exception::auto_ptr_exception(const std::string& msg)
    : message(msg) {}

const char* auto_ptr_exception::what() const noexcept
{
    return message.c_str();
}
