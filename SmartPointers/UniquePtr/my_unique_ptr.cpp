#include "my_unique_ptr.hpp"
#include "my_unique_ptr_exceptions.hpp"

MyUniquePtr::MyUniquePtr(int* p )
    : ptr{p} {}

MyUniquePtr::~MyUniquePtr() 
{
    delete ptr;
}

MyUniquePtr::MyUniquePtr(MyUniquePtr&& other) noexcept
    : ptr{other.ptr}
    {
        other.ptr = nullptr;
    }

MyUniquePtr& MyUniquePtr::operator=(MyUniquePtr&& other) noexcept
{
    if(this != &other)
    {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

int& MyUniquePtr::operator*() const
{
    if(!ptr)
    {
        throw UniquePtrException("Dereferencing null pointer");
    }
    return *ptr;
}

int* MyUniquePtr::operator->() const
{
    if(!ptr)
    {
        throw UniquePtrException("Accessing null pointer");
    }
    return ptr;
}

int* MyUniquePtr::get() const
{
    return ptr;
}

void MyUniquePtr::reset(int* p)
{
    if(ptr != p)
    {
        delete ptr;
        ptr = p;
    }
}

int* MyUniquePtr::release()
{
    if(!ptr)
    {
        throw UniquePtrException("Releasing  null unique_ptr");
    }
    int* tmp = ptr;
    ptr = nullptr;
    return tmp;
}

MyUniquePtr::operator bool() const
{
    return ptr != nullptr;
}











