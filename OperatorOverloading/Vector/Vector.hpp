#include <iostream>


#ifndef VECTOR_HPP
#define VECTOR_HPP

class MyVector
{
private:
        size_t size;
        size_t capacity;
        int* data;
public:
        MyVector();
        
        MyVector(const MyVector& other);
        
        MyVector(MyVector&& other);

        ~MyVector();

        MyVector& operator=(const MyVector& other);
        
        MyVector& operator=(MyVector&& other);
        
        friend MyVector operator+(const MyVector& lhs,const MyVector& rhs);
        
        friend MyVector operator-(const MyVector& lhs,const MyVector& rhs);
        
        friend MyVector operator*(const MyVector& lhs,const MyVector& rhs);
        
        friend MyVector operator/(const MyVector& lhs,const MyVector& rhs);

        MyVector& operator+=(const MyVector&);

        MyVector& operator+=(const int&);

        MyVector& operator-=(const MyVector&);

        MyVector& operator-=(const int&);

        MyVector& operator*=(const MyVector&);

        MyVector& operator*=(const int&);

        MyVector& operator/=(const MyVector&); 

        MyVector& operator/=(const int&);

        MyVector& operator++();

        MyVector& operator--();

        MyVector operator++(int);

        MyVector operator--(int);

        friend bool operator==(const MyVector& lhs,const MyVector& rhs);

        friend bool operator==(const MyVector& lhs,const int& rhs);
 
        friend bool operator!=(const MyVector& lhs,const MyVector& rhs);

        friend bool operator!=(const MyVector& lhs,const int& rhs);

        friend std::ostream& operator<<(std::ostream& lhs,const MyVector& rhs);

        friend std::istream& operator>>(std::istream& lhs,MyVector& rhs);

        int& operator[](size_t size);

        const int& operator[](size_t size) const;

        size_t get_size() const;

        size_t get_capacity() const ;

        void push_back(int value);

        void pop_back();

        void resize(size_t new_size);

        void clear();

        void print() const;
       
};

#endif