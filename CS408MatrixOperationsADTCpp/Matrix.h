// acts as #ifndef
#pragma once

class Matrix {
private:
    double * mat;
    int numRows;
    int numCols;
    int size;

    void arrayCopy(double * arrayM, int size);
public:
    Matrix();
    Matrix(double * arrayM, int numRows, int numCols);
    Matrix(const Matrix &m);
    ~Matrix();

    // matrix operation functions
    Matrix addMat(Matrix m);
    Matrix subMat(Matrix m);
    Matrix multMat(Matrix m);

    void printMat();
};

