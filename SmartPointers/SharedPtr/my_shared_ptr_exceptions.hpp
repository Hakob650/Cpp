#pragma once

#include <exception>
#include <string>

class SharedPtrExcpetion : public std::exception
{
private:
        std::string message;
public:
        explicit SharedPtrExcpetion(const std::string& msg);

        const char* what() const noexcept override;
};