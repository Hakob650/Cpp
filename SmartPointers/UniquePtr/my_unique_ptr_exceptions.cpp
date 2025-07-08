#include "my_unique_ptr_exceptions.hpp"

UniquePtrException::UniquePtrException(const std::string& msg)
    : message{msg} {}

const char* UniquePtrException::what() const noexcept
{
    return message.c_str();
}