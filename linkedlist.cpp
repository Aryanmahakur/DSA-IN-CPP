#include <iostream>
using namespace std;

// ---------------------------
// Definition of Node Class
// ---------------------------
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};
D
// ---------------------------
// Print Linked List
// ---------------------------
void printList(node *head)
{
    int count = 0;
    node *temp = head;

    while (temp != nullptr)
    {
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
void insertAtBeginning(node *&head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
}

// ---------------------------
// Insert at Last
// ---------------------------
void insertAtLast(node *&head, int val)
{
    node *newNode = new node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// ---------------------------
// Insert at Specific Position
// ---------------------------
void insertAtPos(node *&head, int pos, int val)
{
    node *newNode = new node(val);

    // Insert at head
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    node *temp = head;
    int count = 0;

    while (temp != nullptr && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
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
void deleteFirstNode(node *&head)
{
    if (head == nullptr)
        return;

    node *temp = head;
    head = head->next;
    delete temp;
}

// ---------------------------
// Delete Last Node
// ---------------------------
void deleteLastNode(node *&head)
{
    if (head == nullptr)
        return;

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// ---------------------------
// Delete Node at Specific Position
// ---------------------------
void deleteAtPos(node *&head, int pos)
{
    if (head == nullptr)
        return;

    // Delete head
    if (pos == 0)
    {
        node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    node *temp = head;
    int count = 0;

    while (temp != nullptr && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Position out of bounds" << endl;
        return;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
int findpos(node *&head, int searchdata)
{
    int count = 0;
    node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == searchdata)
            return count;
        temp = temp->next;
        count++;
    }

    return 0;
};
node *reverselinkedlist(node *head)
{
    node* temp=head;
    node* prev=nullptr;
    node* next=nullptr;
    while (temp!=nullptr){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }

    head=prev;
    return head;

}
void middle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        /* code */
    }
    cout << slow->data << endl;
}
int findnth(node *head, int n)
{
    node *temp = head;
    int count = 1;
    while (temp != nullptr)
    {
        if (count == n)
        {
            return temp->data;
        }
        temp = temp->next;
        count++;
    }
    cout << "Node doesn't exist" << endl;
    return -1; // or throw an error
}
void deleteduplicates(node *head)
{
    node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->data == temp->next->data)
        {
            node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete; // Free memory
        }
        else
        {
            temp = temp->next;
        }
    }
}
void deleteDuplicatesUnsorted(node *head)
{
    node *current = head;

    while (current != nullptr)
    {
        node *prev = current;
        node *temp = current->next;

        while (temp != nullptr)
        {
            if (temp->data == current->data)
            {
                // Duplicate found; delete the node
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }
}
node *insertatsorted(node *head, int data)
{
    node *newnode = new node(data);
    node *temp = head;
    if (temp == nullptr || data < temp->data)
    {
        newnode->next = temp;
        return newnode;
    }
    while (temp->next != nullptr && temp->next->data < data)
    {
        /* code */
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
node *deleteakey(node *head, int key)
{
    node *temp = head;
    if (head == nullptr)
        return nullptr;
    if (head->data == key)
    {
        node *todelete = head;
        head = head->next;
        delete todelete;
        return head;
    }
    while (temp->next != nullptr && temp->next->data != key)
    {
        temp = temp->next;
        /* code */
    }
    if (temp->next != nullptr)
    {
        node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
    return head;
}

bool hasLoop(node *head)
{
    node *slow = head;
    node *fast = head;
    if (slow->next == nullptr)
    {
        return false;
    }
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "it loop" << endl;
            node *temp = head;
            while (slow->next != temp->next)
            {
                slow = slow->next;
                temp = temp->next;
            }

            // Step 2: Break the loop
            slow->next = nullptr; // or fast->next = nullptr
            cout << "Loop removed." << endl;
            return true;
        }
    }

    return false;
}
node* merger(node* head,node* head2){
    node* dummy=new node(-1);
    node* tail=dummy;
    while (head!=nullptr && head2!=nullptr)
    {
        /* code */
        if(head->data<head2->data){
            tail->next=head;
            head=head->next;
        }else{
            tail->next=head2;
            head2=head2->next;
        }
        tail=tail->next;
    }
      if (head != nullptr) tail->next = head;
    if (head2 != nullptr) tail->next = head2;

    return dummy->next; // skip dummy node
}
// ---------------------------
// Main Function
// ---------------------------
int main()
{
    
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    
    node *head1 = new node(15);
    head1->next = new node(25);
    head1->next->next = new node(35);
    head1->next->next->next = new node(45);
  //  merger(head,head1);
 reverselinkedlist(head);
    printList(head);
    //  head->next->next->next->next = head->next; // create loop: 40 → 20

   // hasLoop(head);                                    // 40->next = 20
  //  cout << (hasLoop(head)?"true": "false" )<< endl; // 40->next = 20
                   /*
                       hasLoop(head);
                       insertatsorted(head,25);
                       deleteakey(head,30);
                       printList(head);
                        middle(head);
                       head = reverselinkedlist(head);  // Reverse and reassign
               
                       cout << "Reversed List: ";
                       printList(head);
                       int a= findpos(head,10);
                       cout<<"pos"<<a<<endl ;
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
                   */
    return 0;
}
