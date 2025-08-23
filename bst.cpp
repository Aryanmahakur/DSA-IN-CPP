#include <iostream>
#include <climits>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Insert into BST
Node *insert(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal (sorted)
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search in BST
bool search(Node *root, int key)
{
    if (root == nullptr)
        return false;

    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum value in BST
int findMin(Node *root)
{
    if (root == nullptr)
        return INT_MAX;
    Node *curr = root;
    while (curr->left != nullptr)
        curr = curr->left;
    return curr->data;
}

// Find maximum value in BST
int findMax(Node *root)
{
    if (root == nullptr)
        return INT_MIN;
    Node *curr = root;
    while (curr->right != nullptr)
        curr = curr->right;
    return curr->data;
}

// Find node with minimum value in BST (returns pointer, needed for deletion)
Node *findMinNode(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

// Find height of BST
int findHeight(Node *root)
{
    if (root == nullptr)
        return 0;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    return 1 + max(left, right);
}

// Find Lowest Common Ancestor in BST
Node *LCA(Node *root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;

    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

// Delete a node from BST
Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr && root->left == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //   else if

        Node *successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);

        return root;
    };

    bool ifbst(Node * root, int minVal, int maxVal)
    {
        if (root == nullptr)
            return true;

        // Value must be in (minVal, maxVal)
        if (root->data <= minVal || root->data >= maxVal)
            return false;

        // Recursively check left and right subtree with updated bounds
        return ifbst(root->left, minVal, root->data) &&
               ifbst(root->right, root->data, maxVal);
    }
    Node *inorderSuccessor(Node * root, Node * target)
    {
        Node *successor = nullptr;

        while (root != nullptr)
        {
            if (target->data < root->data)
            {
                successor = root; // Potential successor
                root = root->left;
            }
            else
            {
                root = root->right; // Move right, successor not here
            }
        }

        return successor;
    }

    // Wrapper so you can just call ifbst(root)
    bool ifbst(Node * root)
    {
        return ifbst(root, INT_MIN, INT_MAX);
    }
}
// Main function
int main()
{
    Node *root = nullptr;

    // Insert values into BST
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : arr)
    {
        root = insert(root, val);
    }

    // Inorder (sorted)
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

    // Min and Max
    cout << "Minimum: " << findMin(root) << endl;
    cout << "Maximum: " << findMax(root) << endl;

    // Height
    cout << "Height: " << findHeight(root) << endl;

    // LCA
    Node *lca = LCA(root, 30, 75);
    if (lca)
        cout << "LCA is: " << lca->data << endl;
    else
        cout << "LCA not found.\n";

    // Delete a node
    cout << "Deleting node 50...\n";
    root = deleteNode(root, 50);

    // Inorder after deletion
    cout << "Inorder After Deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
