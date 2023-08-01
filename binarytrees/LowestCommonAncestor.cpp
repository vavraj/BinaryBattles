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

node *solve(node *root, int n1, int n2)
{
    if (root == NULL || root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftAns = solve(root->left, n1, n2);
    node *rightAns = solve(root->right, n1, n2);

    if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (left != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (left != NULL && rightAns != NULL)
    {
        return root;
    }
}

int LCA(node *root, int n1, int n2)
{
    node *ans;
    ans = solve(root, n1, n2);
    return ans->data;
}

int main()
{

    return 0;
}