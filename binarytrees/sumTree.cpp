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

node *buildfromLevelOrder(node *&root)
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

pair<bool, int> isSum(node *root)
{
    // base condition
    if (root == NULL)
    {
        return make_pair(true, 0);
    }
    if(root->left==NULL && root->right==NULL)//suppose leaf node hai then (0+0!=root->data)
    {
        return make_pair(true,root->data);
    }

    pair<bool, int> left = isSum(root->left);
    pair<bool, int> right = isSum(root->right);

    int sum = left.second + right.second;
    bool curr = sum == root->data;

    if (left.first && right.first && curr)
    {
        return make_pair(true, 2*root->data);
    }
    else
    {
        return make_pair(false,2*root->data);
    }
}

int main()
{
    node*root=NULL;
    buildfromLevelOrder(root);
    if(isSum(root).first)
    {
        cout<<"Balanced Sum Tree! "<<endl;
    }
    else{
        cout<<"Not A Balanced Sum Tree! "<<endl;
    }
    return 0;
}
