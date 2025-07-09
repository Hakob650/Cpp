# MyUniquePtr – Custom C++ Unique Pointer

`MyUniquePtr` is a custom C++ smart pointer implementation that provides **exclusive ownership** of dynamically allocated memory. It mimics the behavior of `std::unique_ptr` and includes:

- Move-only semantics
- Automatic memory management (RAII)
- Null pointer safety with exceptions
- Basic unit testing using Google Test

---

## 🚀 Features

- ✅ Exclusive ownership (`MyUniquePtr` cannot be copied)
- ✅ Move constructor and move assignment
- ✅ `reset()`, `release()`, and `get()` functionality
- ✅ Dereference (`*`) and arrow (`->`) operators with exception safety
- ✅ Custom `UniquePtrException` for null dereferencing/access

---

## 📁 File Structure

.
├── my_unique_ptr.hpp # MyUniquePtr class declaration
├── my_unique_ptr.cpp # MyUniquePtr method definitions
├── my_unique_ptr_exceptions.hpp # UniquePtrException class
├── test_unique_ptr.cpp # Google Test unit tests
├── main.cpp # Sample usage
├── Makefile # Build and test automation
└── README.md # Project description


---

## ⚙️ Build Instructions

To build the main demo:

```bash
    make
    ./unique_ptr_demo
```

To clean and rebuild everything:

```bash
    make rebuild
```

🧪 Running Unit Tests
Make sure Google Test is installed.

To compile and run tests:

```bash
    make test
```

Or manually:

```bash   
    g++ -std=c++17 test_unique_ptr.cpp my_unique_ptr.cpp my_unique_ptr_exceptions.cpp -lgtest -lgtest_main -pthread -o run_tests
    ./run_tests
```







