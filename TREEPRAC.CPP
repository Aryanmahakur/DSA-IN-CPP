#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
int findheight(node* temp){
  if(temp==nullptr){
    return 0;

  }
  return 1 + max(findheight(temp->left),findheight(temp->right));
   
}
int main()
{
    node *temp = new node(1);
    temp->left = new node(2);
    temp->right = new node(3);
    temp->left->left = new node(4);
    temp->left->right = new node(5);
    temp->right->left = new node(6);
    temp->right->right = new node(7);

   cout<<findheight(temp)<<endl;
}