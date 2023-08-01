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

// optimize solution
pair<int, int> diameterFast(node *root) // TC=O(N)  SC=O(H)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1; // opt3 = height(root->left) + height(root->right) + 1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1; // ans = max(left, right) + 1;

    return ans;
}
int diameter(node *root) // TC=O(N*N)
{
    if (root == NULL)
    {
        return 0;
    }
    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) + height(root->right) + 1;

    return max(opt1, max(opt2, opt3));
}
int main()
{
    node *root = NULL;
    root = buildfromLevelOrder(root);
    cout << "Diameter: " << diameter(root) << endl;
    cout << "DiameterFast: " << diameterFast(root).first << endl;
}