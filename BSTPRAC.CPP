#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Inorder traversal (Left → Root → Right)
// void inorder(TreeNode* root) {
//     if (root == nullptr) return;
//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }

/*
int getCount(TreeNode* root, int l, int h) {
    if(root==nullptr)return 0;
    int count=0;
    
     
     TreeNode* temp=root;
     if(temp->val >=l && temp->val <=h){
            count++;
     };
      count += getCount(temp->left,l,h);
        
    count += getCount(temp->right,l,h);
    
    return count;
};
*/


int main() {
    // Manually build a BST:
    //        4
    //       / \
    //      2   6
    //     / \ / \
    //    1  3 5  7

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << "Inorder Traversal of BST: ";
    inorder(root);  // Output: 1 2 3 4 5 6 7
    cout << endl;
     cout<< getCount(root,1,5);
    return 0;
}
