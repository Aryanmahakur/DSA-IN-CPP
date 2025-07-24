#include <iostream>
using namespace std;

// Node definition
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Insert at head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at tail
void insertAtTail(Node *&head, int val)
{
    if (head == nullptr)
    {
        insertAtHead(head, val);
        return;
    }

    Node *newNode = new Node(val);
    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;a
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete head node
void deleteAtHead(Node *&head)
{
    if (head == nullptr)
        return;

    if (head->next == head) // only one node
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    Node *last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    delete temp;
}

// Delete by value
void deleteByValue(Node *&head, int val)
{
    if (head == nullptr)
        return;

    if (head->data == val)
    {
        deleteAtHead(head);
        return;
    }

    Node *curr = head;

    while (curr->next != head && curr->next->data != val)
    {
        curr = curr->next;
    }

    if (curr->next == head)
    {
        cout << "Value not found!" << endl;
        return;
    }

    Node *toDelete = curr->next;
    curr->next = curr->next->next;
    delete toDelete;
}

// Search
bool search(Node *head, int key)
{
    if (head == nullptr)
        return false;

    Node *temp = head;
    do
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    } while (temp != head);

    return false;
}

// Display
void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    cout << "Circular Linked List: ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

// MAIN
int main()
{
    Node *head = nullptr;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5);

    display(head); // Output: 5 -> 10 -> 20 -> 30 -> (back to head)

    cout << "Deleting 10...\n";
    deleteByValue(head, 10);
    display(head);

    cout << "Searching for 20: " << (search(head, 20) ? "Found" : "Not Found") << endl;

    cout << "Deleting head...\n";
    deleteAtHead(head);
    display(head);

    return 0;
}















































































#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    // 🔸 Insert at end - Time Complexity: O(n)
    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head) // Traverses all n nodes
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // 🔸 Display the list - Time Complexity: O(n)
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }

    // 🔸 Insert at beginning - Time Complexity: O(n)
    void insertatbegging(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head) // Traverses all n nodes to update last node
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // 🔸 Insert at specific position - Time Complexity: O(pos) (best case O(1), worst case O(n))
    void insertatpos(int pos, int data)
    {
        Node *newnode = new Node(data);
        if (head == nullptr)
        {
            head = newnode;
            head->next = head;
            return;
        }
        if (pos == 0)
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
            return;
        }
        Node *temp = head;
        int count = 0;
        while (count < pos - 1 && temp->next != head) // Traverses up to pos
        {
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    // 🔸 Delete at specific position - Time Complexity: O(pos) (best case O(1), worst case O(n))
    void deletepos(int pos)
    {
        if (head == nullptr)
            return;

        if (pos == 0)
        {
            if (head->next == head)
            {
                delete head;
                head = nullptr;
                return;
            }
            Node *temp = head;

            // Find the last node - Time Complexity: O(n)
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }

            last->next = head->next; // Fix circular link
            head = head->next;
            delete temp;
            return;
        }

        // Deleting non-head node
        Node *temp = head;
        int count = 0;

        while (count < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            count++;
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // 🔸 Main function — use outside the class
};

// 🔹 Correct main() should be outside the class
int main()
{
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);

    cout << "Circular Linked List:\n";
    cll.insertatbegging(11);
    cll.display();

    return 0;
}
