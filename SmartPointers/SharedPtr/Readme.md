# SharedPtr - Custom Shared Pointer Implementation in C++

## Overview

`SharedPtr` is a simplified reference-counted smart pointer that manages shared ownership of a dynamically allocated `int`. It keeps track of how many `SharedPtr` instances share the same resource and automatically deletes the resource when the last owner is destroyed.

## Features

- Reference counting to manage shared ownership.
- Copy constructor and copy assignment operator increase the reference count.
- Destructor decreases the reference count and deletes the resource when no owners remain.
- Supports:
  - Dereference operator (`*`) and arrow operator (`->`).
  - `get()` method to access the raw pointer.
  - `use_count()` method to get the current number of owners.
  - Boolean conversion to check if the pointer is valid.
- Throws `SharedPtrException` on dereferencing or accessing a null pointer.

## Usage Example

```cpp
#include "my_shared_ptr.hpp"
#include <iostream>

int main() {
    SharedPtr sp1(new int(42));
    std::cout << "Use count after sp1 creation: " << sp1.use_count() << std::endl; // 1

    SharedPtr sp2 = sp1; // Shared ownership
    std::cout << "Use count after sp2 copy: " << sp1.use_count() << std::endl; // 2

    std::cout << "Value pointed by sp2: " << *sp2 << std::endl; // 42

    sp1 = SharedPtr(); // sp1 releases ownership
    std::cout << "Use count after sp1 reset: " << sp2.use_count() << std::endl; // 1

    return 0;
}
```

Exception Handling

SharedPtr throws SharedPtrException if you attempt to dereference or access members through a null pointer.

SharedPtr sp;
try {
    *sp;  // Throws SharedPtrException
} catch (const SharedPtrException& e) {
    std::cerr << e.what() << std::endl;
}


Building and Testing

```bash
make all       # Compile the project
make test      # Run the unit tests for SharedPtr
./test_shared_ptr  # Execute the tests binary
```

Limitations

    Only manages pointers to int (can be extended via templates).

    No support for custom deleters.

    Not thread-safe.

    For production code, prefer std::shared_ptr.