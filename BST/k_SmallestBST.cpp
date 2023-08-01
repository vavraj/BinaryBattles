//{ Driver Code Starts
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree

// } Driver Code Ends
/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Return the Kth smallest element in the given BST
    void inorder(Node *root, vector<int> &array)
    {
        if (root == NULL)
            return;

        inorder(root->left, array);
        array.push_back(root->data);
        inorder(root->right, array);
    }
    int KthSmallestElement(Node *root, int K)
    {
        vector<int> array;
        inorder(root, array);
        if (K > array.size())
            return -1;
        else
            return array[K - 1];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        // Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        //  getline(cin, s);
        Solution obj;
        // cout << obj.KthSmallestElement(root, k) << endl;
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends