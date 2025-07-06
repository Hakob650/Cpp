Bank Account Management System

A simple C++ console application for managing bank accounts. This project demonstrates object-oriented programming concepts, exception handling, and unit testing with Google Test.
Features

    Create and manage multiple bank accounts

    Deposit and withdraw funds with balance validation

    Transfer funds between accounts

    Exception handling for invalid operations

    Unit tests covering core functionalities using Google Test

    Organized project structure with separate modules for accounts, system logic, and exceptions

    
    
Project Structure

BankAccountManagementSystem/
├── include/                   # Header files (.hpp)
│   ├── BankAccount.hpp
│   └── BankSystem.hpp
├── src/                       # Source files (.cpp)
│   ├── BankAccount.cpp
│   └── BankSystem.cpp
├── bank_system_exceptions/    # Custom exception classes
│   ├── exceptions.hpp
│   └── exceptions.cpp
├── googletests/               # Google Test unit tests
│   └── test_bank_management_system.cpp
├── main.cpp                   # Main application entry point
├── Makefile                   # Build configuration
└── README.md                  # Project documentation (this file)


Build and Run

Prerequisites
    
    C++ compiler supporting C++17
    
    Google Test library installed — see Google Test GitHub for installation instructions

Build application

```bash
make
./bank_app
```

Run tests

```bash
make test
./bank_tests
```


Clean build files
```bash
make clean
```
