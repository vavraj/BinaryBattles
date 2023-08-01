#include<iostream>
#include<vector>
#include<map>
#include<queue>

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

vector<int> verticalTraversal(node*root)
{
    map<int,map<int,vector<int>>>nodes;
    queue<pair<node*,pair<int,int>>>q;
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }

    q.push(make_pair(root,make_pair(0,0)));//pushing root node and hd=0 and level=0
 
    while(!q.empty())
    {
        pair<node*,pair<int,int>>temp=q.front();
        q.pop();

        int hd=temp.second.first;
        int lvl=temp.second.second;
        node*curr=temp.first;

        nodes[hd][lvl].push_back(curr->data);

        if(curr->left)
        {
            q.push(make_pair(curr->left,make_pair(hd-1,lvl+1)));
        }
        if(curr->right)
        {
            q.push(make_pair(curr->right,make_pair(hd+1,lvl+1)));
        }
    }
    
    for(auto i:nodes) // map<int,map<int,vector<int>>>nodes;
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main()
{
    node*root=NULL;
    root=buildfromLevelOrder(root);
    for(auto i:verticalTraversal(root))
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}