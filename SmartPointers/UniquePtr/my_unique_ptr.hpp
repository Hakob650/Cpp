#pragma once

#include <iostream>
#include <utility>
#include "my_unique_ptr_exceptions.hpp"

template <typename T>
class my_unique_ptr
{
private:
        T* ptr;

        my_unique_ptr(const my_unique_ptr& other) = delete;

        my_unique_ptr& operator=(const my_unique_ptr& other) = delete;
public:
        my_unique_ptr(T* p = nullptr)
            : ptr{p} {}

        ~my_unique_ptr()
        {
            delete ptr;
        }

        my_unique_ptr(my_unique_ptr&& other) noexcept
            : ptr(other.ptr)
            {
                other.ptr = nullptr;
            }

        my_unique_ptr& operator=(my_unique_ptr&& other) noexcept
        {
            if(this != &other)
            {
                delete ptr;
                ptr = other.ptr;
                other.ptr = nullptr;
            }

            return *this;
        }

        T* release() noexcept
        {
            std::exchange(ptr, nullptr);
        }

        void reset(T* p = nullptr) noexcept
        {
            T* old_ptr = ptr;
            ptr = p;
            delete old_ptr;
        }

        void swap(my_unique_ptr& other) noexcept
        {
            std::swap(this->ptr, other.ptr);
        }

        T* get() const noexcept
        {
            return ptr;
        }

        T& operator*()
        {
            if(!ptr)
            {
                throw my_unique_ptr_exceptions("Dereferencing null pointer");
            }
            return *ptr;
        }

        const T& operator*() const
        {
            if(!ptr)
            {
                throw my_unique_ptr_exceptions("Dereferencing null pointer");
            }
            return *ptr;
        }

        T* operator->() 
        {
            if(!ptr)
            {
                throw my_unique_ptr_exceptions("Accessing null pointer");
            }
            return ptr;
        }

        const T* operator->() const
        {
            if(!ptr)
            {

            }
            return ptr;
        }

        explicit operator bool() const noexcept
        {
            return ptr != nullptr;
        } 

        T& operator[](std::size_t i) noexcept
        {
            return ptr[i];
        }

        const T& operator[](std::size_t i) const noexcept
        {
            return ptr[i];
        }

        friend std::ostream& operator<<(std::ostream& output_stream, const my_unique_ptr& ptr)
        {
            if(ptr)
            {
                output_stream << ptr;
            }
            else
            {
                output_stream << "nullptr";
            }
            return output_stream;
        }

        friend bool operator==(const my_unique_ptr& lhs, std::nullptr_t) noexcept
        {
            return lhs.get() == nullptr;
        }

        friend bool operator==(std::nullptr_t, const my_unique_ptr& rhs) noexcept
        {
            return rhs.get() == nullptr;
        }

        friend bool operator==(const my_unique_ptr& lhs, const my_unique_ptr& rhs) noexcept
        {
            return lhs.get() == rhs.get();
        }

        friend bool operator!=(const my_unique_ptr<T>& lhs, std::nullptr_t) noexcept
        {
            return lhs.get() != nullptr;
        }

        friend bool operator!=(std::nullptr_t, const my_unique_ptr<T>& rhs) noexcept
        {
            return rhs.get() != nullptr;
        }

        friend bool operator!=(const my_unique_ptr<T>& lhs, const my_unique_ptr<T>& rhs) noexcept
        {
            return lhs.get() != rhs.get();
        }

        friend bool operator<(const my_unique_ptr<T>& lhs, std::nullptr_t) noexcept
        {
            return lhs.get() < nullptr;
        }

        friend bool operator<(std::nullptr_t, const my_unique_ptr<T>& rhs) noexcept
        {
            return rhs.get() < nullptr;
        }

        friend bool operator<(const my_unique_ptr<T>& lhs, const my_unique_ptr<T>& rhs) noexcept
        {
            return lhs.get() < rhs.get();
        }

        friend bool operator<=(const my_unique_ptr<T>& lhs, std::nullptr_t) noexcept
        {
            return lhs.get() <= nullptr;
        }
  
        friend bool operator<=(std::nullptr_t, const my_unique_ptr<T>& rhs) noexcept
        {
            return rhs.get() <= nullptr;
        }
        
        friend bool operator<=(const my_unique_ptr<T>& lhs, const my_unique_ptr<T>& rhs) noexcept
        {
            return lhs.get() <= rhs.get();
        }

        friend bool operator>(const my_unique_ptr<T>& lhs, std::nullptr_t) noexcept
        {
            return lhs.get() > nullptr;
        }

        friend bool operator>(std::nullptr_t, const my_unique_ptr<T>& rhs) noexcept
        {
            return rhs.get() > nullptr;
        }
       
        friend bool operator>(const my_unique_ptr<T>& lhs, const my_unique_ptr<T>& rhs) noexcept
        {
            return lhs.get() > rhs.get();
        }

         
        friend bool operator>=(const my_unique_ptr<T>& lhs, std::nullptr_t) noexcept
        {
            return lhs.get() >= nullptr;
        }
        
        friend bool operator>=(std::nullptr_t, const my_unique_ptr<T>& rhs) noexcept
        {
            return rhs.get() >= nullptr;
        }

        friend bool operator>=(const my_unique_ptr<T>& lhs, const my_unique_ptr<T>& rhs) noexcept
        {
            return lhs.get() >= rhs.get();
        }
};
