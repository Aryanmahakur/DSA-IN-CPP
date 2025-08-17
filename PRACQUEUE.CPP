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
    void push_front(int val){
        Node* temp= new Node(val);
        if (front == nullptr) { // Queue is empty
            front = rear = temp;
        }else{
          temp->next=front;
          front=temp;
        }
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
    void deque_back() {
    if (rear == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }
    if (front == rear) { // only 1 element
        cout << rear->data << " dequeued from back.\n";
        delete rear;
        front = rear = nullptr;
        return;
    }

    Node* current = front;
    while (current->next != rear) { // stop at 2nd last node
        current = current->next;
    }

    cout << rear->data << " dequeued from back.\n";
    delete rear;
    rear = current;
    rear->next = nullptr;
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
