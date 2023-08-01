//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    Node*root=NULL;

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
void inorderStore(Node*root,vector<int>&v)
{
    if(root==NULL)
    return ;
    
    inorderStore(root->left,v);
    v.push_back(root->data);
    inorderStore(root->right,v);
}

    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>v1;
        vector<int>v2;
        
        inorderStore(root1,v1);
        inorderStore(root2,v2);
    
    
    int i=0;
    int j=v2.size()-1;
    int ans=0;
    while(i<v1.size() && j>=0)
    {
        cout<<"Hi";
        if(v1[i]+v2[j]==x)
        {
            ans++;
            i++;
            j--;
        }
        else if(v1[i]+v2[j]>x)
        {
            j--;
        }
        else{
            i++;
        }
    }
    return ans;
}
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends