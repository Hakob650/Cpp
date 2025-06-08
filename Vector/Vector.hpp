#include <iostream>

#ifndef VECTOR_HPP
#define VECTOR_HPP

class MyVector {
private:
  size_t size;
  size_t capacity;
  int *data;
public:
    MyVector();

    ~MyVector();

    MyVector(const MyVector& other);

    MyVector(MyVector&& other);

    MyVector& operator=(const MyVector& other);

    MyVector& operator=(MyVector&& other);
  
    size_t get_size();

    size_t get_capacity();

    void push_back( int value ); 

    void pop_back( );

    void resize(size_t newsize);

    void clear();

    void print() const;
};
#endif