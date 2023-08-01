#include <iostream>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPos(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}
Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);

    int pos = findPos(in, element, n);

    root->left = solve(in, pre, index, inorderStart, pos - 1, n);
    root->right = solve(in, pre, index, pos + 1, inorderEnd, n);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int preorderindex = 0;
    Node *root = solve(in, pre, preorderindex, 0, n - 1, n);
    return root;
}

/*
using map

void nodetomap(int in[],int n,map<int,int>&mapping)
    {
        for(int i=0;i<n;i++)
        {
            mapping[in[i]]=i;
        }
    }
    Node*solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd, int n,map<int,int>&mapping)
    {
        if(index>=n || inorderStart>inorderEnd)
        {
            return NULL;
        }
        
        int element=pre[index++];
        Node*root=new Node(element);
        
        int pos=mapping[element];
        
        root->left=solve(in,pre,index,inorderStart,pos-1,n,mapping);
        root->right=solve(in,pre,index,pos+1,inorderEnd,n,mapping);
    
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=0;
        map<int,int>mapping;
        nodetomap(in,n,mapping);
        Node*root=solve(in,pre,preorderindex,0,n-1,n,mapping);
        return root ;
        
    }
*/

// post order traversal and inorder traversal

// catch we have to build right tree first
void nodetomap(int in[],int n,map<int,int>&mapping)
    {
        for(int i=0;i<n;i++)
        {
            mapping[in[i]]=i;
        }
    }
     Node*solve(int in[],int post[],int &index,int inorderStart,int inorderEnd, int n,map<int,int>&mapping)
    {
        if(index<0 || inorderStart>inorderEnd)
        {
            return NULL;
        }
        
        int element=post[index--];
        Node*root=new Node(element);
        
        int pos=mapping[element];
        
        root->right=solve(in,post,index,pos+1,inorderEnd,n,mapping);
        root->left=solve(in,post,index,inorderStart,pos-1,n,mapping);
    
        return root;
    }
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int preorderindex=n-1;
        map<int,int>mapping;
        nodetomap(in,n,mapping);
        Node*root=solve(in,post,preorderindex,0,n-1,n,mapping);
        return root ;
}
