#pragma once

#include <exception>
#include <string>

class auto_ptr_exception : public std::exception
{
private:
        std::string message;
public:
    explicit auto_ptr_exception(const std::string& msg) ;

    const char* what() const  noexcept override;
};