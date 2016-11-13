#include <iostream>
#include "Matrix.h"

void printCommands();
void printTwoMatrices(Matrix m1, Matrix m2);
void printResults(Matrix m1, Matrix m2, Matrix m3);

/**
* @brief    Performs 2D array matrix operations and displays their results
* @author   Connor A. Haskins
* @date     11/11/2016
*/
int main() {
    // dimension constants defined in Matrix.h
    const int numRows = 5;
    const int numCols = 5;
    double arrayM1[numRows * numCols] = { 1.0, 2.0, 3.0, 4.0, 5.0, 2.0, 2.0, 2.0, 2.0, 2.0, 3.0, 1.0, 1.0, 1.0, 3.0, 0.0, 0.0, 2.0, 3.0, 2.0, 4.0, 4.0, 4.0, 0.0, 0.0 };
    Matrix m1 = Matrix(arrayM1, numRows, numCols);
    double arrayM2[numRows * numCols] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 1.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0 };
    Matrix m2 = Matrix(arrayM2, numRows, numCols);

    printTwoMatrices(m1, m2);
    printCommands();

    char choice;
    std::cin >> choice;

    // while the user enters a given command, continue the program
    while (choice > '0' && choice < '4') {
        if (choice == '1') {
            Matrix m3 = m1 + m2;

            std::cout << "(1) M4 = M1 + M2 \n";
            printResults(m1, m2, m3);
        }
        else if (choice == '2') {
            Matrix m3 = m1 - m2;

            std::cout << "(2) M4 = M1 - M2 \n";
            printResults(m1, m2, m3);
        }
        else if (choice == '3') {
            Matrix m3 = m1 * m2;

            std::cout << "(3) M5 = M1 * M2 \n";
            printResults(m1, m2, m3);
        }
        printCommands();
        std::cin >> choice;
    }

    return 0;
}

/**
* @brief   Display the user's options
*/
void printCommands() {
    std::cout << "(1) M3 = M1 + M2 \n";
    std::cout << "(2) M4 = M1 - M2 \n";
    std::cout << "(3) M5 = M1 * M2 \n";
    std::cout << "Enter the one of the following commands. \n";
    std::cout << "Or any other key to terminate. \n";
    std::cout << "\n";
}

/**
* @brief   Print two matrices.
* @param   m1
* @param   m2
*/
void printTwoMatrices(Matrix m1, Matrix m2) {
    std::cout << "===============Matrix 1===============\n";
    m1.printMat();
    std::cout << "===============Matrix 2===============\n";
    m2.printMat();
    std::cout << "\n";
}


/**
* @brief   Print two matrices and their result matrix.
* @param   m1 left arg
* @param   m2 right arg
* @param   m3 results matrix
*/
void printResults(Matrix m1, Matrix m2, Matrix m3) {
    printTwoMatrices(m1, m2);
    std::cout << "================Result================\n";
    m3.printMat();
    std::cout << "\n\n";
}