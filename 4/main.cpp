#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <cmath>
#include "sparse_matrix.hpp"
#include "sparse_vector.hpp"

int main() {
    try {
        std::cout << "=== SparseVector ===" << std::endl;

        SparseVector<int> vec1(10); 
        vec1[2] = 5;
        vec1[5] = 10;
        vec1[8] = 20;

        std::cout << "Vec 1: ";
        vec1.print();

        SparseVector<int> vec2(10);
        vec2[3] = 15;
        vec2[5] = -10;
        vec2[9] = 25;

        std::cout << "Vec 2: ";
        vec2.print();

        SparseVector<int> vecSum = vec1 + vec2;
        std::cout << "vector sum: ";
        vecSum.print();

        SparseVector<int> vecScaled = vec1 * 2;
        std::cout << "vec1 * 2 = ";
        vecScaled.print();

        std::cout << "\n=== SparseMatrix ===" << std::endl;

        SparseMatrix<int> mat1(3, 3); // Создаем разреженную матрицу 3x3
        mat1(0, 0) = 1;
        mat1(0, 2) = 2;
        mat1(1, 1) = 3;
        mat1(2, 0) = 4;

        std::cout << "Matrix 1:" << std::endl;
        mat1.print();

        SparseMatrix<int> mat2(3, 3); // Вторая матрица 3x3
        mat2(0, 0) = 5;
        mat2(0, 1) = 6;
        mat2(1, 2) = 7;
        mat2(2, 2) = 8;

        std::cout << "Matrix 2:" << std::endl;
        mat2.print();

        // Сложение матриц
        SparseMatrix<int> matSum = mat1 + mat2;
        std::cout << "Matrix sum:" << std::endl;
        matSum.print();

        // Умножение матриц
        SparseMatrix<int> matProd = mat1 * mat2;
        std::cout << "Matrix product:" << std::endl;
        matProd.print();

        // Транспонирование матрицы
        SparseMatrix<int> matTransposed = mat1.transpose();
        std::cout << "Matrix 1 transposed:" << std::endl;
        matTransposed.print();

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
