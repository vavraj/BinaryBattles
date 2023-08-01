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

int height(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

//  using class
/*
class data{
    public:
    bool value;
    int height;
};
data isBalancedFast(node *root)
{
    // base condition
    if (root == NULL)
    {
        data p;
        p.value=true;
        p.height=0;
        return p;
    }
    data left = isBalancedFast(root->left);
    data right = isBalancedFast(root->right);
    bool op1 = left.value;
    bool op2 = right.value;
    bool op3 = abs(left.height - right.height) <= 1;
    data ans;
    if (op1 && op2 && op3)
    {
        ans.value = true;
    }
    else
    {
        ans.value=false;
    }
    ans.height = max(left.height, right.height) + 1;//isme hm height store kr rhe hai
    return ans;
}
*/

pair<bool, int> isBalancedFast(node *root) // TC=O(N)
{
    // base condition
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);
    bool op1 = left.first;
    bool op2 = right.first;
    bool op3 = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    if (op1 && op2 && op3)
    {
        ans.first = true;
    }
    else
    {
        ans.first=false;
    }
    ans.second = max(left.second, right.second) + 1;//isme hm height store kr rhe hai
    return ans;
}
bool isBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *root = NULL;
    root = buildfromLevelOrder(root);
    if (isBalancedFast(root).first)
    {
        cout << "Balanced " << endl;
    }
    else
    {
        cout << "Not Balanced " << endl;
    }
    return 0;
}