#include <iostream>
#include<stack>
#include<queue>

using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
void addNode(int data, node *&root)
{
    node *temp = new node(data);
    if (root == NULL)
    {
        root = temp;
    }
    else if (data < root->data)
    {
        addNode(data,root->left);
    }
    else{
        addNode(data,root->right);
    }
}
void dfs(node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>st;
    st.push(root);
    while (!st.empty())
    {
        node* temp=st.front();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        {
            st.push(temp->left);
        }
        if(temp->right)
        {
            st.push(temp->right);
        }
    }
    cout<<endl;

}

int main()
{
    node*root=NULL;
    char c='y';

    do{
        cout<<"enter an integer ";
        int n;
        cin>>n;
        addNode(n,root);
        cout<<"do you want to continue";
        cin>>c;
    }
    while(c=='y');
    // addNode(5,root);
    // addNode(15,root);
    // addNode(7,root);
    // addNode(11,root);
    // addNode(17,root);
    // addNode(19,root);
    // addNode(22,root);
    // addNode(12,root);
    dfs(root);
    return 0;
}