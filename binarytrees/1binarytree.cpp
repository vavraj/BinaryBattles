#include <iostream>
#include <queue>
#include<stack>
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

node *buildTree(node *root) // depthwise traversal
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data to be inserted in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to be inserted in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) // purana level complete traverse ho chuka hai
        {
            cout << endl;
            if (!q.empty()) // q still has some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void preorderTraversal(node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }

    node *temp = root;

    cout << temp->data << " ";
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);
}
void inorderTraversal(node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }

    node *temp = root;

    inorderTraversal(temp->left);
    cout << temp->data << " ";
    inorderTraversal(temp->right);
}

void non_rec_Inorder(node*root)
{
    stack<node*> st;
    if(root==NULL)
    {
        return;
    }
    st.push(root);
    node*curr=st.top();
    while(!st.empty())
    {
        while(curr!=NULL)
        {
            curr=curr->left;
            st.push(curr);
        }
        if(!st.empty())
        {
            node*temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            curr=temp->right;
        }
    }
}
void postorderTraversal(node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }

    node *temp = root;

    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout << temp->data << " ";
}
int main()
{
    node *root = NULL;
    root=buildfromLevelOrder(root);
    non_rec_Inorder(root);
    /*
    root = buildTree(root);
    cout<<"LevelOrder"<<endl;
    levelOrderTraversal(root);
    cout<<"\nPreOrder"<<endl;
    preorderTraversal(root);
    cout<<"\nInOrder"<<endl;
    inorderTraversal(root);
    cout<<"\nPostOrder"<<endl;
    postorderTraversal(root);
    */
    return 0;
}