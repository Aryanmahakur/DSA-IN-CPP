#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> myMap;

    // Insert key-value pairs
    myMap["apple"] = 10;
    myMap["banana"] = 20;

    // Access value
    cout << "Apple: " << myMap["apple"] << endl;

    // Correct key existence check
    if (myMap.find("banana") != myMap.end()) {
        cout << "Banana found" << endl;
    }

    // Erase a key
    myMap.erase("apple");

    return 0;
}
#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename K, typename V>
class HashMap {
private:
    static const int SIZE = 10;  // Number of buckets
    vector<list<pair<K, V>>> table;  // Array of buckets (each bucket is a list of key-value pairs)

    int hashFunction(K key) {
        return hash<K>()(key) % SIZE;  // Use STL hash and mod to get bucket index
    }

public:
    HashMap() {
        table.resize(SIZE);
    }
void insert(K key, V value) {
    int index = hashFunction(key);
    for (auto &pair : table[index]) {
        if (pair.first == key) {
            pair.second = value;  // Update value if key already exists
            return;
        }
    }
    table[index].push_back({key, value});  // Add new key-value pair
}

bool find(K key) {
    int index = hashFunction(key);
    for (auto &pair : table[index]) {
        if (pair.first == key) return true;
    }
    return false;
}

void erase(K key) {
    int index = hashFunction(key);
    auto &bucket = table[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            bucket.erase(it);
            return;
        }
    }a
}

void display() {
    for (int i = 0; i < SIZE; ++i) {
        cout << "Bucket " << i << ": ";
        for (auto &pair : table[i]) {
            cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        cout << endl;
    }
}

}
};

// MAIN FUNCTION
int main() {
    // HashMap with <string, int> pairs
    HashMap<string, int> myMap;

    // Insert key-value pairs
    myMap.insert("apple", 10);
    myMap.insert("banana", 20);
    myMap.insert("cherry", 30);
    myMap.insert("apple", 40);  // Updates the value of apple to 40

    // Display the map
    cout << "Initial HashMap:" << endl;
    myMap.display();

    // Find operation
    cout << "\nFinding 'banana': ";
    if (myMap.find("banana")) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    // Delete operation
    myMap.erase("banana");

    // Display after deletion
    cout << "\nHashMap after deleting 'banana':" << endl;
    myMap.display();

    return 0;
}
