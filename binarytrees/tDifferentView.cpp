#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

// top view
vector<int> topView(node *root) // TC=O(N*N) because map me check bhi krega so worst case me N square ho skta hai
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> topnode;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *currNode = temp.first;
        int hd = temp.second;
        // if one value present then do nothing
        if (topnode.find(hd) == topnode.end()) // comes to end if it doesnt find hd
        {
            topnode[hd] = currNode->data; // stores value if no mapping found
        }

        if (currNode->left)
            q.push(make_pair(currNode->left, hd - 1));
        if (currNode->right)
            q.push(make_pair(currNode->right, hd + 1));
    }

    for (auto i : topnode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// bottom view
vector<int> bottomView(node *root) // TC=O(N) because saare node ko ek baar visit krega
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> topnode;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *currNode = temp.first;
        int hd = temp.second;

        topnode[hd] = currNode->data; // koi condition mat check karo bas daal do jo last me bachega wahi mera ans hoga
        if (currNode->left)
            q.push(make_pair(currNode->left, hd - 1));
        if (currNode->right)
            q.push(make_pair(currNode->right, hd + 1));
    }

    for (auto i : topnode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// left view
vector<int> leftView(node*root,vector<int>&ans,int lvl)
{
    // base condition
    if(root==NULL)
    {
        return ans;
    }

    if(lvl==ans.size())
    {
        ans.push_back(root->data);
    }

    leftView(root->left,ans,lvl+1);
    leftView(root->right,ans,lvl+1);

    return ans;
}

// right view
vector<int> rightView(node*root,vector<int>&ans,int lvl)
{
    // base condition
    if(root==NULL)
    {
        return ans;
    }

    if(lvl==ans.size())
    {
        ans.push_back(root->data);
    }

    rightView(root->right,ans,lvl+1);
    rightView(root->left,ans,lvl+1);

    return ans;
}

int main()
{
    node *root = NULL;
    root = buildfromLevelOrder(root);
    vector<int>ans;
    for (auto i : rightView(root,ans,0))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}