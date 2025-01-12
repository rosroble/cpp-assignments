#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <random>
#include "sparse_vector.hpp"
#include "sparse_matrix.hpp"

using namespace std;
using namespace chrono;

// Генерация плотного вектора
vector<double> generateDenseVector(size_t size, double density) {
    vector<double> vec(size, 0);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
    uniform_int_distribution<> idxDist(0, size - 1);

    size_t nonZeroCount = static_cast<size_t>(density * size);
    for (size_t i = 0; i < nonZeroCount; ++i) {
        vec[idxDist(gen)] = dis(gen) * 10;
    }
    return vec;
}

// Генерация разреженного вектора
SparseVector<double> generateSparseVector(size_t size, double density) {
    SparseVector<double> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
    uniform_int_distribution<> idxDist(0, size - 1);

    size_t nonZeroCount = static_cast<size_t>(density * size);
    for (size_t i = 0; i < nonZeroCount; ++i) {
        vec[idxDist(gen)] = dis(gen) * 10;
    }
    return vec;
}

// Измерение времени выполнения операции
template <typename Func>
void measureTime(const string& operation, Func&& func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << operation << ": " << duration << " µs" << endl;
}

int main() {
    size_t size = 100000;
    double density = 0.1;
    
    cout << "Testing with density " << density << "\n";
    auto denseVector = generateDenseVector(size, density);
    auto sparseVector = generateSparseVector(size, density);

    measureTime("Dense Vector Scalar Multiplication", [&]() {
        for (auto& val : denseVector) {
            val *= 2;
        }
    });

    measureTime("Sparse Vector Scalar Multiplication", [&]() {
        sparseVector = sparseVector * 2;
    });

    return 0;
}
