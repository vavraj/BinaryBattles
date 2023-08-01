#include <iostream>
using namespace std;
class node
{
public:
    char *key;
    node *left;
    node *right;
    char *meaning;
    node(char *key, char *meaning)
    {
        this->key = key;
        this->meaning = meaning;
        this->left = NULL;
        this->right = NULL;
    }
};
class dictionary
{
public:
    node *root;

    void insert(node *root, char *key, char *meaning);
    void search(node *root, char *key);
    void display(node *root);
    void update(node *root, char *key, char *key2, char *meaning2);
    node* delete_key(node *root, char *key);
    node* min(node *root);
};
void dictionary::insert(node *root, char *key, char *meaning)
{
    node *temp = new node(key, meaning);
    if (root == NULL)
    {
        root = temp;
        return;
    }
    if (strcmp(key, root->key) < 0)
    {
        insert(root->left, key, meaning);
    }
    else
    {
        insert(root->right, key, meaning);
    }
}
void dictionary::search(node *root, char *key)
{
    if (root == NULL)
    {
        cout << "search not found ";
        return;
    }
    if (root->key == key)
    {
        cout << "search found ";
    }
    else if (strcmp(key, root->key) < 0)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}
void dictionary::display(node *root)
{
    if (root == NULL)
        return;

    display(root->left);

    cout << "keyword-" << root->key << " meaning-" << root->meaning << endl;

    display(root->right);
}
void dictionary::update(node *root, char *key, char *key2, char *meaning2)
{
    if (root == NULL)
    {
        cout << "key not found ";
        return;
    }
    if (root->key == key)
    {
        root->key = key2;
        root->meaning = meaning2;
        cout << "the value is updated ";
    }
    else if (strcmp(key, root->key) < 0)
    {
        update(root->left, key, key2, meaning2);
    }
    else
    {
        update(root->right, key, key2, meaning2);
    }
}
node *dictionary::min(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node* dictionary::delete_key(node *root, char *key)
{
    if (root == NULL)
    {
        cout<<"Key not found "<<endl;
        return NULL;
    }
    if(root->key==key)
    {
        if(root->left==NULL && root->right==NULL)
        {
            node*temp=root;
            delete temp;
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            node*temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            node*temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else{
            node*mini=min(root->right);
            root->key=mini->key;
            root->meaning=mini->meaning;
            root->right=delete_key(root->right,mini->key);
        }
    }
    else if(strcmp(key,root->key)<0){
        return delete_key(root->left,key);

    }
    else{
        return delete_key(root->right,key);

    }

}
int main()
{
    dictionary d;
    d.root = NULL;

    return 0;
}