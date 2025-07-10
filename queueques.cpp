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
class stack{
  queue<int> q1, q2;

public:
    // Push element onto the stack
    void push(int x) {
        q1.push(x);
    }

   void pop(){
    while (q1.size()>1)
    {
        q2.push(q1.front());
        q1.pop();
        /* code */
    }
    cout<<"deleted"<<q1.front()<<endl;
    q1.pop();
    swap(q1,q2);
    
   }
   void top(){
     while (q1.size()>1)
    {
        q2.push(q1.front());
        q1.pop();
        /* code */
    }
    cout<<"top"<<q1.front()<<endl;
   int temp = q1.front();
   q2.push(temp);
   q1.pop();
  swap(q1,q2);
    
   }
   bool isempty(){
    return q1.empty();
   }
};

int main() {
    stack s;

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
#include <iostream>
#include <queue>
#include <string>
using namespace std;
void genratebinary(int n)
{
    queue<string>st;
    st.push("1");
    for (int i = 0; i < n; i++)
    {
        cout<<st.front()<<endl;
        string c=st.front();
        st.pop();
        /* code */
        st.push(c+"0");
        st.push(c+"1");
    }

    
}


void leave(){
 queue<int>q1;
 queue<int>q2;
 queue<int>result;
 q1.push(1);
 q1.push(2);
 q1.push(3);
 q1.push(4);
 q1.push(5);
 q1.push(6);

 int size=q1.size()/2;

for (int i = 0; i < size; i++)
{
 q2.push(q1.front());
 q1.pop();
 /* code */
}

for (int i = 0; i < size; i++)
{
 /* code */
 result.push(q2.front());
 q2.pop();
 result.push(q1.front());
 q1.pop();

}

while(!result.empty())
{
  cout<<result.front()<<endl;
  result.pop();
 /* code */
}


 




};
int main() {
    int N = 5;
   // generateBinaryNumbers(N);


























    return 0;


};
