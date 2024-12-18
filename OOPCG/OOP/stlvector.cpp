#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// User-defined structure for personal records
struct PersonalRecord {
    string name;
    string dob; // Date of Birth in format "YYYY-MM-DD"
    string phoneNumber;

    // Constructor for easy record creation
    PersonalRecord(string n, string d, string p) : name(n), dob(d), phoneNumber(p) {}
};

// Function to display records
void displayRecords(const vector<PersonalRecord>& records) {
    cout << "Personal Records:" << endl;
    for (const auto& record : records) {
        cout << "Name: " << record.name << ", DOB: " << record.dob << ", Phone: " << record.phoneNumber << endl;
    }
}

// Comparison function for sorting by name
bool compareByName(const PersonalRecord& a, const PersonalRecord& b) {
    return a.name < b.name; // Sorts alphabetically by name
}

// Function to search for a record by name
PersonalRecord* searchRecordByName(vector<PersonalRecord>& records, const string& name) {
    auto it = find_if(records.begin(), records.end(), [&name](const PersonalRecord& record) {
        return record.name == name;
    });
    if (it != records.end()) {
        return &(*it);
    }
    return nullptr; // Return nullptr if not found
}

int main() {
    // Creating a vector to store personal records
    vector<PersonalRecord> records;

    // Taking user input for records
    int n;
    cout << "Enter the number of records you want to input: ";
    cin >> n;
    cin.ignore(); // to ignore the newline character after the number input

    for (int i = 0; i < n; ++i) {
        string name, dob, phoneNumber;

        cout << "\nEnter details for record " << i + 1 << ":\n";
        
        cout << "Name: ";
        getline(cin, name);
        
        cout << "Date of Birth (YYYY-MM-DD): ";
        getline(cin, dob);

        cout << "Phone Number: ";
        getline(cin, phoneNumber);

        records.push_back(PersonalRecord(name, dob, phoneNumber));
    }

    // Display the records before sorting
    cout << "\nBefore Sorting:" << endl;
    displayRecords(records);

    // Sorting records by name
    sort(records.begin(), records.end(), compareByName);
    
    // Display the records after sorting
    cout << "\nAfter Sorting by Name:" << endl;
    displayRecords(records);

    // Searching for a record by name
    string nameToSearch;
    cout << "\nEnter a name to search: ";
    getline(cin, nameToSearch);

    PersonalRecord* foundRecord = searchRecordByName(records, nameToSearch);
    if (foundRecord) {
        cout << "\nRecord Found!" << endl;
        cout << "Name: " << foundRecord->name << ", DOB: " << foundRecord->dob << ", Phone: " << foundRecord->phoneNumber << endl;
    } else {
        cout << "\nRecord not found!" << endl;
    }

    return 0;
}
