#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

template <typename T>
std::vector<std::vector<T>> multiplyMatrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2)
{
    size_t rows1 = matrix1.size();
    size_t cols1 = matrix1[0].size();
    size_t rows2 = matrix2.size();
    size_t cols2 = matrix2[0].size();

    if(cols1 != rows2)
    {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication!");
    }

    std::vector<std::vector<T>> result(rows1, std::vector<T>(cols2, T()));

    for(size_t i = 0; i < rows1; ++i)
    {
        for(size_t j = 0; j < cols2; ++j)
        {
            for(size_t k = 0; k < cols1; ++k)
            {
                result[i][j] = matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

template<>
std::vector<std::vector<int>> multiplyMatrices<int>(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2)
{
    size_t rows1 = matrix1.size();
    size_t cols1 = matrix1[0].size();
    size_t rows2 = matrix2.size();
    size_t cols2 = matrix2[0].size();

    if(cols1 != rows2)
    {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication!");
    }

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for(size_t i = 0; i < rows1; ++i)
    {
        for(size_t j = 0; j < cols2; ++j)
        {
            for(size_t k = 0; k < cols1; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

template<>
std::vector<std::vector<double>> multiplyMatrices<double>(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2)
{
    size_t rows1 = matrix1.size();
    size_t cols1 = matrix1[0].size();
    size_t rows2 = matrix2.size();
    size_t cols2 = matrix2[0].size();

    if(cols1 != rows2)
    {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication!");
    }

    std::vector<std::vector<double>> result(rows1, std::vector<double>(cols2, 0.0));

    for(size_t i = 0; i < rows1; ++i)
    {
        for(size_t j = 0; j < cols2; ++j)
        {
            for(size_t k = 0; k < cols1; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

template<>
std::vector<std::vector<std::string>> multiplyMatrices<std::string>(const std::vector<std::vector<std::string>>& matrix1, const std::vector<std::vector<std::string>>& matrix2)
{
    size_t rows1 = matrix1.size();
    size_t cols1 = matrix1[0].size();
    size_t rows2 = matrix2.size();
    size_t cols2 = matrix2[0].size();

    if(cols1 != rows2)
    {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication!");
    }

    std::vector<std::vector<std::string>> result(rows1, std::vector<std::string>(cols2, ""));

    for(size_t i = 0; i < rows1; ++i)
    {
        for(size_t j = 0; j < cols2; ++j)
        {
            for(size_t k = 0; k < cols1; ++k)
            {
                result[i][j] += matrix1[i][k] + matrix2[k][j];
            }
        }
    }

    return result;
}

template <typename T>
void printMatrix(const std::vector<std::vector<T>>& matrix)
{
    for(const auto& row : matrix)
    {
        for(const auto& elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> mat1_int = {{1,2}, {3,4}};
    std::vector<std::vector<int>> mat2_int = {{5,6}, {7,8}};
    auto result_int = multiplyMatrices(mat1_int, mat2_int);
    std::cout << "Result of multiplying two integer matrices: " << std::endl;
    printMatrix(result_int);

    std::vector<std::vector<double>> mat1_double = {{1.1, 2.2}, {3.3, 4.4}};
    std::vector<std::vector<double>> mat2_double  = {{5.5, 6.6}, {7.7, 8.8}};
    auto double_result = multiplyMatrices(mat1_double, mat2_double);
    std::cout << "Result of multiplying two double matrices: " << std::endl;
    printMatrix(double_result);

    std::vector<std::vector<std::string>> mat1_string = {{"A", "B"}, {"C", "D"}};
    std::vector<std::vector<std::string>> mat2_string = {{"X", "Y"}, {"Z", "W"}};
    auto string_result = multiplyMatrices(mat1_string, mat2_string);
    std::cout << "Result of concatenating two string matrices: " << std::endl;
    printMatrix(string_result);

    return 0;
}