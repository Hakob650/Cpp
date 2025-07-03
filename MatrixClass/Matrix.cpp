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
        for(size_t j =0 ; j < cols_; ++j)
        {
            data_[i][j] = 0.0;
        }     
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
    

Matrix& Matrix::operator=(Matrix&& other) noexcept
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
    for(size_t i = 0; i < rows_; ++i)
    {
        for(size_t j = 0; j < cols_; ++j)
        {
            std::cout<< data_[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

