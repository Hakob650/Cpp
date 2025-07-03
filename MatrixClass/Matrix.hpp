#define MATRIX_H

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

    Matrix& operator=(Matrix&& other) noexcept;

	~Matrix();

	void set(size_t row,size_t col,double value);

	double get(size_t row,size_t col) const;

	size_t GetRows() const;

	size_t GetCols() const;
	
	void print() const;
};

#endif
