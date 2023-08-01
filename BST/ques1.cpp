//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    class node{
        public:
        int data;
        node*right;
        node*left;
        node(int data)
        {
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
    };
    node* insertNode_and_findSucc(node*root,int key,node*&succ)
    {
        if(root==NULL)
        {
            return new node(key);
        }
        if(key<root->data)
        {
            succ=root;
            root->left=insertNode_and_findSucc(root->left,key,succ);
        }
        else{
            root->right=insertNode_and_findSucc(root->right,key,succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        node*root=NULL;
        for(int i=n-1;i>=0;i--)
        {
            node*succ=NULL;
            root=insertNode_and_findSucc(root,arr[i],succ);
            if(succ)
            {
                arr[i]=succ->data;
            }
            else{
                arr[i]=-1;
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends