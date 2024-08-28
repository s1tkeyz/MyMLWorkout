#pragma once

#include <cstddef>
#include <stdexcept>
#include <cinttypes>
#include <utility>

using index_t = uint8_t;

/* Действительнозначная прямоугольная матрица */
class Matrix {
    public:
        Matrix(index_t, index_t);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other);

        ~Matrix();

        /* Возвращает размер матрицы */
        std::pair<index_t, index_t> GetShape();

        /* Возвращает значение матрицы по индексу */
        double At(index_t, index_t);

        /* Операция умножения матрицы на число */
        friend Matrix operator *(double lambda, const Matrix& m);

        /* Операция умножения матриц */
        Matrix operator *(const Matrix& rhs);

        /* Операция сложения матриц */
        Matrix operator +(const Matrix& rhs);

        /* Операция вычитания матриц */
        Matrix operator -(const Matrix& rhs);

        /* Операция обращения матрицы */
        Matrix operator ~();

    private:
        index_t rows_n;
        index_t cols_n;

        double *buffer;

        double& index(index_t, index_t);
};