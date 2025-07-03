#ifndef DERIVED_HPP
#define DERIVED_HPP

#include "VTable.hpp"
#include "Base.hpp"

class Derived : public Base
{
private:
        VTable* derived_vptr;
public:
        Derived();

        void foo() override;

        static void derived_thunk(void* obj);

        void print_type() const;
};

#endif