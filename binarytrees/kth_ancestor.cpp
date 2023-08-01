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

node *solve(node *root, int Node, int k)
{
    if (root == NULL || root->data == Node)
    {
        return root;
    }

    node *leftAns = solve(root->left, Node, k);
    node *rightAns = solve(root->right, Node, k);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // locking the value of k
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
}

int kth_Ancestor(node *root, int k, int Node)
{
    node *ans = solve(root, Node, k);
    if (ans->data == NULL || ans->data == Node)
        return -1;
    
    return ans->data;
}

int main()
{

    return 0;
}