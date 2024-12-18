#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

// Friend class declaration
class StudentDatabase;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;
    static int totalStudents;  // Static member function for counting students

public:
    // Constructor
    Student(string n, int r, string c, char d, string dob, string bg, string addr, string phone, string license)
        : name(n), rollNumber(r), studentClass(c), division(d), dateOfBirth(dob), bloodGroup(bg), contactAddress(addr), telephoneNumber(phone), drivingLicenseNo(license) {
        totalStudents++; // Increment total students
    }

    // Default constructor
    Student() : name("Unknown"), rollNumber(0), studentClass("N/A"), division('N'), dateOfBirth("N/A"), bloodGroup("N/A"), contactAddress("N/A"), telephoneNumber("N/A"), drivingLicenseNo("N/A") {
        totalStudents++;
    }

    // Copy constructor
    Student(const Student &other) : name(other.name), rollNumber(other.rollNumber), studentClass(other.studentClass), division(other.division),
                                     dateOfBirth(other.dateOfBirth), bloodGroup(other.bloodGroup), contactAddress(other.contactAddress),
                                     telephoneNumber(other.telephoneNumber), drivingLicenseNo(other.drivingLicenseNo) {
        totalStudents++;
    }

    // Destructor
    ~Student() {
        totalStudents--;
    }

    // Static member function
    static int getTotalStudents() {
        return totalStudents;
    }

    // Friend class to access private members of Student class
    friend class StudentDatabase;

    // Display function to print student details
    void displayStudentInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No.: " << drivingLicenseNo << endl;
    }

    // Inline function for updating details
    inline void updateDetails(string n, int r, string c, char d, string dob, string bg, string addr, string phone, string license) {
        name = n;
        rollNumber = r;
        studentClass = c;
        division = d;
        dateOfBirth = dob;
        bloodGroup = bg;
        contactAddress = addr;
        telephoneNumber = phone;
        drivingLicenseNo = license;
    }
};

// Initialize static member
int Student::totalStudents = 0;

// StudentDatabase class to manage student information
class StudentDatabase {
private:
    vector<Student> students;  // Use vector for dynamic array of students

public:
    // Function to add student to database
    void addStudent(const string& name, int rollNumber, const string& studentClass, char division, const string& dob, const string& bg,
                    const string& addr, const string& phone, const string& license) {
        students.push_back(Student(name, rollNumber, studentClass, division, dob, bg, addr, phone, license));
    }

    // Function to display all students
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No student records found." << endl;
        } else {
            for (const auto& student : students) {
                student.displayStudentInfo();
                cout << "------------------------" << endl;
            }
        }
    }

    // Function to find student by roll number
    void findStudentByRollNumber(int rollNumber) const {
        bool found = false;
        for (const auto& student : students) {
            if (student.rollNumber == rollNumber) {
                student.displayStudentInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student not found." << endl;
        }
    }

    // Function to delete a student record by roll number
    void deleteStudentByRollNumber(int rollNumber) {
        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->rollNumber == rollNumber) {
                students.erase(it);  // Remove the student from the vector
                found = true;
                cout << "Student record deleted successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student not found. Deletion failed." << endl;
        }
    }

    // Destructor
    ~StudentDatabase() {
        cout << "Student database is being destroyed." << endl;
    }
};

int main() {
    try {
        StudentDatabase db;  // Create the student database

        int option;
        do {
            // Display menu
            cout << "\n----- Student Database Menu -----\n";
            cout << "1. Add Student\n";
            cout << "2. Display All Students\n";
            cout << "3. Search Student by Roll Number\n";
            cout << "4. Delete Student by Roll Number\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> option;

            switch (option) {
                case 1: {
                    // Add student details
                    string name, studentClass, dateOfBirth, bloodGroup, contactAddress, telephoneNumber, drivingLicenseNo;
                    int rollNumber;
                    char division;

                    cout << "Enter student name: ";
                    cin.ignore();  // To ignore any leftover newline character
                    getline(cin, name);
                    cout << "Enter roll number: ";
                    cin >> rollNumber;
                    cout << "Enter class: ";
                    cin >> studentClass;
                    cout << "Enter division: ";
                    cin >> division;
                    cout << "Enter date of birth (yyyy-mm-dd): ";
                    cin >> dateOfBirth;
                    cout << "Enter blood group: ";
                    cin >> bloodGroup;
                    cout << "Enter contact address: ";
                    cin.ignore();  // To ignore any leftover newline character
                    getline(cin, contactAddress);
                    cout << "Enter telephone number: ";
                    cin >> telephoneNumber;
                    cout << "Enter driving license number: ";
                    cin >> drivingLicenseNo;

                    db.addStudent(name, rollNumber, studentClass, division, dateOfBirth, bloodGroup, contactAddress, telephoneNumber, drivingLicenseNo);
                    break;
                }
                case 2:
                    // Display all students
                    db.displayAllStudents();
                    break;
                case 3: {
                    // Search student by roll number
                    int rollNumber;
                    cout << "Enter roll number to search: ";
                    cin >> rollNumber;
                    db.findStudentByRollNumber(rollNumber);
                    break;
                }
                case 4: {
                    // Delete student by roll number
                    int rollNumber;
                    cout << "Enter roll number to delete: ";
                    cin >> rollNumber;
                    db.deleteStudentByRollNumber(rollNumber);
                    break;
                }
                case 5:
                    cout << "Exiting program...\n";
                    break;
                default:
                    cout << "Invalid option, please try again.\n";
            }

        } while (option != 5);  // Repeat menu until exit option is selected

    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
