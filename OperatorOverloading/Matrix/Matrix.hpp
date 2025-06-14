#include <cstddef>

#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix
{
private:
	size_t rows_;
	size_t cols_;
	double** data_;

public:
	
Matrix();
	
    Matrix(size_t rows,size_t cols);

    Matrix(const Matrix& other);

    Matrix(Matrix&& other);

    Matrix& operator=(const Matrix& other);

    Matrix& operator=(Matrix&& other);

    double& operator()(size_t i,size_t j);

    const double& operator()(size_t i,size_t j) const;

    friend Matrix operator+(const Matrix& lhs,const Matrix& rhs);

    friend Matrix operator-(const Matrix& lhs,const Matrix& rhs);

    friend Matrix operator*(const Matrix& lhs,const Matrix& rhs);

    friend Matrix operator/(const Matrix& lhs,const Matrix& rhs);

    friend bool operator==(const Matrix& lhs,const Matrix& rhs);

    friend bool operator!=(const Matrix& lhs,const Matrix& rhs);

    friend std::ostream& operator<<(std::ostream& os,const Matrix& rhs);

    friend std::istream& operator>>(std::istream& is ,const Matrix& rhs);

    ~Matrix();

    void set(size_t row,size_t col,double value);

    double get(size_t row,size_t col) const;

    size_t GetRows() const;

    size_t GetCols() const;
	
    void print() const;
};

#endif