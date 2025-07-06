#include "exceptions.hpp"

BankAccountException::BankAccountException(const std::string& msg) 
    : message(msg) {}

const char* BankAccountException::what() const noexcept
{
        return message.c_str();
}

BankSystemException::BankSystemException(const std::string& msg)
    : message(msg)  {}

const char* BankSystemException::what() const noexcept 
{
    return message.c_str();
}




