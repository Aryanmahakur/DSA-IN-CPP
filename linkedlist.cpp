#include <iostream>
using namespace std;

// ---------------------------
// Definition of Node Class
// ---------------------------
class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

// ---------------------------
// Print Linked List
// ---------------------------
void printList(node* head) {
    int count = 0;
    node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }

    cout << "NULL" << endl;
    cout << "Node count: " << count << endl;
}

// ---------------------------
// Insert at Beginning
// ---------------------------
void insertAtBeginning(node*& head, int val) {
    node* newNode = new node(val);
    newNode->next = head;
    head = newNode;
}

// ---------------------------
// Insert at Last
// ---------------------------
void insertAtLast(node*& head, int val) {
    node* newNode = new node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// ---------------------------
// Insert at Specific Position
// ---------------------------
void insertAtPos(node*& head, int pos, int val) {
    node* newNode = new node(val);

    // Insert at head
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    node* temp = head;
    int count = 0;

    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// ---------------------------
// Delete First Node
// ---------------------------
void deleteFirstNode(node*& head) {
    if (head == nullptr) return;

    node* temp = head;
    head = head->next;
    delete temp;
}

// ---------------------------
// Delete Last Node
// ---------------------------
void deleteLastNode(node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// ---------------------------
// Delete Node at Specific Position
// ---------------------------
void deleteAtPos(node*& head, int pos) {
    if (head == nullptr) return;

    // Delete head
    if (pos == 0) {
        node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    node* temp = head;
    int count = 0;

    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// ---------------------------
// Main Function
// ---------------------------
int main() {
    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);

    deleteAtPos(head, 2);             // Delete node at position 2 (30)
    printList(head);

    cout << "After insertions and deletions:" << endl;

    insertAtBeginning(head, 1);       // Insert 1 at beginning
    insertAtLast(head, 80);           // Insert 80 at last
    printList(head);

    deleteLastNode(head);             // Delete last node (80)
    deleteFirstNode(head);            // Delete first node (1)
    insertAtPos(head, 3, 100);        // Insert 100 at position 3
    printList(head);

    return 0;
}
