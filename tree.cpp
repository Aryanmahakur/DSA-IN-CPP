#include <iostream>
using namespace std;

// Define the Node structure
struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Preorder Traversal: Root -> Left -> Right
void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->left);
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal: Left -> Right -> Root
void postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // Create nodes
    Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    // Print traversals
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

// Define the Node structure
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

// Iterative Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* temp = st.top();
        st.pop();
        cout << temp->data << " ";

        // Push right first so left is processed first
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
}

// Iterative Inorder: Left -> Root -> Right
void inorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Iterative Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main() {
    // Create nodes
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    // Print traversals
    cout << "Iterative Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Iterative Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Iterative Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}
