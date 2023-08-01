#include <iostream>
#include <queue>
#include <stack>
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

void morrisTraversal(node *root) // TC = O(N) & SC = O(1)
{
    if (root == NULL)
    {
        return;
    }
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            node *pred = curr->left;
            while (pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right == NULL) // temporary link creation
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // temporary link removal
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
int main()
{
    node *root = NULL;
    root = buildfromLevelOrder(root);
    morrisTraversal(root);
    return 0;
}