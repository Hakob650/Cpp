#pragma once

#include <iostream>

template <typename T>
struct control_block
{
    T* ptr;
    int shared_count;
    int weak_count;

    control_block(T* p)
        : ptr(p), shared_count(1), weak_count(0) {}

    ~control_block()
        {
            std::cout << "Control Block Destructed!" << std::endl;
        }
};