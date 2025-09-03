#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    std::vector<T> m_elements;
public:
    void push(const T&);
    void pop();
    T top() const;
    bool empty() const;
};

template <typename T>
void Stack<T>::push(const T& element) 
{
    m_elements.push_back(element);
}

template <typename T>
void Stack<T>::pop() 
{
    if (m_elements.empty()) 
    {
        throw std::out_of_range("Stack<T>::pop(): empty stack");
    }
    m_elements.pop_back();
}

template <typename T>
T Stack<T>::top() const 
{
    if (m_elements.empty()) 
    {
        throw std::out_of_range("Stack<T>::top(): empty stack");
    }
    return m_elements.back();
}

template <typename T>
bool Stack<T>::empty() const
{
    return m_elements.empty();
}

int main() 
{
    try 
    {
        Stack<int> IntStack;
        std::cout << "Pushing elements onto Stack" << std::endl;
        IntStack.push(10);
        IntStack.push(20);
        IntStack.push(30);

        std::cout << "Top element is: " << IntStack.top() << std::endl;

        std::cout << "Popping elements" << std::endl;
        IntStack.pop();
        std::cout << "Top element is: " << IntStack.top() << std::endl;
        IntStack.pop();
        std::cout << "Top element is: " << IntStack.top() << std::endl;
        IntStack.pop();
        std::cout << "Attempting to get top of an empty Stack" << std::endl;
        std::cout << "Top element is: " << IntStack.top() << std::endl; 
    }
    catch(const std::out_of_range& except)
    {
        std::cout << "Caught Exception: " << except.what() << std::endl;
    }

    return 0;
}
