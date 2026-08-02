// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.4U85
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================




#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// REQUIREMENTS:
// 1. Define a struct called Student
// 2. Store all records in a vector<Student>
// 3. Average scores must be rounded to 2 decimal places (use setprecision(2))
// 4. Each feature MUST be in its own function
// 5. Handle invalid menu choices and missing student IDs gracefully

struct Student {
    string name;          // the student's full name
    int id;               // unique student ID number
    vector<double> scores; // list of scores from multiple assessments
};

// Function prototypes
void addStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void calculateAverageScore(const vector<Student>& students);
double getAverage(const vector<double>& scores);

int main() {
    vector<Student> students; // Store all records
    int choice;

    do {
        // HOW THE MENU SHOULD LOOK
        cout << "\n===============================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "===============================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(); // clear buffer so getline works

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageScore(students);
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter 1-4." << endl; // Handle invalid menu
        }
    } while (choice != 4);

    return 0;
}

// Function 1: Add a Student
void addStudent(vector<Student>& students) {
    Student s;
    int numScores;
    double score;

    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

// Function 2: Display All Students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "\n" << left << setw(20) << "Name" 
         << setw(15) << "ID" 
         << setw(25) << "Scores" 
         << "Average" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    for (const auto& s : students) {
        cout << left << setw(20) << s.name 
             << setw(15) << s.id;

        // Print all scores
        for (double sc : s.scores) {
            cout << sc << " ";
        }

        // REQUIREMENT: Average scores rounded to 2 decimal places
        cout << fixed << setprecision(2) << getAverage(s.scores) << endl;
    }
}

// Function 3: Calculate Average Score for a Specific Student
void calculateAverageScore(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;

    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << s.name << "'s average score: " 
                 << fixed << setprecision(2) << getAverage(s.scores) << endl;
            return;
        }
    }
    // Handle missing student IDs gracefully
    cout << "Error: Student ID not found." << endl;
}

// Helper Function: Calculate Average
double getAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    
    double sum = 0;
    for (double sc : scores) {
        sum += sc;
    }
    return sum / scores.size();
}