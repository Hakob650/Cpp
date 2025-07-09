# my_auto_ptr - Custom Auto Pointer Implementation in C++

## Overview

`my_auto_ptr` is a simplified, educational implementation of an auto pointer managing exclusive ownership of a dynamically allocated `int`.

### Features

- Exclusive ownership: only one `my_auto_ptr` owns the resource at a time.
- Transfers ownership on copy or assignment.
- Supports:
  - Dereference (`*`) and arrow (`->`) operators.
  - `get()`, `release()`, and `reset()` member functions.
  - Boolean conversion to check if the pointer is non-null.
- Throws `auto_ptr_exception` on invalid operations such as dereferencing null pointers.

### Usage

```cpp
#include "my_auto_ptr.hpp"
#include <iostream>

int main() {
    my_auto_ptr ap(new int(10));
    std::cout << *ap << std::endl;

    // Ownership transfer
    my_auto_ptr ap2 = ap; // ap now null, ap2 owns the pointer

    return 0;
}
```

Exception Handling

Throws auto_ptr_exception when dereferencing or accessing null pointers.
Building and Testing

Use the provided Makefile to build the demo and tests:

make all
make test
./test_auto_ptr

Notes

    This is for learning purposes only.

    std::auto_ptr is deprecated; prefer std::unique_ptr in real code.

