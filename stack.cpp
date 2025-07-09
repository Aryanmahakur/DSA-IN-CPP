#include <iostream>
using namespace std;
#include <stack>
class Stack {
private:
    int top;
    int arr[100];  // max size

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();    // 30 20 10
    s.pop();
    s.display();    // 20 10
    cout << "Top element: " << s.peek() << "\n";
}
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }    
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(15);
    s.push(25);
    s.display();    // 25 15 5
    s.pop();
    s.display();    // 15 5
    cout << "Top: " << s.peek() << "\n";
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
#include <queue>  // Include STL queue
using namespace std;

int main() {
    // Declare a queue of integers
    queue<int> q;

    // Enqueue (push) elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue front: " << q.front() << endl;  // 10
    cout << "Queue back: " << q.back() << endl;    // 30
    cout << "Queue size: " << q.size() << endl;    // 3

    // Dequeue (pop) elements
    q.pop();  // removes 10

    cout << "\nAfter one pop:\n";
    cout << "Queue front: " << q.front() << endl;  // 20
    cout << "Queue back: " << q.back() << endl;    // 30
    cout << "Queue size: " << q.size() << endl;    // 2

    // Print all elements in the queue
    cout << "\nRemaining elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
