#include <iostream>
#include "matrix.h"

Matrix::Matrix() : rows_(0) , cols_(0) , data_(nullptr) {} //default constructor

//Parameterized constructor
Matrix::Matrix(size_t rows, size_t cols) : rows_(rows) , cols_(cols) 
{
	allocate_memory(rows_,cols_);
}

//Destructor
Matrix::~Matrix()
{
	deallocate_memory();
}

//Allocate memory
void Matrix::allocate_memory(size_t rows,size_t cols)
{
	data_ = new double*[rows];
	for(size_t i = 0; i < rows; ++i)
	{
		data_[i] = new double[rows];
		for(size_t j = 0 ; j < cols; ++j)
		{
			data_[i][j] = 0.0;
		}
	}
}

//Deallocate_memory
void Matrix::deallocate_memory()
{
	if(data_)
	{
		for(size_t i = 0 ; i < rows_; ++i)
		{
			delete[] data_[i];
		}
		delete[] data_;
		data_ = nullptr;
	}
}

void Matrix::set(size_t row, size_t col, double value)
{
	if(row < rows_ && col < cols_)
	{
		data_[row][col] = value;
	}
	else{
		std::cerr<<"set() index out pf bounds\n";
	}
}

double Matrix::get(size_t row, size_t col) const
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
			std::cout<<data_[i][j]<<" ";
		}
		std::cout<<'\n';
	}
}






