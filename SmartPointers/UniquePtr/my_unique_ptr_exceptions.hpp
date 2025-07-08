#pragma once

#include <exception>
#include <string>

class UniquePtrException : public std::exception
{
private:
        std::string message;
public:
        UniquePtrException(const std::string& msg);

        const char* what() const noexcept override;
};