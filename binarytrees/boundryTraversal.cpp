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

void traverseLeft(node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}
void traverseLeaf(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
void traverseRight(node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundry(node *root)
{
    // base condition
    vector<int> ans;
    if (root == NULL)
        return ans;

    // store root data
    ans.push_back(root->data);

    // store left nodes excluding leaf
    traverseLeft(root->left, ans);

    // store all leaf nodes
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // store right nodes excluding leaf
    traverseRight(root->right,ans);

    return ans;
}
int main()
{
    node *root = NULL;
    root = buildfromLevelOrder(root);
    for (auto i : boundry(root))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}