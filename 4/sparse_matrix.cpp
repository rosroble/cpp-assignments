#ifndef SPARSE_MATRIX_TPP
#define SPARSE_MATRIX_TPP

#include "sparse_matrix.hpp"

template <typename T>
SparseMatrix<T>::SparseMatrix(size_t rows, size_t cols) : rows(rows), cols(cols) {}

template <typename T>
T& SparseMatrix<T>::operator()(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

template <typename T>
T SparseMatrix<T>::at(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    auto rowIt = data.find(row);
    if (rowIt != data.end()) {
        auto colIt = rowIt->second.find(col);
        if (colIt != rowIt->second.end()) {
            return colIt->second;
        }
    }
    return T{};
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::transpose() const {
    SparseMatrix<T> result(cols, rows);
    for (const auto& [row, rowData] : data) {
        for (const auto& [col, value] : rowData) {
            result(col, row) = value;
        }
    }
    return result;
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::operator+(const SparseMatrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    SparseMatrix<T> result(rows, cols);
    for (const auto& [row, rowData] : data) {
        for (const auto& [col, value] : rowData) {
            result(row, col) = value;
        }
    }
    for (const auto& [row, rowData] : other.data) {
        for (const auto& [col, value] : rowData) {
            result(row, col) += value;
        }
    }
    return result;
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::operator*(const SparseMatrix<T>& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions must be compatible for multiplication");
    }
    SparseMatrix<T> result(rows, other.cols);
    for (const auto& [row, rowData] : data) {
        for (const auto& [col, value] : rowData) {
            for (const auto& [k, otherValue] : other.data.at(col)) {
                result(row, k) += value * otherValue;
            }
        }
    }
    return result;
}

template <typename T>
void SparseMatrix<T>::print() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << at(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

#endif // SPARSE_MATRIX_TPP
