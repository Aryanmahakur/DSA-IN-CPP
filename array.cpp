#include <iostream>
#include <string>
#include <climits>
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
            cout << "❌ Array is Not Sorted\n";
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << "✅ Array is Sorted\n";
    }
}

///////////////////////////////////////////////////////////////
// ➕ Function 3: Move All Zeroes to the End
///////////////////////////////////////////////////////////////
void moveZeroToEnd(int arr[], int n) {
    int count = 0;  // Index to place next non-zero
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
// 🥈 Function 4: Find Second Maximum Element
///////////////////////////////////////////////////////////////
void secondMax(int arr[], int n) {
    int max = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            second = max;
            max = arr[i];
        } else if (arr[i] > second && arr[i] != max) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        cout << "⚠️ No second maximum (all elements might be same)\n";
    } else {
        cout << "🥈 Second Maximum: " << second << endl;
    }
}

///////////////////////////////////////////////////////////////
// 🔁 Function 5: Check if a Word is a Palindrome
///////////////////////////////////////////////////////////////
bool isPalindrome(string word, int start, int end) {
    while (start < end) {
        if (word[start] != word[end]) return false;
        start++;
        end--;
    }
    return true;
}

///////////////////////////////////////////////////////////////
// 🧪 Main Function
///////////////////////////////////////////////////////////////
int main() {
    ///////////////////////////////////////////////////////////
    // 🎯 Sample Array
    ///////////////////////////////////////////////////////////
    int arr[] = {10, 59, 0, 50, 55, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    ///////////////////////////////////////////////////////////
    // 🥈 Find Second Maximum
    ///////////////////////////////////////////////////////////
    secondMax(arr, size);

    ///////////////////////////////////////////////////////////
    // 🔠 Check Palindrome
    ///////////////////////////////////////////////////////////
    string word = "madam";
    cout << "\n🔍 Checking if \"" << word << "\" is a Palindrome:\n";
    bool result = isPalindrome(word, 0, word.length() - 1);
    cout << (result ? "✅ It is a palindrome\n" : "❌ It is not a palindrome\n");

    ///////////////////////////////////////////////////////////
    // ➕ Move Zeroes to End
    ///////////////////////////////////////////////////////////
    moveZeroToEnd(arr, size);
    cout << "\n👉 After Moving Zeroes to End:\n";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";

    ///////////////////////////////////////////////////////////
    // 🔼 Find Maximum and Minimum
    ///////////////////////////////////////////////////////////
    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    cout << "\n🔹 Maximum Element: " << max << endl;
    cout << "🔹 Minimum Element: " << min << endl;

    ///////////////////////////////////////////////////////////
    // 🔁 Reverse the Array
    ///////////////////////////////////////////////////////////
    reverseArray(arr, size);
    cout << "\n🔁 After Reversing the Array:\n";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";

    ///////////////////////////////////////////////////////////
    // 📊 Check if Sorted
    ///////////////////////////////////////////////////////////
    cout << "\n🧪 Sorted Check:\n";
    checkSorted(arr, size);

    ///////////////////////////////////////////////////////////
    // 🔁 Print Elements in Reverse Order
    ///////////////////////////////////////////////////////////
    cout << "\n🔁 Elements in Reverse Order:\n";
    for (int i = size - 1; i >= 0; i--) cout << arr[i] << " ";
    cout << "\n";

    ///////////////////////////////////////////////////////////
    // 📏 Print Array Size
    ///////////////////////////////////////////////////////////
    cout << "\n📏 Size of the Array: " << size << endl;

    return 0;
}
