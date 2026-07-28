// Name: GIFTY AFUA AHEMAH NTOW
// Student ID: 22461638
// Assignment 5: Fibonacci Sequence




// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function prototypes
void printFibonacciTerms(int n);
bool isFibonacciNumber(int num);

int main() {
    int choice;

    cout << "--- FIBONACCI SEQUENCE GENERATOR ---" << endl;
    cout << "1. Print First N Terms" << endl;
    cout << "2. Check if Number is Fibonacci" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "\nHow many terms? ";
        cin >> n;

        if (n <= 0) {
            cout << "Error: N must be a positive integer!" << endl;
        } else {
            cout << "Fibonacci sequence: ";
            printFibonacciTerms(n);
            cout << endl;
        }
    } 
    else if (choice == 2) {
        int num;
        cout << "\nEnter a number to check: ";
        cin >> num;

        if (isFibonacciNumber(num)) {
            cout << num << " is a Fibonacci number." << endl;
        } else {
            cout << num << " is NOT a Fibonacci number." << endl;
        }
    } 
    else {
        cout << "Invalid choice!" << endl;
    }
    return 0;
}

// Function to print first N Fibonacci terms
void printFibonacciTerms(int n) {
    int first = 0;
    int second = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << first;
        } else {
            cout << " " << second;  
            int next = first + second;
            first = second;
            second = next;
        }
    }
}

// Function to check if a number is Fibonacci
bool isFibonacciNumber(int num) {
    if (num < 0) return false;
    if (num == 0 || num == 1) return true;
    
    int first = 0;
    int second = 1;
    int next = 1;
    
    while (next < num) {
        next = first + second;
        first = second;
        second = next;
    }
    return next == num;
}
