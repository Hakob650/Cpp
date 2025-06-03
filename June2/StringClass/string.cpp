#include <iostream>
#include <cstring>
#include "string.h"

//default constructor
String::String() : data_(nullptr) , size(0)
{
	data_ = new char[1];
	data_[0] = '\0';
}

//parameterized constructor
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

String::~String()
{
	delete[] data_;
}

size_t String::length() const
{
	return size;
}

const char* String::c_str() const 
{
	return data_;
}

void String::print() const
{
	std::cout<<data_<<std::endl;
}

