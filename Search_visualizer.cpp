#include <iostream>
using namespace std;

// Function to print array with marker
void printArray(int arr[], int size, int currentPos = -1) {
    cout << "[";
    for(int i = 0; i < size; i++) {
        if(i == currentPos) {
            cout << " *" << arr[i] << "*";
        } else {
            cout << " " << arr[i];
        }
        if(i < size-1) cout << ",";
    }
    cout << " ]" << endl;
}

// Function to check if array is sorted
bool isSorted(int arr[], int size) {
    for(int i = 0; i < size-1; i++) {
        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

// Function to sort array using bubble sort
void sortArray(int arr[], int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Linear Search Visualization
void linearSearchVisual(int arr[], int size) {
    int target;
    cout << "\nEnter the number to search: ";
    cin >> target;
    
    cout << "\n=== LINEAR SEARCH VISUALIZATION ===" << endl;
    cout << "Searching for: " << target << endl;
    cout << "Array: ";
    printArray(arr, size);
    cout << endl;
    
    bool found = false;
    
    for(int i = 0; i < size; i++) {
        cout << "Step " << i+1 << ": ";
        printArray(arr, size, i);
        
        cout << "   Checking if " << arr[i] << " == " << target;
        
        if(arr[i] == target) {
            cout << " ✓ MATCH!" << endl;
            cout << "   " << target << " found at position " << i+1 << " (index " << i << ")" << endl;
            found = true;
            break;
        } else {
            cout << " ✗ Not equal" << endl;
        }
        
        cout << "   ----------------------" << endl;
    }
    
    if(!found) {
        cout << "\n" << target << " not found in the array." << endl;
    }
}

// Binary Search Visualization
void binarySearchVisual(int arr[], int size) {
    // Check if array is sorted
    if(!isSorted(arr, size)) {
        cout << "\nNOTE: Array is not sorted. Binary search requires sorted array." << endl;
        cout << "Sorting array for binary search..." << endl;
        
        // Create a copy to sort
        int* sortedArr = new int[size];
        for(int i = 0; i < size; i++) {
            sortedArr[i] = arr[i];
        }
        
        sortArray(sortedArr, size);
        
        cout << "Original array: ";
        printArray(arr, size);
        cout << "Sorted array:   ";
        printArray(sortedArr, size);
        
        // Perform binary search on sorted array
        binarySearchVisual(sortedArr, size);
        
        delete[] sortedArr;
        return;
    }
    
    int target;
    cout << "\nEnter the number to search: ";
    cin >> target;
    
    cout << "\n=== BINARY SEARCH VISUALIZATION ===" << endl;
    cout << "Searching for: " << target << endl;
    cout << "Array: ";
    printArray(arr, size);
    cout << endl;
    
    int left = 0;
    int right = size - 1;
    int step = 1;
    bool found = false;
    
    while(left <= right) {
        cout << "Step " << step << ":" << endl;
        cout << "   Search range: positions " << left << " to " << right << endl;
        
        // Show current search area
        cout << "   Current area: [";
        for(int i = left; i <= right; i++) {
            cout << " " << arr[i];
            if(i < right) cout << ",";
        }
        cout << " ]" << endl;
        
        // Calculate middle
        int mid = (left + right) / 2;
        cout << "   Middle position: (" << left << " + " << right << ") / 2 = " << mid << endl;
        cout << "   Value at middle: arr[" << mid << "] = " << arr[mid] << endl;
        
        cout << "   Compare: " << arr[mid] << " with " << target << endl;
        
        if(arr[mid] == target) {
            cout << "   ✓ MATCH FOUND!" << endl;
            cout << "   " << target << " found at position " << mid+1 << " (index " << mid << ")" << endl;
            found = true;
            break;
        }
        else if(arr[mid] < target) {
            cout << "   " << arr[mid] << " < " << target << ", so search RIGHT half" << endl;
            left = mid + 1;
        }
        else {
            cout << "   " << arr[mid] << " > " << target << ", so search LEFT half" << endl;
            right = mid - 1;
        }
        
        cout << "   ----------------------" << endl;
        step++;
    }
    
    if(!found) {
        cout << "\n" << target << " not found in the array." << endl;
    }
}

int main() {
    int size;
    
    cout << "========================================" << endl;
    cout << "     SEARCH ALGORITHM VISUALIZER" << endl;
    cout << "========================================" << endl << endl;
    
    // Get array size from user
    cout << "Enter the size of array: ";
    cin >> size;
    
    // Create and fill array
    int* arr = new int[size];
    
    cout << "\nEnter " << size << " numbers for the array:" << endl;
    for(int i = 0; i < size; i++) {
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
    }
    
    // Display the array
    cout << "\nYour array is: ";
    printArray(arr, size);
    cout << endl;
    
    int choice;
    
    do {
        // Display menu
        cout << "\n============ MENU ============" << endl;
        cout << "1. Perform Linear Search" << endl;
        cout << "2. Perform Binary Search" << endl;
        cout << "3. View Array Again" << endl;
        cout << "4. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cout << endl;
        
        switch(choice) {
            case 1:
                linearSearchVisual(arr, size);
                break;
                
            case 2:
                binarySearchVisual(arr, size);
                break;
                
            case 3:
                cout << "Current array: ";
                printArray(arr, size);
                if(isSorted(arr, size)) {
                    cout << "(Array is sorted)" << endl;
                } else {
                    cout << "(Array is NOT sorted)" << endl;
                }
                break;
                
            case 4:
                cout << "Thank you for using Search Visualizer!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please enter 1-4." << endl;
        }
        
    } while(choice != 4);
    
    // Clean up
    delete[] arr;
    
    return 0;
}
