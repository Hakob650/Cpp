#include <iostream>
#include <cstring>
#include "String.hpp"

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

bool operator==(const String& lhs,const String& rhs)
{
    return std::strcmp(lhs.data_,rhs.data_) == 0;
}
		
bool operator!=(const String& lhs,const String& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String& lhs,const String& rhs)
{
    return std::strcmp(lhs.data_,rhs.data_) < 0;
}

bool operator>(const String& lhs,const String& rhs)
{
    return std::strcmp(lhs.data_,rhs.data_) > 0;
}

bool operator<=(const String& lhs,const String& rhs)
{
    return std::strcmp(lhs.data_,rhs.data_) <= 0;
}

bool operator>=(const String& lhs,const String& rhs)
{
     return std::strcmp(lhs.data_,rhs.data_) >= 0;
}

String operator+(const String& lhs,const String& rhs)
{   
    size_t new_size = lhs.size + rhs.size;
    
    char* new_data = new char[new_size + 1];
    
    std::strcpy(new_data,lhs.data_);
    
    std::strcat(new_data,rhs.data_);
    
    String res(new_data);
    
    delete[] new_data;
    
    return  res;
}

String& String::operator+=(const String& rhs)
{
    *this = *this + rhs;
    return *this;
}

char& String::operator[](size_t index)
{
    return data_[index];
}

const char& String::operator[](size_t index) const
{
    return data_[index];
}

std::istream& operator>>(std::istream& is,String& rhs)
{
    char buff[1024];
    is >> buff;

    rhs = String(buff);

    return is;
}

std::ostream& operator<<(std::ostream& os,const String& rhs)
{
    os<<rhs.c_str();
    return os;
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