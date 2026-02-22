#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

// Yardýmcý matematik fonksiyonlarý
double sigmoid(double x);
double dsigmoid(double y);

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    Matrix(int r, int c);

    int getRows() const;
    int getCols() const;
    double& at(int r, int c);
    void print() const;

    // Matematiksel Operasyonlar
    Matrix multiply(const Matrix& other) const;
    void add(const Matrix& other);
    void add(double n);
    void map(double (*func)(double));
    void randomize();
    void multiply(double n);
    void multiplyElements(const Matrix& other);

    // Statik Operasyonlar
    static Matrix subtract(const Matrix& a, const Matrix& b);
    static Matrix transpose(const Matrix& a);
};

#endif
