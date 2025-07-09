#pragma once

#include <exception>
#include <string>

class SharedPtrException : public std::exception
{
private:
        std::string message;
public:
        explicit SharedPtrException(const std::string& msg);

        const char* what() const noexcept override;
};