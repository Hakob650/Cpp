#pragma once

#include <iostream>
#include <algorithm>
#include "control_block.hpp"
#include "my_shared_ptr_exceptions.hpp"

template <typename T>
class my_shared_ptr
{
private:
        T* ptr;
        control_block<T>* cb;


    void release()
    {
        if(cb->shared_count)
        {
            if(--cb->shared_count == 0)
            {
                std::cout << "deleting managed object and control block" << std::endl;

                delete cb;
            }
        }
    }
public:
        explicit my_shared_ptr(T* p = nullptr)
            : ptr(p), cb(p ? new control_block<T>(p) : nullptr) {}

        my_shared_ptr(const my_shared_ptr& other)
            : ptr(other.ptr), cb(other.cb)
            {
                if(cb)
                {
                    ++cb->shared_count;
                }
                std::cout << "shared ptr copied, count = " << (cb ? cb->shared_count : 0) << std::endl;
            }
        
        my_shared_ptr& operator=(const my_shared_ptr& other)
        {
                if(this != &other)
                {
                    release();
                    ptr = other.ptr;
                    cb = other.cb;

                    if(cb)
                    {
                        ++cb->shared_count;
                    }
                }
                return *this;

                std::cout << "Copy Assignment Operator Called" << std::endl;
        }

        my_shared_ptr(my_shared_ptr&& other) noexcept
            :ptr(other.ptr), cb(other.cb)
            {
                    other.ptr = nullptr;
                    
                    other.cb = nullptr;   
                    
                    std::cout << "Move Constructor Called" << std::endl;
            }

            my_shared_ptr& operator=(my_shared_ptr&& other) noexcept
            {
                if(this != &other)
                {
                    release(); 

                    ptr = other.ptr;

                    cb = other.cb;

                    other.ptr = nullptr;

                    other.cb = nullptr;
                }
                
                return *this;

                std::cout << "Move Assignment Operator Called" << std::endl;
            }

            T* operator->()
            {
                if(!ptr)
                {
                    throw my_shared_ptr_exception("Dereferencing null pointer");
                }
                return ptr;
            }

            const T* operator->() const
            {
                if(!ptr)
                {
                    throw my_shared_ptr_exception("Dereferencing null pointer");
                }
                return ptr;
            }

            T& operator*() 
            {
                if(!ptr)
                {
                    throw my_shared_ptr_exception("Accessing member of null shared pointer");
                }
                return *ptr;
            }

            const T& operator*() const
            {
                 if(!ptr)
                {
                    throw my_shared_ptr_exception("Accessing member of null shared pointer");
                }
                return ptr;
            }

            int use_count() const
            {
                return cb ? cb->shared_count : 0;
            }

            void swap(my_shared_ptr& other) noexcept
            {
                std::swap(ptr, other.ptr);
                
                std::swap(cb->shared_count, other.cb->shared_count);
            } 

            explicit operator bool() const noexcept
            {
                return ptr != nullptr;
            }

            friend bool operator==(const my_shared_ptr& lhs, std::nullptr_t)
            {
                return lhs.get() == nullptr;
            }

            friend bool operator==(std::nullptr_t, const my_shared_ptr& rhs)
            {
                return rhs.get() == nullptr;
            }

            friend bool operator==(const my_shared_ptr& lhs, const my_shared_ptr& rhs)
            {
                return lhs.get() == rhs.get();
            }

            friend bool operator!=(const my_shared_ptr& lhs, std::nullptr_t)
            {
                return lhs.get() != nullptr;
            }

            friend bool operator!=(std::nullptr_t, const my_shared_ptr& rhs)
            {
                return rhs.get() != nullptr;
            }

            friend bool operator!=(const my_shared_ptr& lhs, const my_shared_ptr& rhs)
            {
                return lhs.get() != rhs.get();
            }

            friend bool operator<(const my_shared_ptr& lhs, std::nullptr_t)
            {
                return lhs.get() < nullptr;
            }

            friend bool operator<(std::nullptr_t, const my_shared_ptr& rhs)
            {
                return rhs.get() < nullptr;
            }

            friend bool operator<(const my_shared_ptr& lhs, const my_shared_ptr& rhs)
            {
                return lhs.get() < rhs.get();
            }

            friend bool operator<=(const my_shared_ptr& lhs, std::nullptr_t)
            {
                return lhs.get() <= nullptr;
            }

            friend bool operator<=(std::nullptr_t, const my_shared_ptr& rhs)
            {
                return rhs.get() <= nullptr;
            }

            friend bool operator<=(const my_shared_ptr& lhs, const my_shared_ptr& rhs)
            {
                return lhs.get() <= rhs.get();
            }
            friend bool operator>(const my_shared_ptr& lhs, std::nullptr_t)
            {
                return lhs.get() > nullptr;
            }

            friend bool operator>(std::nullptr_t, const my_shared_ptr& rhs)
            {
                return rhs.get() > nullptr;
            }

            friend bool operator>(const my_shared_ptr& lhs, const my_shared_ptr& rhs)
            {
                return lhs.get() > rhs.get();
            }

            friend bool operator>=(const my_shared_ptr& lhs, std::nullptr_t)
            {
                return lhs.get() >= nullptr;
            }

            friend bool operator>=(std::nullptr_t, const my_shared_ptr& rhs)
            {
                return rhs.get() >= nullptr;
            }

            friend bool operator>=(const my_shared_ptr& lhs, const my_shared_ptr& rhs)
            {
                return lhs.get() >= rhs.get();
            }

            friend std::ostream& operator<<(std::ostream& output_stream, const my_shared_ptr& shared_ptr)
            {
                if(shared_ptr->ptr)
                {
                    output_stream << " *shared_ptr->ptr = " << *shared_ptr->ptr << std::endl;
                }
                else
                {
                    output_stream << "nullptr" << std::endl;
                }

                return output_stream;
            }
};
