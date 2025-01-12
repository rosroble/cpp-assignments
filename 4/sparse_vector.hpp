#ifndef SPARSE_VECTOR_H
#define SPARSE_VECTOR_H

#include <unordered_map>
#include <stdexcept>
#include <iostream>

template <typename T>
class SparseVector {
private:
    std::unordered_map<size_t, T> data;
    size_t size;

public:
    SparseVector(size_t size);

    T& operator[](size_t index);
    T at(size_t index) const;

    SparseVector<T> operator*(T scalar) const;

    SparseVector<T> operator+(const SparseVector<T>& other) const;

    void print() const;
};

#include "sparse_vector.cpp"

#endif // SPARSE_VECTOR_H
