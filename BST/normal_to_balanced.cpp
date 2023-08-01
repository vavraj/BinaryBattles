//{ Driver Code Starts
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inOrderTraversal(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left, v);
    v.push_back(root->data);
    inOrderTraversal(root->right, v);
}

Node *solve(vector<int> inOrder, int l, int h)
{
    if (l > h)
        return NULL;
    int mid = (l + h) / 2;
    Node *curr = new Node(inOrder[mid]);
    curr->left = solve(inOrder, l, mid - 1);
    curr->right = solve(inOrder, mid + 1, h);

    return curr;
}
Node *buildBalancedTree(Node *root)
{
    vector<int> inOrder;
    inOrderTraversal(root, inOrder);
    root = solve(inOrder, 0, inOrder.size() - 1);
    return root;
}
