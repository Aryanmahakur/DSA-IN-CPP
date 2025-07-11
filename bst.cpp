#include <iostream>
#include <climits>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
   if(root==nullptr)return new Node(val);

if(val<root->data){
     root->left=insert(root->left,val);
}
 else
        root->right = insert(root->right, val);

    return root;
}


// Inorder Traversal (sorted)
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search in BST
bool search(Node* root, int key) {
   if(root==nullptr)return false;
   if(root->data==key)return true;
   if(root->data>key){
     return search(root->left,key);
   }
    else
        return search(root->right, key);

}

// Find minimum in BST
int findMin(Node* root) {
    if (root == nullptr) return INT_MAX;

   Node* curr=root;
   while (curr->left!=nullptr)
   {
    curr=curr->left;
    /* code */
   }
   return curr->data;
   
}

// Find maximum in BST
int findMax(Node* root) {
    if (root == nullptr) return INT_MIN;

    Node* curr = root;
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    return curr->data;
}

// Find height of BST
int findHeight(Node* root) {
    if (root == nullptr) return 0;

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return 1 + max(left, right);
}
int main() {
    Node* root = nullptr;

    // Insert values into BST
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : arr) {
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

    return 0;
}
