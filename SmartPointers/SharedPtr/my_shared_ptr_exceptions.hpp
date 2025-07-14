#pragma once

#include <exception>
#include <string>

class my_shared_ptr_exception : public std::exception
{
private:
        std::string message;
public:
        explicit my_shared_ptr_exception(const std::string& msg);
};