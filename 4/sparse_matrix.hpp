#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <unordered_map>
#include <stdexcept>
#include <iostream>

template <typename T>
class SparseMatrix {
private:
    std::unordered_map<size_t, std::unordered_map<size_t, T>> data;
    size_t rows;
    size_t cols;

public:
    SparseMatrix(size_t rows, size_t cols);

    T& operator()(size_t row, size_t col);
    T at(size_t row, size_t col) const;

    SparseMatrix<T> transpose() const;

    SparseMatrix<T> operator+(const SparseMatrix<T>& other) const;
    SparseMatrix<T> operator*(const SparseMatrix<T>& other) const;

    void print() const;
};

#include "sparse_matrix.cpp"

#endif // SPARSE_MATRIX_H
