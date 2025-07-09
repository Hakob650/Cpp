#include <iostream>
#include "my_shared_ptr.hpp"
#include "my_shared_ptr_exceptions.hpp"

SharedPtr::SharedPtr(int* p) 
    : ptr(p), ref_count(p ? new int(1) : nullptr) {}


SharedPtr::SharedPtr(const SharedPtr& other)
    : ptr(other.ptr), ref_count(other.ref_count)
    {
        if(ref_count)
        {
            ++(*ref_count);
        }
    }

SharedPtr& SharedPtr::operator=(const SharedPtr& other)
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


void SharedPtr::custom_deleter()
{
    if(ref_count)
    {
        --(*ref_count);
        if(*ref_count == 0)
        {
            delete ptr;
            delete ref_count;
            ptr = nullptr;
            ref_count = nullptr;
        }
    }
}


int& SharedPtr::operator*() const
{
    if(!ptr)
    {
        throw SharedPtrException("Dereferencing null pointer");
    }
    return *ptr;
}

int* SharedPtr::operator->() const
{
    if(!ptr)
    {
        throw SharedPtrException("Accessing null pointer");
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
