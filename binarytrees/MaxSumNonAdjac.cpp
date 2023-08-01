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

node *buildfromLevelOrder(node *root)
{
    queue<node *> q;
    int rootdata;
    cout << "Enter Root Data ";
    cin >> rootdata;
    root = new node(rootdata);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << ":";
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter right node for " << temp->data << ":";
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}
pair<int,int>solve(node*root)
{
    if(root==NULL)
    {
        return make_pair(0,0);
    }

    pair<int,int>leftAns=solve(root->left);
    pair<int,int>rightAns=solve(root->right);

    pair<int,int>temp;
    temp.first=root->data+leftAns.second+rightAns.first;
    temp.second=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);

    return temp;


}

int MaxSum(node*root)
{
    pair<int,int>ans=solve(root);
    return max(ans.first,ans.second);
}