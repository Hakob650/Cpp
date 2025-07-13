#pragma once

#include <iostream>
#include <algorithm>
#include "control_block.hpp"

template <typename T>
class my_shared_ptr
{
private:
        T* ptr;
        control_block<T>* control_block;


    void release()
    {
        if(control_block->shared_count)
        {
            if(--control_block->shared_count == 0)
            {
                std::cout << "deleting managed object and control block" << std::endl;

                delete control_block;
            }
        }
    }
public:
        explicit my_shared_ptr(T* p = nullptr)
            : ptr(p), control_block(p ? new control_block<T> p : nullptr) {}

        my_shared_ptr(const my_shared_ptr& other)
            : ptr(other.ptr), control_block(other.control_block)
            {
                if(control_block)
                {
                    ++control_block->shared_count;
                }
                std::cout << "shared ptr copied, count = " << (control_block ? control_block->shared_count : 0) << std::endl;
            }
        
        my_shared_ptr& operator=(const my_shared_ptr& other)
        {
                if(this != &other)
                {
                    release();
                    ptr = other.ptr;
                    control_block = other.control_block;

                    if(control_block)
                    {
                        ++control_block->shared_count;
                    }
                }
                return *this;

                std::cout << "Copy Assignment Operator Called" << std::endl;
        }

        my_shared_ptr(my_shared_ptr&& other) noexcept
            :ptr(other.ptr), control_block(other.control_block)
            {
                    other.ptr = nullptr;
                    
                    other.control_block = nullptr;   
                    
                    std::cout << "Move Constructor Called" << std::endl;
            }

            my_shared_ptr& operator=(my_shared_ptr&& other) noexcept
            {
                if(this != &other)
                {
                    release(); 

                    ptr = other.ptr;

                    control_block = other.control_block;

                    other.ptr = nullptr;

                    other.control_block = nullptr;
                }
                
                return *this;

                std::cout << "Move Assignment Operator Called" << std::endl;
            }

            T* operator->()
            {
                return ptr;
            }

            const T* operator->() const
            {
                return ptr;
            }

            T& operator*() 
            {
                return *ptr;
            }

            const T& operator*() const
            {
                return ptr;
            }

            int use_count() const
            {
                return control_block ? control_block->shared_count : 0;
            }

            void swap(my_shared_ptr& other) noexcept
            {
                std::swap(ptr, other.ptr);
                
                std::swap(control_block->shared_count, other.control_block->shared_count);
            } 

            explicit operator bool() const noexcept
            {
                return ptr != nullptr;
            }

            friend bool operator==(const my_shared_ptr& lhs, std::nullptr_t)
            {
                return lhs.get() == nullptr;
            }

            friend bool operator==(const my_shared_ptr& rhs, std::nullptr_t)
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

            friend bool operator!=(const my_shared_ptr& rhs, std::nullptr_t)
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

            friend bool operator<(const my_shared_ptr& rhs, std::nullptr_t)
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

            friend bool operator<=(const my_shared_ptr& rhs, std::nullptr_t)
            {
                return rhs.get() <= nullptr;
            }

            friend bool operator>(const my_shared_ptr& lhs, std::nullptr_t)
            {
                return lhs.get() > nullptr;
            }

            friend bool operator>(const my_shared_ptr& rhs, std::nullptr_t)
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

            friend bool operator>=(const my_shared_ptr& rhs, std::nullptr_t)
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
