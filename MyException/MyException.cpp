#include <iostream>
#include <stdexcept>
#include <string>

class DivisionByZero : public std::runtime_error
{
public:
        explicit DivisionByZero(const std::string& msg)
            : std::runtime_error(msg) {}
};


class Calculator
{
public:
        int divide(int a, int b)
        {
            if(b == 0)
            {
                throw DivisionByZero("Division by zero");
            }
            return a / b;
        }
};

int main()
{
    Calculator calculator;

    try
    {
        int result = calculator.divide(10, 2);
        std::cout << "result = " << result << std::endl;
    }
    catch(const DivisionByZero& exception)
    {
        std::cerr << "Exception caught: " << exception.what() << std::endl;
    }

    try
    {
        int result = calculator.divide(5, 0);
        std::cout << "result = " << result << std::endl;
    }
    catch(const DivisionByZero& exception)
    {
        std::cerr << "Exception caught: " << exception.what() << std::endl;
    }

    try
    {
        int result = calculator.divide(20,4);
        std::cout << "result = " << result << std::endl;
    }
    catch(const DivisionByZero& exception)
    {
        std::cerr << "Exception caught: " << exception.what() << std::endl;
    }
    

    try
    {
        int result = calculator.divide(100,2);
        std::cout << "result = " << result << std::endl;
    }
    catch(const std::exception& exception)
    {
        std::cerr <<"MyException caught: " << exception.what() << std::endl;
    }
    
    return 0;
}
