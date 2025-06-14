#include <iostream>
#include "Matrix.hpp"

Matrix::Matrix() 
    : rows_(0),cols_(0),data_(nullptr) {}

Matrix::Matrix(size_t rows,size_t cols)
{
    rows_ = rows;
    cols_ = cols;
    data_ = new double*[rows_];
    for(size_t i = 0; i < rows_; ++i)
    {
        data_[i] = new double[cols_];
    }
}

Matrix::Matrix(const Matrix& other)
{
    rows_ = other.rows_;
    cols_ = other.cols_;
    data_= new double*[rows_];
    for(size_t i = 0; i < rows_; ++i)
    {
        data_[i] = new double[cols_];
        for(size_t  j =0; j < cols_; ++j)
        {
            data_[i][j] = other.data_[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& other)
  : rows_(other.rows_),cols_(other.cols_),data_(other.data_) 
{
    other.rows_ = 0;
    other.cols_ = 0;
    other.data_ = nullptr;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if(this != &other)
    {
        for(size_t i = 0; i < rows_; ++i)
        {
            delete[] data_[i];
        }
            delete[] data_;

            rows_ = other.rows_;
            cols_ = other.cols_;
            data_ = new double*[rows_];
            for(size_t i = 0; i < rows_; ++i)
            {
                data_[i] = new double[cols_];
                for(size_t j = 0; j < cols_; ++j)
                {
                data_[i][j] = other.data_[i][j];
                }
            }
        }
        return *this;
}
    

Matrix& Matrix::operator=(Matrix&& other)
{
    if(this != &other)
    {
        if(data_)
        {
            for(size_t i = 0; i < rows_; ++i)
            {
                delete[] data_[i];
            }
            delete[] data_;
        }
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = other.data_;

        other.rows_ = 0;
        other.cols_ = 0;
        other.data_ = nullptr;
    }
    return *this;
}

double& Matrix::operator()(size_t i,size_t j)
{
    if(i >= rows_ && j >= cols_)
    {
        std::cout<<"Out of range";
    }
    return data_[i][j];
}

const double& Matrix::operator()(size_t i,size_t j) const
{
    if(i >= rows_ && j >= cols_)
    {
        std::cout<<"Out of range";
    }
    return data_[i][j];
}   

Matrix operator+(const Matrix& lhs,const Matrix& rhs)
{
    if((lhs.rows_ != rhs.rows_) || ( lhs.cols_ != rhs.cols_))
    {
        std::cout<<"Size mismatch for addition";
    }
    Matrix res(lhs.rows_,lhs.cols_);
    for(size_t i = 0; i < lhs.rows_; ++i)
    {
        for(size_t j = 0; j < lhs.cols_; ++j)
        {
            res.data_[i][j] = lhs.data_[i][j] + rhs.data_[i][j];
        }
    }
    return res;
}

Matrix operator-(const Matrix& lhs,const Matrix& rhs)
{
    if((lhs.rows_ != rhs.rows_) || ( lhs.cols_ != rhs.cols_))
    {
        std::cout<<"Size mismatch for addition";
    }
    Matrix res(lhs.rows_,lhs.cols_);
    for(size_t i = 0; i < lhs.rows_; ++i)
    {
        for(size_t j = 0; j < lhs.cols_; ++j)
        {
            res.data_[i][j] = lhs.data_[i][j] - rhs.data_[i][j];
        }
    }
    return res;    
}

Matrix operator*(const Matrix& lhs,const Matrix& rhs)
{
    if((lhs.rows_ != rhs.rows_) || ( lhs.cols_ != rhs.cols_))
    {
        std::cout<<"Size mismatch for addition";
    }
    Matrix res(lhs.rows_,lhs.cols_);
    for(size_t i = 0; i < lhs.rows_; ++i)
    {
        for(size_t j = 0; j < lhs.cols_; ++j)
        {
            res.data_[i][j] = lhs.data_[i][j] * rhs.data_[i][j];
        }
    }
    return res;
}

Matrix operator/(const Matrix& lhs,const Matrix& rhs)
{
    if((lhs.rows_ != rhs.rows_) || ( lhs.cols_ != rhs.cols_))
    {
        std::cout<<"Size mismatch for addition";
    }
    Matrix res(lhs.rows_,lhs.cols_);
    for(size_t i = 0; i < lhs.rows_; ++i)
    {
        for(size_t j = 0; j < lhs.cols_; ++j)
        {
            res.data_[i][j] = lhs.data_[i][j] / rhs.data_[i][j];
        }
    }
    return res;
}

bool operator==(const Matrix& lhs,const Matrix& rhs)
{
    if((lhs.rows_ != rhs.rows_) || (lhs.cols_ != rhs.cols_))
    {
        return false;
    }
    for(size_t i = 0; i < lhs.rows_; ++i)
    {
        for(size_t j = 0; j < lhs.cols_; ++j)
        {
            if(lhs.data_[i][i] != rhs.data_[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Matrix& lhs,const Matrix& rhs)
{
    return !(lhs ==  rhs);
}

std::ostream& operator<<(std::ostream& os,const Matrix& rhs)
{
    for(size_t i = 0; i < rhs.rows_; ++i)
    {
        for(size_t j = 0; j < rhs.cols_; ++j)
        {
            os<<rhs.data_[i][j]<<" ";
        }
        os<<"\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is,const Matrix& rhs)
{
    for(size_t i = 0; i < rhs.rows_; ++i)
    {
        for(size_t j = 0; j < rhs.cols_; ++j)
        {
            is>>rhs.data_[i][j];
        }
    }
    return is;   
}

Matrix::~Matrix()
{
    for(size_t i = 0; i < rows_; ++i)
    {
        delete[] data_[i];
    }
    delete[] data_;

    data_ = nullptr;
    rows_ = 0;
    cols_ = 0;
}

void Matrix::set(size_t row,size_t col,double value)
{
    if(row < rows_ && col < cols_)
    {
        data_[row][col] = value;
    }
}

double Matrix::get(size_t row,size_t col) const
{
    if(row < rows_ && col < cols_)
    {
        return data_[row][col];
    }
    return 0.0;
}

size_t Matrix::GetRows() const
{
    return rows_;
}

size_t Matrix::GetCols() const
{
    return cols_;
}

void Matrix::print() const
{
    std::cout<<*this;
}