/*#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // 🔁 Reverse a string
    string str = "hello";
    stack<char> charStack;

    for (char ch : str)
    {
        charStack.push(ch);
    }

    string reversedStr = "";
    while (!charStack.empty())
    {
        reversedStr += charStack.top();
        charStack.pop();
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversedStr << endl;

    // 🔁 Reverse a stack of integers
    stack<int> s, temp;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Original stack (popping): ";
    while (!s.empty())
    {
        temp.push(s.top());
        cout << s.top() << " ";  // shows 30 20 10
        s.pop();
    }

    cout << "\nReversed stack: ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";  // shows 10 20 30
        temp.pop();
    }

    // 🔁 Reverse a number using stack
    int num = 1234;
    stack<int> digitStack;

    while (num > 0)
    {
        digitStack.push(num % 10);
        num /= 10;
    }

    int reversedNum = 0;
    while (!digitStack.empty())
    {
        reversedNum = reversedNum * 10 + digitStack.top();
        digitStack.pop();
    }

    cout << "\nReversed number: " << reversedNum << endl;

    return 0;
}*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr)
{
    int size = arr.size();
    vector<int> result(size, -1);
    stack<int> st;
    for (int i = size - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
            /* code */
        }
        if (!st.empty())
        {
            result[i] = st.top();
        }
        st.push(arr[i]);

        /* code */
    }
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(arr);

    cout << "Next Greater Elements:\n";
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}
bool isValid(string s){

    stack<char> c;
    for (char cc : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c); // opening bracket
        }
        else
        {
            if (c.empty())
            {
                return false;

            }
            if(cc==)
        }
    }
