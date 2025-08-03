#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <iostream>

template <void (*Function)()>
class Executor
{
    public:
        void run() {
            Function();
        }
};

#endif