#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class
class Queue {
    Node* front; // points to front node
    Node* rear;  // points to rear node

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { // Queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        // If queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << temp->data << " dequeued.\n";
        delete temp;
    }

    // Get front element
    int getFront() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }
    int getRear() {
    if (rear == nullptr) {
        cout << "Queue is empty.\n";
        return -1;  // or throw an exception
    }
    return rear->data;  // ✅ use '->' for pointer
}

    

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display all elements
    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    q.display();
    cout << "Front element: " << q.getFront() << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // Enqueue
    void enqueue(int x) {
        if (size == capacity) {
            cout << "Queue is Full\n";
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % capacity;  // wrap around if needed (circular)
        size++;
        cout << x << " enqueued.\n";
    }

    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        front = (front + 1) % capacity;
        size--;
    }

    // Get Front Element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
    if (size == 0) {
        cout << "Queue is empty.\n";
        return -1;
    }
    return arr[(rear - 1 + capacity) % capacity];
}

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Get size of queue
    int getSize() {
        return size;
    }

    // Display Queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);  // queue of capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.getFront() << endl;

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Back: " << q.back() << endl;   // 30

    q.pop(); // removes 10

    cout << "Front after pop: " << q.front() << endl; // 20

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
