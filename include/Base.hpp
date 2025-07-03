#ifndef BASE_HPP
#define BASE_HPP

#include "VTable.hpp"

class Base
{
private:
        VTable* base_vptr;
public:
        Base();

        static void base_thunk(void* obj);

        void call_virtual(int index);

        virtual void foo();

        void print_type() const;
};

#endif