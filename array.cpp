#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////
// 🔁 Function 1: Reverse an Array
///////////////////////////////////////////////////////////////
void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

///////////////////////////////////////////////////////////////
// 📊 Function 2: Check if Array is Sorted (Ascending Order)
///////////////////////////////////////////////////////////////
void checkSorted(int arr[], int n) {
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "Array is Not Sorted" << endl;
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << "Array is Sorted" << endl;
    }
}

///////////////////////////////////////////////////////////////
// ➕ Function 3: Move All Zeroes to the End
///////////////////////////////////////////////////////////////
void moveZeroToEnd(int arr[], int n) {
    int count = 0;  // Position to place the next non-zero element
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }
    while (count < n) {
        arr[count++] = 0;
    }
}

///////////////////////////////////////////////////////////////
// 🧪 Main Function
///////////////////////////////////////////////////////////////
int main() {
    // ✅ Initialize array and find size
    int arr[] = {10, 0, 50, 55, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    // ➕ Move all zeroes to the end
    cout << "\n👉 After Moving Zeroes to End:\n";
    moveZeroToEnd(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // ✅ Find Maximum and Minimum
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    cout << "\n🔹 Maximum Element: " << max << endl;
    cout << "🔹 Minimum Element: " << min << endl;

    // 🔁 Reverse the array
    reverseArray(arr, size);
    cout << "\n👉 After Reversing the Array:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 📊 Check if the reversed array is sorted
    cout << "\n🧪 Sorted Check:\n";
    checkSorted(arr, size);

    // 🔄 Print array in reverse order (again)
    cout << "\n🔁 Elements in Reverse Order:\n";
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 📏 Print array size
    cout << "\n📏 Size of the Array: " << size << endl;

    return 0;
}
