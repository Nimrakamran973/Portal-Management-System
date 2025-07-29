#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_SUBJECTS = 5;

struct Student {
    string name, fathername, regNo, semester, department, program;
    string subjects[MAX_SUBJECTS];
    double attendance[MAX_SUBJECTS];
    double marks[MAX_SUBJECTS][3]; // [0] = Final, [1] = Mids, [2] = Aggregate
};

// Function to calculate aggregate marks
void calculateAggregate(Student& student, int numSubject) {
    for (int i = 0; i < numSubject; i++) {
        student.marks[i][2] = (student.marks[i][0] * 0.5) + (student.marks[i][1] * 0.25);
    }
}

// Function to display the profile of a student
void showProfile(const Student& student) {
    cout << "Student Name: " << student.name << endl;
    cout << "Father Name: " << student.fathername << endl;
    cout << "Registration No: " << student.regNo << endl;
    cout << "Semester: " << student.semester << endl;
    cout << "Department: " << student.department << endl;
    cout << "Program: " << student.program << endl;
}

// Function to display attendance and marks data
void displayData(const Student& student, int numSubject) {
    cout << "Attendance and Marks:" << endl;
    for (int i = 0; i < numSubject; i++) {
        cout << "Subject: " << student.subjects[i] << endl;
        cout << "Attendance: " << student.attendance[i] << "%" << endl;
        cout << "Final: " << student.marks[i][0] << "%, Mids: " << student.marks[i][1]
             << "%, Aggregate: " << fixed << setprecision(2) << student.marks[i][2] << "%" << endl;
    }
}

int main() {
    // Array of students
    Student students[] = {
        {"Sara Ahmed", "Ahmed Khan", "CS01", "1st", "Computer Science", "Artificial Intelligence",
         {"English", "Physics", "Programming", "ICT", "Islamiat"},
         {75, 80, 85, 70, 90},
         {{78, 72, 0}, {80, 75, 0}, {85, 82, 0}, {70, 65, 0}, {90, 88, 0}}},

        {"Alishba", "Manzoor", "CS02", "1st", "Computer Science", "Artificial Intelligence",
         {"English", "Physics", "Programming", "ICT", "Islamiat"},
         {85, 75, 80, 90, 88},
         {{85, 80, 0}, {78, 74, 0}, {85, 82, 0}, {70, 65, 0}, {90, 88, 0}}},

        {"Asadullah", "M. Naeem", "CS03", "1st", "Computer Science", "Artificial Intelligence",
         {"English", "Physics", "Programming", "ICT", "Islamiat"},
         {80, 85, 88, 75, 95},
         {{82, 80, 0}, {79, 76, 0}, {87, 84, 0}, {75, 70, 0}, {95, 92, 0}}}
    };

    const int numStudents = sizeof(students) / sizeof(students[0]);
    int choice, selectedStudent;

    while (true) {
        cout << "\nStudent Portal:\n";
        cout << "1. View Profile\n";
        cout << "2. View Data\n";
        cout << "3. Calculate Aggregate\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter student number (1-" << numStudents << "): ";
                cin >> selectedStudent;
                if (selectedStudent >= 1 && selectedStudent <= numStudents) {
                    showProfile(students[selectedStudent - 1]);
                } else {
                    cout << "Invalid student number!" << endl;
                }
                break;
            }

            case 2: {
                cout << "Enter student number (1-" << numStudents << "): ";
                cin >> selectedStudent;
                if (selectedStudent >= 1 && selectedStudent <= numStudents) {
                    displayData(students[selectedStudent - 1], MAX_SUBJECTS);
                } else {
                    cout << "Invalid student number!" << endl;
                }
                break;
            }

            case 3: {
                cout << "Enter student number (1-" << numStudents << "): ";
                cin >> selectedStudent;
                if (selectedStudent >= 1 && selectedStudent <= numStudents) {
                    calculateAggregate(students[selectedStudent - 1], MAX_SUBJECTS);
                    cout << "Aggregate calculated successfully!" << endl;
                } else {
                    cout << "Invalid student number!" << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting portal..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    }

    return 0;
}
                	