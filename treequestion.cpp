#include <iostream>
#include <climits>
using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive function to find the maximum value
int findMax(Node* root) {
    if(root==nullptr)return INT_MIN;
    int max1=findMax(root->left);
    int max2=findMax(root->right);
    return max(root->data,max(max1,max2));
   };

int main() {
    /*
        Sample Tree:
                10
               /  \
              20   5
             / \    \
            8  25    3
    */

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(5);
    root->left->left = new Node(8);
    root->left->right = new Node(25);
    root->right->right = new Node(3);

    cout << "Maximum value in the tree: " << findMax(root) << endl;

    return 0;
}
