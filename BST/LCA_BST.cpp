//{ Driver Code Starts
#include<iostream>
#include<queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree

Node* LCA(Node * root , int l , int h);

// } Driver Code Ends


//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root==NULL)
   return NULL;
   
//   recursive way

  /*
  if(root->data<n1 && root->data<n2)
  return LCA(root->right,n1,n2);
  if(root->data>n1 && root->data>n2)
  return LCA(root->left,n1,n2);
  return root;
  */
   
//   iterative way
   
   while(root!=NULL)
   {
       if(root->data<n1 && root->data<n2)
            root=root->right;
       else if(root->data>n1 && root->data>n2)
            root=root->left;
            
        else 
        return root;
   }
   
}


