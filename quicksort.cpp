#include <iostream>
#include <vector>
using namespace std;

// Partition function (Lomuto Partition Scheme)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot element
    int i = low - 1;        // pointer for smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // move smaller element to the left
        }
    }

    swap(arr[i + 1], arr[high]); // place pivot in the correct position
    return i + 1; // return pivot index
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);  // left of pivot
        quickSort(arr, pi + 1, high); // right of pivot
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Apply quick sort
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:   ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
