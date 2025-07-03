#include <iostream>
#include "Vector.hpp"

MyVector::MyVector() 
    : size(0), capacity(1) {
        data = new int[capacity];
        std::cout<< "Default constructor called, capacity: " << capacity << std::endl;
}

MyVector::~MyVector()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
    std::cout<< "Destructor called, size: " << size << ", capacity: " << capacity << std::endl;
}

MyVector::MyVector(const MyVector& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for(size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
    std::cout<< "Copy constructor called, size: " << size << ", capacity: " << capacity << std::endl;
}

MyVector::MyVector(MyVector&& other)
{
    size = other.size;
    capacity = other.capacity;
    data = other.data;

    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;

    std::cout<< "Move constructor called, size: " << size << ", capacity: " << capacity << std::endl;
}

MyVector& MyVector::operator=(const MyVector& other)
{
    if(this != &other)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        for(size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    } return *this;

    std::cout<< "Copy assignment operator called, size: " << size << ", capacity: " << capacity << std::endl;
}

MyVector& MyVector::operator=(MyVector&& other)
{
    if(this != &other)
    {
        delete[] data;

        size = other.size;
        capacity = other.capacity;
        data = other.data;

        other.size = 0;
        other.capacity = 0;
        other.data = nullptr;
    }
    return *this;

    std::cout<< "Move assignment operator called, size: " << size << ", capacity: " << capacity << std::endl;
}

size_t MyVector::get_size()
{
    return size;
}

size_t MyVector::get_capacity()
{
    return capacity;
}

void MyVector::push_back(int value)
{
    if(size >= capacity)
    {
        resize(capacity * 2);
    }
    data[size++] = value;
}

void MyVector::pop_back()
{
    if(size > 0)
    {
        --size;
    }
}

void MyVector::resize(size_t newsize)
{
    if(newsize > capacity)
    {
        int* new_data = new int[newsize];
        for(size_t i =0; i < size; ++i)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = newsize;
    }
}

void MyVector::clear()
{
    size = 0;
}

void MyVector::print() const
{
    for(size_t i = 0; i < size; ++i)
    {
        std::cout<<data[i]<<" ";
    } std::cout<<std::endl;
}
