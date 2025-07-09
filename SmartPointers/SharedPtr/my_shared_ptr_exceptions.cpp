#include "my_shared_ptr_exceptions.hpp"

SharedPtrException::SharedPtrException(const std::string& msg)
    : message(msg) {}

const char* SharedPtrException::what() const noexcept
{
    return message.c_str();
}