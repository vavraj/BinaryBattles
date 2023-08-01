#include<iostream>
using namespace std;

class Solution {
  public:
  class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

  };
  int countNodes(struct Node* tree)
  {
      if(tree == NULL)
      return 0;
      
      int ans  = 1 + countNodes(tree->left) + countNodes(tree->right);
      
      return ans;
      
  }
  bool isCBT(struct Node*tree,int i,int nodeCount)
  {
      if (tree==NULL)
        return true;
      if(i>nodeCount)
        return false;
      else{
          bool left=isCBT(tree->left,2*i,nodeCount);
          bool right=isCBT(tree->right,2*i+1,nodeCount);
          
          return (left && right);
      }
  }
  
  bool isMaxHeap(struct Node*tree)
  {
      if(tree->left==NULL && tree->right==NULL)
      {
          return true;
      }
      if(tree->right==NULL)
      {
          return (tree->data > tree->left->data);
      }
      else
      {
          bool left=isMaxHeap(tree->left);
          bool right= isMaxHeap(tree->right);
          return (left && right && ((tree->data > tree->left->data) && (tree->data > tree->right->data))); 
      }
  }
    bool isHeap(struct Node* tree) {
        int nodeCount=countNodes(tree);
        
        int i=1;
        if(isCBT(tree,i,nodeCount) && isMaxHeap(tree))
        {
            return true;
        }
        else {
             return false;
    }
    }
};