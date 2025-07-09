#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    queue<int>q;
  //  queue<int>result;
  stack<int>result;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    while (!q.empty())
    {
        result.push(q.front()) ;
        q.pop();
    };
    while (!result.empty())
    {
        q.push(result.top());
        result.pop();
        /* code */
    }
    
    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}