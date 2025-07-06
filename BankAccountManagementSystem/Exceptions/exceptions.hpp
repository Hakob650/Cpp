#pragma once

#include <exception>
#include <string>

class BankAccountException : public std::exception 
{
private:
    std::string message;

public:
    explicit BankAccountException(const std::string& msg);

    virtual const char* what() const noexcept override;
};

class BankSystemException : public std::exception 
{
private:
    std::string message;

public:
    explicit BankSystemException(const std::string& msg);

    virtual const char* what() const noexcept override;
};




