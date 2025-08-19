#include <iostream>
#include <vector>
using namespace std;

// Ascending Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Descending Binary Search
int binarySearchDescending(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}aaa

// First and Last Occurrence using Linear Search
vector<int> firstLastOccurrence(int arr[], int target, int n) {
    vector<int> ind;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            ind.push_back(i);
    }
    if (ind.empty())
        return {-1, -1};
    return {ind.front(), ind.back()};
}

// Find Peak Element (maximum value)
int findPeak(int arr[], int n) {
    int peak = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > peak) {
            peak = arr[i];
        }
    }
    return peak;
}

int main() {
    // 🔼 Ascending Binary Search
    int asc[] = {5, 10, 15, 20, 25, 30};
    int n1 = sizeof(asc) / sizeof(asc[0]);
    int target1 = 20;
    int result1 = binarySearch(asc, n1, target1);
    if (result1 != -1)
        cout << "Ascending → Element found at index " << result1 << endl;
    else
        cout << "Ascending → Element not found" << endl;

    // 🔽 Descending Binary Search
    int desc[] = {30, 25, 20, 15, 10, 5};
    int n2 = sizeof(desc) / sizeof(desc[0]);
    int target2 = 20;
    int result2 = binarySearchDescending(desc, n2, target2);
    if (result2 != -1)
        cout << "Descending → Element found at index " << result2 << endl;
    else
        cout << "Descending → Element not found" << endl;

    // 🔼 Peak Element
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Peak Element: " << findPeak(arr, n) << endl;

    // 🎯 First and Last Occurrence
    int arr2[] = {2, 4, 4, 4, 5, 6};
    int target3 = 4;
    int n3 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> fl = firstLastOccurrence(arr2, target3, n3);
    cout << "First and Last Occurrence of " << target3 << ": " << fl[0] << ", " << fl[1] << endl;

    return 0;
}
