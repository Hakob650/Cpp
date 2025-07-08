#pragma once

class MyUniquePtr
{
private:
        int* ptr;
public:
        explicit MyUniquePtr(int* p= nullptr);
        ~MyUniquePtr();
        MyUniquePtr(MyUniquePtr&& other) noexcept;
        MyUniquePtr& operator=(MyUniquePtr&& other) noexcept;
        
        MyUniquePtr(const MyUniquePtr& other) = delete;
        MyUniquePtr& operator=(MyUniquePtr& other) = delete;

        int& operator*() const;
        int* operator->() const;
        int* get() const;

        int* release();
        void reset(int* p);

        explicit operator bool() const;
};