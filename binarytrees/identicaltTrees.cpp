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

bool isIdentical(node *root1, node *root2)
{
    // base case
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);//is left identical 
    bool right = isIdentical(root1->right, root2->right);//is right identical

    bool value = root1->data == root2->data;//is current identical

    if (left && right && value) //if all three identical
        return true;
    else
        return false;
}
int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    cout << "Tree 1:" << endl;
    buildfromLevelOrder(root1);
    cout << "Tree 2:" << endl;
    buildfromLevelOrder(root2);
    cout<<isIdentical(root1, root2)<<endl;
    if (isIdentical(root1, root2))
    {
        cout << "Identical! " << endl;
    }
    else
    {
        cout << "Not Identical! " << endl;
    }
    return 0;
}