#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root) // depthwise traversal
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data to be inserted in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to be inserted in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void countLeaf(node *root,int &count) // using inorder traversal
{
    // base condition
    if (root == NULL)
    {
        return;
    }

    
    countLeaf(root->left,count);
    if(root->left==NULL && root->right==NULL)
    {
        count++;
    }
    countLeaf(root->right,count);
}
int main()
{
    node*root=NULL;
    root=buildTree(root);
    int count=0;
    countLeaf(root,count);
    cout<<"Count: "<<count<<endl;
}