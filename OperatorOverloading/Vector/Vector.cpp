#include <iostream>
#include "Vector.hpp"

MyVector::MyVector()
   : size(0), capacity(1) {
            data = new int[capacity];
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
}

MyVector::MyVector(MyVector&& other)
{
    size = other.size;
    capacity = other.capacity;
    data  = other.data;
    
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

MyVector& MyVector::operator=(const MyVector& other)
{
    if(this == & other)
    {
        return *this;
    }
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for(size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
    return *this;
}

MyVector& MyVector::operator=(MyVector&& other)
{
    if(this == &other)
{
        return *this;
    }
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = other.data;

    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;

    return *this;
}

MyVector::~MyVector()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

size_t MyVector::get_size() const
{
    return size;
}

size_t MyVector::get_capacity() const
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

void MyVector::resize(size_t new_size)
{
    if(new_size > capacity)
    {
        int* new_data = new int[new_size];
        for(size_t i = 0; i < size; ++i)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_size;
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
    }
    std::cout<<std::endl;
}

MyVector operator+(const MyVector& lhs,const MyVector& rhs)
{
    MyVector res;
    
    size_t maxSize = std::max(lhs.size,rhs.size);
    size_t minSize = std::min(lhs.size,rhs.size);

    res.size = maxSize;
    res.capacity = maxSize;
    res.data = new int[res.capacity];

    for(size_t i = 0; i < minSize; ++i)
    {
        res.data[i] = lhs.data[i] + rhs.data[i];
    }
    
    const MyVector& longer = (lhs.size > rhs.size) ? lhs : rhs;
    for(size_t i = minSize; i < maxSize; ++i)
    {
        res.data[i] = longer.data[i];
    }
    return res;
}

MyVector operator-(const MyVector& lhs,const MyVector& rhs)
{
    MyVector res;

    size_t maxSize = std::max(lhs.size,rhs.size);
    size_t minSize = std::min(lhs.size,rhs.size);

    res.size = maxSize;
    res.capacity = maxSize;
    res.data = new int[res.capacity];

    const MyVector& longer = (lhs.size > rhs.size) ? lhs : rhs;
    for(size_t i = 0; i < minSize; ++i)
    {
        res.data[i] = lhs.data[i] - rhs.data[i];
    } 

    for(size_t i = minSize; i < maxSize; ++i)
    {
        res.data[i] = longer.data[i];
    }
    return res;
}

MyVector operator*(const MyVector& lhs,const MyVector& rhs)
{
    MyVector res;

    size_t minSize = std::min(lhs.size,rhs.size);
    size_t maxSize = std::max(lhs.size,rhs.size);

    res.size = maxSize;
    res.capacity = maxSize;
    res.data = new int[res.capacity];

    for(size_t i = 0; i < minSize; ++i)
    {
        res.data[i] = lhs.data[i] * rhs.data[i];
    }

    const MyVector& longer = (lhs.size > rhs.size) ? lhs : rhs;
    for(size_t i = minSize; i < maxSize; ++i)
    {
        res.data[i] = longer.data[i];
    }
    return res;
}

MyVector operator/(const MyVector& lhs,const MyVector& rhs)
{
    MyVector res;

    size_t minSize = std::min(lhs.size,rhs.size);
    size_t maxSize = std::max(lhs.size,rhs.size);

    res.size = maxSize;
    res.capacity = maxSize;
    res.data = new int[res.capacity];

    for(size_t i = 0; i < minSize; ++i)
    {
        res.data[i] = lhs.data[i] / rhs.data[i];
    }
    
    const MyVector& longer = (lhs.size > rhs.size) ? lhs : rhs;
    
    for(size_t i = minSize; i < maxSize; ++i)
    {
        res.data[i] = longer.data[i];
    }    
    return res;
}

MyVector& MyVector::operator+=(const MyVector& rhs)
{
    if(this->size != rhs.size)
    {
        std::cout<<"Vectors must be the same size";
    }
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] += rhs.data[i];
    }
    return *this;
}

 MyVector& MyVector::operator+=(const int& rhs)
{
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] += rhs;
    }
    return *this;
}

MyVector& MyVector::operator-=(const MyVector& rhs)
{
    if(this->size != rhs.size)
    {
        std::cout<<"Vectors Must Be the Same Size";
    }
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] -= rhs.data[i];
    }
    return *this;
}

MyVector& MyVector::operator-=(const int& rhs)
{
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] -= rhs;
    }
    return *this;
}

MyVector& MyVector::operator*=(const MyVector& rhs)
{
    if(this->size != rhs.size)
    {
        std::cout<<"Vectors Must Be The Same Size";
    }
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] *= rhs.data[i];
    }
    return *this;
}

MyVector& MyVector::operator*=(const int& rhs)
{
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] *= rhs;
    }
    return *this;
}

MyVector& MyVector::operator/=(const MyVector& rhs)
{
    if(this->size != rhs.size)
    {
        std::cout<<"Vectors Must Be The Same Size";
    }
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] /= rhs.data[i];
    }
    return *this;
}

MyVector& MyVector::operator/=(const int& rhs)
{
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] /= rhs;
    }
    return *this;
}

MyVector& MyVector::operator++()
{
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i]++;
    }
    return *this;
}

MyVector MyVector::operator++(int)
{
    MyVector tmp = *this;
    ++(*this);
    return tmp;
}

MyVector& MyVector::operator--()
{
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i]--;
    }
    return *this;
}

MyVector MyVector::operator--(int)
{
    MyVector tmp = *this;
    --(*this);
    return tmp;
}

bool operator==(const MyVector& lhs,const MyVector& rhs)
{
    if(lhs.size != rhs.size)
    {
        return false;
    }
    for(size_t i = 0; i < lhs.size; ++i)
    {
        if(lhs.data[i] != rhs.data[i])
        {
            return false;
        }
    }
    return true;
}

bool operator==(const MyVector& lhs,const int& rhs)
{
    for(size_t i = 0; i < lhs.size; ++i)
    {
        if(lhs.data[i] != rhs)
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const MyVector& lhs,const MyVector& rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const MyVector& lhs,const int& rhs)
{
    return !(lhs == rhs);
}

std::istream& operator>>(std::istream& is,MyVector& rhs)
{
    for(size_t i = 0; i < rhs.size; ++i)
    {
        is>>rhs.data[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os,const MyVector& rhs)
{
    os << "[";
    for(size_t i = 0; i < rhs.size; ++i)
    {
        os << rhs.data[i];
    }
    os << "]";
    return os;
}

int& MyVector::operator[](size_t index)
{
    return data[index];
}

const int& MyVector::operator[](size_t index) const
{
    return data[index];
}


