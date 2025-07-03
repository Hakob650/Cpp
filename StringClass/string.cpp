#include <iostream>
#include <cstring>
#include "string.hpp"

String::String()
    : data_(nullptr),size(0) {
        data_ = new char[1];
        data_[0] = '\0';
    }

String::String(const char* str)
{
    if(str)
    {
       size = std::strlen(str);
       data_ = new char[size + 1];
       std::strcpy(data_,str);
    }
    else
    {
        size = 0;
        data_ = new char[1];
        data_[0] = '\0';
    } 
}

String::String(const String& other)
: size(other.size) {
    if(other.data_)
    {
    data_ = new char[size + 1];
    std::strcpy(data_,other.data_);
    }
    else
    {
        data_ = new char[1];
        data_[0] = '\0';
    }
}

String::String(String&& other)
    : data_(other.data_),size(other.size) {
        other.data_ = nullptr;
        other.size = 0;
    }

String& String::operator=(const String& other)
{
    if(this != &other)
    {
        delete[] data_;
        size = other.size;
        if(other.data_)
        {
            data_ = new char[size + 1];
            std::strcpy(data_,other.data_);
        }
        else
        {
            data_ = new char[1];
            data_[0] = '\0';
        }
    }
    return *this;
}

String& String::operator=(String&& other)
{
    if(this != &other)
    {
        delete[] data_;
        data_ = other.data_;
        size = other.size;
        
        other.data_ = nullptr;
        other.size = 0;
    }
    return *this;
}

String::~String()
{
    delete[] data_;
    data_ = nullptr;
    size = 0;
}

size_t String::length() const
{
    return std::strlen(data_);
}

const char* String::c_str() const
{
    return data_ ? data_ : "";
}

void String::print() const
{
    if(data_)
    {
        std::cout<< data_ <<std::endl;
    }
    else
    {
        std::cout<<"String is empty"<<std::endl;
    }
}

