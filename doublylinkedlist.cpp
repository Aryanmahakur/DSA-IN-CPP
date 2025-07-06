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
void insertattail(Node *&head, int val)
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
void deleteFirst(Node *&head)
{
    if (head == nullptr)
        return;

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
}
void deletelast(Node *&head)
{
    if (head == nullptr)
        return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        /* code */
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
void deleteatpos(Node *&head, int pos)
{
    if (head == nullptr)
        return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    int count = 0;
    Node *temp = head;
    while (temp->next != nullptr && count < pos - 1)
    {
        /* code */
        temp = temp->next;
        count++;
    }
    // if (temp == nullptr || temp->next == nullptr) return;

    Node *deletess = temp->next;
    temp->next = temp->next->next;
    if (temp->next != nullptr)
    {
        /* code */
        temp->next->prev = temp;
    }

    delete deletess;
}
void deletedata(Node *&head, int data)
{
    if (head == nullptr)
        return;
    if (head->data == data)
    {
        Node *heads = head;
        head = head->next;

        if (head != nullptr)
        {

            head->prev = nullptr;
        }

        delete heads;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->next->data == data)
        {
            Node *del = temp->next;
            temp->next = del->next;
            if (temp->next != nullptr)
            {
                temp->next->prev = temp;
            }
            delete del;
            return;
        }
        temp = temp->next;
    }
    {
        /* code */
    }
}
void reverseDLL(Node*& head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* current = head;
    Node* temp = nullptr;

   while (current!=nullptr)
   {
    temp=current->prev;
    current->prev=current->next;
    current->next=temp;
    /* code */

    current=current->prev;
   }
   if(head!=nullptr){
    head=temp->prev;
   }
   
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
    // deleteFirst(head);
    // insertattail(head,100);
    // Print the list
  //  deleteatpos(head, 2);
  deletedata(head,20);
    printList(head);

    return 0;
}
