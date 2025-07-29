#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays: arr[left..mid] and arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);
aaa
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy any remaining elements of L[]
    while (i < n1)
        arr[k++] = L[i++];

    // Copy any remaining elements of R[]
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// Driver code
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Perform merge sort
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:   ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
