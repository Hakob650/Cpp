#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

class Matrix
{
private:
	size_t rows_;
	size_t cols_;
	double** data_;
	
	void allocate_memory(size_t rows,size_t cols);
	
	void deallocate_memory();

public:
	Matrix();
	Matrix(size_t rows,size_t cols);

	~Matrix();

	void set(size_t row,size_t col,double value);

	double get(size_t row,size_t col) const;

	size_t GetRows() const;

	size_t GetCols() const;
	
	void print() const;
};

#endif
