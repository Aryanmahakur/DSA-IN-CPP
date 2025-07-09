#include <iostream>
#include <queue>
#include <stack>  // ❌ remove the semicolon here
using namespace std;

int main() {
    queue<int> q;
    stack<int> result;
    queue<int>res;
    int k=3;
    int start=0;
    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Step 1: Push queue elements into stack
    while (start<k) {
        result.push(q.front());
        q.pop();
        start++;
    }

    // Step 2: Push stack elements back into queue (reversed order)
   
  while (!result.empty())
  {
      res.push(result.top());
      result.pop();
    /* code */
  }
  

    // Step 3: Print reversed queue
    cout << "Reversed Queue: ";
    while (!q.empty()) {
        res.push(q.front());
        q.pop();
    }
    while (!res.empty())

    {
        cout<<res.front()<<endl;
        res.pop();
        /* code */
    }
    

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    // Push element onto the stack
    void push(int x) {
        q1.push(x);
    }

    // Remove the top element
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        // Move all elements except the last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Remove the last element (top of the stack)
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Return the top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        int topElement;

        // Move all elements except the last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Get the last element
        topElement = q1.front();
        q2.push(topElement);
        q1.pop();

        // Swap queues
        swap(q1, q2);

        return topElement;
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;  // Output: 30
    s.pop();

    cout << "Top: " << s.top() << endl;  // Output: 20
    s.pop();

    cout << "Top: " << s.top() << endl;  // Output: 10
    s.pop();

    s.pop();  // Output: Stack is empty

    return 0;
}
