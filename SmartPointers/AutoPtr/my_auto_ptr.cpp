#include <iostream>
#include "my_auto_ptr_exceptions.hpp"
#include "my_auto_ptr.hpp"

my_auto_ptr::my_auto_ptr(int* p)
    : ptr{p} {}

//copy ctor transfers ownership! dangerous!
my_auto_ptr::my_auto_ptr(my_auto_ptr& other)
    : ptr{other.ptr} {
        other.ptr = nullptr;
    }

my_auto_ptr& my_auto_ptr::operator=(my_auto_ptr& other)
{
    if(this != &other)
    {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

my_auto_ptr::~my_auto_ptr() { delete ptr; }

int& my_auto_ptr::operator*() const 
{
    if(!ptr)
    {
        throw auto_ptr_exception("Dereferencing null pointer");
    } 
    return *ptr; 
}

int* my_auto_ptr::operator->() const 
{
    if(!ptr)
    {
        throw auto_ptr_exception("Accessing null pointer");
    } 
    return ptr; 
}

int* my_auto_ptr::get() const { return ptr; }

int* my_auto_ptr::release()
{
    if(!ptr)
    {
        throw auto_ptr_exception("Release called on null pointer");
    }
    int* tmp = ptr;
    ptr = nullptr;
    return tmp;
}

void my_auto_ptr::reset(int* p)
{
    if(ptr != p)
    {
        delete ptr;
        ptr = p;
    }
}

my_auto_ptr:: operator bool() const { return ptr != nullptr; }


