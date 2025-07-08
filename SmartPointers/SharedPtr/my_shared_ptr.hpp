#pragma once

class SharedPtr
{
private:
        int* ptr;
        int* ref_count;

        void custom_deletor();
public:
        explicit SharedPtr(int* p = nullptr);

        SharedPtr(const SharedPtr& other);

        SharedPtr& operator=(SharedPtr& other);

        ~SharedPtr();

        int& operator*() const;

        int* operator->() const;

        int* get() const;

        int use_count() const;

        explicit operator bool() const;
};