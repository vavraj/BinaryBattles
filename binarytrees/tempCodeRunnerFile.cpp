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
    ~node()
    {
        this->right=NULL;
        this->left=NULL;
        delete right;
        delete left;
    }
};

node *insertData(node *&root, int d)
{
    // base condition
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertData(root->right, d);
    }
    else
    {
        root->left = insertData(root->left, d);
    }
    return root;
}
void createBST(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertData(root, data);
        cin >> data;
    }
}

bool search(node *root, int val) // SC = O(H)  TC = O(log N)
{
    // base condition
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }

    if (val < root->data)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

bool searchIteratively(node *root, int val) // SC = O(1)
{
    if (root == NULL)
    {
        return false;
    }
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        if (val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
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

node*minValue(node*root)
{
    if(root==NULL)
    return NULL;

    node*temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

node*maxValue(node*root)
{
    if(root==NULL)
    return NULL;

    node*temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}

node* deleteNode(node*root,int value)
{
    // base case
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==value)
    {
        // 0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child 

        //left child 
        if(root->left!=NULL && root->right==NULL) 
        {
            node*temp=root->left;
            delete root;
            return temp;
        }


        //right child 
        if(root->left==NULL && root->right!=NULL) 
        {
            node*temp=root->right;
            delete root;
            return temp;
        }
        
        // 2 child 

        if(root->left!=NULL && root->right!=NULL)
        {
            int mini=minValue(root->right)->data;
            root->data=mini;
            root->right=deleteNode(root->right,mini);
            return root;
        }

    }

    if(value<root->data)
    {
        root->left=deleteNode(root->left,value);
    }
    else{
        root->right=deleteNode(root->right,value);
    }
    return root;
}
int main()
{
    node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    if (searchIteratively(root, 15))
    {
        cout << "Found " << endl;
    }
    else
    {
        cout << "Not Found " << endl;
    }

    cout<<minValue(root)->data<<endl;
    root=deleteNode(root,10);
    cout<<minValue(root)->data<<endl;
    return 0;
}