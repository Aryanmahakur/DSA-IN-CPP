int findMax(Node* root) {
    if(root==nullptr)return INT_MIN;
    int max1=findMax(root->left);
    int max2=findMax(root->right);
    max(root->data,max(max1,max2));
   };