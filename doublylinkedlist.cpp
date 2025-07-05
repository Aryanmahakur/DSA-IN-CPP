#include <iostream>
using namespace std;

// Node definition
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to print the doubly linked list
void printList(Node *head)
{
    Node *temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
};
void insertattail(Node*& head, int val)
{
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        /* code */
    }
    temp->next = newnode;
    newnode->prev = temp;
  //  head=newnode;
};
void deleteFirst(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
}

int main()
{
    // Create nodes manually
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Linking nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;
    deleteFirst(head);
    insertattail(head,100);
    // Print the list
    printList(head);

    return 0;
}
