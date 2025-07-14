#include <iostream>
#include "my_shared_ptr.hpp"

class Test 
{
public:
    Test(int val) : value(val) 
    {
        std::cout << "Test(" << value << ") constructed\n";
    }

    ~Test() 
    {
        std::cout << "Test(" << value << ") destructed\n";
    }

    void print() const 
    {
        std::cout << "Value = " << value << std::endl;
    }
private:
    int value;
};

std::ostream& operator<<(std::ostream& os, const Test& t) 
{
    os << "Test object";
    return os;
}

int main() 
{
    try 
    {
        {
            my_shared_ptr<Test> ptr1(new Test(42));
            std::cout << "Use count after ptr1: " << ptr1.use_count() << "\n";

            {
                my_shared_ptr<Test> ptr2 = ptr1;
                std::cout << "Use count after ptr2: " << ptr1.use_count() << "\n";

                ptr2->print();
            }

            std::cout << "Use count after ptr2 goes out of scope: " << ptr1.use_count() << "\n";

            my_shared_ptr<Test> ptr3 = std::move(ptr1);
            std::cout << "Use count after move to ptr3: " << ptr3.use_count() << "\n";

            if (!ptr1) 
            {
                std::cout << "ptr1 is now null after move.\n";
            }

            std::cout << *ptr3 << "\n";
        }

        std::cout << "All shared pointers are now out of scope.\n";

    } catch (const my_shared_ptr_exception& e) 
    {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}
