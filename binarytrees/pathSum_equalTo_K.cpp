#include <iostream>
#include<queue>
#include <vector>

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
void solve(node *root, int &count, int k, vector<int> &path)
{
    // base condition
    if (root == NULL)
        return;
    
    path.push_back(root->data);

    solve(root->left,count,k,path);
    solve(root->right,count,k,path);
    int sum=0;
    for(int i=path.size()-1;i>=0;i--)
    {
        sum+=path[i];
        if(sum==k)
        count++;
    }
    path.pop_back();

}
int sumKPath(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, count, k, path);
    return count;
}
int main()
{
    node*root=NULL;
    root=buildfromLevelOrder(root);
    cout<<sumKPath(root,3);
}