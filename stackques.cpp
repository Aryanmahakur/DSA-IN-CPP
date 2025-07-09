#include <iostream>
#include <vector>
#include <stack>
#include <cctype> // for isdigit() and isalpha()
using namespace std;

// ✅ Next Greater Element
vector<int>nextgreater(vector<int>arr){
    int n=arr.size();
    vector<int>result(n,-1);
    stack<int>c;
    for (int i = n-1; i>=0; i--)
    {
        while (!c.empty()&&c.top()<=arr[i])
        {
            c.pop();
            /* code */
        }
        if(!c.empty()){
           result[i]=c.top();
        }
        
        /* code */
        c.push(arr[i]);
    }
    return result;
}
vector<int> prevsmall(vector<int> &arr){
    int n=arr.size();
    vector<int>result(n,-1);
    stack<int>c;
    for (int i = 0; i<=; i--)
    {
        while (!c.empty()&&c.top()<=arr[i])
        {
            c.pop();
            /* code */
        }
        if(!c.empty()){
           result[i]=c.top();
        }
        
        /* code */
        c.push(arr[i]);
    }
    return result;
    }
 stack<int> sortStack(stack<int> &input) {
    stack<int> helper;
    int size = input.size();
for (int i = 0; i < size; i++)
{
     int temp=input.top();
     input.pop();
    while (!helper.empty()&&helper.top()>=temp)
    {
         input.push(helper.top());
         helper.pop();
        /* code */
    }
    helper.push(temp);

    
    /* code */
}
return helper;

}


    

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> calculateSpan(const vector<int>& prices) {
    stack<int> c;
    int n = prices.size();
    vector<int> a(n); // Resize to hold 'n' elements

    for (int i = 0; i < n; i++) {
        while (!c.empty() && prices[c.top()] <= prices[i]) {
            c.pop();
        }

        if (c.empty()) {
            a[i] = i + 1; // Entire stretch from day 0
        } else {
            a[i] = i - c.top(); // Distance from previous greater element
        }

        c.push(i); // Push current index
    }

    return a;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> result = calculateSpan(prices);

    cout << "Stock Spans:\n";
    for (int span : result) {
        cout << span << " ";
    }

    return 0;
}

// ✅ Valid Parentheses
bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;

            if ((c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{'))
            {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

// ✅ Evaluate Postfix
int evaluatePostfix(string expr)
{
    stack<int> st;

    for (char ch : expr)
    {
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int result;
            switch (ch)
            {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default:
                cout << "Invalid operator!" << endl;
                return -1;
            }

            st.push(result);
        }
    }

    return st.top();
}

// ✅ Add to last (operands first, then operators)
void addtolast(string val)
{
    stack<char> c;
    for (char cc : val)
    {
        if (isalpha(cc))
        {
            cout << cc << endl;
        }
        else
        {
            c.push(cc);
        }
    }

    while (!c.empty())
    {
        cout << c.top() << endl;
        c.pop();
    }
}

// ✅ SINGLE main() function
int main()
{
    // ➤ Reverse a string
    string str = "hello";
    stack<char> charStack;
    for (char ch : str)
        charStack.push(ch);

    string reversedStr = "";
    while (!charStack.empty())
    {
        reversedStr += charStack.top();
        charStack.pop();
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversedStr << endl;

    // ➤ Reverse a stack
    stack<int> s, temp;
    s.push(10); s.push(20); s.push(30);

    cout << "\nOriginal stack (popping): ";
    while (!s.empty())
    {
        temp.push(s.top());
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\nReversed stack: ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    // ➤ Reverse a number using stack
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
    cout << "\n\nReversed number: " << reversedNum << endl;

    // ➤ Next Greater Element
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ngeResult = nextGreaterElement(arr);

    cout << "\nNext Greater Elements:\n";
    for (int x : ngeResult)
    {
        cout << x << " ";
    }

    // ➤ Valid Parentheses
    cout << "\n\nBracket Validity Check:\n";
    cout << "([]{}) is " << (isValid("([]{})") ? "valid" : "invalid") << endl;
    cout << "([)] is " << (isValid("([)]") ? "valid" : "invalid") << endl;

    // ➤ Evaluate Postfix Expression
    string postfixExpr = "231*+9-";
    int evalResult = evaluatePostfix(postfixExpr);
    cout << "\nPostfix Expression Result: " << evalResult << endl; // Output: -4

    // ➤ Add to Last (operands first)
    string postfix = "ab+c*d";
    cout << "\nAdd to Last (Operands then Operators):\n";
    addtolast(postfix);

    return 0;
}
