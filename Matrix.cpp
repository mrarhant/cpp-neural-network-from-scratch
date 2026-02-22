#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

// Matematik Fonksiyonlarýnýn Tanýmý
double sigmoid(double x) { return 1.0 / (1.0 + std::exp(-x)); }
double dsigmoid(double y) { return y * (1.0 - y); }

// Kurucu (Constructor)
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = std::vector<std::vector<double>>(rows, std::vector<double>(cols, 0.0));
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }
double& Matrix::at(int r, int c) { return data[r][c]; }

void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::multiply(const Matrix& other) const {
    if (this->cols != other.getRows()) throw std::invalid_argument("Boyut uyusmazligi!");
    Matrix result(this->rows, other.getCols());
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < other.getCols(); ++j) {
            double sum = 0.0;
            for (int k = 0; k < this->cols; ++k) sum += this->data[i][k] * other.data[k][j];
            result.at(i, j) = sum;
        }
    }
    return result;
}

void Matrix::add(const Matrix& other) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            this->data[i][j] += other.data[i][j];
}

void Matrix::add(double n) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            this->data[i][j] += n;
}

void Matrix::map(double (*func)(double)) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            this->data[i][j] = func(this->data[i][j]);
}

void Matrix::randomize() {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            this->data[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
}

void Matrix::multiply(double n) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            this->data[i][j] *= n;
}

void Matrix::multiplyElements(const Matrix& other) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            this->data[i][j] *= other.data[i][j];
}

Matrix Matrix::subtract(const Matrix& a, const Matrix& b) {
    Matrix result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i)
        for (int j = 0; j < a.getCols(); ++j)
            result.at(i, j) = a.data[i][j] - b.data[i][j];
    return result;
}

Matrix Matrix::transpose(const Matrix& a) {
    Matrix result(a.getCols(), a.getRows());
    for (int i = 0; i < a.getRows(); ++i)
        for (int j = 0; j < a.getCols(); ++j)
            result.at(j, i) = a.data[i][j];
    return result;
}
