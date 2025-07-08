#include <iostream>
#include "my_shared_ptr.hpp"
#include "my_shared_ptr_exceptions.hpp"

SharedPtr::SharedPtr(int* p) 
    : ptr(p), ref_count(nullptr) {}

SharedPtr::SharedPtr(const SharedPtr& other)
    : ptr(other.ptr), ref_count(other.ref_count)
    {
        if(ref_count)
        {
            ++(*ref_count);
        }
    }

SharedPtr& SharedPtr::operator=(SharedPtr& other)
{
    if(this != &other)
    {
        custom_deletor();
        ptr = other.ptr;
        ref_count = other.ref_count;
        if(ref_count)
        {
            ++(*ref_count);
        }
    }
    return *this;
}

SharedPtr::~SharedPtr()
{
    custom_deletor();
}


void SharedPtr::custom_deletor()
{
    if(ref_count)
    {
        --(*ref_count);
        delete ptr;
        delete ref_count;
    }
}
int& SharedPtr::operator*() const
{
    if(!ptr)
    {
        throw SharedPtrExcpetion("Dereferencing null pointer");
    }
    return *ptr;
}

int* SharedPtr::operator->() const
{
    if(!ptr)
    {
        throw("Accessing null pointer");
    }
    return ptr;
}

int* SharedPtr::get() const
{
    return ptr;
}

int SharedPtr::use_count() const
{
    return ref_count ? *ref_count : 0;
}

SharedPtr::operator bool() const
{
    return ptr != nullptr;
}