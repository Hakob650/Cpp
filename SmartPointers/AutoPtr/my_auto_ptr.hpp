#pragma once

class my_auto_ptr
{
private:
        int* ptr;
public:
        explicit my_auto_ptr(int* p = nullptr);

        my_auto_ptr(my_auto_ptr& other);

        my_auto_ptr& operator=(my_auto_ptr& other);

       ~my_auto_ptr();

        int& operator*() const;

        int* operator->() const;
 
        int* get() const;

        int* release();

        void reset(int* p = nullptr);

        explicit operator bool() const;
};
