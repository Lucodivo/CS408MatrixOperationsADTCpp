#include <iostream>
#include "Matrix.h"

/**
 * @brief   Default constructor
 */
Matrix::Matrix() {
    this->numRows = 0;
    this->numCols = 0;
    this->size = 0;
    this->mat = NULL;
}

/**
 * @brief   Constructor
 * @param   arrayM  A one dimensional array matrix
 * @param   numRows Number of rows in the matrix
 * @param   numCols Number of cols in the matrix
 */
Matrix::Matrix(double * arrayM, int numRows, int numCols) {
    this->numRows = numRows;
    this->numCols = numCols;
    this->size = numRows * numCols;
    this->mat = new double[this->size];
    arrayCopy(arrayM, this->size);
}

/**
 * @brief   Copy constructor
 * @param   m   Matrix to copy
 */
Matrix::Matrix(const Matrix &m) {
    this->numRows = m.numRows;
    this->numCols = m.numCols;
    this->size = m.size;
    this->mat = new double[this->size];
    arrayCopy(m.mat, m.size);
}

/**
 * @brief   Destructor: deallocates private member array
 */
Matrix::~Matrix(){
    delete [] this->mat;
}

/**
 * @brief   Add a matrix to this one
 * @param   m   addend Matrix
 * @return  summation Matrix
 */
Matrix Matrix::operator+(Matrix m) {
    double * newMat = new double[this->size];
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < this->numCols; j++) {
            int index = (this->numCols * i) + j;
            newMat[index] = this->mat[index] + m.mat[index];
        }
    }
    return Matrix(newMat, this->numRows, this->numCols);
}

/**
 * @brief   Subtract a Matrix from this one.
 * @param   m   subtrahend Matrix
 * @return  difference Matrix
 */

Matrix Matrix::operator-(Matrix m) {
    double * newMat = new double[this->size];
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < this->numCols; j++) {
            int index = (this->numCols * i) + j;
            newMat[index] = this->mat[index] - m.mat[index];
        }
    }
    return Matrix(newMat, this->numRows, this->numCols);
}

/**
 * @brief   Multiply a matrix by this one using matrix multiplication
 *          (DOES NOT SIMPLY MULTIPLY CORRESPONDING INDEXES)
 * @param   m   multiplier multiplier
 * @return  product Matrix
 */

Matrix Matrix::operator*(Matrix m) {
    double * newMat = new double[this->numRows * m.numCols];
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < m.numCols; j++) {
            int newIndex = (this->numCols * i) + j;
            newMat[newIndex] = 0;
            for (int k = 0; k < this->numCols; k++) {
                int thisIndex = (this->numCols * i) + k;
                int paramIndex = (this->numCols * k) + j;
                newMat[newIndex] += this->mat[thisIndex] * m.mat[paramIndex];
            }
        }
    }
    return Matrix(newMat, this->numRows, this->numCols);
}

/**
 * @brief   Copy parameter array into this array
 * @param   arrayM  Array to be copied
 * @param   size    Size of array to be copied
 */
void Matrix::arrayCopy(double * arrayM, int size) {
    for (int i = 0; i < size; i++) {
        this->mat[i] = arrayM[i];
    }
}

/**
* @brief	Prints this matrix to console
*/
void Matrix::printMat() {
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < this->numCols; j++) {
            std::cout << this->mat[(this->numCols * i) + j] << "\t";
        }
        std::cout << "\n";
    }
}