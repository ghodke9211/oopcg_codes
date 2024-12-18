#include <iostream>
using namespace std;

// Template function for selection sort
template <typename T>
void selectionSort(T arr[], int size) {
    // Loop through each element in the array
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;  // Assume the current element is the minimum
        // Find the smallest element in the remaining unsorted part of the array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update minIndex if a smaller element is found
            }
        }
        swap(arr[i], arr[minIndex]);  // Swap the found minimum element with the current element
    }
}

// Function to display the array
template <typename T>
void displayArray(T arr[], int size) {
    // Print each element in the array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intSize, floatSize;

    // Ask user for the size of the integer array and input the elements
    cout << "Enter size for the integer array: ";
    cin >> intSize;
    int intArr[100];  // Fixed-size array for integers (assuming the max size is 100)
    
    cout << "Enter " << intSize << " integer elements: ";
    for (int i = 0; i < intSize; i++) {
        cin >> intArr[i];  // Input elements into the array
    }

    // Ask user for the size of the float array and input the elements
    cout << "Enter size for the float array: ";
    cin >> floatSize;
    float floatArr[100];  // Fixed-size array for floats (assuming the max size is 100)

    cout << "Enter " << floatSize << " float elements: ";
    for (int i = 0; i < floatSize; i++) {
        cin >> floatArr[i];  // Input elements into the array
    }

   
    cout << "\nBefore sorting:\nInteger array: ";
    displayArray(intArr, intSize);  
    cout << "Float array: ";
    displayArray(floatArr, floatSize);  
    
    selectionSort(intArr, intSize);  
    selectionSort(floatArr, floatSize);  
    
    cout << "\nAfter sorting:\nInteger array: ";
    displayArray(intArr, intSize); 
    cout << "Float array: ";
    displayArray(floatArr, floatSize);  

    return 0;
}
