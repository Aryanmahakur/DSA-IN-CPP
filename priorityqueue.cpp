#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        int n = heap.size();

        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Insert a new value into the heap
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Bubble up
        while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Remove and return the maximum element
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

    // Display heap as array
    void display() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }

    // Peek maximum without removing
    int getMax() {
        return heap.empty() ? -1 : heap[0];
    }
};

int main() {
    MaxHeap h;

    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);
    h.insert(10);

    cout << "Heap: ";
    h.display();  // Output: 40 30 20 15 10 (structure may vary but root is max)

    cout << "Max: " << h.getMax() << endl;

    cout << "Extracted Max: " << h.extractMax() << endl;

    cout << "Heap after extraction: ";
    h.display();

    return 0;
}
