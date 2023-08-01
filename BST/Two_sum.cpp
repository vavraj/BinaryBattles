//{ Driver Code Starts
#include<iostream>

using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 

// } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    void inOrderTraversal(struct Node *root,vector<int>&v)
    {
        if(root==NULL)
        return;
        
        inOrderTraversal(root->left,v);
        v.push_back(root->data);
        inOrderTraversal(root->right,v);
    }
    int isPairPresent(struct Node *root, int target)
    {
        vector<int>v;
        inOrderTraversal(root,v);
        int i=0;int j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]==target)
                return 1;
            else if(v[i]+v[j]>target)
                j--;
            else
                i++;
        }
        return 0;
    }
};