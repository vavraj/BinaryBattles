#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;



    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

//step 1: store inorder of both bst in array or a queue
void inorder(TreeNode *root,queue<TreeNode*>&v)
{
    if(root==NULL)
    return ;

    inorder(root->left,v);
    v.push(root);
    inorder(root->right,v);
}
//step 2: merege both the arrays
vector<int> merge(queue<TreeNode *>v1,queue<TreeNode*>v2)
{
    vector<int>ans;
    while(!v1.empty() && !v2.empty())
    {
        TreeNode*temp1=v1.front();
        TreeNode*temp2=v2.front();
        if(temp1->data>temp2->data)
        {
            ans.push_back(temp2->data);
            v2.pop();
        }
        else{
            ans.push_back(temp1->data);
            v1.pop();
        }
    }
    while(!v1.empty())
    {
        ans.push_back(v1.front()->data);
        v1.pop();
    }
    while(!v2.empty())
    {
        ans.push_back(v2.front()->data);
        v2.pop();
    }
    return ans;
}
//step 3: build bst from the merged array 
TreeNode*buildBST(vector<int>v,int l,int h)
{
    if(l>h)
        return NULL;
    int mid=(l+h)/2;

    TreeNode*root=new TreeNode(v[mid]);
    root->left=buildBST(v,l,mid-1);
    root->right=buildBST(v,mid+1,h);
    return root;
    
}
TreeNode*mergeBST(TreeNode*root1, TreeNode*root2){
    // Write your code here.
    queue<TreeNode*>v1;
    queue<TreeNode*>v2;
    inorder(root1,v1);
    inorder(root2,v2);
    vector<int>v3=merge(v1,v2);
    return buildBST(v3,0,v3.size()-1);
}