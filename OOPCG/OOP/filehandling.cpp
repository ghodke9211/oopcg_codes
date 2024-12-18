#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // File name
    string fileName = "user_data.txt";

    // Step 1: Create an output file and write user input to it
    ofstream outputFile(fileName); // Open file for writing
    if (!outputFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    // Take user input
    cout << "Enter text to write to the file (type 'EXIT' to stop):" << endl;
    string userInput;
    while (true) {
        getline(cin, userInput);
        if (userInput == "EXIT") {
            break; // Exit loop if user types "EXIT"
        }
        outputFile << userInput << endl; // Write user input to the file
    }

    // Close the output file
    outputFile.close();

    // Step 2: Open the file as an input file and read the information
    ifstream inputFile(fileName); // Open file for reading
    if (!inputFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    // Read and display the content of the file
    string line;
    cout << "\nContents of the file:" << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // Close the input file
    inputFile.close();

    return 0;
}
