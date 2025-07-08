#include "my_shared_ptr_exceptions.hpp"

SharedPtrExcpetion::SharedPtrExcpetion(const std::string& msg)
    : message(msg) {}

const char* SharedPtrExcpetion::what() const noexcept
{
    return message.c_str();
}