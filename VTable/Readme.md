VTable Simulation Project

This project implements a manual simulation of virtual tables (vtables) in C++ to demonstrate dynamic polymorphism mechanics. It includes:

    Custom virtual table implementation with function pointers.
    Support for type information (type_info) at runtime.
    Unit tests using Google Test to verify the correctness of vtable behavior.

Features

    Manual vtable setup for base and derived classes.
    Method call dispatch via function pointers.
    Runtime type info accessible through vtable.
    Unit tests covering calls and type information.

Project Structure

. ├── Src/ │
├── Base.cpp │ 
├── Derived.cpp │ 
├── TypeInfo.cpp 
├── Include/ │ 
├── Base.hpp │ 
├── Derived.hpp │ 
├── TypeInfo.hpp 
├── Tests/ │ 
├── test_VTable.cpp 
├── main.cpp 
├── Makefile 
├── README.md

Requirements
  
  
    C++17 compatible compiler (e.g., g++)
    Google Test framework installed
    Make utility

Build and Run

Clone the repository or download the source.

Build the main program:

     make
     ./program

Build and run tests: 

```bash
      make test
      ./test
``` 
