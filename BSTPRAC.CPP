#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int val)
    {
        data = val;
        right = left = nullptr;
    }
};
node *insert(node *root, int val)
{
    if (root == nullptr)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void preorder(node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root == nullptr)
        return;
    preorder(root->left);
    cout << root->data << " ";

    preorder(root->right);
}
void postorder(node *root)
{
    if (root == nullptr)
        return;

    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}
bool search(node* root, int key)
{
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
    {
        return search(root->left, key);
    }
    if (key > root->data)
    {
        return search(root->right, key);
    }
}
int findmin(node *root)
{
    if (root == nullptr)
        return 0;
    node *curr = root;
    while (curr->left != nullptr)
    {
        curr = curr->left;
        /* code */
    }
    return curr->data;
}

int findmax(node *root)
{
    if (root == nullptr)
        return 0;
    node *curr = root;
    while (curr->right != nullptr)
    {
        curr = curr->right;
        /* code */
    }
    return curr->data;
}

int main()
{
   node* root= new node(10);
//    node* root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);
    preorder(root);
    return 0;
}
