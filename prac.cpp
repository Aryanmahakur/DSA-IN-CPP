// // stack with array

// #include <iostream>
// /*
// class stack
// {
// private:
//     int top;
//     int arr[100];

// public:
//     stack()
//     {
//         top = -1;
//     }
//     void push(int x)
//     {
//         if (top >=99)
//         {
//             std::cout << "the array is full" << std::endl;
//             return;
//         }

//         arr[++top] = x;
//     }
//     void pop()
//     {
//         if (top == -1)
//         {
//             std::cout << "the array is empty" << std::endl;
//             return;
//         }
//         top--;
//     }
//     int peek()
//     {
//         if (top == -1)
//         {
//             std::cout << "the array is empty" << std::endl;
//             return 0;
//         }
//         return arr[top];
//     }
//     bool isempty()
//     {
//         if (top == -1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     void display()
//     {
//         if (top == -1)
//         {
//             std::cout << "the array is empty" << std::endl;
//             return;
//         }
//         for (int i = top; i >= 0; i--)
//         {
//             std::cout << arr[i] << " ";
//         }
//     }
// };
// int main(){
//     stack s;
//     s.push(10);
//     s.display();
// }
// */
// class node{
//     public:
//     int data;
//     node* next;
// node(int x){
//     data=x;
//     next=nullptr;

// }
// };
// class stack{
//     private:
//     node* top;
//     public:
//     stack(){
//         top=nullptr;

//     }
//     void push(int x){
//         node* newnode=new node(x);
//         newnode->next=top;
//         top=newnode;
//     }

//     void pop(){
//         if(top==nullptr){
//              std::cout << "the node is empty" << std::endl;
//              return;
//         }
//         node* temp=top;
//         top=top->next;
//         delete temp;
//     }
//     int peek(){
//          if(top==nullptr){
//              std::cout << "the node is empty" << std::endl;
//              return;
//         }
//         return top->data;
//     }
//       bool isEmpty() {
//         return top == nullptr;
//     }
//     void display(){
//         node* temp=top;
//         while (temp!=nullptr)
//         {
//             std::cout<<temp->data<<std::endl;
//             temp=temp->next;
//             /* code */
//         }

        
//     }
// };
// int main(){
//     stack s;
//     s.push(10);
// // }
// #include <iostream>
// #include <stack>
// using namespace std;

// string reverse(string a){
//     stack<char>aa;
    
//    string r="";
// for(char c:a){
//     aa.push(c);
// }
// while (!aa.empty())
// {
//     r +=aa.top();
//     aa.pop();
// };
// return r;
// };

// int main(){
//    string a="hello";
//    string aaaa=reverse(a);
//    cout<<aaaa<<endl;
// }
#include <iostream>
#include <stack>
using namespace std;

// Insert element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }
    
    int topVal = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(topVal);
}

// Reverse the stack using recursion
void reverseStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }
    
    int topVal = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topVal);
}

int main() {
    stack<int> st;

    // Push elements into stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Original stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(st);

    cout << "Reversed stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}



#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Your stack-based logic here
        
    }
};

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution sol;
    vector<int> result = sol.dailyTemperatures(temperatures);

    // Print the result
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;
}








