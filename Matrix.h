#pragma once
#include <iostream>

class Matrix {
public:
    Matrix(int, int);
    Matrix(double**, int, int);
    Matrix();
    ~Matrix();
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);

    inline double& operator()(int x, int y) { return p[x][y]; }

    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(double);
    Matrix& operator/=(double);

    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);
    double getElemByIndex(int row, int col);
    void elementSearch(double element);
    void swapRows(int, int);
    Matrix transpose();
    static double dotProduct(Matrix, Matrix);
    static Matrix augment(Matrix, Matrix);

private:
    int rows_, cols_;
    double** p;

    void allocSpace();
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);