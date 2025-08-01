#include <iostream>  // Include this!

using namespace std;  // Or use std::cout everywhere

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {10, 25, 3, 10, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    for (int a : arr) {
        cout << a << endl;
    }
}
