#ifndef SPARSE_VECTOR_TPP
#define SPARSE_VECTOR_TPP

#include "sparse_vector.hpp"
    
template <typename T>
SparseVector<T>::SparseVector(size_t size) : size(size) {}

template <typename T>
T& SparseVector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
T SparseVector<T>::at(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    auto it = data.find(index);
    return (it != data.end()) ? it->second : T{};
}

template <typename T>
SparseVector<T> SparseVector<T>::operator*(T scalar) const {
    SparseVector<T> result(size);
    for (const auto& [index, value] : data) {
        result[index] = value * scalar;
    }
    return result;
}

template <typename T>
SparseVector<T> SparseVector<T>::operator+(const SparseVector<T>& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vector sizes must match");
    }
    SparseVector<T> result(size);
    for (const auto& [index, value] : data) {
        result[index] = value;
    }
    for (const auto& [index, value] : other.data) {
        result[index] += value;
    }
    return result;
}

template <typename T>
void SparseVector<T>::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << at(i) << " ";
    }
    std::cout << std::endl;
}

#endif // SPARSE_VECTOR_TPP
