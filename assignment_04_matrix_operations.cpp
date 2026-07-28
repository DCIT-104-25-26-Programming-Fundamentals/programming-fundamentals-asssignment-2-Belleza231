// Name: GIFTY AFUA AHEMAH NTOW
// Student ID: 22461638
// Assignment 4: Matrix Operations





// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



#include <iostream>
#include <iomanip> // for setw
using namespace std;

const int MAX = 10;

// Function prototypes
void inputMatrix(int mat[MAX][MAX], int rows, int cols);
void displayMatrix(int mat[MAX][MAX], int rows, int cols);
void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int rows, int cols);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int sum[MAX][MAX], int rows, int cols);
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int prod[MAX][MAX], int m, int n, int p);

int main() {
    int choice;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;
    
    cout << "=== MATRIX OPERATIONS ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    if (choice == 1) {
        // PART A: Transpose
        cout << "\nEnter number of rows: ";
        cin >> rows1;
        cout << "Enter number of columns: ";
        cin >> cols1;
        
        cout << "\nEnter elements of matrix:" << endl;
        inputMatrix(mat1, rows1, cols1);
        
        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(mat1, rows1, cols1);
        
        transposeMatrix(mat1, result, rows1, cols1);
        
        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(result, cols1, rows1);
        
    } else if (choice == 2) {
        // PART B: Add
        cout << "\nEnter number of rows: ";
        cin >> rows1;
        cout << "Enter number of columns: ";
        cin >> cols1;
        rows2 = rows1; cols2 = cols1;
        
        cout << "\nEnter elements of first matrix:" << endl;
        inputMatrix(mat1, rows1, cols1);
        
        cout << "\nEnter elements of second matrix:" << endl;
        inputMatrix(mat2, rows2, cols2);
        
        addMatrices(mat1, mat2, result, rows1, cols1);
        
        cout << "\nResult after Addition:" << endl;
        displayMatrix(result, rows1, cols1);
        
    } else if (choice == 3) {
        // PART C: Multiply
        cout << "\nEnter rows and columns of first matrix: ";
        cin >> rows1 >> cols1;
        cout << "Enter rows and columns of second matrix: ";
        cin >> rows2 >> cols2;
        
        if (cols1!= rows2) {
            cout << "Error: Columns of first matrix must equal rows of second matrix!" << endl;
            return 1;
        }
        
        cout << "\nEnter elements of first matrix:" << endl;
        inputMatrix(mat1, rows1, cols1);
        
        cout << "\nEnter elements of second matrix:" << endl;
        inputMatrix(mat2, rows2, cols2);
        
        multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
        
        cout << "\nResult after Multiplication:" << endl;
        displayMatrix(result, rows1, cols2);
        
    } else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

// Input matrix elements
void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Display matrix in grid
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j]; // neat alignment
        }
        cout << endl;
    }
}

// PART A: Transpose
void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j]; // row becomes column
        }
    }
}

// PART B: Add
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int sum[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART C: Multiply
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int prod[MAX][MAX], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < n; k++) {
                prod[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
