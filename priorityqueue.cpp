#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/////////////////////////////////////////////////////
// 1. BUILT-IN MAX HEAP (priority_queue<int>)
/////////////////////////////////////////////////////

void builtInMaxHeap() {
    priority_queue<int> pq;  // Default = Max Heap

    pq.push(20);
    pq.push(15);
    pq.push(30);
    pq.push(40);
    pq.push(10);

    cout << "Built-in Max Heap:\n";
    cout << "Top (Max): " << pq.top() << endl;  // Output: 40

    pq.pop();  // Removes 40

    cout << "Next Top: " << pq.top() << endl;   // Output: 30

    cout << "Remaining Heap: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n\n";
}

/////////////////////////////////////////////////////
// 2. MANUAL MAX HEAP IMPLEMENTATION
/////////////////////////////////////////////////////

class MaxHeap {
    vector<int> heap;
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int n = heap.size();

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}
bool isMaxHeap(const vector<int>& heap) {
    int n = heap.size();
    for (int i = 0; i <= (n - 2) / 2; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && heap[i] < heap[left]) return false;
        if (right < n && heap[i] < heap[right]) return false;
    }
    return true;
}

    

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Bubble up
        while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return maxVal;
    }

    int getMax() {
        return heap.empty() ? -1 : heap[0];
    }

    void display() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

void manualMaxHeapTest() {
    MaxHeap h;

    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);
    h.insert(10);

    cout << "Manual Max Heap:\n";
    h.display();  // Max will be at root

    cout << "Max: " << h.getMax() << endl;

    cout << "Extracted Max: " << h.extractMax() << endl;

    cout << "Heap after extraction: ";
    h.display();

    cout << "\n";
}

/////////////////////////////////////////////////////
// 3. MANUAL MIN HEAP IMPLEMENTATION
/////////////////////////////////////////////////////

class MinHeap {
    vector<int> heap;

    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int n = heap.size();

        if (left < n && heap[left] < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Bubble up
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return minVal;
    }

    int getMin() {
        return heap.empty() ? -1 : heap[0];
    }

    void display() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

void manualMinHeapTest() {
    MinHeap h;

    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);
    h.insert(10);

    cout << "Manual Min Heap:\n";
    h.display();  // Min will be at root

    cout << "Min: " << h.getMin() << endl;

    cout << "Extracted Min: " << h.extractMin() << endl;

    cout << "Heap after extraction: ";
    h.display();

    cout << "\n";
}

/////////////////////////////////////////////////////
// 4. BUILT-IN MIN HEAP (priority_queue with greater<>)
/////////////////////////////////////////////////////

void builtInMinHeap() {
    // Custom comparator makes it a Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(20);
    minHeap.push(15);
    minHeap.push(30);
    minHeap.push(40);
    minHeap.push(10);

    cout << "Built-in Min Heap:\n";
    cout << "Min: " << minHeap.top() << endl;  // Output: 10

    minHeap.pop();  // Removes 10

    cout << "Remaining Min Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << "\n";
}

/////////////////////////////////////////////////////
// MAIN FUNCTION
/////////////////////////////////////////////////////

int main() {
    builtInMaxHeap();     // Uses priority_queue<int>
    manualMaxHeapTest();  // Your MaxHeap class
    manualMinHeapTest();  // Your MinHeap class
    builtInMinHeap();     // Uses priority_queue<int, vector<int>, greater<int>>
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthLargest(const vector<int>& heap, int k) {
    int n = heap.size();
    priority_queue<pair<int, int>> pq;
    pq.push({heap[0], 0});
    vector<bool> visited(n, false);
    visited[0] = true;

    int count = 0;
    while (!pq.empty()) {
        auto [val, idx] = pq.top(); pq.pop();
        count++;
        if (count == k) return val;

        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < n && !visited[left]) {
            pq.push({heap[left], left});
            visited[left] = true;
        }

        if (right < n && !visited[right]) {
            pq.push({heap[right], right});
            visited[right] = true;
        }
    }

    return -1;
}

int main() {
    vector<int> heap = {50, 30, 40, 10, 5, 20, 35};
    int k = 3;
    cout << k << "rd largest: " << kthLargest(heap, k) << endl;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthLargest(const vector<int>& arr, int k) {
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
int count=0;
    for (int num : arr) {
        minHeap.push(num);
        count++;
        if (count >k) {
            minHeap.pop(); // Remove the smallest
        }
    }

    return minHeap.top(); // Kth largest
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(const vector<int>& arr, int k) {
    // Max Heap
    priority_queue<int> maxHeap;
    int count = 0;

    for (int num : arr) {
        maxHeap.push(num);
        count++;
        if (count > k) {
            maxHeap.pop(); // Remove the largest among k+1 → keep k smallest
        }
    }

    return maxHeap.top(); // K-th smallest
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "K-th Smallest Element: " << kthSmallest(arr, k) << endl;
    return 0;
}

int main() {
    vector<int> arr = {50, 30, 40, 10, 5, 20, 35};
    int k = 3;

    cout << k << "rd largest using min-heap: " << kthLargest(arr, k) << endl;
    return 0;
}
