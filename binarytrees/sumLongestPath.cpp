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

/*
void solve(node *root, pair<int, int> &ans, int lvl, int sum)
{
    if (root == NULL)
    {
         if(lvl>ans.second)
        {
            ans.second=lvl;
            ans.first=sum;
        }
        if(lvl==ans.second)
        {
            ans.first=max(sum,ans.first);
        }
        return;
    }
    sum += root->data;
    
    solve(root->left, ans, lvl + 1, sum);
    solve(root->right, ans, lvl + 1, sum);
}
pair<int, int> LongestRootToLeafSum(node *root)
{
    // base case

    pair<int, int> ans = make_pair(0, 0);
    if (root == NULL)
    {
        return ans;
    }
    int sum=0;
    solve(root, ans, 0, sum);
    return ans;
}
*/
void solve(node*root,int len,int &maxLen,int sum, int &maxSum)
{
    if(root==NULL)
    {
        if(len>maxLen)
        {
            maxLen=len;
            maxSum=sum;
        }
        else if(len==maxLen)
        {
            maxSum=max(maxSum,sum);
        }
        return;
    }

    sum+=root->data;
    solve(root->left,len+1,maxLen,sum,maxSum);
    solve(root->right,len+1,maxLen,sum,maxSum);
}

int LongestRootToLeafSum(node*root)
{
    int len=0;
    int maxLen=0;
    int sum=0;
    int maxSum=0;
    
    solve(root,len,maxLen,sum,maxSum);
    return maxSum;
}
int main()
{
    
    return 0;
}