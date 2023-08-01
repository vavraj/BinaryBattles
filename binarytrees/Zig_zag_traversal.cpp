#include <iostream>
#include <vector>
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

vector<int> ZigZagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    queue<node *> q;
    q.push(root);
    bool LeftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // process each level
        for (int i = 0; i < size; i++)
        {
            node *frontNode = q.front();
            q.pop();
            // normal insert or reverse insert
            int index = LeftToRight ? i : size - 1 - i;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
        // change the direction
        LeftToRight = !LeftToRight;
        for (auto i : ans)
            result.push_back(i);
    }
    return result;
}

int main()
{
    node *root = NULL;
    root=buildfromLevelOrder(root);

    for(auto i:ZigZagTraversal(root))
    {
        cout<<i<<" ";
    }
    cout << endl;
    return 0;
}