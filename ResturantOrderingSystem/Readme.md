# 🍽️ Restaurant Management System

A C++ console application simulating a restaurant backend system using object-oriented programming. This system includes customer management, dish organization, ordering, and unit testing via Google Test.

---

## 🧩 Features

- Manage menu items: Appetizers, Entrees, Desserts
- Place and view customer orders
- Track order history per customer
- Designed with modern C++ (C++17), copy/move semantics
- Automated unit testing using Google Test

---

## 📁 Project Structure
.
├── include/ # Header files (classes, interfaces)
├── src/ # Source code
├── Test/ # Unit test source files
├── main.cpp # Application entry point
├── Makefile # Build configuration
└── README.md # Documentation


---

## 🛠️ Building the Project

To compile the main application:

  ```bash
    make
  ```

To clean up all generated files:
  ```bash
    make clean
  ```

▶️ Running the Application
  After compiling, run the application:
    ```bash
      ./resturant_app
    ```
    (Make sure your main.cpp defines an entry point using the Resturant class.)

✅ Running Unit Tests
Make sure you have Google Test installed. To build and run tests:

```bash
make test
```
This builds test_resturant and runs all unit tests in Test/test_resturantSystem.cpp.


🧪 Test Coverage Overview
The test suite covers:

  ✅ Dish constructors, getters, display

  ✅ Derived classes: Appetizer, Entree, Dessert

  ✅ Customer operations: creation, copying, moving, placing/viewing orders

  ✅ Menu operations: add, lookup, display

  ✅ Order construction, copy/move, total calculation

  ✅ Resturant behavior: menu access, placing/viewing orders

  🔧 Dependencies
C++17 compatible compiler (e.g. g++)

Google Test for unit testing
Install on Debian-based systems:

```bash  
  sudo apt-get install libgtest-dev
  sudo apt-get install cmake
  cd /usr/src/gtest
  sudo cmake .
  sudo make
  sudo cp *.a /usr/lib
```
















