#include<vector>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};

class Solution{
  public:
  void inOrder(Node*root,vector<int>&v)
  {
      if(root==NULL)
      return;
      
      inOrder(root->left,v);
      v.push_back(root->data);
      inOrder(root->right,v);
  }
  Node*solve(Node*root,vector<int>v,int &i)
  {
      if(root==NULL || i<0)
      return NULL;
      root->data=v[i--];
      root->right=solve(root->right,v,i);
      root->left=solve(root->left,v,i);
      return root;
  }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int>v;
        inOrder(root,v);
        int i=v.size()-1;
        root=solve(root,v,i);
    }    
};