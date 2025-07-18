// #include <iostream>
// #include <unordered_set>
// using namespace std;

// int main() {
//     // Declare an unordered_set (HashSet)
//     unordered_set<int> hashSet;
//     //set<int> hashSet; for sorted 

//     // Insert elements into the set
//     hashSet.insert(10);
//     hashSet.insert(20);
//     hashSet.insert(30);
//     hashSet.insert(23);  // Duplicate - ignored automatically

//     // Check if 20 is present in the set
//     if (hashSet.find(20) != hashSet.end()) {
//         cout << "20 is in the set" << endl;
//     } else {
//         cout << "20 is not in the set" << endl;
//     }

//     // Remove element 10 from the set
//    // hashSet.erase(10);

//     // Print all elements in the set
//     cout << "Elements in the set: ";
//     for (int val : hashSet) {
//         cout << val << " ";
//     }
//     cout << endl;

//     // Print the size of the set
//     cout << "Set size: " << hashSet.size() << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;

// class HashSet {
//     const int SIZE = 1000;
//     vector<list<int>> table;

//     int hash(int key) {
//         return key % SIZE;
//     }

// public:
//     HashSet() {
//         table.resize(SIZE);
//     }

//     void insert(int key) {
//         int index = hash(key);
//         for (int n : table[index]) {
//             if (n == key) return; // Already present
//         }
//         table[index].push_back(key);
//     }

//     void remove(int key) {
//         int index = hash(key);
//         table[index].remove(key); // Removes key if present
//     }

//     bool check(int key) {
//         int index = hash(key);
//         for (int n : table[index]) {
//             if (n == key) return true;
//         }
//         return false;
//     }

//     void display() {
//         for (int i = 0; i < SIZE; ++i) {
//             if (!table[i].empty()) {
//                 cout << "Index " << i << ": ";
//                 for (int n : table[i]) {
//                     cout << n << " ";
//                 }
//                 cout << endl;
//             }
//         }
//     }
// };

// int main() {
//     HashSet hs;

//     hs.insert(10);
//     hs.insert(20);
//     hs.insert(1020); // Will go to same index as 20 due to mod 1000
//     hs.insert(30);

//     hs.display();

//     cout << "Check 20: " << (hs.check(20) ? "Present" : "Not present") << endl;

//     hs.remove(20);
//     cout << "After removing 20:\n";
//     hs.display();

//     return 0;
// }
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> unionOfArrays(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> resultSet;

    for (int num : a)
        resultSet.insert(num);

    for (int num : b)
        resultSet.insert(num);

    vector<int> result(resultSet.begin(), resultSet.end());
    return result;
}


int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    vector<int> result = unionOfArrays(arr1, arr2);

    cout << "Union of arrays: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());  // Insert all from arr1
    unordered_set<int> resultSet;

    for (int num : arr2) {
        if (set1.contains(num)) {
            resultSet.insert(num);  // Only insert if present in both
        }
    }

    return vector<int>(resultSet.begin(), resultSet.end());  // Convert set to vector
}


int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3, 5};

    vector<int> intersection = findIntersection(arr1, arr2);

    cout << "Intersection: ";
    for (int num : intersection) {
        cout << num << " ";
    }

    return 0;
}

aa